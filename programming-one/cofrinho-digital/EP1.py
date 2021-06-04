from os import system, name


def limpaTela():
    if name == 'nt':
        system('cls')
    else:
        system('clear')


"""
#Função Menu - apresenta ao usuário a interface principal do programa onde poderá fazer as suas escolhas quanto
a funcionalidade para querer realizar.
Entrada: Quantidade de notas disponiveis e saldo
Retorno: None
"""


def menu(saldoPessoal=188, qtdn1=1, qtdn2=1,  qtdn5=1, qtdn10=1, qtdn20=1, qtdn50=1, qtdn100=1):
    limpaTela()
    print('\033[1;92m-'*70)
    print('*'*19, 'Bem vindo ao Cofrinho Digital', '*'*20, '\n')
    print('Relatorio Atual')
    print(f'Saldo: R${saldoPessoal:.2f}')
    print(' '*20, '\033[1;94m1 - Depositar')
    print(' '*20, '\033[1;94m2 - Sacar')
    print(' '*20, '\033[1;94m3 - Saldo')
    print(' '*20, '\033[1;94m4 - Relatorio')
    print(' '*20, '\033[1;91m5 - Finalizar')
    print('\n', '\033[1;92m-'*70)
    opcao = int(input('Escolha uma opção: '))
    if(opcao == 1):
        limpaTela()
        saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100 = depositar(
            saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100)
        menu(saldoPessoal, qtdn1, qtdn2,  qtdn5,
             qtdn10, qtdn20, qtdn50, qtdn100)
    elif(opcao == 2):
        limpaTela()
        saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100 = saques(
            saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100)
        menu(saldoPessoal, qtdn1, qtdn2,  qtdn5,
             qtdn10, qtdn20, qtdn50, qtdn100)
    elif(opcao == 3):
        limpaTela()
        saldo(saldoPessoal)
        seguraTela = input()
        menu(saldoPessoal, qtdn1, qtdn2,  qtdn5,
             qtdn10, qtdn20, qtdn50, qtdn100)
    elif(opcao == 4):
        limpaTela()
        relatorio(saldoPessoal, qtdn1, qtdn2,  qtdn5,
                  qtdn10, qtdn20, qtdn50, qtdn100)
        menu(saldoPessoal, qtdn1, qtdn2,  qtdn5,
             qtdn10, qtdn20, qtdn50, qtdn100)
    elif(opcao == 5):
        limpaTela()
        if saldoPessoal != '0' and saldoPessoal != 0:
            print('Tera que retirar todo o valor')
            print(saldoPessoal)
            saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100 = saques(
                saldoPessoal, qtdn1, qtdn2,  qtdn5, qtdn10, qtdn20, qtdn50, qtdn100)
            menu(saldoPessoal, qtdn1, qtdn2,  qtdn5,
                 qtdn10, qtdn20, qtdn50, qtdn100)
        else:
            exit()
    else:
        mensagemErros('menu')


"""
#Função mensagemErros- função gerencia possiveis erros apresentados pelo programa.
Entrada: string contendo o nome do local aonde foi chamada.
Retorno: retorna os alertas em destaque na tela para o usuário.
"""


def mensagemErros(erro, saldo=0, n1=0, n2=0, n5=0, n10=0, n20=0, n50=0, n100=0):
    if(erro == 'menu'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Opcao Incorreta! Tente novamente.')
        print(' '*19, 'Pressione E para voltar')
        print('-'*70)
        errorMenu = input()
        if(errorMenu == 'E') or (errorMenu == 'e'):
            menu()
        else:
            mensagemErros('menu')
    elif(erro == 'saldo'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Opcao Incorreta! Tente novamente.')
        print('-'*70)
        errorMenu = input()
        if(errorMenu == 'E') or (errorMenu == 'e'):
            menu()
    elif(erro == 'deposito'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Nota não reconhecida!')
        print(' '*19, 'Pressione E para voltar ao menu principal')
        print(' '*19, 'ou pressione Enter para continuar.')
        print('-'*70)
        errorMenu = input()
        if(errorMenu == 'E') or (errorMenu == 'e'):
            menu(saldo, n1, n2, n5, n10, n20, n50, n100)
    elif(erro == 'saque'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Sem Saldo!')
        print('-'*70)
    elif(erro == 'saque2'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Sem notas disponiveis!')
        print('-'*70)
        errorMenu = input()
        if(errorMenu == 'E') or (errorMenu == 'e'):
            menu(saldo, n1, n2, n5, n10, n20, n50, n100)
    elif(erro == 'relatorio'):
        print('\n', '\033[1;31m')
        print('-'*70)
        print(' '*19, 'Opcao Incorreta! Tente novamente.')
        print('-'*70)
        errorMenu = input()
        if(errorMenu == 'E') or (errorMenu == 'e'):
            menu()


"""
#Função saldo - função apresenta o saldo disponivel para o usuario
Entrada: saldo do usuário 
Retorno: None
"""


def saldo(saldo):
    limpaTela()
    print('\033[1;92m-'*70)
    print('*'*19, 'Bem vindo ao Cofrinho Digital', '*'*20, '\n')
    print('-'*31, 'Saldo', '-'*32)
    print(f'Saldo atual:', ' '*45, f'R${saldo}')
    print(' '*15, 'Pressione qualquer tecla para continuar!')
    print('\033[1;92m-'*70)


"""
#Função relatorio - função apresenta relatorio da quantidade de notas e o saldo disponivel no cofre
Entrada: valores inteiros - saldo e quantidades de notas de cada valor
Retorno: retorna o valor do saldo e a quantidade de nota de cada valor.
"""


def relatorio(saldo, n1, n2, n5, n10, n20, n50, n100):
    limpaTela()
    print('\033[1;92m-'*70)
    print('*'*19, 'Bem vindo ao Cofrinho Digital', '*'*20, '\n')
    print('-'*30, 'relatorio', '-'*31)
    print(f'Notas de R$100,00: {n100}')
    print(f'Notas de R$50,00:  {n50}')
    print(f'Notas de R$20,00:  {n20}')
    print(f'Notas de R$10,00:  {n10}')
    print(f'Notas de R$5,00:   {n5}')
    print(f'Notas de R$2,00:   {n2}')
    print(f'Notas de R$1,00:   {n1}')
    print(f'\n')
    print(f'Saldo Corrente: R${saldo:.2f}')
    print('\033[1;92m-'*70)
    print('Pressione E para voltar ao menu principal')
    saldoMenu = input()
    if(saldoMenu == 'E' or saldoMenu == 'e'):
        return saldo, n1, n2, n5, n10, n20, n50, n100
    else:
        mensagemErros('relatorio')
        seguraTela = input()
        return relatorio(saldo, n1, n2, n5, n10, n20, n50, n100)


"""
#Função saques - função realiza saque com o valor determinado pelo usuario.
Entrada: valor do saque.
Retona: os valores do saldo e das quantidades de notas atualizadas
"""


def saques(saldo, n1, n2, n5, n10, n20, n50, n100):
    print('\033[1;92m-'*70)
    print(f'Saldo:', ' '*20, f'R${saldo}')
    print('Pressione E para voltar ao menu principal.')
    print('')
    valorSaque = input('Insira o valor a ser sacado: ')
    if(valorSaque == 'E' or valorSaque == 'e'):
        menu(saldo, n1, n2, n5, n10, n20, n50, n100)
    if int(valorSaque) > saldo:
        mensagemErros('saque')
        sacarTudo = input("Deseja sacar o saldo restante? (s/n)")
        if(sacarTudo == 's' or sacarTudo == 'S'):
            saque2, n1, n2, n5, n10, n20, n50, n100 = verifica(
                saldo, saldo, n1, n2, n5, n10, n20, n50, n100)
            menu(0, n1, n2, n5, n10, n20, n50, n100)
        if(sacarTudo == 'n' or sacarTudo == 'N'):
            menu(saldo, n1, n2, n5, n10, n20, n50, n100)
    else:
        valorSaque = int(valorSaque)
        saque2, n1, n2, n5, n10, n20, n50, n100 = verifica(
            valorSaque, saldo, n1, n2, n5, n10, n20, n50, n100)
        if(saque2 == 0):
            return saques((saldo - valorSaque), n1, n2, n5, n10, n20, n50, n100)
        else:
            return saques(saldo, n1, n2, n5, n10, n20, n50, n100)


"""
#Função verifica - verifica e atualiza a quantidade de notas que precisam ser sacadas.
Entrada: valor do saque e a quantidade de notas disponivel
Retono: retorna as quantidades de notas atualizadas
"""


def verifica(saque, saldo, n1, n2, n5, n10, n20, n50, n100):
    valorSaque = saque
    n100Sacadas = 0
    n50Sacadas = 0
    n20Sacadas = 0
    n10Sacadas = 0
    n5Sacadas = 0
    n2Sacadas = 0
    n1Sacadas = 0
    if(valorSaque != 0):
        if n100*100 > 0:
            if(valorSaque//100 <= n100 and n100*100 <= valorSaque):
                n100Sacadas = valorSaque//100
                valorSaque -= 100*(n100Sacadas)
            if(n100*100 <= valorSaque):
                n100Sacadas = n100
                valorSaque -= 100*(n100Sacadas)

        if(n50*50 > 0):
            if(valorSaque//50 <= n50 and n50*50 <= valorSaque):
                n50Sacadas = valorSaque//50
                valorSaque -= 50*(n50Sacadas)
            if(n50*50 <= valorSaque):
                n50Sacadas = n50
                valorSaque -= 50*(n50Sacadas)

        if(n20*20 > 0):
            if(valorSaque//20 <= n20 and n20*20 <= valorSaque):
                n20Sacadas = valorSaque//20
                valorSaque -= 20*(n20Sacadas)
            if(n20*20 <= valorSaque):
                n20Sacadas = n20
                valorSaque -= 20*(n20Sacadas)

        if(n10*10 > 0):
            if(valorSaque//10 <= n10 and n10*10 <= valorSaque):
                n10Sacadas = valorSaque//10
                valorSaque -= 10*(n10Sacadas)
            if(n10*10 <= valorSaque):
                n10Sacadas = n10
                valorSaque -= 10*(n10Sacadas)

        if(n5*5 > 0):
            if(valorSaque//5 <= n5 and n5*5 <= valorSaque):
                n5Sacadas = valorSaque//5
                valorSaque -= 5*(n5Sacadas)
            if(n5*5 <= valorSaque):
                n5Sacadas = n5
                valorSaque -= 5*(n5Sacadas)

        if(n2*2 > 0):
            if(valorSaque//2 <= n2 and n2*2 <= valorSaque):
                n2Sacadas = valorSaque//2
                valorSaque -= 2*(n2Sacadas)
            if(n2*2 <= valorSaque):
                n2Sacadas = n2
                valorSaque -= 2*(n2Sacadas)

        if(n1*1 > 0):
            if(valorSaque//1 <= n1 and n1*1 <= valorSaque):
                n1Sacadas = valorSaque//1
                valorSaque -= 1*(n1Sacadas)
            if(n1*1 <= valorSaque):
                n1Sacadas = n1
                valorSaque -= 1*(n1Sacadas)

        """
        Verifica a quantidade de notas que foram sacadas e imprime o valor das notas.

        """
        if(valorSaque == 0):
            if(n100Sacadas > 0):
                imprimeNota(n100Sacadas, 100)
                n100 -= n100Sacadas
            if(n50Sacadas > 0):
                imprimeNota(n50Sacadas, 50)
                n50 -= n50Sacadas
            if(n20Sacadas > 0):
                imprimeNota(n20Sacadas, 20)
                n20 -= n20Sacadas
            if(n10Sacadas > 0):
                imprimeNota(n10Sacadas, 10)
                n10 -= n10Sacadas
            if(n5Sacadas > 0):
                imprimeNota(n5Sacadas, 5)
                n5 -= n5Sacadas
            if(n2Sacadas > 0):
                imprimeNota(n2Sacadas, 2)
                n2 -= n2Sacadas
            if(n1Sacadas > 0):
                imprimeNota(n1Sacadas, 1)
                n1 -= n1Sacadas
            return valorSaque, n1, n2, n5, n10, n20, n50, n100
        else:
            mensagemErros('saque2', saldo, n1, n2, n5, n10, n20, n50, n100)
    else:
        return valorSaque, n1, n2, n5, n10, n20, n50, n100

    print('\033[1;92m-'*70)


"""
#Função imprimeNota - função exibe ao usuario as notas que foram sacadas.
Entrada: quantidade de notas sacadas e o valor das notas sacadas.
Retona: exibe os valores sacados para usuario.
"""


def imprimeNota(nNota, nota):
    if(nNota > 0):
        print(f'Valor sacado: R${nota}')
        return imprimeNota(nNota-1, nota)


"""
#Função depositar - função realiza depositos de valores concedidos pelo usuario.
Entrada: valor do deposito.
Retona: os valores do deposito e das quantidades de notas atualizadas
"""


def depositar(notasDepositadas, n1, n2, n5, n10, n20, n50, n100):
    limpaTela()
    print('\033[1;92m-'*70)
    print('*'*19, 'Bem vindo ao Cofrinho Digital', '*'*20, '\n')
    print('-'*30, 'Deposito', '-'*30)
    print(f'Valor depositado até momento:',
          ' '*20, f'R${notasDepositadas:.2f}')
    print('Pressione E para voltar ao menu principal.')
    print('')
    nota = input('Digite o valor da nota depositada: ')
    if(nota == 'E' or nota == 'e'):
        return notasDepositadas, n1, n2, n5, n10, n20, n50, n100
    elif nota != '100' and nota != '50' and nota != '20' and nota != '10' and nota != '5' and nota != '2' and nota != '1':
        mensagemErros('deposito', notasDepositadas,
                      n1, n2, n5, n10, n20, n50, n100)
        return depositar(notasDepositadas, n1, n2, n5, n10, n20, n50, n100)
    else:
        if nota == '1':
            n1 += 1
        elif nota == '2':
            n2 += 1
        elif nota == '5':
            n5 += 1
        elif nota == '10':
            n10 += 1
        elif nota == '20':
            n20 += 1
        elif nota == '50':
            n50 += 1
        elif nota == '100':
            n100 += 1
        return depositar(notasDepositadas + int(nota), n1, n2, n5, n10, n20, n50, n100)
    print('\033[1;92m-'*70)


menu()
