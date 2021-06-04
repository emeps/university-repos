#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "Image.h"

int imageUploaded = 0;

int menu();

void pausa();

int main()
{
    Image pnm;
    int option;
    char saveImg;
    do
    {
        system("clear");
        option = menu();
        switch (option)
        {
        case 1:
            open(&pnm);
            printf("Image successfully opened!\n");
            imageUploaded = 1;
            pausa();
            break;
        case 2:
            save(&pnm);
            printf("Image saved successfully!\n");
            pausa();
            break;
        case 3:
            darken(&pnm);
            printf("Darkened image.\n");
            pausa();
            break;
        case 4:
            lighten(&pnm);
            printf("Brightened image\n");
            pausa();
            break;
        case 5:
            sobel(&pnm);
            printf("Sobel filter applied to the image\n");
            pausa();
            break;
        case 6:
            laplace(&pnm);
            printf("Laplace filter applied to the image\n");
            pausa();
            break;
        case 7:
            if (imageUploaded == 1)
            {
                do
                {
                    getc(stdin);
                    printf("Do you want to save the image [Y/N]? ");
                    scanf("%c", &saveImg);
                } while (saveImg != 'y' && saveImg != 'Y' && saveImg != 'n' && saveImg != 'N');
                if (saveImg == 'y' || saveImg == 'Y')
                    save(&pnm);
                printf("Image saved successfully!\n");
                pausa();
            }
            break;
        }
    } while (option != 7);
}

int menu()
{

    printf("\n+-----------------------------------+");
    printf("\n|            Options menu           |");
    printf("\n+-----------------------------------+");
    printf("\n|                                   |");
    printf("\n|  Open........................[1]  |");
    if (imageUploaded == 1)
    {
        printf("\n|  Save........................[2]  |");
        printf("\n|  Darken Image................[3]  |");
        printf("\n|  Lighten Image...............[4]  |");
        printf("\n|  Sobel Filter................[5]  |");
        printf("\n|  Laplace Filter..............[6]  |");
    }
    printf("\n|  quit........................[7]  |");
    printf("\n|                                   |");
    printf("\n+-----------------------------------+");
    int option;
    if (imageUploaded == 1)
    {
        do
        {
            printf("\nWhich option? ");
            scanf("%d", &option);
        } while (option < 1 || option > 7);
    }
    else
    {
        do
        {
            printf("\nWhich option? ");
            scanf("%d", &option);
        } while (option != 1 && option != 7);
    }
    return option;
}

void pausa()
{
    printf("Press enter to continue ...");
    fflush(stdin);
    getc(stdin);
    getchar();
}
