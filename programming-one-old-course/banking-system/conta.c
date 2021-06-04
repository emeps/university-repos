#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conta.h"


Conta inicializaConta(){
    int i;
    Conta c;
    printf("Insira o nome do titular\t");
    printf("\n");
    scanf(" %50[^\n]s",c.titular.nome);
    fflush(stdin);
    printf("Insira o endereco do titular\t");
    printf("\n");
    scanf(" %100[^\n]s",c.titular.endereco);
    fflush(stdin);
    printf("Insira o CPF do titular\t");
    printf("\n");
    scanf(" %15[^\n]s",c.titular.cpf);
    fflush(stdin);
    printf("Insira a quantidade de telefone do titular\t");
    printf("\n");
    scanf(" %d",&c.titular.qtTelefone);
    fflush(stdin);
    for(i=0;i<c.titular.qtTelefone;i++){
        printf("Insira o DDD do telefone do titular\t");
        printf("\n");
        scanf(" %5[^\n]s",c.titular.telefone[i].ddd);
        fflush(stdin);
        printf("Insira o numero do telefone do titular\t");
        printf("\n");
        scanf(" %15[^\n]s",c.titular.telefone[i].numero);
        fflush(stdin);
    }
    printf("Insira um numero de identificacao para o titular\t");
    printf("\n");
    scanf(" %7[^\n]s",c.id);
    fflush(stdin);
    printf("Insira 1 - Para indicar conta ativa ou 0 - Para indicar conta inativa\t");
    printf("\n");
    scanf(" %d", &c.contaAtiva);
    printf("Insira o tipo de conta para o titular. 'P' para poupança ou 'C' para corrente\t");
    printf("\n");
    scanf(" %c",&c.tipoConta);
    printf("Insira saldo inicial da conta\t");
    printf("\n");
    scanf(" %f", &c.saldo);
    return c;
}

int carregaContas(Conta *conta){
    char nome[20];
    int numContas;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome);

    FILE *arq = fopen(nome, "r");
    //FILE *arq = fopen("contas.txt", "r");
    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo %s\n", nome);
        exit(1);
    }

    fscanf(arq, "%d", &numContas);

    //conta = malloc(numContas*sizeof(Conta));

    for(int i = 0; i < numContas; i++){
        fscanf(arq, "%7s", conta[i].id);
        fgetc(arq);
        //printf("%s\n", conta[i].id);
        fscanf(arq, "%50[^\n]s", conta[i].titular.nome);
        fgetc(arq);
        //printf("%s\n", conta[i].titular.nome);
        fscanf(arq, "%100[^\n]s", conta[i].titular.endereco);
        fgetc(arq);
        //printf("%s\n", conta[i].titular.endereco);
        fscanf(arq, "%15s", conta[i].titular.cpf);
        fgetc(arq);
        //printf("%s\n", conta[i].titular.cpf);
        fscanf(arq, "%d", &conta[i].titular.qtTelefone);
        //printf("%d\n", conta[i].titular.qtTelefone);
        for(int j = 0; j < conta[i].titular.qtTelefone; j++){
            fscanf(arq, "%s", conta[i].titular.telefone[j].ddd);
            fgetc(arq);
            fscanf(arq, "%15[^\n]s", conta[i].titular.telefone[j].numero);
            //printf("%s %s\n", conta[i].titular.telefone[j].ddd, conta[i].titular.telefone[j].numero);
        }
        fscanf(arq, "%d", &conta[i].contaAtiva);
        fgetc(arq);
        fscanf(arq, "%c", &conta[i].tipoConta);
        fscanf(arq, "%f", &conta[i].saldo);

        //printf("%d\n", conta[i].contaAtiva);
        //printf("%c\n", conta[i].tipoConta);
        //printf("%f\n", conta[i].saldo);
    }

    fclose(arq);

    return numContas;
}

void imprimeConta(Conta *c){
    printf("----------------------------------------------------------------------\n");
	printf("Correntista: %s\n", c->titular.nome);
	printf("CPF: %s\n", c->titular.cpf);
	printf("Endereco: %s\n", c->titular.endereco);
	printf("Telefones:\n");
	for(int i = 0; i < c->titular.qtTelefone; i++)
		printf("%s %s\n", c->titular.telefone[i].ddd, c->titular.telefone[i].numero);
    printf("Identificacao do Correntista (ID): %s\n", c->id);
    printf("Status da Conta:\t");
    if(c->contaAtiva == 1)
    	printf("Conta Ativada\n");
    else
    	printf("Conta Desativada\n");
    printf("Tipo da Conta:\t");
    if(c->tipoConta == 'p')
    	printf("Conta Poupanca\n");
    else
    	printf("Conta Corrente\n");
    printf("Saldo: %.2f\n", c->saldo);
    printf("----------------------------------------------------------------------\n");
}

void salvaContas(Conta *c, int numContas){
    int i;
    FILE *arq;
    char contaBK[10];
    printf("Digite o nome do arquivo para ser salvo:\t");
    printf("\n");
    scanf("%s",contaBK);

    arq = fopen(contaBK,"w");
    if(arq == 0){
        printf("Nao foi possivel abrir o arquivo %s", contaBK);
        return;
    }
    fprintf(arq, "%d\n", numContas);
    for (i=0;i<numContas;i++){
        fprintf(arq,"\n%s\n", c[i].id);
        //printf("%s\n", conta[i].id);
        fprintf(arq,"%s\n", c[i].titular.nome);
        //printf("%s\n", conta[i].titular.nome);
        fprintf(arq,"%s\n", c[i].titular.endereco);
        //printf("%s\n", conta[i].titular.endereco);
        fprintf(arq,"%s\n", c[i].titular.cpf);
        //printf("%s\n", conta[i].titular.cpf);
        fprintf(arq,"%d\n",c[i].titular.qtTelefone);
        //printf("%d\n", c[i].titular.qtTelefone);
        for(int j = 0; j < c[i].titular.qtTelefone; j++){
            fprintf(arq, "%s ", c[i].titular.telefone[j].ddd);
            fprintf(arq, "%s\n", c[i].titular.telefone[j].numero);
            //printf("%s %s\n", conta[i].titular.telefone[j].ddd, conta[i].titular.telefone[j].numero);
        }
        fprintf(arq, "%d\n", c[i].contaAtiva);
        fprintf(arq, "%c\n", c[i].tipoConta);
        fprintf(arq, "%.2f\n", c[i].saldo);
    }
    fclose(arq);
    printf("%d foram gravados\n",numContas);


}

void ordenaContas(Conta *c,int numContas){
    int escolha,i,j;
    Conta aux;
    do{
        printf("Por favor escolha o tipo de ordenacao que deseja usar");
        printf("\n|  Ordenar por ID..............[1]  |");
        printf("\n|  Ordenar por Nome............[2]  |");
        printf("\n|  Ordenar por CPF.............[3]  |");
        printf("\nSua escolha:\t");
        printf("\n");
        scanf("%d",&escolha);
    }while(escolha>3 || escolha <1);
    switch(escolha){
        case 1:
            for(i=0;i<numContas; i++){
                for(j=0; j<numContas-1; j++){
                    if(strcmp(c[j].id,c[j+1].id) >0){
                        aux = c[j];
                        c[j]= c[j+1];
                        c[j+1] = aux;
                    }
                }
            }
            break;
        case 2:
            for(i=0;i<numContas; i++){
                for(j=0; j<numContas -1; j++){
                    if(strcmp(c[j].titular.nome,c[j+1].titular.nome) >0){
                        aux = c[j];
                        c[j]= c[j+1];
                        c[j+1] = aux;
                    }
                }
            }
            break;
        case 3:
            for(i=0;i<numContas ; i++){
                for(j=0; j<numContas -1; j++){
                    if(strcmp(c[j].titular.cpf , c[j+1].titular.cpf) >0){
                        aux = c[j];
                        c[j]= c[j+1];
                        c[j+1] = aux;
                    }
                }
            }
            break;


    }

}

int buscaConta(Conta *c, int numContas, char bc[], int escolha){
     int inf = 0;
     int sup = numContas-1;
     int meio;
     if (escolha == 1){
        while (inf <= sup)
            {
                 meio = (inf + sup)/2;
                 if (strcmp(bc,c[meio].id)==0)
                      return meio;
                 if (strcmp(bc,c[meio].id)<0)
                      sup = meio-1;
                 else
                      inf = meio+1;
            }
            return -1;
     }else if(escolha == 2){
         while (inf <= sup)
            {
                 meio = (inf + sup)/2;
                 if (strcmp(bc,c[meio].titular.nome)==0)
                      return meio;
                 if (strcmp(bc,c[meio].titular.nome)<0)
                      sup = meio-1;
                 else
                      inf = meio+1;
            }
            return -1;

     }else{
         while (inf <= sup)
            {
                 meio = (inf + sup)/2;
                 if (strcmp(bc,c[meio].titular.cpf)==0)
                      return meio;
                 if (strcmp(bc,c[meio].titular.cpf)<0)
                      sup = meio-1;
                 else
                      inf = meio+1;
            }
            return -1;

     }
}

void saqueConta (Conta *c){
    int saque;
    if(c->contaAtiva == 1){
        printf("Insira o valor valido para ser sacado:\t");
        scanf("%d",&saque);
        if((saque>0)&&(saque<c->saldo)){
                c->saldo = c->saldo - saque;
                printf("Transacao realizada com sucesso!\n");
                printf("Novo saldo eh:%.2f\n",c->saldo);
        }else{
            printf("Operacao invalida:\n");
        }
    }else{
        printf("Conta inativa\n");
    }
}

void depositoConta (Conta *c){
    int deposito;
    if(c->contaAtiva == 1){
        printf("Insira o valor valido para ser depositado:\t");
        scanf("%d",&deposito);
        if((deposito>0)){
                c->saldo = c->saldo + deposito;
                printf("Transacao realizada com sucesso!\n");
                printf("Novo saldo eh:%.2f\n",c->saldo);
        }else{
            printf("Operacao invalida:\n");
        }
    }else{
        printf("Conta inativa\n");
    }
}

void transferenciaConta(Conta *c1, Conta *c2){

    float transferencia;
    if((c1->contaAtiva == 1)&&(c2->contaAtiva ==1)){
        printf("Insira o valor valido para ser transferido:\t");
        scanf("%f",&transferencia);
        if((transferencia>0)&&(transferencia<c1->saldo)){
                c1->saldo = c1->saldo - transferencia;
                c2->saldo = c2->saldo + transferencia;
                printf("\n");
                printf("Transacao realizada com sucesso!\n");
                printf("Sr. %s seu novo saldo eh:%.2f\n",c1->titular.nome,c1->saldo);
                printf("\n-----------------------------------------------------------");
                printf("\nBeneficiario: %s.Valor da transferencia:%.2f\n",c2->titular.nome,transferencia);
                printf("\n-----------------------------------------------------------");
        }else{
            printf("Operacao invalida:\n");
        }
    }else{
        printf("Conta inativa\n");
    }

}
