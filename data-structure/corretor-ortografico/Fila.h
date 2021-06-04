#ifndef EP3_FILA_H
#define EP3_FILA_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "Util.h"

typedef struct noFila {
    struct noFila *proximo;
    char *palavra;
}NoFila;

typedef struct fila {
    struct noFila* inicio;
    struct noFila* fim;
    int n;
}Fila;

Fila *criarFila();

NoFila *criarNoFila(char *p);

int filaVazia(Fila *fila);

void enqueue(Fila *f, NoFila *no);

void dequeue(Fila *f, NoFila *no);

NoFila* buscarNoFila(Fila *f, char *chave);

void liberarNoFila(NoFila *no);

void liberarFila(Fila *f);

#endif
