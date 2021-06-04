#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED
typedef struct{
    char ddd[5];
    char numero[15];
}Telefone;

typedef struct{
    char nome[50];
    char endereco[100];
    char cpf[15];
    int qtTelefone;
    Telefone telefone[50];
}Pessoa;

typedef struct{
    char id[7];
    int contaAtiva;
    char tipoConta;
    float saldo;
    Pessoa titular;
}Conta;

Conta inicializaConta();
void salvaContas(Conta *c,int numContas);
void imprimeConta(Conta *c);
int carregaContas(Conta *conta);
void saqueConta(Conta *c);
void depositoConta(Conta *c);
void transferenciaConta(Conta *c1, Conta *c2);
void ordenaContas( Conta *c, int numContas);
int buscaConta ( Conta *c,int numContas,char bc[], int escolha);


#endif // CONTA_H_INCLUDED
