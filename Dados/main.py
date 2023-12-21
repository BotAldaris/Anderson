import serial
import time
import csv

# Configurações da porta serial
porta_serial = 'COM3'  # Altere para a porta serial do seu dispositivo
velocidade_serial = 9600

# Abre a porta serial
ser = serial.Serial(porta_serial, velocidade_serial, timeout=1)

# Nome do arquivo CSV para salvar os dados
nome_arquivo_csv = 'ki1.csv'

# Abre o arquivo CSV para escrever
with open(nome_arquivo_csv, 'w', newline='') as arquivo_csv:
    # Configura o escritor CSV
    escritor_csv = csv.writer(arquivo_csv)
    # Escreve o cabeçalho no arquivo CSV
    escritor_csv.writerow(['Timestamp', 'Valor'])

    # Obtém o timestamp da primeira medição
    start_timestamp = time.time()

    # Inicializa o timestamp anterior
    before_timestamp = None

    try:
        while True:
            # Lê os dados da porta serial
            dados_str = ser.readline().decode('utf-8').strip()

            # Calcula o timestamp em segundos desde a primeira medição
            elapsed_time = time.time() - start_timestamp

            # Verifica se o timestamp mudou antes de escrever no arquivo CSV
            if before_timestamp is None or elapsed_time != before_timestamp:
                # Converte os dados para float
                try:
                    valor = float(dados_str)
                except ValueError:
                    print(f"Ignorando dados inválidos: {dados_str}")
                    continue

                # Escreve os dados no arquivo CSV
                escritor_csv.writerow([elapsed_time, valor])
                arquivo_csv.flush()  # Certifica-se de que os dados são escritos imediatamente

                # Imprime os dados no console
                print(f"{elapsed_time} - {valor}")

                # Atualiza o timestamp anterior
                before_timestamp = elapsed_time

    except KeyboardInterrupt:
        # Fecha a porta serial quando o programa é interrompido
        ser.close()
        print("\nLeitura da porta serial interrompida. Dados salvos em", nome_arquivo_csv)
