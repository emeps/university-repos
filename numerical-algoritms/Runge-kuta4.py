#script runge-kutta4.py

import numpy as np
from numpy import linalg as LA
from matplotlib import pyplot as plt 



#============================================================================
def solExata(t):
#----------------------------------------------------------------------------
# Função que retorna a solução exata do PVI
# y(t) = (3e^(-2t) + 2t + 1)/4
#----------------------------------------------------------------------------
    return (3*np.exp(-2*t)+2*t+1)/4
#============================================================================


#============================================================================
def Func(t,y):
#----------------------------------------------------------------------------
# Função f(t,y) do lado direito do PVI dy/dt = f(t,y)
# f(t,y) = t - 2y + 1
#----------------------------------------------------------------------------
	return t - 2*y + 1
#============================================================================

#============================================================================
def metRK4(t0,tf,y0,M):
#----------------------------------------------------------------------------
# Função que resolve o PVI y' = f(t,y) no intervalo [t0, tf], com condicao 
# inicial y(t0) = y0 e numero de subintervalos igual a M, de forma que 
# h = (tf - t0)/M, usando o método de Euler explícito
#----------------------------------------------------------------------------
    h = (tf - t0)/M
    t = np.linspace(t0,tf,M+1)
    y = np.zeros(M+1) 
    y[0] = y0
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
    for i in range(0, M):
    	k1 = Func(t[i],y[i])
    	k2 = Func(t[i] + c2*h,y[i] + a21*k1*h)
    	k3 = Func(t[i] + c3*h,y[i] + (a31*k1 + a32*k2)*h)
    	k4 = Func(t[i] + c4*h,y[i] + (a41*k1 + a42*k2 + a43*k3)*h)
    	y[i+1] = y[i] + h*(b1*k1 + b2*k2 + b3*k3 + b4*k4)
    return t, y
#============================================================================




#============================================================================
# Parte principal do programa que implementa o método de Euler explícito para
# resolver PVIs
#============================================================================

t0 = 0  # tempo inicial
tf = 2  # tempo final
y0 = 1  # valor inicial: y0 = y(t0)
M = 30 # número de subintervalos (número de ponto é igual a M + 1)
#
t, y = metRK4(t0,tf,y0,M)
yex = solExata(t)

print("============================================================")
print('{:>5s}{:>13s}{:>13s}{:>13s}{:>13s}'.format('i','ti','sol exata','sol aprox','erro abs'))
print("============================================================")
for i in range(0,M+1):
    print('{:5d}{:>13,.4f}{:>13,.4f}{:>13,.4f}{:>13,.4f}'.format(i,t[i],yex[i],y[i],abs(yex[i]-y[i])))
print("============================================================")

print("Erro na norma do máximo =",LA.norm(y - yex, np.inf))

#print(t)
#print("y = ")
#print(y)
#print("solExata = ")
#print(yex)
#erro = abs(y - yex)
#print("erro = ")
#print(erro)

plt.plot(t,y, linestyle='solid',color='black', label='Solução aproximada (método RK4)')
plt.plot(t,yex, linestyle='dashed',color='blue', label='Solução exata')
plt.xlabel('t')
plt.ylabel('y(t)')
plt.grid(True)
plt.legend()
plt.show()