#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "Util.h"
#include "Avl.h"
#include "Bintree.h"
#include "Fila.h"

/* Número máximo de caracteres em uma linha */
#define TAM_MAX_LINHA 1024
/* Número máximo de caracteres em uma palavra */
#define TAM_MAX_PALAVRA 128

//const char *delimitadores = " \t\v\f\n!\"#$%&'()*+,./:;<=>?@[\\]^_`{|}~";
const char *whiteSpace = " \t\v\f\n";

/* Função auxiliar para contabiliar o tempo */
double MyClock()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

/* Função auxiliar para remover as pontuação das palavras */
void removePontuacao(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (!ispunct(str[i]) || str[i] == '-' || str[i] == '/')
            str[count++] = str[i];
    str[count] = '\0';
}

/* Converte os caracteres de uma string para minusculo */
void converteMinusculo(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[])
{
    double inicioProg = MyClock();
    char linha[TAM_MAX_LINHA];
    char nomeArqDicionario[TAM_MAX_PALAVRA];
    char nomeArqTexto[TAM_MAX_PALAVRA];
    char palavra[TAM_MAX_PALAVRA];
    char cpypalavra[TAM_MAX_PALAVRA];
    char cpypalavra2[TAM_MAX_PALAVRA];
    bool arvoreAVL = false;

    /* Lê os valores passados como argumento para o programa */
    for (int i = 1; i < argc; ++i)
    {
        if (!strncmp(argv[i], "-avl", 4))
        {
            arvoreAVL = true;
        }
        else if (!strncmp(argv[i], "-d", 2))
        {
            strcpy(nomeArqDicionario, argv[i + 1]);
            i++;
        }
        else if (!strncmp(argv[i], "-t", 2))
        {
            strcpy(nomeArqTexto, argv[i + 1]);
            i++;
        }
        else
        {
            fprintf(stderr, "Uso: ./%s -d <ArquivoDicionario> -t <Texto> [-avl]\n", argv[0]);
            exit(1);
        }
    }

    FILE *fDicionario, *fTexto;

    No *raiz = NULL;
    NoAVL *raizAVL = NULL;
    Fila *filaPalavras = criarFila();

    /* Carrega o dicionário */
    fDicionario = fopen(nomeArqDicionario, "r");
    if (fDicionario == NULL)
    {
        printf("Nao foi possivel abrir o arquivo '%s'\n", nomeArqDicionario);
        exit(EXIT_FAILURE);
    }

    /* Cria a árvore binária de busca com as palávras do dicionário */
    while (fscanf(fDicionario, "%s", palavra) == 1)
    {
        if (arvoreAVL)
        {
            raizAVL = inserirNoAVL(raizAVL, criarNoAVL(palavra));
        }
        else
        {
            raiz = inserirNo(raiz, criarNo(palavra));
        }
    }

    /* Carrega o texto */
    fTexto = fopen(nomeArqTexto, "r");
    if (fTexto == NULL)
    {
        printf("Nao foi possivel abrir o arquivo '%s'\n", nomeArqTexto);
        exit(EXIT_FAILURE);
    }
    /* Cria uma fila de palavras incorretas */
    while (fgets(linha, TAM_MAX_LINHA, fTexto) != NULL)
    {

        /* Separa as palavras da linha */
        char *word = strtok(linha, whiteSpace);
        // Percorre a linha extraindo as palavras
        while (word != NULL)
        {
            if (isdigit(word[0]) || word[0] == '-')
            {
                printf("%s ", word);
                word = strtok(NULL, whiteSpace);
                continue;
            }
            strcpy(cpypalavra, word);
            removePontuacao(cpypalavra);
            strcpy(cpypalavra2, cpypalavra);
            converteMinusculo(cpypalavra2);

            if ((raizAVL && (buscarNoAVL(raizAVL, cpypalavra) || buscarNoAVL(raizAVL, cpypalavra2))) || (raiz && (buscarNo(raiz, cpypalavra) || buscarNo(raiz, cpypalavra2))))
            {
                printf("%s ", word);
            }
            else
            {
                printf("\033[1;31m%s\033[00m ", word);
                if (buscarNoFila(filaPalavras, word) == NULL)
                    enqueue(filaPalavras, criarNoFila(word));
            }
            //Pega a próxima palavra
            word = strtok(NULL, whiteSpace);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Palavra(s) incorreta(s) e sugestão(ões)\n");
    printf("----------------------------------------\n");
    NoFila *palavraIncorreta = filaPalavras->inicio;
    while (palavraIncorreta != NULL)
    {
        if (arvoreAVL == true)
        {
            printf("%s: ", palavraIncorreta->palavra);
            comparaAVL(raizAVL, palavraIncorreta->palavra);
            printf("\n");
            palavraIncorreta = palavraIncorreta->proximo;
        }
        else
        {
            printf("%s: ", palavraIncorreta->palavra);
            compara(raiz, palavraIncorreta->palavra);
            printf("\n");
            palavraIncorreta = palavraIncorreta->proximo;
        }
    }
    printf("----------------------------------------\n");
    printf("\033[1;32mTempo Total: %.10lf seg\n\n\033[00m", (MyClock() - inicioProg) / CLOCKS_PER_SEC);

    liberarFila(filaPalavras);
    raizAVL != NULL ? liberarNoAVL(raizAVL) : liberarNo(raiz);

    fclose(fDicionario);
    fclose(fTexto);
    return 0;
}
