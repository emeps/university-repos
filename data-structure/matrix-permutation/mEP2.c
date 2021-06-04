#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int tamanhoMatriz;
    scanf("%d", &tamanhoMatriz);
    if (tamanhoMatriz >= 2 && tamanhoMatriz <= 500)
    {

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        int *vetorP = malloc(tamanhoMatriz * sizeof(int));
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            scanf("%d", &vetorP[i]);
        }

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        int **matrizB;
        matrizB = malloc(tamanhoMatriz * sizeof(int *));
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            matrizB[i] = malloc(tamanhoMatriz * sizeof(int));
        }
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            for (int j = 0; j < tamanhoMatriz; j++)
            {
                scanf("%d", &matrizB[i][j]);
            }
        }
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        int k = 0;
        int n = 0;
        int count = 0;
        int *aux;
        int aux2;
        while (count < tamanhoMatriz)
        {
            if (vetorP[k] == n + 1)
            {
                count++;
                k++;
                n++;
            }
            else
            {
                aux2 = vetorP[n];
                aux = matrizB[aux2 - 1];

                matrizB[aux2 - 1] = matrizB[k];
                matrizB[k] = aux;

                vetorP[n] = vetorP[aux2 - 1];
                vetorP[aux2 - 1] = aux2;
            }
        }

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            for (int j = 0; j < tamanhoMatriz; j++)
            {
                printf("%d ", matrizB[i][j]);
            }
            printf("\n");
        }
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            free(matrizB[i]);
        }
        free(matrizB);
        free(vetorP);
        return 0;
    }
    else
    {
        printf("\nValor invalido para o tamanho da matriz\n");
    }
}
