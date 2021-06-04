import random
from os import system, name

def getMatricula():
    """
    Retorna a matricula do aluno como string
    """
    return "2020205603"

def getNome():
    """
    Retorna o nome completo do aluno
    """
    return "EMERSON PATRYCK DA SILVA"

def limpaTela():
    if name == 'nt':
        system('cls')
    else:
        system('clear')

# Inicializar o tabuleiro com as posições vazias
def inicializaTabuleiro():
    tabuleiro = [" "]*10
    return tabuleiro

# Imprimir o tabuleiro.
def tabuleiroJogo(tabuleiro):
    # Para exibir cada jogada comenta a linha abaixo.
    limpaTela()
    print('-'*60)
    print('JOGO DA VELHA')
    print('-'*60)
    print(f' {tabuleiro[7]} | {tabuleiro[8]} | {tabuleiro[9]} ')
    print(f'---+---+---')
    print(f' {tabuleiro[4]} | {tabuleiro[5]} | {tabuleiro[6]} ')
    print(f'---+---+---')
    print(f' {tabuleiro[1]} | {tabuleiro[2]} | {tabuleiro[3]} ')

# Definição dos jogadores X ou O.
def definirJogadorUM():
    jogadorUm = input("Escolha entre 'X' ou 'O' para jogar (Jogador 1): ")
    if(jogadorUm == 'x' or jogadorUm == 'X'):
        jogadorUm = 'X'
        return jogadorUm
    elif(jogadorUm == 'o' or jogadorUm == 'O'):
        jogadorUm = 'O'
        return jogadorUm
    else:
        print('Entrada invalida!\nTente novamente.')
        return definirJogadorUM()

# Define o se há um vencedor ou se houve empate.
def definirVencedor(tabuleiro, jogador, typeJogador, i=9):
    if typeJogador == 'C':
        typeJogador = 'Computador'
    else:
        typeJogador = 'Jogador'
    # Verificação dos casos quando o jogodor faz a trinca horizontal
    if((tabuleiro[1] == tabuleiro[2] == tabuleiro[3]) and (tabuleiro[1] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True
    elif((tabuleiro[6] == tabuleiro[4] == tabuleiro[5]) and (tabuleiro[6] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True

    elif((tabuleiro[7] == tabuleiro[8] == tabuleiro[9]) and (tabuleiro[7] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True

    # Verificação dos casos quando o jogodor faz a trinca vertical
    elif((tabuleiro[1] == tabuleiro[4] == tabuleiro[7]) and (tabuleiro[1] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True
    elif((tabuleiro[2] == tabuleiro[5] == tabuleiro[8]) and (tabuleiro[2] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True
    elif((tabuleiro[3] == tabuleiro[6] == tabuleiro[9]) and (tabuleiro[3] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True

    # Verificação dos casos quando o jogador faz trinca nas diagonais
    elif((tabuleiro[1] == tabuleiro[5] == tabuleiro[9]) and (tabuleiro[1] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True
    elif((tabuleiro[3] == tabuleiro[5] == tabuleiro[7]) and (tabuleiro[3] == jogador)):
        print(f"O {typeJogador} '{jogador}' venceu!")
        return True
    else:
        verificaEspaçoVazio(tabuleiro)

# Verifica se há jogadas disponiveis ainda.
def verificaEspaçoVazio(tabuleiro, i=1):
    if i >= 9:
        return print("Deu Velha! Empate.")
    else:
        if tabuleiro[i] == ' ':
            return ' '
        else:
            return verificaEspaçoVazio(tabuleiro, i+1)


def jogadaComputador(tabuleiro, simboloComputador):
    """
    Recebe o tabuleiro e o simbolo (X ou O) do computador e determina onde o computador deve jogar
    O tabuleiro pode estar vazio (caso o computador seja o primeiro a jogar) ou com algumas posições preenchidas, 
    sendo a posição 0 do tabuleiro descartada.

    Parâmetros:
    tabuleiro: lista de tamanho 10 representando o tabuleiro
    simboloComputador: letra do computador

    Retorno:
    Posição (entre 1 e 9) da jogada do computador

    Estratégia:
    A estrategia desenvolvida é sempre conseguir garantir 3 cantos (1,3,7 e 9), ou seja, formando um triangulo,
    pois a taxa de sucesso envolvendo esse tipo de jogada são altas.
    """
    if simboloComputador == 'X':
        simboloJogador = 'O'
    else:
         simboloJogador = 'X'

    defesaUm = simboloJogador + simboloJogador + ' '
    defesaDois = ' ' + simboloJogador + simboloJogador 
    defesaTres = simboloJogador+ ' ' + simboloJogador 
    empateUm = ' ' + simboloJogador + ' '
    empateDois = ' ' + simboloComputador + ' ' 
    empateTres = simboloComputador+ ' ' + simboloJogador
    empateQuatro = simboloJogador+ ' ' + simboloComputador

    # Quando o computador começa primeiro. Aplicação da tatica.
    if tabuleiro[1] == tabuleiro[2] == tabuleiro[3] == tabuleiro[4] == tabuleiro[5] == tabuleiro[6] == tabuleiro[7] == tabuleiro[8] == tabuleiro[9] == ' ':
        if tabuleiro[1] == tabuleiro[3] == simboloComputador:
            return 2
        elif(tabuleiro[1] == tabuleiro[7] == simboloComputador):
            return 4
        elif(tabuleiro[1] == tabuleiro[9] == simboloComputador):
            return 5
        elif(tabuleiro[7] == tabuleiro[9] == simboloComputador):
            return 8
        elif(tabuleiro[7] == tabuleiro[3] == simboloComputador):
            return 5
        elif(tabuleiro[9] == tabuleiro[3] == simboloComputador):
            return 6
        else:
            if tabuleiro[1] == ' ':
                return 1
            elif tabuleiro[3] == ' ':
                return 3
            elif tabuleiro[7] == ' ':
                return 7
            elif tabuleiro[9] == ' ':
                return 9
    else:

        # Defesa 1 
        if (defesaUm == tabuleiro[1]+tabuleiro[2]+tabuleiro[3]): 
            return 3
        elif (defesaUm == tabuleiro[1]+tabuleiro[4]+tabuleiro[7]):
            return 7 
        elif (defesaUm == tabuleiro[1]+tabuleiro[5]+tabuleiro[9]): 
            return 9 
        elif (defesaUm == tabuleiro[2]+tabuleiro[5]+tabuleiro[8]): 
            return 8 
        elif (defesaUm == tabuleiro[3]+tabuleiro[6]+tabuleiro[9]): 
            return 9 
        elif (defesaUm == tabuleiro[3]+tabuleiro[5]+tabuleiro[7]): 
            return 7 
        elif (defesaUm == tabuleiro[6]+tabuleiro[5]+tabuleiro[4]): 
            return 4 
        elif (defesaUm == tabuleiro[9]+tabuleiro[8]+tabuleiro[7]): 
            return 7 

        # Defesa 2
        if (defesaDois == tabuleiro[1]+tabuleiro[2]+tabuleiro[3]):
            return 1 
        elif (defesaDois == tabuleiro[1]+tabuleiro[4]+tabuleiro[7]): 
            return 1 
        elif (defesaDois == tabuleiro[1]+tabuleiro[5]+tabuleiro[9]): 
            return 1 
        elif (defesaDois == tabuleiro[2]+tabuleiro[5]+tabuleiro[8]): 
            return 2 
        elif (defesaDois == tabuleiro[3]+tabuleiro[6]+tabuleiro[9]): 
            return 3 
        elif (defesaDois == tabuleiro[3]+tabuleiro[5]+tabuleiro[7]): 
            return 3 
        elif (defesaDois == tabuleiro[6]+tabuleiro[5]+tabuleiro[4]): 
            return 6 
        elif (defesaDois == tabuleiro[9]+tabuleiro[8]+tabuleiro[7]): 
            return 9 
        
        # Defesa 3
        if (defesaTres == tabuleiro[1]+tabuleiro[2]+tabuleiro[3]): 
            return 2 
        elif (defesaTres == tabuleiro[1]+tabuleiro[4]+tabuleiro[7]): 
            return 4 
        elif (defesaTres == tabuleiro[1]+tabuleiro[5]+tabuleiro[9]): 
            return 5 
        elif (defesaTres == tabuleiro[2]+tabuleiro[5]+tabuleiro[8]): 
            return 5 
        elif (defesaTres == tabuleiro[3]+tabuleiro[6]+tabuleiro[9]): 
            return 6 
        elif (defesaTres == tabuleiro[3]+tabuleiro[5]+tabuleiro[7]): 
            return 5 
        elif (defesaTres == tabuleiro[6]+tabuleiro[5]+tabuleiro[4]): 
            return 5 
        elif (defesaTres == tabuleiro[9]+tabuleiro[8]+tabuleiro[7]): 
            return 8 

        # Contra-ataque
        if (tabuleiro[1] == tabuleiro[3] == simboloComputador) and tabuleiro[2] == ' ':
            return 2
        elif(tabuleiro[1] == tabuleiro[7] == simboloComputador) and tabuleiro[4] == ' ':
            return 4
        elif(tabuleiro[1] == tabuleiro[9] == simboloComputador) and tabuleiro[5] == ' ':
            return 5
        elif(tabuleiro[7] == tabuleiro[9] == simboloComputador) and tabuleiro[8] == ' ':
            return 8
        elif(tabuleiro[7] == tabuleiro[3] == simboloComputador) and tabuleiro[5] == ' ':
            return 5
        elif(tabuleiro[9] == tabuleiro[3] == simboloComputador) and tabuleiro[6] == ' ':
            return 6
        else:
            if tabuleiro[1] == ' ':
                return 1
            elif tabuleiro[3] == ' ':
                return 3
            elif tabuleiro[7] == ' ':
                return 7
            elif tabuleiro[9] == ' ':
                return 9
        
        # Empate
        if (tabuleiro[2]+ tabuleiro[5]+tabuleiro[8] == empateUm) or (tabuleiro[2]+ tabuleiro[5]+tabuleiro[8] == empateDois):
            return 2 if (random.choice([2,8]) == 2) else 8
        elif (tabuleiro[6]+ tabuleiro[5]+tabuleiro[4] == empateUm) or (tabuleiro[6]+ tabuleiro[5]+tabuleiro[4] == empateDois):
            return 4 if (random.choice([4,6]) == 4) else 6
        elif(tabuleiro[5] == ' '):
            return 5        

# Sorteia a ordem dos jogadores
def sorteioRodada():
    # Escolhendo a ordem dos jogadores
    ordem = random.choice([1, 2])
    jogadorUm = definirJogadorUM()
    if(jogadorUm == 'X'):
        jogadorDois = 'O'
    elif(jogadorUm == 'O'):
        jogadorDois = 'X'
    return jogadorUm, jogadorDois, ordem

# Valida a posição de entrada
def verificaResultado(jogada, resultado):
    if resultado[jogada] != 'X' and resultado[jogada] != 'O':
        return True
    elif resultado[jogada] == 'X' or resultado[jogada] == 'O':
        return False

# Jogada de cada jogador.
def jogadaDoJogador(resultado, jogador, typeJogador):
    if typeJogador == 'J':
        jogada = int(input(f"Insira em qual posição você, jogador '{jogador}' quer jogar (1-9):"))
        if verificaResultado(jogada, resultado):
            resultado[jogada] = jogador
            return resultado
        else:
            limpaTela()
            print('Jogada não permitida!\nInsira novamente uma posição valida.')
            tabuleiroJogo(resultado)
            resultado = jogadaDoJogador(resultado, jogador, typeJogador)
            return resultado
    if typeJogador == 'C':
        jogada = jogadaComputador(resultado, jogador)
        if verificaResultado(jogada, resultado):
            resultado[jogada] = jogador
            return resultado
        else:
            limpaTela()
            print('Jogada não permitida!\nInsira novamente uma posição valida.')
            tabuleiroJogo(resultado)
            resultado = jogadaDoJogador(resultado, jogador, typeJogador)
            return resultado

# Estabelece o fluxo do jogo
def roundsJogados(resultado, jogadorUm=0, jogadorDois=0, ordem=0, rounds=1):
    if rounds >= 10:
        return
    else:
        if ordem == 1:
            print(f'Rodada: {rounds}')
            if (rounds % 2 == 1):
                resultado = jogadaDoJogador(resultado, jogadorUm, 'J')
                tabuleiroJogo(resultado)
                if not definirVencedor(resultado, jogadorUm, 'J'):
                    return roundsJogados(resultado, jogadorUm, jogadorDois, ordem, rounds+1)
            elif (rounds % 2 == 0):
                resultado = jogadaDoJogador(resultado, jogadorDois, 'C')
                tabuleiroJogo(resultado)
                if not definirVencedor(resultado, jogadorDois, 'C'):
                    return roundsJogados(resultado, jogadorUm, jogadorDois, ordem, rounds+1)
        elif ordem == 2:
            print(f'Rodada: {rounds}')
            if (rounds % 2 == 1):
                resultado = jogadaDoJogador(resultado, jogadorDois, 'C')
                tabuleiroJogo(resultado)
                if not definirVencedor(resultado, jogadorDois, 'C'):
                    return roundsJogados(resultado, jogadorUm, jogadorDois, ordem, rounds+1)
            elif (rounds % 2 == 0):
                resultado = jogadaDoJogador(resultado, jogadorUm, 'J')
                tabuleiroJogo(resultado)
                if not definirVencedor(resultado, jogadorUm, 'J'):
                    return roundsJogados(resultado, jogadorUm, jogadorDois, ordem, rounds+1)


def main():
    limpaTela()
    print(getMatricula())
    print(getNome())

    resultado = inicializaTabuleiro()
    jogadorUm, jogadorDois, ordem = sorteioRodada()
    tabuleiroJogo(resultado)
    if ordem == 1:
        print(f'O jogador começa jogando!')
        input('Pressione Enter para continuar')
        roundsJogados(resultado, jogadorUm, jogadorDois, ordem)
    if ordem == 2:
        print(f'O Computador começa jogando!')
        input('Pressione Enter para continuar')
        roundsJogados(resultado, jogadorUm, jogadorDois, ordem)

## NÃO ALTERE O CÓDIGO ABAIXO ##
if __name__ == "__main__":
    main()

