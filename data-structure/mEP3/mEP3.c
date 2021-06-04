#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

Lista *juntaLista(Lista *l1, Lista *l2) {
    Lista *resultado = criaLista();
    No *no1 = NULL;
    No *no2 = NULL;
    No *nor = NULL;
    /* Complete o código da função */
    /* Não faça nenhuma alocação e nem crie outras funções */    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    no1 = l1->inicio;
    no2 = l2->inicio;
    if(no1->id < no2->id) {   
        resultado->inicio = no1;
        no1 = no1->proximo;
    }
    else {
        resultado->inicio = no2;
        no2 = no2->proximo;
    }
    nor = resultado->inicio;
    while(no1 != NULL && no2 != NULL) {
        if(no1->id < no2->id) {
            nor->proximo = no1;
            no1 = no1->proximo;
        }
        else {
            nor->proximo = no2;
            no2 = no2->proximo;
        }
        nor = nor->proximo;
    }
    if(no1 == NULL) {
        nor->proximo = no2;
    }
    else if(no2 == NULL) {
        nor->proximo = no1;
    }

    return resultado;
}

