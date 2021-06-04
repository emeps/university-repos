def checkSide(a, b, c):
    if(a == b == c):
        print('Triangulo equilatero.')
    elif (a == b != c or a == c != b or b == c != a):
        print('Triangulo isosceles.')
    elif (a != b and a != c):
        print('Triangulo escaleno.')


def checkAngle(a, b, c):
    if((a**2) < (b**2 + c**2)):
        print('Triangulo acutangulo.')
    elif((a**2) == (b**2 + c**2)):
        print('Triangulo retangulo.')
    elif((a**2) > (b**2 + c**2)):
        print('Triangulo obtusangulo.')


def checkValues(a, b, c):
    if(a <= 0 or b <= 0 or c <= 0):
        print('Valores invalidos.')
    elif((a >= c + b) or (b >= a + c) or (c >= a + b)):
        print('Valores nao podem formar um triangulo.')
    elif(b > a and b > c):
        checkSide(a, b, c)
        checkAngle(b, a, c)
    elif(c > a and c > b):
        checkSide(a, b, c)
        checkAngle(c, b, a)
    else:
        checkSide(a, b, c)
        checkAngle(a, b, c)


def valueInput():
    a = int(input())
    b = int(input())
    c = int(input())
    checkValues(a, b, c)


valueInput()
