#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct pilha
{
    Objeto *inicio;
    int n;
} Pilha;

Pilha *criaPilha()
{
    Pilha *p = mallocSafe(sizeof(Pilha));
    p->inicio = NULL;
    p->n = 0;
    return p;
}

/* Faz a desalocação da pilha */
void liberaPilha(Pilha *p)
{

    Objeto *aux = p->inicio;
    while (aux)
    {
        Objeto *temporario = aux->proximo;
        free(aux);
        aux = temporario;
    }
    free(p);
    p = NULL;
}

/* Insere um novo objeto a pilha */
void empilha(Pilha *p, Objeto *no)
{

    Objeto *aux = copiaObjeto(no);
    aux->proximo = p->inicio;
    p->inicio = aux;
    p->n++;
}

/* Remove (apaga) o último elemento da pilha */
void desempilha(Pilha *p)
{
    if (pilhaVazia(p))
    {
        printf("Erro: Pilha Vazia!");
    }
    else
    {
        Objeto *temporario = p->inicio;
        p->inicio = p->inicio->proximo;
        p->n--;
        liberaObjeto(temporario);
    }
}

/* Retorna o objeto do topo da pilha */
Objeto *topoPilha(Pilha *p)
{
    if (pilhaVazia(p))
    {
        printf("Erro: Pilha Vazia!");
        return NULL;
    }
    return p->inicio;
}

/* Verifica se a pilha está vazia */
bool pilhaVazia(Pilha *p)
{
    return (p == NULL || p->n == 0);
}

/* Retorna o número de elementos na pilha */
int tamanhoPilha(Pilha *p)
{
    if (pilhaVazia(p))
        return 0;
    return p->n;
}

/* Fução que imprime os elementos da pilha 
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use a função imprimeObjeto.
 */

void imprimePilha(Pilha *pilha, int tipo)
{
    if (!pilhaVazia(pilha))
    {
        Objeto *obj = pilha->inicio;
        while (obj != NULL)
        {
            imprimeObjeto(obj, tipo);
            obj = obj->proximo;
        }
    }
    else
    {
        printf("Erro: Pilha Vazia!");
    }
}