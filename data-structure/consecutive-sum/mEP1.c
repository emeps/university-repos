#include <stdio.h>
#include <stdlib.h>

int main()
{
    long tamanho_array;
    long dias_consectivos;
    long *conteudo_array;
    long soma_acumulada = 0;
    long soma_maxima = 0;
    int initK = 0;

    /* Leitura do tamanho da array */
    scanf("%ld", &tamanho_array);

    /* Alocação e leitura dos valores do array */
    conteudo_array = malloc(tamanho_array * sizeof(long));
    for (int i = 0; i < tamanho_array; i++)
    {
        scanf("%ld", &conteudo_array[i]);
    }

    /* Leitura dos dias consecutivos (k) */
    scanf("%ld", &dias_consectivos);

    /* Soma dos valores do subarray */
    for (int i = 0; i < dias_consectivos; i++)
    {
        soma_acumulada += conteudo_array[i];
    }
    soma_maxima = soma_acumulada;

    /* Soma e verificação dos novos valores do subarray */
    for (int i = dias_consectivos; i < tamanho_array; i++)
    {
        soma_acumulada += conteudo_array[i] - conteudo_array[initK];
        if ((soma_acumulada > soma_maxima))
        {
            soma_maxima = soma_acumulada;
        }
        initK ++;
    }
    printf("%ld\n", soma_maxima);

    /* Liberação da array alocado */
    free(conteudo_array);
    return 0;
}
