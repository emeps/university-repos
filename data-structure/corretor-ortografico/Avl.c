#include "Avl.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

NoAVL *criarNoAVL(char *p)
{
    NoAVL *novo = (NoAVL *)mallocSafe(sizeof(NoAVL));
    char *palavra = (char *)mallocSafe(sizeof(char) * (strlen(p) + 1));
    strcpy(palavra, p);
    novo->palavra = palavra;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;
    return novo;
}

void liberarNoAVL(NoAVL *r)
{
    if (r != NULL)
    {
        liberarNoAVL(r->esq);
        liberarNoAVL(r->dir);
        free(r->palavra);
        free(r);
    }
}

NoAVL *buscarNoAVL(NoAVL *r, char *p)
{
    if (r == NULL || strcmp(r->palavra, p) == 0)
        return r;
    if (strcmp(r->palavra, p) > 0)
        return buscarNoAVL(r->esq, p);
    else
        return buscarNoAVL(r->dir, p);
}

int altura(NoAVL *r)
{
    if (r == NULL)
        return -1;
    return r->altura;
}

int fatorBalanceamento(NoAVL *r)
{
    return altura(r->esq) - altura(r->dir);
}

NoAVL *rotacaoDireita(NoAVL *A)
{
    NoAVL *B = A->esq;

    //Rotação
    A->esq = B->dir;
    B->dir = A;

    //Atualiza a altura 
    A->altura = max(altura(A->esq), altura(A->dir)) + 1;
    B->altura = max(altura(B->esq), altura(B->dir)) + 1;

    // Nova Raiz
    return B;
}

NoAVL *rotacaoEsquerda(NoAVL *A)
{
    NoAVL *B = A->dir;

    //Rotação
    A->dir = B->esq;
    B->esq = A;

    //Atualiza a altura 
    A->altura = max(altura(A->esq), altura(A->dir)) + 1;
    B->altura = max(altura(B->esq), altura(B->dir)) + 1;

    // Nova Raiz
    return B;
}

NoAVL *inserirNoAVL(NoAVL *r, NoAVL *novo)
{
    if (r == NULL)
        return novo;
    if (strcmp(r->palavra, novo->palavra) > 0)
        r->esq = inserirNoAVL(r->esq, novo);
    else
        r->dir = inserirNoAVL(r->dir, novo);

    r->altura = max(altura(r->esq), altura(r->dir)) + 1;

    int fb = fatorBalanceamento(r);

    //Rotação RR
    if (fb > 1 && fatorBalanceamento(r->esq) >= 0)
        return rotacaoDireita(r);
    //Rotação LL
    if (fb < -1 && fatorBalanceamento(r->dir) <= 0)
        return rotacaoEsquerda(r);
    //Rotação LR
    if (fb > 1 && fatorBalanceamento(r->esq) < 0)
    {
        r->esq = rotacaoEsquerda(r->esq);
        return rotacaoDireita(r);
    }
    //Rotação RL
    if (fb < -1 && fatorBalanceamento(r->dir) > 0)
    {
        r->dir = rotacaoDireita(r->dir);
        return rotacaoEsquerda(r);
    }

    return r;
}

void padding(char ch, int n)
{
    int i;
    for (i = 0; i < n; i++)
        putchar(ch);
}

void imprimeArvore(NoAVL *root, int level)
{
    if (root == NULL)
    {
        padding('\t', level);
        puts("~");
    }
    else
    {
        imprimeArvore(root->dir, level + 1);
        padding('\t', level);
        printf("%s\n", root->palavra);
        imprimeArvore(root->esq, level + 1);
    }
}

void comparaAVL(NoAVL *r, char *palavra)
{
    if (r == NULL)
    {
        return;
    }
    comparaAVL(r->esq, palavra);
    comparaAVL(r->dir, palavra);
    int limite = 3;
    if (abs((int)strlen(r->palavra) - (int)strlen(palavra)) < limite)
    {
        if (distanciaEdicao(r->palavra, palavra) < limite)
        {
            printf("\033[1;32;40m%s\033[00m, ", r->palavra);
        }
    }
}