# Pratica 001
# Emerson Patryck da Silva
# 2020205603
import math as mt

def convertRadians(angle):
    #Conversão radianos -> graus
    return (angle / 180)*mt.pi

def printOut(x,y):
    print("\n")
    print(f'Real part: {x:.4f}\nImaginary part: {y:.4f}')
    #Estética
    comp = complex(x,y)
    print("\n")
    print(f'Rectangular:{comp:.4f}')
    print("\n")

def convertRectangular(z, angle):
    #Conversão da parte real
    x = z*mt.cos(angle)
    #Conversão da parte imaginaria
    y = z*mt.sin(angle)
    printOut(x,y)

#Entradas de dados
z = float(input('Enter the value of the module '))
angle = float(input('Enter the phasor value '))
#Chamada da função de conversão com a chamada para conversão do angulo rads -> graus
convertRectangular(z, convertRadians(angle))