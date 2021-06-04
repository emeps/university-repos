#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

struct fila
{
    Objeto *inicio;
    Objeto *fim;
    int n;
};

Fila *criaFila()
{
    Fila *f = mallocSafe(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

/* Faz a desalocação da fila */
void liberaFila(Fila *f)
{
    Objeto *aux = f->inicio;
    while (aux)
    {
        Objeto *aux2 = aux->proximo;
        liberaObjeto(aux);
        aux = aux2;
    }
    free(f);
    f = NULL;
}

/* Insere um novo objeto a fila */
void enqueue(Fila *f, Objeto *o)
{
    Objeto *aux = o;
    aux->proximo = NULL;
    if (filaVazia(f))
    {
        f->inicio = aux;
    }
    else
    {
        f->fim->proximo = aux;
    }
    f->fim = aux;
    f->n++;
}

/*Remove (apaga) o primeiro elemento da fila */
void dequeue(Fila *f)
{
    if (!filaVazia(f))
    {
        Objeto *temporario = f->inicio;
        f->inicio = f->inicio->proximo;
        f->n--;
        liberaObjeto(temporario);
    }
    else
    {
        printf("Erro: Fila Vazia!\n");
    }
}

/* Retorna o primeiro elemento da fila */
Objeto *front(Fila *f)
{
    if (filaVazia(f))
    {
        printf("Erro: Fila Vazia!");
        return NULL;
    }
    else
        return f->inicio;
}

/* Verifica se a fila está vazia */
bool filaVazia(Fila *f)
{
    return (f == NULL || f->n == 0);
}

/* Retorna o número de elementos na fila */
int tamanhoFila(Fila *f)
{
    if (filaVazia(f))
        return 0;
    return f->n;
}
/* Retorna uma cópia da fila passada como parâmetro */
Fila *copiaFila(Fila *f)
{
    Fila *filaCopiada = NULL;
    if (!filaVazia(f))
    {
        filaCopiada = criaFila();
        Objeto *obj = f->inicio;
        Objeto *copiaObj = NULL;

        copiaObj = copiaObjeto(obj);
        filaCopiada->inicio = copiaObj;
        while (obj != f->fim)
        {
            obj = obj->proximo;
            copiaObj->proximo = copiaObjeto(obj);
            copiaObj = copiaObj->proximo;
        }
        filaCopiada->fim = copiaObj;
        filaCopiada->n = f->n;
    }
    else
    {
        printf("Erro: Fila Vazia!\n");
    }

    return filaCopiada;
}

/* Fução que imprime os elementos da fila 
 * Essa função pode ajudar a detectar problemas nos objetos da fila
 * Para imprimir um objeto, use a função imprimeObjeto.
 */
void imprimeFila(Fila *f, int tipo)
{
    if (!filaVazia(f))
    {
        Objeto *obj = f->inicio;
        while (obj != NULL)
        {
            imprimeObjeto(obj, tipo);
            obj = obj->proximo;
        }
    }
    else
    {
        printf("Erro: Fila Vazia!\n");
    }
}

/* Função de Alta Ordem que recebe uma fila e uma função (cb).
 * Para cada objeto da fila, aplique a função cb ao objeto.
 */
void converteElementosFila(Fila *f, void (*cb)(Objeto *))
{
    if (filaVazia(f))
    {
        printf("Erro: Fila Vazia!\n");
    }
    else
    {
        Objeto *obj = f->inicio;
        while (obj != NULL)
        {
            cb(obj);
            obj = obj->proximo;
        }
    }
}