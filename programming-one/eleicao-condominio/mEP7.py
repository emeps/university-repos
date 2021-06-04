def quantidadeCandidatos(candidatos = []):
    # Quantidade de Candidatos
    qtdCandidatos = int(input())
    candidatos += [qtdCandidatos]
    return qtdCandidatos, candidatos

def cadastroCandidato(qtdCandidatos, candidatos):
    if qtdCandidatos < 1 :
        return candidatos
    else:
        #Nomes do Candidatos
        nomeCandidato = input()
        candidatos += [nomeCandidato]
        return cadastroCandidato(qtdCandidatos - 1, candidatos)   

def votacaoEleicao(numeroEleitores,candidatos, resultadoVotacao = [], votosNulos = 0, votosBrancos = 0  ):
    if numeroEleitores < 1:
        return (resultadoVotacao), votosNulos, votosBrancos
    else:
        votaca = int(input())
        resultadoVotacao += [votaca]
        if(votaca > candidatos[0]):
            votosNulos += 1
        if( votaca == 0):
            votosBrancos += 1
        resultadoVotacao, votosNulos, votosBrancos = votacaoEleicao(numeroEleitores-1, candidatos, resultadoVotacao, votosNulos, votosBrancos)
        return resultadoVotacao, votosNulos, votosBrancos

def checagem(resultadoVotacao, j):
    if len(resultadoVotacao) == 0:
         return 0
    count = 1 if resultadoVotacao[0] == j else 0
    return count + checagem(resultadoVotacao[1:], j)

def apuracaoVotoca(resultado, i = 0, j = 1, contagem = []):
    if i > len(resultado):
        return contagem
    else:
        contagem += [checagem(resultado, j)]
        contagem = apuracaoVotoca(resultado, i + 1, j + 1) 
        return contagem

def resultadoFinal(candidatos, apuracao, i = 1):
    if i <= candidatos[0]:
        print(f'{candidatos[i]}: {apuracao[i-1]}')
        resultadoFinal(candidatos, apuracao, i + 1)


def definirVencedor(apuracao,qtdcandidatos,starter = 0, i = 0, posicao =0):
    if i > qtdcandidatos:
        return posicao
    else:   
        if starter < apuracao[i]:
            starter = apuracao[i]
            posicao = i
            posicao = definirVencedor(apuracao,qtdcandidatos, starter, i + 1, posicao)
            return posicao
            
        else:
            posicao = definirVencedor(apuracao, qtdcandidatos, starter, i+1, posicao)
            return posicao
    

def main():
    qtdCandidatos, candidatos = quantidadeCandidatos()
    candidatos = cadastroCandidato(qtdCandidatos, candidatos)
    numeroEleitores = int(input())
    candidatos += [numeroEleitores]
    resultadoVotacao, votosNulos, votosBrancos = votacaoEleicao(numeroEleitores, candidatos)
    apuracao = apuracaoVotoca(resultadoVotacao)
    resultadoFinal(candidatos, apuracao)
    print(f'Brancos: {votosBrancos}')
    print(f'Nulos: {votosNulos}')
    x = apuracao[0]
    posicao = definirVencedor(apuracao,qtdCandidatos, x)
    print(f'Vencedor(a): {candidatos[posicao+1]}')
 
main()