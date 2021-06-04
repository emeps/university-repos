#include "Fila.h"

Fila *criarFila()
{
    Fila *fila = mallocSafe(sizeof(Fila));
    fila->n = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

NoFila *criarNoFila(char *p)
{
    NoFila *no = mallocSafe(sizeof(NoFila));
    char *palavra = mallocSafe(sizeof(char) * (strlen(p) + 1));
    strcpy(palavra, p);

    no->proximo = NULL;
    no->palavra = palavra;
    return no;
}

int filaVazia(Fila *fila)
{
    return fila->n == 0;
}

void enqueue(Fila *f, NoFila *no)
{
    NoFila *atual = f->inicio;
    if (no != NULL && f != NULL)
    {
        if (filaVazia(f))
        {
            f->inicio = no;
            f->fim = no;
            f->n++;
        }
        else
        {
            f->fim->proximo = no;
            f->fim = no;
            f->n++;
        }
    }
}

void dequeue(Fila *f, NoFila *no)
{
    if (f != NULL && !filaVazia(f))
    {
        NoFila *tmp = f->inicio;
        f->inicio = f->inicio->proximo;
        f->n--;
        liberarNoFila(tmp);
    }
}

NoFila *buscarNoFila(Fila *f, char *chave)
{
    if (f != NULL)
    {
        if (!filaVazia(f))
        {
            NoFila *no = f->inicio;
            while (no != NULL)
            {
                if (strcmp(no->palavra, chave) == 0)
                    return no;
                no = no->proximo;
            }
        }
    }
    return NULL;
}

void liberarNoFila(NoFila *no)
{
    if (no != NULL)
    {
        free(no->palavra);
        free(no);
    }
}

void liberarFila(Fila *f)
{
    NoFila *aux = f->inicio;
    while (aux)
    {
        NoFila *t = aux->proximo;
        liberarNoFila(aux);
        aux = t;
    }
    free(f);
    f = NULL;
}
