import numpy as np
import matplotlib.pyplot as plt


def rungeKutta4(t0, tf, u1_0, u2_0, u3_0, h):
    t = np.arange(t0, tf+h, h)
    M = t.size - 1

    y1 = np.zeros(t.size)
    y1[0] = u1_0
    y2 = np.zeros(t.size)
    y2[0] = u2_0
    y3 = np.zeros(t.size)
    y3[0] = u3_0

    # Parâmetros do método de Runge-Kutta de ordem 4
    b1 = 1.0/6.0
    b2 = 1.0/3.0
    b3 = b2
    b4 = b1
    c2 = 1
    a21 = c2
    c3 = 1.0/5.0
    a31 = 0
    a32 = c3
    c4 = 1
    a41 = a42 = 0
    a43 = c4

    # Execução do método de Runge-Kutta de ordem 4
    for i in range(M):
        k1f1 = f1(t[i], y1[i], y2[i], y3[i])
        k1f2 = f2(t[i], y1[i], y2[i], y3[i])
        k1f3 = f3(t[i], y1[i], y2[i], y3[i])

        k2f1 = f1(t[i] + c2*h, y1[i] + a21*k1f1*h, y2[i] + a21*k1f2*h, y3[i] + a21*k1f3*h)
        k2f2 = f2(t[i] + c2*h, y1[i] + a21*k1f1*h, y2[i] + a21*k1f2*h, y3[i] + a21*k1f3*h)
        k2f3 = f3(t[i] + c2*h, y1[i] + a21*k1f1*h, y2[i] + a21*k1f2*h, y3[i] + a21*k1f3*h)

        k3f1 = f1(t[i] + c3*h, y1[i] + (a31*k1f1 + a32*k2f1)*h,
                  y2[i] + (a31*k1f2 + a32*k2f2)*h, y3[i] + (a31*k1f3 + a32*k2f3)*h)
        k3f2 = f2(t[i] + c3*h, y1[i] + (a31*k1f1 + a32*k2f1)*h,
                  y2[i] + (a31*k1f2 + a32*k2f2)*h, y3[i] + (a31*k1f3 + a32*k2f3)*h)
        k3f3 = f3(t[i] + c3*h, y1[i] + (a31*k1f1 + a32*k2f1)*h,
                  y2[i] + (a31*k1f2 + a32*k2f2)*h, y3[i] + (a31*k1f3 + a32*k2f3)*h)

        k4f1 = f1(t[i] + c4*h, y1[i] + (a41*k1f1 + a42*k2f1 + a43*k3f1)*h,
                  y2[i] + (a41*k1f2 + a42*k2f2 + a43*k3f2)*h, y3[i] + (a41*k1f3 + a42*k2f3 + a43*k3f3)*h)
        k4f2 = f2(t[i] + c4*h, y1[i] + (a41*k1f1 + a42*k2f1 + a43*k3f1)*h,
                  y2[i] + (a41*k1f2 + a42*k2f2 + a43*k3f2)*h, y3[i] + (a41*k1f3 + a42*k2f3 + a43*k3f3)*h)
        k4f3 = f3(t[i] + c4*h, y1[i] + (a41*k1f1 + a42*k2f1 + a43*k3f1)*h,
                  y2[i] + (a41*k1f2 + a42*k2f2 + a43*k3f2)*h, y3[i] + (a41*k1f3 + a42*k2f3 + a43*k3f3)*h)

        y1[i+1] = y1[i] + h*(b1*k1f1 + b2*k2f1 + b3*k3f1 + b4*k4f1)
        y2[i+1] = y2[i] + h*(b1*k1f2 + b2*k2f2 + b3*k3f2 + b4*k4f2)
        y3[i+1] = y3[i] + h*(b1*k1f3 + b2*k2f3 + b3*k3f3 + b4*k4f3)
    return t, y1, y2, y3


# Função 1 do sistema de PVIs de primeira ordem
def f1(t, y1, y2, y3):
    sigma = 10.
    return sigma*(y2-y1)


# Função 2 do sistema de PVIs de primeira ordem
def f2(t, y1, y2, y3):
    r = 28.
    return r*y1-y2-y1*y3


# Função 3 do sistema de PVIs de primeira ordem
def f3(t, y1, y2, y3):
    b = 8./3.
    return y1*y2-b*y3

# Valores dos extremos do intervalo
t0 = 0
tf = 100

# Valores iniciais
y1_0 = 0
y2_0 = 1
y3_0 = 0

# Tamanho do sub-intervalo
h = 0.01

t, y1, y2, y3 = rungeKutta4(t0, tf, y1_0, y2_0, y3_0, h)

# Plot do gráfico y3(t) em função do y1(t)
fig, ax = plt.subplots(figsize=(15, 6.5))
fig.suptitle("Sistema de Lorenz\n Runge-Kutta ordem 4")
ax.plot(y1, y3, color="#980064")
ax.set_ylabel("y3(t)")
ax.set_xlabel("y1(t)")
ax.text(-20.0, 0.0,
        "b1 = 1/6\
        b2 = 1/3\
        b3 = b2\
        b4 = b1\
        c2 = 1\n\
a21 = c2\
        c3 = 1/5\
        a31 = 0\
        a32 = c3\
        c4 = 1\n\
a41 = a42 = 0\
        a43 = c4", alpha=0.6)
fig.tight_layout()
plt.show()
