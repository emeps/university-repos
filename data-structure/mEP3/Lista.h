#ifndef __LISTA_H
#define __LISTA_H

typedef struct no {
	int id;
    struct no *proximo;
} No;

typedef struct  lista {
    No *inicio;
} Lista;

Lista *criaLista();

Lista* juntaLista(Lista *l1, Lista *l2);

#endif