# Entradas
peso = float(input())
idade = int(input())
if(idade == 16 or idade == 17):
    documentoAutorizacao = input()
boaSaude = input()
drogado = input()
primeiraDoacao = input()
if(primeiraDoacao == 'n' or primeiraDoacao == 'N'):
    ultimaDoacao = int(input())
    maximoAnualDoacao = int(input())
sexo = input()
if(sexo == 'F' or sexo == 'f'):
    gravidez = input()
    amamentacao = input()
    if(amamentacao == 's' or amamentacao == 'S'):
        idadeBebeAmamentacao = int(input())

impedimentos = 0
# Saidas
print(f'Peso: {peso}')
print(f'Idade: {idade}')
if(idade == 16 or idade == 17):
    print(f'Documento de autorizacao: {documentoAutorizacao}')
print(f'Boa saude: {boaSaude}')
print(f'Uso drogas injetaveis: {drogado}')
print(f'Primeira doacao: {primeiraDoacao}')
if(primeiraDoacao == 'n' or primeiraDoacao == 'N'):
    print(f'Meses desde ultima doacao: {ultimaDoacao}')
    print(f'Doacoes nos ultimos 12 meses: {maximoAnualDoacao}')
print(f'Sexo biologico: {sexo}')
if(sexo == 'F' or sexo == 'f'):
    print(f'Gravidez: {gravidez}')
    print(f'Amamentando: {amamentacao}')
    if(amamentacao == 's' or amamentacao == 'S'):
        print(f'Meses bebe: {idadeBebeAmamentacao}')

# Impedimentos
if(peso < 50):
    print('Impedimento: abaixo do peso minimo.')
    impedimentos += 1

if(idade >= 16 and idade <= 69):
    if(idade < 18):
        if(documentoAutorizacao == 'N' or documentoAutorizacao == 'n'):
            print('Impedimento: menor de 18 anos, sem consentimento dos responsaveis.')
            impedimentos += 1
    elif(idade > 60):
        if(primeiraDoacao == 'S' or primeiraDoacao == 's'):
            print('Impedimento: maior de 60 anos, primeira doacao.')
            impedimentos += 1

elif(idade < 16):
    print('Impedimento: menor de 16 anos.')
    impedimentos += 1
else:
    print('Impedimento: maior de 69 anos.')
    impedimentos += 1

# if(idade < 16):
#     print('Impedimento: menor de 16 anos.')
#     impedimentos += 1

# if(idade == 16 or idade == 17):
#     if(documentoAutorizacao == 'N' or documentoAutorizacao == 'n'):
#         print('Impedimento: menor de 18 anos, sem consentimento dos responsaveis.')
#         impedimentos += 1

# if(idade > 60):
#     if(primeiraDoacao == 'S' or primeiraDoacao == 's'):
#         print('Impedimento: maior de 60 anos, primeira doacao.')
#         impedimentos += 1

# if(idade > 69):
#     print('Impedimento: maior de 69 anos.')
#     impedimentos += 1

if(boaSaude == 'N' or boaSaude == 'n'):
    print('Impedimento: nao esta em boa saude.')
    impedimentos += 1

if(drogado == 'S' or drogado == 's'):
    print('Impedimento: uso de drogas injetaveis.')
    impedimentos += 1

if(sexo == 'M' or sexo == 'm'):
    if(primeiraDoacao == 'N' or primeiraDoacao == 'n'):
        if(ultimaDoacao < 2):
            print('Impedimento: intervalo minimo entre as doacoes nao foi respeitado.')
            impedimentos += 1

        if(maximoAnualDoacao >= 4):
            print('Impedimento: numero maximo de doacoes anuais foi atingido.')
            impedimentos += 1

elif(sexo == 'F' or sexo == 'f'):
    if(primeiraDoacao == 'N' or primeiraDoacao == 'n'):
        if(ultimaDoacao < 3):
            print('Impedimento: intervalo minimo entre as doacoes nao foi respeitado.')
            impedimentos += 1

        if(maximoAnualDoacao >= 3):
            print('Impedimento: numero maximo de doacoes anuais foi atingido.')
            impedimentos += 1

    if(gravidez == 's' or gravidez == 'S'):
        print('Impedimento: gravidez.')
        impedimentos += 1

    if(amamentacao == 's' or amamentacao == 'S'):
        if(idadeBebeAmamentacao < 12):
            print('Impedimento: amamentacao.')
            impedimentos += 1

if(impedimentos == 0):
    print('Procure um hemocentro.')
