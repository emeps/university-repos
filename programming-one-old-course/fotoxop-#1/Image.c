#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "Image.h"

void laplace(Image *pnm)
{
    int i, j, coefficientLaplace;

    Image *copyImage = malloc(sizeof(Image));
    copyImage = copy(pnm);
    for (i = 1; i < pnm->heightImagem - 1; i++)
    {
        for (j = 1; j < pnm->widthImagem - 1; j++)
        {
            coefficientLaplace = copyImage->matrixPixel[i - 1][j] * (-1) +
                                 copyImage->matrixPixel[i][j - 1] * (-1) +
                                 copyImage->matrixPixel[i][j] * (4) +
                                 copyImage->matrixPixel[i][j + 1] * (-1) +
                                 copyImage->matrixPixel[i + 1][j] * (-1);
            if (coefficientLaplace > 255)
            {
                pnm->matrixPixel[i][j] = 255;
            }
            if (coefficientLaplace < 0)
            {
                pnm->matrixPixel[i][j] = 0;
            }
            else
            {
                pnm->matrixPixel[i][j] = coefficientLaplace;
            }
        }
    }
}

void darken(Image *pnm)
{
    int i, j, dimmingFactor;
    do
    {
        printf("Enter a value to darken the image (0 - 255):\t");
        printf("\n");
        scanf("%d", &dimmingFactor);
    } while (dimmingFactor < 0 || dimmingFactor > 255);
    for (i = 0; i < pnm->heightImagem; i++)
    {
        for (j = 0; j < pnm->widthImagem; j++)
        {
            if ((pnm->matrixPixel[i][j] - dimmingFactor < 0))
            {
                pnm->matrixPixel[i][j] = 0;
            }
            else
            {
                pnm->matrixPixel[i][j] = pnm->matrixPixel[i][j] - dimmingFactor;
            }
        }
    }
}

void lighten(Image *pnm)
{
    int i, j, lighteningFactor;
    do
    {
        printf("Enter a value to brighten the image (0 - 255):\t");
        printf("\n");
        scanf("%d", &lighteningFactor);
    } while (lighteningFactor < 0 || lighteningFactor > 255);
    for (i = 0; i < pnm->heightImagem; i++)
    {
        for (j = 0; j < pnm->widthImagem; j++)
        {
            if ((pnm->matrixPixel[i][j] + lighteningFactor > 255))
            {
                pnm->matrixPixel[i][j] = 255;
            }
            else
            {
                pnm->matrixPixel[i][j] = pnm->matrixPixel[i][j] + lighteningFactor;
            }
        }
    }
}

void save(Image *pnm)
{
    int i, j;
    FILE *arq;
    char namePNM[50];
    printf("Enter the file name to save the image:\t");
    printf("\n");
    scanf("%s", namePNM);

    arq = fopen(namePNM, "w");
    if (arq == NULL)
    {
        printf("Could not open the file %s\n", namePNM);
        exit(1);
    }

    fprintf(arq, "%s\n", pnm->typeImagem);
    fprintf(arq, "%s\n", pnm->comentImagem);
    fprintf(arq, "%d %d\n %d\n", pnm->widthImagem, pnm->heightImagem, pnm->maxPixel);

    for (i = 0; i < pnm->heightImagem; i++)
    {
        for (j = 0; j < pnm->widthImagem; j++)
        {
            fprintf(arq, "%d\n", pnm->matrixPixel[i][j]);
        }
    }
    fclose(arq);
    printf("Image saved successfully.\n");
}

void open(Image *pnm)
{
    int i, j;
    char namePNM[10];

    printf("Enter the file name PNM: ");
    scanf("%s", namePNM);

    FILE *arq = fopen(namePNM, "r");
    if (arq == NULL)
    {
        printf("Could not open the file %s\n", namePNM);
        exit(1);
    }
    printf("Image name: %s\n", namePNM);
    fscanf(arq, "%3[^\n]s", pnm->typeImagem);
    if (strcmp(pnm->typeImagem, "P2") != 0)
    {
        printf("Invalid image format (must be 'P2')\n");
        exit(1);
    }
    printf("Image type: %s\n", pnm->typeImagem); 
    fgetc(arq);

    fscanf(arq, "%200[^\n]s", pnm->comentImagem);
    fgetc(arq);
    printf("Comment: %s\n", pnm->comentImagem); 

    fscanf(arq, "%d %d %d", &pnm->widthImagem, &pnm->heightImagem, &pnm->maxPixel);
    printf("Width = %d; Height = %d; Pixel = %d;\n", pnm->widthImagem, pnm->heightImagem, pnm->maxPixel); 

    if (pnm->widthImagem > 719 || pnm->heightImagem > 719)
    {
        printf("Very large figure!");
        exit(1);
    }

    for (i = 0; i < pnm->heightImagem; i++)
    {
        for (j = 0; j < pnm->widthImagem; j++)
        {
            fscanf(arq, "%d", &pnm->matrixPixel[i][j]);
        }
    }
    fclose(arq);
}

Image *copy(Image *pnm)
{
    int i, j;
    Image *copyImage = malloc(sizeof(Image));
    strcpy(copyImage->typeImagem, pnm->typeImagem);
    strcpy(copyImage->comentImagem, pnm->comentImagem);
    copyImage->widthImagem = pnm->widthImagem;
    copyImage->heightImagem = pnm->heightImagem;
    copyImage->maxPixel = pnm->maxPixel;

    for (i = 0; i < copyImage->heightImagem; i++)
    {
        for (j = 0; j < copyImage->widthImagem; j++)
        {
            copyImage->matrixPixel[i][j] = pnm->matrixPixel[i][j];
        }
    }
    return copyImage;
}

void sobel(Image *pnm)
{
    int i, j, sobelX, sobelY, valor;
    Image *copyImage = malloc(sizeof(Image));
    copyImage = copy(pnm);
    for (i = 1; i < pnm->heightImagem - 1; i++)
    {
        for (j = 1; j < pnm->widthImagem - 1 ; j++)
        {
            sobelY = copyImage->matrixPixel[i - 1][j - 1] * (1) + copyImage->matrixPixel[i - 1][j] * (2) + copyImage->matrixPixel[i - 1][j + 1] * (1) +
                 0 + 0 + 0 +
                 copyImage->matrixPixel[i + 1][j - 1] * (-1) + copyImage->matrixPixel[i + 1][j] * (-2) + copyImage->matrixPixel[i + 1][j + 1] * (-1);
            sobelX = copyImage->matrixPixel[i - 1][j - 1] * (1) + 0 + copyImage->matrixPixel[i - 1][j + 1] * (-1) +
                 copyImage->matrixPixel[i][j - 1] * (2) + 0 + copyImage->matrixPixel[i][j + 1] * (-2) +
                 copyImage->matrixPixel[i + 1][j - 1] * (1) + 0 + copyImage->matrixPixel[i + 1][j + 1] * (-1);
            valor = (sobelX + sobelY) / 2;
            if (valor > 255)
            {
                pnm->matrixPixel[i][j] = 255;
            }
            if (valor < 0)
            {
                pnm->matrixPixel[i][j] = 0;
            }
            else
            {
                pnm->matrixPixel[i][j] = valor;
            }
        }
    }
    save(pnm);
    free(copyImage);
}
