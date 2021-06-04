def imprimeTabuleiro(p1, p2, p3, p4, p5, p6, p7, p8, p9):
    """
    Recebe os valores das nove posições do tabuleiro e imprime o tabuleiro
    """
    # Complete o código da função
    print(f' {p7} | {p8} | {p9} ')
    print(f'---+---+---')
    print(f' {p4} | {p5} | {p6} ')
    print(f'---+---+---')
    print(f' {p1} | {p2} | {p3} ')


def entradaValida(p1, p2, p3, p4, p5, p6, p7, p8, p9):
    """
    Recebe os valores das nove posições do tabuleiro e
    verifica se os valores são válidos, ou seja, retorna True
    se cada variável possui " " ou "x" ou "o" e False, caso contrário.
    """
    # Complete o código da função
    return (
        (True if (p1 == " " or p1 == "x" or p1 == "o") else False) and
        (True if (p2 == " " or p2 == "x" or p2 == "o") else False) and
        (True if (p3 == " " or p3 == "x" or p3 == "o") else False) and
        (True if (p4 == " " or p4 == "x" or p4 == "o") else False) and
        (True if (p5 == " " or p5 == "x" or p5 == "o") else False) and
        (True if (p6 == " " or p6 == "x" or p6 == "o") else False) and
        (True if (p7 == " " or p7 == "x" or p7 == "o") else False) and
        (True if (p8 == " " or p8 == "x" or p8 == "o") else False) and
        (True if (p9 == " " or p9 == "x" or p9 == "o") else False)
    )


def jogadaValida(p1, p2, p3, p4, p5, p6, p7, p8, p9):
    """
    Recebe os valores das nove posições do tabuleiro e
    verifica se os valores formam uma jogada válida.

    Retorna True se a jogada for válida e False, caso contrário
    """
    # Complete o código da função
    countBola = 0
    countX = 0
    if (p1 == 'o'):
        countBola += 1
    elif(p1 == 'x'):
        countX += 1

    if (p2 == 'o'):
        countBola += 1
    elif(p2 == 'x'):
        countX += 1

    if (p3 == 'o'):
        countBola += 1
    elif(p3 == 'x'):
        countX += 1

    if (p4 == 'o'):
        countBola += 1
    elif(p4 == 'x'):
        countX += 1

    if (p5 == 'o'):
        countBola += 1
    elif(p5 == 'x'):
        countX += 1

    if (p6 == 'o'):
        countBola += 1
    elif(p6 == 'x'):
        countX += 1

    if (p7 == 'o'):
        countBola += 1
    elif(p7 == 'x'):
        countX += 1

    if (p8 == 'o'):
        countBola += 1
    elif(p8 == 'x'):
        countX += 1

    if (p9 == 'o'):
        countBola += 1
    elif(p9 == 'x'):
        countX += 1

    # print('X', countX)
    # print('O', countBola)
    if(countX > countBola):
        # print('Dife', (countX - countBola))
        return (True if((countX - countBola) <= 1) else False)
    else:
        # print('Dife', (countBola - countX))
        return (True if((countBola - countX) <= 1) else False)


def verificaJogada(p1, p2, p3, p4, p5, p6, p7, p8, p9):
    """
    Recebe os valores das nove posições do tabuleiro e
    imprime se um jogador ('x' ou 'o') venceu a jogada. 
    (Cada variável representa uma posição no tabuleiro)
    """
    # Complete o código da função

    # Verificação dos casos quando o jogodor faz a trinca horizontal
    if((p1 == p2 == p3) and (p1 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p1 == p2 == p3) and (p1 == "o")):
        print("O jogador 'o' venceu!")
    elif((p6 == p4 == p5) and (p6 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p6 == p4 == p5) and (p6 == "o")):
        print("O jogador 'o' venceu!")
    elif((p7 == p8 == p9) and (p7 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p7 == p8 == p9) and (p7 == "o")):
        print("O jogador 'o' venceu!")

    # Verificação dos casos quando o jogodor faz a trinca vertical
    elif((p1 == p4 == p7) and (p1 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p1 == p4 == p7) and (p1 == "o")):
        print("O jogador 'o' venceu!")
    elif((p2 == p5 == p8) and (p2 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p2 == p5 == p8) and (p2 == "o")):
        print("O jogador 'o' venceu!")
    elif((p3 == p6 == p9) and (p3 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p3 == p6 == p9) and (p3 == "o")):
        print("O jogador 'o' venceu!")

    # Verificação dos casos quando o jogador faz trinca nas diagonais
    elif((p1 == p5 == p9) and (p1 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p1 == p5 == p9) and (p1 == "o")):
        print("O jogador 'o' venceu!")
    elif((p3 == p5 == p7) and (p3 == "x")):
        print(f"O jogador 'x' venceu!")
    elif((p3 == p5 == p7) and (p3 == "o")):
        print("O jogador 'o' venceu!")
    elif(p1 == " " or p2 == " " or p3 == " " or p4 == " " or p5 == " " or p6 == " " or p7 == " " or p8 == " " or p9 == " "):
        print("O jogo nao terminou!")
    else:
        print("Empate!")


## NÃO ALTERE A FUNÇÃO 'main' ##
def main():
    t1 = input()
    t2 = input()
    t3 = input()
    t4 = input()
    t5 = input()
    t6 = input()
    t7 = input()
    t8 = input()
    t9 = input()
    imprimeTabuleiro(t1, t2, t3, t4, t5, t6, t7, t8, t9)
    if not entradaValida(t1, t2, t3, t4, t5, t6, t7, t8, t9):
        print("Entrada invalida!")
    elif not jogadaValida(t1, t2, t3, t4, t5, t6, t7, t8, t9):
        print("Jogada invalida!")
    else:
        verificaJogada(t1, t2, t3, t4, t5, t6, t7, t8, t9)


main()
