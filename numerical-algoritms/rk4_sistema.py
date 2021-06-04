import numpy as np
from numpy import linalg as LA
from matplotlib import pyplot as plt 


#============================================================================
def der_solExata(t):
#----------------------------------------------------------------------------
# Função que retorna a derivada da solução exata do PVI
# y'(t) = (e^t(3+2t) -3 e^-t)/4
#----------------------------------------------------------------------------
    return (np.exp(t)*(3+ 2*t) - 3*np.exp(-t))/4
#============================================================================

#============================================================================
def solExata(t):
#----------------------------------------------------------------------------
# Função que retorna a solução exata do PVI
# y(t) = (e^t(1+2t) + 3e^-t)/4
#----------------------------------------------------------------------------
    return (np.exp(t)*(1+ 2*t) + 3*np.exp(-t))/4
#============================================================================


#============================================================================
def Func1(t,u1,u2):
#----------------------------------------------------------------------------
# Função f1(t,u_1(t),u_2(t)) 
#----------------------------------------------------------------------------
	return u2
#============================================================================

#============================================================================
def Func2(t,u1,u2):
#----------------------------------------------------------------------------
# Função f2(t,u_1(t),u_2(t)) 
#----------------------------------------------------------------------------
    return (u1 + np.exp(t))
#============================================================================

#============================================================================
def metRK4_sistema(t0,tf,u_10,u_20,M):
#----------------------------------------------------------------------------
# Função que resolve um sistema de PVIs com duas equações usando
# o método de Euler explícito
#----------------------------------------------------------------------------
    h = (tf - t0)/M
    t = np.linspace(t0,tf,M+1)
    u1 = np.zeros(M+1)
    u2 = np.zeros(M+1)
    u1[0] = u_10
    u2[0] = u_20
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
        k1f1 = Func1(t[i],u1[i],u2[i])
        k1f2 = Func2(t[i],u1[i],u2[i])
        k2f1 = Func1(t[i] + c2*h,u1[i] + a21*k1f1*h,u2[i] + a21*k1f2*h)
        k2f2 = Func2(t[i] + c2*h,u1[i] + a21*k1f2*h,u2[i] + a21*k1f2*h)
        k3f1 = Func1(t[i] + c3*h,u1[i] + (a31*k1f1 + a32*k2f1)*h,u2[i] + (a31*k1f2 + a32*k2f2)*h)
        k3f2 = Func2(t[i] + c3*h,u1[i] + (a31*k1f1 + a32*k2f1)*h,u2[i] + (a31*k1f2 + a32*k2f2)*h)
        k4f1 = Func1(t[i] + c4*h,u1[i] + (a41*k1f1 + a42*k2f1 + a43*k3f1)*h,u2[i] + (a41*k1f2 + a42*k2f2 + a43*k3f2)*h)
        k4f2 = Func2(t[i] + c4*h,u1[i] + (a41*k1f1 + a42*k2f1 + a43*k3f1)*h,u2[i] + (a41*k1f2 + a42*k2f2 + a43*k3f2)*h)
        u1[i+1] = u1[i] + h*(b1*k1f1 + b2*k2f1 + b3*k3f1 + b4*k4f1)
        u2[i+1] = u2[i] + h*(b1*k1f2 + b2*k2f2 + b3*k3f2 + b4*k4f2)
    return t, u1, u2
#============================================================================

#============================================================================
# Parte principal do programa que implementa o método de Euler explícito para
# resolver um sistema de PVIs com duas equações
#============================================================================

t0 = 0  # tempo inicial
tf = 1  # tempo final
u_10 = 1  # valor inicial: u_1,0 = u_1(t0)
u_20 = 0  # valor inicial: u_2,0 = u_2(t0)
M = 10 # número de subintervalos (número de ponto é igual a M + 1)
#
t, u1, u2 = metRK4_sistema(t0,tf,u_10,u_20,M)
yex = solExata(t)
der_yex = der_solExata(t)

print("============================================================")
print('{:>5s}{:>13s}{:>13s}{:>13s}{:>13s}{:>13s}'.format('i','ti','sol exata','aprox u1','aprox u2','|yex - u1|'))
print("============================================================")
for i in range(0,M+1):
    print('{:5d}{:>13,.4f}{:>13,.4f}{:>13,.4f}{:>13,.4f}{:>13,.4f}'.format(i,t[i],yex[i],u1[i],u2[i],abs(yex[i]-u1[i])))
print("============================================================")

plt.plot(t,u1, linestyle='solid',color='black',linewidth=2,label='Método RK4 - u_1(t)')
plt.plot(t,yex, linestyle='dashed',color='blue',linewidth=2,label='Solução exata: y(t)')
#plt.plot(t,u2, linestyle='solid',color='black',linewidth=2,label='Método RK4 - u_2(t)')
#plt.plot(t,der_yex, linestyle='dashed',color='blue',linewidth=2,label='Derivada da solução exata: y\'(t)')
plt.xlabel('t')
plt.ylabel('y(t)')
plt.grid(True)
plt.legend()
plt.show()