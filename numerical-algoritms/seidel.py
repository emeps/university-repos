def gaussSeidel(A,b,sol,iteracoes):
    iteracao = 0
    while iteracao < iteracoes:
        for i in range(len(A)):
            x = b[i]
            for j in range(len(A)):
                if i!=j:
                    x-= A[i][j]*sol[j]
            x/=A[i][j]
            sol[i] = x
        iteracao += 1
    print(sol)

A= [[14, -2, -4],[4, 12, -6],[2, 6 ,4]]


gaussSeidel(A,[1,1,1],[230,115,0],50)