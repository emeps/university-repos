# Pratica 001
# Emerson Patryck da Silva
# 2020205603
import math as mt

def printOut(n,k):
    print("\n")
    print(f'Modulo: {n:.4f}\nFasor: {k:.4f}')
    print("\n")

def checkQuadrant(angle,complexNumber):
    #Verificação do quadrante pertencente
    if(complexNumber.real > 0 and complexNumber.imag > 0):
        return angle
    elif(complexNumber.real < 0 and complexNumber.imag > 0):
        return 180 + angle
    elif(complexNumber.real < 0 and complexNumber.imag < 0):
        return 270 - angle
    elif(complexNumber.real > 0 and complexNumber.imag < 0):
        return 360 + angle

def convertPolar(complexNumber):
    #Calcula o modulo
    z = mt.sqrt(mt.pow(complexNumber.real,2) + mt.pow(complexNumber.imag,2))
    #Calcula o fasor em graus
    angle = mt.degrees(mt.atan(complexNumber.imag/complexNumber.real))
    #Imprime o resultado da conversão
    printOut(z,checkQuadrant(angle, complexNumber))

#Entradas dos dados
complexNumber = complex(float(input('Enter the value of the real part ')),
float(input('Enter the value of the imaginary part ')))
#Chamada da função conversão
convertPolar(complexNumber)