import serial
import time
import csv

# Configurações da porta serial
porta_serial = 'COM3'  # Altere para a porta serial do seu dispositivo
velocidade_serial = 9600

# Abre a porta serial
ser = serial.Serial(porta_serial, velocidade_serial, timeout=1)

# Nome do arquivo CSV para salvar os dados
nome_arquivo_csv = 'dados_serial.csv'

# Abre o arquivo CSV para escrever
with open(nome_arquivo_csv, 'w', newline='') as arquivo_csv:
    # Configura o escritor CSV
    escritor_csv = csv.writer(arquivo_csv)
    beforetimestamp = time.strftime("%H:%M:%S", time.localtime())
    # Escreve o cabeçalho no arquivo CSV
    escritor_csv.writerow(['Timestamp', 'Valor'])

    try:
        while True:
            # Lê os dados da porta serial
            dados_str = ser.readline().decode('utf-8').strip()

            # Obtém a data e hora atual
            timestamp = time.strftime("%H:%M:%S", time.localtime())
            if beforetimestamp != timestamp:
                # Converte os dados para float
                try:
                    valor = float(dados_str)
                except ValueError:
                    print(f"Ignorando dados inválidos: {dados_str}")
                    continue

                # Escreve os dados no arquivo CSV
                escritor_csv.writerow([timestamp, valor])
                arquivo_csv.flush()  # Certifica-se de que os dados são escritos imediatamente

                # Imprime os dados no console
                print(f"{timestamp} - {valor}")
            beforetimestamp = timestamp

    except KeyboardInterrupt:
        # Fecha a porta serial quando o programa é interrompido
        ser.close()
        print("\nLeitura da porta serial interrompida. Dados salvos em", nome_arquivo_csv)
