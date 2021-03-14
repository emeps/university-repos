# Pratica 001
# Emerson Patryck da Silva
# 2020205603
import numpy as np
import matplotlib.pyplot as plt

k = 0.667
t1 = 3.927e-9
Ds = 3*np.pi
Tam = 1/(100*Ds)

x = np.arange(-2*Ds , 2*Ds , Tam)

H = 0.1*np.cos(2e8*t1 - k*x)

plt.plot(x,H)
plt.title('H(y) = 0,1cos((2.10^8)t - kx)')
plt.xlabel('Comprimento [lambda]')
plt.ylabel('Amplitude')
plt.grid(True)

plt.show()