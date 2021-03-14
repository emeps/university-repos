# Pratica 001
# Emerson Patryck da Silva
# 2020205603
import numpy as np
import matplotlib.pyplot as plt


Ds = 6*np.pi
Tam = 1/(50*Ds)
B = 0.33333

x = np.arange(-2*Ds, 2*Ds, Tam)

E = 50*np.cos(B*x)
E1 = -50*np.sin(B*x)
E2 = -50*np.cos(B*x)

fig, ax1 = plt.subplots(3,1)
ax1[0].plot(x/Ds, E, 'r-', linewidth=2)
ax1[0].set_xlabel("Comprimento (lambda)")
ax1[0].set_ylabel("Amplitude")
ax1[0].grid(True)
ax1[0].set_title('E(y) = 50*cos(B*x)')

ax1[1].plot(x/Ds, E1, 'r-', linewidth=2)
ax1[1].set_xlabel("Comprimento (lambda)")
ax1[1].set_ylabel("Amplitude")
ax1[1].grid(True)
ax1[1].set_title('E(y) = -50*sin(B*x)')

ax1[2].plot(x/Ds, E2, 'r-', linewidth=2)
ax1[2].set_xlabel("Comprimento (lambda)")
ax1[2].set_ylabel("Amplitude")
ax1[2].grid(True)
ax1[2].set_title('E(y) = -50*cos(B*x)')
fig.tight_layout()

plt.show()