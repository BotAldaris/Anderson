import pandas as pd
import matplotlib.pyplot as plt

# Leitura dos dados do CSV
df = pd.read_csv('dados_serial.csv')

# Convertendo a coluna Timestamp para o formato de tempo
df['Timestamp'] = pd.to_datetime(df['Timestamp'], format='%H:%M:%S')

# Encontrando o horário e o valor correspondente ao maior valor
indice_max_valor = df['Valor'].idxmax()
horario_max_valor = df.loc[indice_max_valor, 'Timestamp']
valor_max = df.loc[indice_max_valor, 'Valor']

# Plotando o gráfico
plt.plot(df['Timestamp'], df['Valor'])
plt.xlabel('Timestamp')
plt.ylabel('Valor')
plt.title('Gráfico a partir de dados CSV')

# Adicionando uma marcação para o ponto de valor máximo no gráfico
plt.scatter(horario_max_valor, valor_max, color='red', label=f'Maior Valor\nHora: {horario_max_valor.time()}\nValor: {valor_max}')
plt.legend()

# Exibindo o gráfico
plt.show()
