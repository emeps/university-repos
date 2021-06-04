#include "Bintree.h"


No *criarNo(char *p)
{
    No *novo = (No *)mallocSafe(sizeof(No));
    char *palavra = (char *)mallocSafe(sizeof(char) * (strlen(p) + 1));
    strcpy(palavra, p);
    novo->palavra = palavra;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void liberarNo(No *r)
{
    if (r != NULL)
    {
        liberarNo(r->esq);
        liberarNo(r->dir);
        free(r->palavra);
        free(r);
    }
}

void imprimirNo(No *raiz)
{
    printf("%s ", raiz->palavra);
}

No *buscarNo(No *raiz, char *p)
{
    if (raiz == NULL || strcmp(raiz->palavra, p) == 0)
        return raiz;
    if (strcmp(raiz->palavra, p) > 0)
        return buscarNo(raiz->esq, p);
    else
        return buscarNo(raiz->dir, p);
}

No *inserirNo(No *raiz, No *novo)
{
    if (raiz == NULL)
    {
        return novo;
    }
    if (strcmp(raiz->palavra, novo->palavra) > 0)
        raiz->esq = inserirNo(raiz->esq, novo);
    else
        raiz->dir = inserirNo(raiz->dir, novo);
    return raiz;
}

No *removerNo(No *raiz, char *palavra)
{
    No *pai = NULL;
    No *atual = raiz;
    while (atual != NULL && strcmp(atual->palavra, palavra) != 0)
    {
        pai = atual;
        if (strcmp(atual->palavra, palavra) > 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if (atual == NULL)
    {
        printf("Chave não encontrada!\n");
        return raiz;
    }

    // Folha
    if (atual->dir == NULL && atual->esq == NULL)
    {
        if (atual != raiz)
        {
            if (pai->esq == atual)
                pai->esq = NULL;
            else
                pai->dir = NULL;
        }
        else
        {
            raiz = NULL;
        }
        free(atual->palavra);
        free(atual);
    }
    
    //Filho Unico Esquerda
    else if (atual->dir == NULL)
    {
        if (atual != raiz)
        { // ou pai != NULL;
            if (pai->esq == atual)
                pai->esq = atual->esq;
            else
                pai->dir = atual->esq;
        }
        else
        {
            raiz = atual->esq;
        }
        free(atual->palavra);
        free(atual);
    }
    //Filho Unico Direita
    else if (atual->esq == NULL)
    {
        if (atual != raiz)
        { // ou pai != NULL;
            if (pai->esq == atual)
                pai->esq = atual->dir;
            else
                pai->dir = atual->dir;
        }
        else
        {
            raiz = atual->dir;
        }
        free(atual->palavra);
        free(atual);
    }
    //Dois filhos
    else
    {
        No *t = atual->esq;
        pai = NULL;
        while (t->dir != NULL)
        {
            pai = t;
            t = t->dir;
        }
        if (pai != NULL)
            pai->dir = t->esq;
        else 
            atual->esq = t->esq;
        atual->palavra = t->palavra; 
        free(t->palavra);
        free(t);
        
    }

    return raiz;
}

void compara(No *r, char *palavra)
{
    if (r == NULL)
    {
        return;
    }
    compara(r->esq, palavra);
    compara(r->dir, palavra);
    int limite = 3;
    if (abs((int)strlen(r->palavra) - (int)strlen(palavra)) < limite)
    {
        if (distanciaEdicao(r->palavra, palavra) < limite)
        {
            printf("\033[1;32;40m%s\033[00m, ", r->palavra);
        }
    }
}