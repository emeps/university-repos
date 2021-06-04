#script runge-kutta2.py

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
def metRK2(t0,tf,y0,M):
#----------------------------------------------------------------------------
# Função que resolve o PVI y' = f(t,y) no intervalo [t0, tf], com condicao 
# inicial y(t0) = y0 e numero de subintervalos igual a M, de forma que 
# h = (tf - t0)/M, usando o método de Euler explícito
#----------------------------------------------------------------------------
    h = (tf - t0)/M
    t = np.linspace(t0,tf,M+1)
    y = np.zeros(M+1) 
    y[0] = y0
    c2 = 1
    a21 = c2
    b1 = 1
    b2 = 0
    for i in range(0, M):
    	k1 = Func(t[i],y[i])
    	k2 = Func(t[i] + c2*h,y[i] + a21*h*k1)
    	y[i+1] = y[i] + h*(b1*k1 + b2*k2)
    return t, y
#============================================================================




#============================================================================
# Parte principal do programa que implementa o método de Euler explícito para
# resolver PVIs
#============================================================================

t0 = 0  # tempo inicial
tf = 2  # tempo final
y0 = 1  # valor inicial: y0 = y(t0)
M = 10 # número de subintervalos (número de ponto é igual a M + 1)
#
t, y = metRK2(t0,tf,y0,M)
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

plt.plot(t,y, linestyle='solid',color='black', label='Solução aproximada (método RK2)')
plt.plot(t,yex, linestyle='dashed',color='blue', label='Solução exata')
plt.xlabel('t')
plt.ylabel('y(t)')
plt.grid(True)
plt.legend()
plt.show()