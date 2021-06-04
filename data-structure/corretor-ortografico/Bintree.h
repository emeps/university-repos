#ifndef EP3_BINTREE_H
#define EP3_BINTREE_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include "Util.h"

typedef struct no {
    char *palavra;
    struct no *esq;
    struct no *dir;
}No;

No *criarNo(char *p);

void liberarNo(No *r);

No *buscarNo(No *raiz, char* palavra);

No *inserirNo(No *raiz, No *novo);

No *removerNo(No *raiz, char* palavra);

void imprimirNo(No *raiz);

void compara(No *r, char *palavra);

#endif