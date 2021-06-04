#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

/* Recebe uma fila de objetos em notação pós-fixa, avalia e retorna o resultado da expressação */
Objeto *avalia(Fila *posFixa)
{

    Pilha *operandos = criaPilha();
    Objeto *obj = front(posFixa);
    Objeto *objPilha = NULL;
    Objeto *op1 = NULL;
    Objeto *op2 = NULL;
    
    while (obj != NULL)
    {
        if (obj->categoria == FLOAT || obj->categoria == INT)
        {
            empilha(operandos, obj);
        }
        else
        {
            if (!pilhaVazia(operandos))
            {
                switch (obj->categoria)
                {
                case (OPER_MENOS_UNARIO):
                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);
                    if (op1->categoria == INT)
                    {
                        op1->valor.vInt = -(op1->valor.vInt);
                    }
                    else if (op1->categoria == FLOAT)
                    {
                        op1->valor.vFloat = -(op1->valor.vFloat);
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    break;
                case (OPER_EXPONENCIACAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    if (op1->categoria == INT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = pow(op1->valor.vInt, op2->valor.vFloat);
                        op1->categoria = FLOAT;
                    }
                    else if (op1->categoria == INT && op2->categoria == INT)
                    {
                        op1->valor.vInt = pow(op1->valor.vInt, op2->valor.vInt);
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = pow(op1->valor.vFloat, op2->valor.vFloat);
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == INT)
                    {
                        op1->valor.vFloat = pow(op1->valor.vFloat, op2->valor.vInt);
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                case (OPER_RESTO_DIVISAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);
                    
                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    op1->valor.vInt = op1->valor.vInt % op2->valor.vInt;

                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                case (OPER_MULTIPLICACAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    if (op1->categoria == INT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vInt*op2->valor.vFloat;
                        op1->categoria = FLOAT;
                    }
                    else if (op1->categoria == INT && op2->categoria == INT)
                    {
                        op1->valor.vInt = op1->valor.vInt*op2->valor.vInt;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat*op2->valor.vFloat;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == INT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat*op2->valor.vInt;
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                case (OPER_DIVISAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    if (op1->categoria == INT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vInt/op2->valor.vFloat;
                        op1->categoria = FLOAT;
                    }
                    else if (op1->categoria == INT && op2->categoria == INT)
                    {
                        op1->valor.vInt = op1->valor.vInt/op2->valor.vInt;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat/op2->valor.vFloat;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == INT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat/op2->valor.vInt;
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                case (OPER_ADICAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    if (op1->categoria == INT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vInt+op2->valor.vFloat;
                        op1->categoria = FLOAT;
                    }
                    else if (op1->categoria == INT && op2->categoria == INT)
                    {
                        op1->valor.vInt = op1->valor.vInt+op2->valor.vInt;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat+op2->valor.vFloat;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == INT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat+op2->valor.vInt;
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                case (OPER_SUBTRACAO):
                    objPilha = topoPilha(operandos);
                    op2 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    objPilha = topoPilha(operandos);
                    op1 = copiaObjeto(objPilha);
                    desempilha(operandos);

                    if (op1->categoria == INT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vInt-op2->valor.vFloat;
                        op1->categoria = FLOAT;
                    }
                    else if (op1->categoria == INT && op2->categoria == INT)
                    {
                        op1->valor.vInt = op1->valor.vInt-op2->valor.vInt;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == FLOAT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat-op2->valor.vFloat;
                    }
                    else if (op1->categoria == FLOAT && op2->categoria == INT)
                    {
                        op1->valor.vFloat = op1->valor.vFloat-op2->valor.vInt;
                    }
                    empilha(operandos, op1);
                    liberaObjeto(op1);
                    liberaObjeto(op2);
                    break;
                default:
                    break;
                }
            }
        }
        obj = obj->proximo;
    }
    objPilha = copiaObjeto(topoPilha(operandos));
    liberaPilha(operandos);
    return objPilha;
}
