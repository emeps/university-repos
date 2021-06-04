#include <stdio.h>
#include <stdlib.h>

#include "Conta.h"

int contaCarregada = 0;

int menu();

void pausa();

int main(){
    //Conta *conta = (Conta*)malloc(100*sizeof(Conta));
    Conta conta[1000];
    int opcao, numContas, resultado, busca, resultado1;
    char salvarContas, BuscarConta[50];
    char IDConta1[7];
    char IDConta2[7];
    do {
        system("clear"); // limpa a tela
        opcao = menu();
        switch( opcao ) {
            case 1:
                numContas = carregaContas(conta);
                printf("Dados com as contas aberto com sucesso!\n");
                contaCarregada = 1;
                pausa();
                break;
            case 2:
                salvaContas(conta,numContas);
                pausa();
                break;
            case 3:
                conta[numContas] = inicializaConta();
                numContas ++;
                pausa();
                break;
            case 4:
                printf("Digite a ID da conta a ser impressa: ");
                scanf("%s", IDConta1);
                resultado = buscaConta(conta,numContas,IDConta1,1);
                if(resultado == -1){
                    printf("Conta nao encontrada\n");
                }else{
                    imprimeConta(&conta[resultado]);
                }
                pausa();
                break;
            case 5:
                printf("Digite a ID da conta que deseja fazer o saque: ");
                scanf("%s", IDConta1);
                resultado = buscaConta(conta,numContas,IDConta1,1);
                if(resultado == -1){
                    printf("Conta nao encontrada\n");
                }else{
                    saqueConta(&conta[resultado]);
                }
                pausa();
                break;
            case 6:
                printf("Digite a ID da conta que deseja fazer o deposito: ");
                scanf("%s", IDConta1);
                resultado = buscaConta(conta,numContas,IDConta1,1);
                if(resultado == -1){
                    printf("Conta nao encontrada\n");
                }else{
                    depositoConta(&conta[resultado]);
                }
                pausa();
                break;
            case 7:
                printf("------------------ Transferencia ------------------\n");
                printf("Digite a ID da conta que deseja fazer o saque:\t ");
                scanf("%s", IDConta1);
                printf("\n");
                printf("Digite a ID da conta que deseja fazer o deposito:\t ");
                scanf("%s", IDConta2);
                printf("\n");
                resultado = buscaConta(conta,numContas,IDConta1,1);
                resultado1 = buscaConta(conta,numContas,IDConta2,1);
                if((resultado == -1)||(resultado1 == -1)){
                    printf("Conta nao encontrada\n");
                }else{
                    transferenciaConta(&conta[resultado],&conta[resultado1]);
                }
                pausa();
                break;
            case 8:
                ordenaContas(conta,numContas);
                printf("Operacao realizada com sucesso!\n");
                pausa();
                break;
            case 9:
                do{
                    printf("Por favor escolha o tipo de busca que deseja usar");
                    printf("\n|  Buscar por ID..............[1]  |");
                    printf("\n|  Buscar por Nome............[2]  |");
                    printf("\n|  Buscar por CPF.............[3]  |");
                    printf("\n   Sua escolha:\t");
                    printf("\n");
                    scanf("%d",&busca);
                }while(busca>3 || busca <1);
                switch(busca){
                    case 1:
                        printf("Voce escolheu buscar por ID.\n");
                        printf("Por favor insira a ID a ser buscada:\t");
                        scanf(" %s",BuscarConta);
                        printf("\n");
                        resultado = buscaConta(conta,numContas,BuscarConta,busca);
                        if(resultado == -1)
                            printf("Titular nao encontrado\n");
                        else{
                            imprimeConta(&conta[resultado]);
                            printf("Operacao realizada com sucesso!\n");
                        }
                        break;
                    case 2:
                        printf("Voce escolheu buscar por NOME.\n");
                        printf("Por favor insira o nome a ser buscado:\t");
                        scanf(" %[0-9a-zA-Z ]",BuscarConta); // scanf formatado, somente assim para ler espaços
                        printf("\n");
                        resultado = buscaConta(conta,numContas,BuscarConta,busca);
                        if(resultado == -1){
                            printf("Titular nao encontrado\n");
                        }else{
                            imprimeConta(&conta[resultado]);
                            printf("Operacao realizada com sucesso!\n");
                        }
                        break;
                    case 3:
                        printf("Voce escolheu buscar por CPF.\n");
                        printf("Por favor insira o CPF a ser buscado:\t");
                        scanf(" %s",BuscarConta);
                        printf("\n");
                        resultado = buscaConta(conta,numContas,BuscarConta,busca);
                        if(resultado == -1){
                            printf("Titular nao encontrado\n");
                        }else{
                            imprimeConta(&conta[resultado]);
                            printf("Operacao realizada com sucesso!\n");
                        }
                        break;
                }
                pausa();
                break;
            case 10:
                if(contaCarregada == 1){
                    do{
                        getc(stdin);
                        printf("Deseja salvar os dados das contas [S/N]? ");
                        scanf("%c", &salvarContas);
                    }while(salvarContas != 's' && salvarContas != 'S' && salvarContas != 'n' && salvarContas != 'N');
                    if(salvarContas == 's' || salvarContas == 'S')
                        salvaContas(conta,numContas);

                    printf("Contas salvas com sucesso!\n");
                    pausa();
                }
                break;
        }
    }while(opcao != 10);

    return 0;
}


int menu() {
    /*
     Objetivo  : apresentar o menu e retornar o numero da opcao escolhida.
     Argumentos: nenhum.
     Retorno   : numero da opcao escolhida.
     */
    printf("\n+-----------------------------------+");
    printf("\n|           MENU DE OPCOES          |");
    printf("\n+-----------------------------------+");
    printf("\n|                                   |");
    printf("\n|  Abrir......................[ 1]  |");
    if(contaCarregada == 1){
        printf("\n|  Salvar Contas..............[ 2]  |");
        printf("\n|  Cadastrar Conta............[ 3]  |");
        printf("\n|  Imprimir Conta.............[ 4]  |");
        printf("\n|  Saque......................[ 5]  |");
        printf("\n|  Deposito...................[ 6]  |");
        printf("\n|  Transferencia..............[ 7]  |");
        printf("\n|  Ordenar Contas.............[ 8]  |");
        printf("\n|  Buscar Conta...............[ 9]  |");
    }
    printf("\n|  Sair.......................[10]  |");
    printf("\n|                                   |");
    printf("\n+-----------------------------------+");
    int opcao;
    if(contaCarregada == 1){
        do {
            printf("\nQual a opcao? ");
            scanf("%d", &opcao);
        }while(opcao < 1  ||  opcao > 10);
    }
    else{
        do {
            printf("\nQual a opcao? ");
            scanf("%d", &opcao);
        }while(opcao != 1  &&  opcao != 10);
    }
    //fflush(stdin);
    return opcao;
}

void pausa() {
    /*
     Objetivo  : fazer uma pausa no processamento.
     Argumentos: nenhum.
     Retorno   : nenhum.
     */
    // fflush(stdin);
    printf("Tecle ENTER para continuar...");fflush(stdin);
    //getchar();
    getc(stdin);
    getchar();
}
