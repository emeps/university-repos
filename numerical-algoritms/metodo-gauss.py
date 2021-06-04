from numpy import linalg as LA
import numpy as np

# Criação da matriz princial
def diagonal(tamanho):
    diag = []
    for x in range(tamanho):
        for y in range(tamanho):
            # Para os valores de posição da matriz que não são iguais
            if(x != y):
                diag.append(0)
            else:
                diag.append(4)
    diag = np.array(diag)
    diag = diag.reshape(tamanho, tamanho)
    return diag

# Criação da matriz inferior.
def inferior(tamanho):
    inf = np.zeros(shape=(tamanho, tamanho))
    for x in range(tamanho):
        for y in range(tamanho):
            # Os valores são para acima da linha da diagonal.
            if(x != (tamanho/2)) and (y == x - 1):
                inf[x][y] = -1
            # Os valores são para a metade da coluna da matriz onde tem uma diagonal
            # não nula.
            elif(x >= (tamanho/2)) and (y == x - (tamanho/2)):
                inf[x][y] = -1
    return inf

# Criação da matriz superior.
def superior(tamanho):
    sup = np.zeros(shape=(tamanho, tamanho))
    for x in range(tamanho):
        for y in range(tamanho):
            # Os valores são para acima da linha da diagonal.
            if(x != (tamanho/2) -1) and (y == x + 1):
                sup[x][y] = -1
            # Os valores são para a metade da linha da matriz onde tem uma diagonal
            # não nula.
            elif(x <= (tamanho/2)) and (y == x + (tamanho/2)):
                sup[x][y] = -1
    return sup

# Soma de todas as matrizes para formar a matriz principal.
def soma (superior, inferior, diagonal):
    return superior + inferior + diagonal

# Criação do vetor B dado os aspectos do problemas onde a metade é zero pois não há
# chance de sair pelo sul e outra metade é igual a 1 onde estão localizadas as saidas sul.
# Aproveitamos e criamos os vetor inicial, vetor no qual será o ponta pé inicial para o 
# desenvolvimento do calculo.
def matrizB(tamanho):
    b = np.zeros(shape=(tamanho))
    matrizInicial = np.zeros(shape=(tamanho))
    for x in range(tamanho):
        # Metade do vetor B é igual a 1, pois aonde tem possibilidade de saida pelo sul.
        if( x >= (tamanho/2)):
            b[x] = 1
            matrizInicial[x] = 0
        # Metade do vetor B é igual a zero, pois não tem possibilidade de saida pelo sul.
        else:
            b[x] = 0
            matrizInicial[x] = 0
    return (b,matrizInicial)  

def gaussSeidel( A,b, inicial):
    erro = np.inf
    while erro > 0.00001 :
        # Desenvolvimento dos calculos do metodo de Gauss-Seidel
        for i in range(len(A)):
            x = b[i]
            norma = np.array(inicial)
            for j in range(len(A)):
                if i!=j:
                    x -= A[i][j]*inicial[j]
            x/=A[i][i]
            inicial[i] = x
            inicial  = np.array(inicial)
            # Calculo do Erro, critério de parada.
            erro = LA.norm((inicial - norma),np.inf)/LA.norm(inicial,np.inf)
            # print(f'Erro: {erro}')
    # Impressão das Probabilidades
    print('Erro: ',erro)
    impress(inicial)

def impress(matriz):
    for i in matriz:
            print('------------------')
            print(i)
    print('------------------') 

#inicialização do sistema.
tamanho = int(input('Entre com o tamanho da Matriz: '))
matrizSuperior = superior(tamanho)
print('Matriz Superior (S)\n',matrizSuperior)
matrizInferior = inferior(tamanho)
print('Matriz Inferior (I)\n',matrizInferior)
matrizDiagonal = diagonal(tamanho)
print('Matriz Diagonal (D)\n',matrizDiagonal)
matrizSoma = soma(matrizSuperior, matrizInferior, matrizDiagonal)
print('Matriz Principal (A):\n', matrizSoma)
matrizTermos = matrizB(tamanho)
print('Matriz dos Termos Independentes \n', matrizTermos[0])
print('Matriz Inicial \n', matrizTermos[1])
gaussSeidel(matrizSoma,matrizTermos[0], matrizTermos[1])