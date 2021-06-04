def imprimirPassaport(tempoCorredor, tempoBase,  validacao, sexo):
    tempoHoras1, tempoMinutos1 = conversorDeMinutosToHoras(tempoCorredor)
    tempoHoras2, tempoMinutos2 = conversorDeMinutosToHoras(tempoBase)
    tempoDiferencaApresentada = subtrairTempo(tempoCorredor, tempoBase)
    tempoAjustado = 0

    if(tempoDiferencaApresentada < 0):
        tempoAjustado = tempoDiferencaApresentada * (-1)
    else:
        tempoAjustado = tempoDiferencaApresentada

    tempoHorasD3, tempoMinutosD3 = conversorDeMinutosToHoras(tempoAjustado)

    if(sexo == 'f' or sexo == 'F'):
        print('Tempo da corredora: {:0>2}h {:0>2}min'.format(
            tempoHoras1, tempoMinutos1))
        print('Tempo necessario: {:0>2}h {:0>2}min'.format(
            tempoHoras2, tempoMinutos2))
        print(f'Conseguiu indice? {validacao}')

        if(tempoDiferencaApresentada > 0):
            print('A corredora correu {:0>2}h {:0>2}min acima do indice'.format(
                tempoHorasD3, tempoMinutosD3))

        elif(tempoDiferencaApresentada <= 0):
            print('A corredora correu {:0>2}h {:0>2}min abaixo do indice'.format(
                tempoHorasD3, tempoMinutosD3))

    elif(sexo == 'm' or sexo == 'M'):
        print('Tempo do corredor: {:0>2}h {:0>2}min'.format(
            tempoHoras1, tempoMinutos1))
        print('Tempo necessario: {:0>2}h {:0>2}min'.format(
            tempoHoras2, tempoMinutos2))
        print(f'Conseguiu indice? {validacao}')

        if(tempoDiferencaApresentada > 0):
            print('O corredor correu {:0>2}h {:0>2}min acima do indice'.format(
                tempoHorasD3, tempoMinutosD3))

        elif(tempoDiferencaApresentada <= 0):
            print('O corredor correu {:0>2}h {:0>2}min abaixo do indice'.format(
                tempoHorasD3, tempoMinutosD3))


def subtrairTempo(tempoCorredor, tempoBase):
    return tempoCorredor - tempoBase


def conversorDeMinutosToHoras(tempo):
    tempoHoras = tempo // 60
    tempoMinutos = tempo % 60
    return tempoHoras, tempoMinutos


def verificaoIdadeTempo(idade, sexo):
    if(idade >= 18 and idade <= 34):
        if(sexo == 'm' or sexo == 'M'):
            return 180
        elif(sexo == 'f' or sexo == 'F'):
            return 210
        else:
            quit()
    if(idade >= 35 and idade <= 39):
        if(sexo == 'm' or sexo == 'M'):
            return 185
        elif(sexo == 'f' or sexo == 'F'):
            return 215
        else:
            quit()
    if(idade >= 40 and idade <= 44):
        if(sexo == 'm' or sexo == 'M'):
            return 190
        elif(sexo == 'f' or sexo == 'F'):
            return 220
        else:
            quit()
    if(idade >= 45 and idade <= 49):
        if(sexo == 'm' or sexo == 'M'):
            return 200
        elif(sexo == 'f' or sexo == 'F'):
            return 230
        else:
            quit()
    if(idade >= 50 and idade <= 54):
        if(sexo == 'm' or sexo == 'M'):
            return 205
        elif(sexo == 'f' or sexo == 'F'):
            return 235
        else:
            quit()
    if(idade >= 55 and idade <= 59):
        if(sexo == 'm' or sexo == 'M'):
            return 215
        elif(sexo == 'f' or sexo == 'F'):
            return 245
        else:
            quit()
    if(idade >= 60 and idade <= 64):
        if(sexo == 'm' or sexo == 'M'):
            return 230
        elif(sexo == 'f' or sexo == 'F'):
            return 260
        else:
            quit()
    if(idade >= 65 and idade <= 69):
        if(sexo == 'm' or sexo == 'M'):
            return 245
        elif(sexo == 'f' or sexo == 'F'):
            return 275
        else:
            quit()
    if(idade >= 70 and idade <= 74):
        if(sexo == 'm' or sexo == 'M'):
            return 260
        elif(sexo == 'f' or sexo == 'F'):
            return 290
        else:
            quit()
    if(idade >= 75 and idade <= 79):
        if(sexo == 'm' or sexo == 'M'):
            return 275
        elif(sexo == 'f' or sexo == 'F'):
            return 305
        else:
            quit()
    if(idade >= 80):
        if(sexo == 'm' or sexo == 'M'):
            return 290
        elif(sexo == 'f' or sexo == 'F'):
            return 320
        else:
            quit()


def verificaIndice(tempoCorredor, tempoBase):
    if(tempoCorredor <= tempoBase):
        return 'SIM'
    else:
        return 'NAO'


def inicializa():
    tempoMinutos = int(input())
    if(tempoMinutos < 0):
        print('Valor invalido')
        quit()
    idadeCorredor = int(input())
    sexoCorredor = input()
    return tempoMinutos, idadeCorredor, sexoCorredor


def main():
    tempoMinutos, idadeCorredor, sexoCorredor = inicializa()

    tempoVerificado = verificaoIdadeTempo(idadeCorredor, sexoCorredor)
    indiceVerificado = verificaIndice(tempoMinutos, tempoVerificado)
    imprimirPassaport(tempoMinutos, tempoVerificado,
                      indiceVerificado, sexoCorredor)


main()
