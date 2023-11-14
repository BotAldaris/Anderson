import datetime

temperaturaInicial = 32.06
temperaturaFinal = 56
ganho = temperaturaFinal - temperaturaInicial
amplitude = 110
k = ganho/amplitude

# 16:15:27
print(temperaturaInicial+ ganho*0.632)
# 16:12:59
print(temperaturaInicial + ganho*0.283)
# 16:11:43
tempoInicial = datetime.timedelta(hours=16,minutes=11,seconds=43)
t1 = datetime.timedelta(hours=16,minutes=12,seconds=59)
t2 = datetime.timedelta(hours=16,minutes=15,seconds=27)
t1s = (t1.total_seconds() - tempoInicial.total_seconds())/60
t2s = (t2.total_seconds() - tempoInicial.total_seconds())/60
tau = (3/2)*(t2s-t1s)
omega = t2s - tau
print(tau)
kp = (1/k)*(tau/omega)*((16*tau+3*omega)/(12*tau))
ti = 2*omega
td = 0.5 * omega
ki = kp /ti
kd = kp * td
print(kp)
print(ki)
print(kd)

print(omega/tau)