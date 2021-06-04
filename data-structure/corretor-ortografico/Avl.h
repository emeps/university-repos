#ifndef EP3_AVL_H
#define EP3_AVL_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#include "Util.h"

typedef struct noAVL {
    char *palavra;
    struct noAVL *dir;
    struct noAVL *esq;
    int altura;
}NoAVL;

NoAVL *criarNoAVL(char *p);

void liberarNoAVL (NoAVL* r);

NoAVL* buscarNoAVL (NoAVL* r, char *p);

int altura(NoAVL *r);

int fatorBalanceamento(NoAVL * r);

NoAVL *rotacaoDireita(NoAVL *A);

NoAVL *rotacaoEsquerda(NoAVL *A); 

NoAVL *inserirNoAVL(NoAVL *r, NoAVL* novo);

NoAVL *removerNoAVL(NoAVL *r, char* palavra);

void imprimeArvore( NoAVL *root, int level );

void comparaAVL(NoAVL *r, char *palavra);

#endif