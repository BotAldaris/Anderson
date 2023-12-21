import pandas as pd
import matplotlib.pyplot as plt

# Leitura dos dados do CSV
df = pd.read_csv('ki1.csv')

# Encontrando o horário e o valor correspondente ao maior valor
indice_max_valor = df[df['Valor'] == 40].index[0]
horario_max_valor = df.loc[indice_max_valor, 'Timestamp']
valor_max = df.loc[indice_max_valor, 'Valor']

# Plotando o gráfico
plt.plot(df['Timestamp'], df['Valor'])
plt.xlabel('Timestamp')
plt.ylabel('Valor')
plt.title("ki1")

# Adicionando uma marcação para o ponto de valor máximo no gráfico
plt.scatter(horario_max_valor, valor_max, color='red', label=f'Maior Valor\nSegundos: {horario_max_valor}\nValor: {valor_max}')
plt.legend()

# Exibindo o gráfico
plt.show()
