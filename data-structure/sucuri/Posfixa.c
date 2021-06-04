#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"

/* A função recebe uma fila de objetos em notação infixa e converte (retorna) 
 * a correspondente em notação pós-fixa.
 * Para evitar problemas de vazamento de memória e/ou falha de segmentação, faça 
 * cópia dos objetos. 
 * Lembre-se que a função 'desempilha' (Pilha.h) e 'dequeue' (Fila.h)
 * fazem a desalocação dos objetos(liberaObjeto)
 */

Fila *infixaParaPosfixa(Fila *infixa)
{
    Pilha *operadores = criaPilha();
    Fila *posFixa = criaFila();
    Objeto *obj = front(infixa);
    Objeto *objPilha = NULL;

    while (obj != NULL)
    {
        if (obj->categoria == 11 || obj->categoria == 12)
        {
            enqueue(posFixa, copiaObjeto(obj));
        }
        else if (obj->categoria == 7)
        {
            empilha(operadores, obj);
        }
        else if (obj->categoria == 8)
        {
            if (!pilhaVazia(operadores))
            {
                objPilha = topoPilha(operadores);
                while (objPilha->categoria != 7)
                {
                    enqueue(posFixa, copiaObjeto(objPilha));
                    desempilha(operadores);
                    objPilha = topoPilha(operadores);
                }
                desempilha(operadores);
            }
        }
        else if (obj->categoria >= 0 && obj->categoria <= 6)
        {

            if (!pilhaVazia(operadores))
            {
                objPilha = topoPilha(operadores);
                while (objPilha->valor.vInt > obj->valor.vInt)
                {
                    enqueue(posFixa, copiaObjeto(objPilha));
                    desempilha(operadores);
                    if (pilhaVazia(operadores))
                    {
                        break;
                    }
                    objPilha = topoPilha(operadores);
                }
            }
            empilha(operadores, obj);
        }
        obj = obj->proximo;
    }
    while (!pilhaVazia(operadores))
    {
        objPilha = topoPilha(operadores);
        enqueue(posFixa, copiaObjeto(objPilha));
        desempilha(operadores);
    }
    liberaPilha(operadores);
    return posFixa;
}

void imprimePosFixa(Fila *posfixa)
{
    Fila *f = copiaFila(posfixa);
    while (!filaVazia(f))
    {
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}