#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Imagem.h"
#include "Filtros.h"

void escurecerImagem(Imagem *img)
{
    int v;
    printf("Digite o fator de escurecimento (0-255): ");
    scanf("%d", &v);

    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {
            Pixel pixel = obtemPixel(img, h, w);
            pixel.cor[RED] = (((int)pixel.cor[RED] - v) >= 0 ? (pixel.cor[RED] - v) : 0);
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] - v) >= 0 ? (pixel.cor[GREEN] - v) : 0);
            pixel.cor[BLUE] = (((int)pixel.cor[BLUE] - v) >= 0 ? (pixel.cor[BLUE] - v) : 0);
            recolorePixel(img, h, w, pixel);
        }
    }
}

void clarearImagem(Imagem *img)
{
    int v;
    printf("Digite o fator de clareamento (0-255): ");
    scanf("%d", &v);
    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {
            Pixel pixel = obtemPixel(img, h, w);
            pixel.cor[RED] = (((int)pixel.cor[RED] + v) > 255 ? 255 : (pixel.cor[RED] + v));
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] + v) > 255 ? 255 : (pixel.cor[GREEN] + v));
            pixel.cor[BLUE] = (((int)pixel.cor[BLUE] + v) > 255 ? 255 : (pixel.cor[BLUE] + v));
            recolorePixel(img, h, w, pixel);
        }
    }
}

void escalaDeCinzaImagem(Imagem *img)
{
    int media;
    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {
            Pixel pixel = obtemPixel(img, h, w);
            media = ((int)pixel.cor[RED] + (int)pixel.cor[GREEN] + (int)pixel.cor[BLUE]) / 3;
            pixel.cor[RED] = media;
            pixel.cor[GREEN] = media;
            pixel.cor[BLUE] = media;
            recolorePixel(img, h, w, pixel);
        }
    }
}

void filtroSobel(Imagem *img)
{

    Imagem *copySobel = copiaImagem(img);

    for (int i = 1; i < obtemAltura(copySobel) - 1; i++)
    {
        for (int j = 1; j < obtemLargura(copySobel) - 1; j++)
        {
            int eixoXRED = 0, eixoYRED = 0, distanciaRED = 0;
            int eixoXGREEN = 0, eixoYGREEN = 0, distanciaGREEN = 0;
            int eixoXBLUE = 0, eixoYBLUE = 0, distanciaBLUE = 0;

            // Matriz Y

            Pixel pixel = obtemPixel(copySobel, i - 1, j - 1);
            eixoYRED += (int)pixel.cor[RED] * (1);
            eixoYGREEN += (int)pixel.cor[GREEN] * (1);
            eixoYBLUE += (int)pixel.cor[BLUE] * (1);

            pixel = obtemPixel(copySobel, i - 1, j);
            eixoYRED += (int)pixel.cor[RED] * (2);
            eixoYGREEN += (int)pixel.cor[GREEN] * (2);
            eixoYBLUE += (int)pixel.cor[BLUE] * (2);

            pixel = obtemPixel(copySobel, i - 1, j + 1);
            eixoYRED += (int)pixel.cor[RED] * (1);
            eixoYGREEN += (int)pixel.cor[GREEN] * (1);
            eixoYBLUE += (int)pixel.cor[BLUE] * (1);

            pixel = obtemPixel(copySobel, i + 1, j - 1);
            eixoYRED += (int)pixel.cor[RED] * (-1);
            eixoYGREEN += (int)pixel.cor[GREEN] * (-1);
            eixoYBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copySobel, i + 1, j);
            eixoYRED += (int)pixel.cor[RED] * (-2);
            eixoYGREEN += (int)pixel.cor[GREEN] * (-2);
            eixoYBLUE += (int)pixel.cor[BLUE] * (-2);

            pixel = obtemPixel(copySobel, i + 1, j + 1);
            eixoYRED += (int)pixel.cor[RED] * (-1);
            eixoYGREEN += (int)pixel.cor[GREEN] * (-1);
            eixoYBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copySobel, i - 1, j);
            eixoYRED += (int)pixel.cor[RED] * (0);
            eixoYGREEN += (int)pixel.cor[GREEN] * (0);
            eixoYBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copySobel, i, j);
            eixoYRED += (int)pixel.cor[RED] * (0);
            eixoYGREEN += (int)pixel.cor[GREEN] * (0);
            eixoYBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copySobel, i + 1, j);
            eixoYRED += (int)pixel.cor[RED] * (0);
            eixoYGREEN += (int)pixel.cor[GREEN] * (0);
            eixoYBLUE += (int)pixel.cor[BLUE] * (0);

            // Matriz X

            pixel = obtemPixel(copySobel, i - 1, j - 1);
            eixoXRED += (int)pixel.cor[RED] * (1);
            eixoXGREEN += (int)pixel.cor[GREEN] * (1);
            eixoXBLUE += (int)pixel.cor[BLUE] * (1);

            pixel = obtemPixel(copySobel, i - 1, j + 1);
            eixoXRED += (int)pixel.cor[RED] * (-1);
            eixoXGREEN += (int)pixel.cor[GREEN] * (-1);
            eixoXBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copySobel, i, j - 1);
            eixoXRED += (int)pixel.cor[RED] * (2);
            eixoXGREEN += (int)pixel.cor[GREEN] * (2);
            eixoXBLUE += (int)pixel.cor[BLUE] * (2);

            pixel = obtemPixel(copySobel, i, j + 1);
            eixoXRED += (int)pixel.cor[RED] * (-2);
            eixoXGREEN += (int)pixel.cor[GREEN] * (-2);
            eixoXBLUE += (int)pixel.cor[BLUE] * (-2);

            pixel = obtemPixel(copySobel, i + 1, j - 1);
            eixoXRED += (int)pixel.cor[RED] * (1);
            eixoXGREEN += (int)pixel.cor[GREEN] * (1);
            eixoXBLUE += (int)pixel.cor[BLUE] * (1);

            pixel = obtemPixel(copySobel, i + 1, j + 1);
            eixoXRED += (int)pixel.cor[RED] * (-1);
            eixoXGREEN += (int)pixel.cor[GREEN] * (-1);
            eixoXBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copySobel, i, j - 1);
            eixoXRED += (int)pixel.cor[RED] * (0);
            eixoXGREEN += (int)pixel.cor[GREEN] * (0);
            eixoXBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copySobel, i, j);
            eixoXRED += (int)pixel.cor[RED] * (0);
            eixoXGREEN += (int)pixel.cor[GREEN] * (0);
            eixoXBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copySobel, i, j + 1);
            eixoXRED += (int)pixel.cor[RED] * (0);
            eixoXGREEN += (int)pixel.cor[GREEN] * (0);
            eixoXBLUE += (int)pixel.cor[BLUE] * (0);

            distanciaRED = sqrt(pow(eixoYRED, 2) + pow(eixoXRED, 2));
            distanciaGREEN = sqrt(pow(eixoYGREEN, 2) + pow(eixoXGREEN, 2));
            distanciaBLUE = sqrt(pow(eixoYBLUE, 2) + pow(eixoXBLUE, 2));

            // distanciaRED = (eixoYRED + eixoXRED)/2;
            // distanciaGREEN = (eixoYGREEN + eixoXGREEN)/2;
            // distanciaBLUE = (eixoYBLUE + eixoXBLUE)/2;

            // Canal vermelho
            if (distanciaRED > 255)
            {

                pixel.cor[RED] = 255;
            }
            else if (distanciaRED < 0)
            {

                pixel.cor[RED] = 0;
            }
            else
            {

                pixel.cor[RED] = distanciaRED;
            }

            // Canal verde
            if (distanciaGREEN > 255)
            {

                pixel.cor[GREEN] = 255;
            }
            else if (distanciaGREEN < 0)
            {

                pixel.cor[GREEN] = 0;
            }
            else
            {

                pixel.cor[GREEN] = distanciaGREEN;
            }

            // Canal azul
            if (distanciaBLUE > 255)
            {

                pixel.cor[BLUE] = 255;
            }
            else if (distanciaBLUE < 0)
            {

                pixel.cor[BLUE] = 0;
            }
            else
            {

                pixel.cor[BLUE] = distanciaBLUE;
            }
            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(copySobel);
}

void deteccaoBordasLaplace(Imagem *img)
{
    Imagem *copyImagem = copiaImagem(img);

    for (int i = 1; i < obtemAltura(copyImagem) - 1; i++)
    {
        for (int j = 1; j < obtemLargura(copyImagem) - 1; j++)
        {
            int modificadorLaplacianoRED = 0, modificadorLaplacianoGREEN = 0, modificadorLaplacianoBLUE = 0;

            Pixel pixel = obtemPixel(copyImagem, i, j);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (4);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (4);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (4);

            pixel = obtemPixel(copyImagem, i - 1, j);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (-1);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (-1);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copyImagem, i, j - 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (-1);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (-1);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copyImagem, i, j + 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (-1);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (-1);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copyImagem, i + 1, j);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (-1);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (-1);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (-1);

            pixel = obtemPixel(copyImagem, i + 1, j + 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (0);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (0);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copyImagem, i - 1, j - 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (0);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (0);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copyImagem, i + 1, j - 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (0);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (0);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (0);

            pixel = obtemPixel(copyImagem, i - 1, j + 1);
            modificadorLaplacianoRED += (int)pixel.cor[RED] * (0);
            modificadorLaplacianoGREEN += (int)pixel.cor[GREEN] * (0);
            modificadorLaplacianoBLUE += (int)pixel.cor[BLUE] * (0);

            if (modificadorLaplacianoRED >= 255)
            {
                pixel.cor[RED] = 255;
            }
            else if (modificadorLaplacianoRED <= 0)
            {
                pixel.cor[RED] = 0;
            }
            else
            {
                pixel.cor[RED] = modificadorLaplacianoRED;
            }

            if (modificadorLaplacianoGREEN >= 255)
            {
                pixel.cor[GREEN] = 255;
            }
            else if (modificadorLaplacianoGREEN <= 0)
            {
                pixel.cor[GREEN] = 0;
            }
            else
            {
                pixel.cor[GREEN] = modificadorLaplacianoGREEN;
            }

            if (modificadorLaplacianoBLUE >= 255)
            {
                pixel.cor[BLUE] = 255;
            }
            else if (modificadorLaplacianoBLUE <= 0)
            {
                pixel.cor[BLUE] = 0;
            }
            else
            {
                pixel.cor[BLUE] = modificadorLaplacianoBLUE;
            }
            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(copyImagem);
}

void meuFiltro(Imagem *img)
{
    Imagem *copySepia = copiaImagem(img);
    Pixel pixel;
    for (int i = 1; i < obtemAltura(copySepia) - 1; i++)
    {
        for (int j = 1; j < obtemLargura(copySepia) - 1; j++)
        {
            int sepRED = 0;
            int sepGREEN = 0;
            int sepBLUE = 0;
            pixel = obtemPixel(copySepia, i, j);
            sepRED += (int)pixel.cor[RED] * 0.769;
            sepGREEN += (int)pixel.cor[GREEN] * 0.686;
            sepBLUE += (int)pixel.cor[BLUE] * 0.534;

            pixel = obtemPixel(copySepia, i, j - 1);
            sepRED += (int)pixel.cor[RED] * 0.393;
            sepGREEN += (int)pixel.cor[GREEN] * 0.349;
            sepBLUE += (int)pixel.cor[BLUE] * 0.272;

            pixel = obtemPixel(copySepia, i, j + 1);
            sepRED += (int)pixel.cor[RED] * 0.189;
            sepGREEN += (int)pixel.cor[GREEN] * 0.168;
            sepBLUE += (int)pixel.cor[BLUE] * 0.131;

            // sepRED /= 3;
            // sepGREEN /= 3;
            // sepBLUE /= 3;

            if (sepRED > 255)
            {
                pixel.cor[RED] = 255;
            }
            else if (sepRED < 0)
            {
                pixel.cor[RED] = 0;
            }
            else
            {
                pixel.cor[RED] = sepRED;
            }
            if (sepGREEN > 255)
            {
                pixel.cor[GREEN] = 255;
            }
            else if (sepGREEN < 0)
            {
                pixel.cor[GREEN] = 0;
            }
            else
            {
                pixel.cor[GREEN] = sepGREEN;
            }
            if (sepBLUE > 255)
            {
                pixel.cor[BLUE] = 255;
            }
            else if (sepBLUE < 0)
            {
                pixel.cor[BLUE] = 0;
            }
            else
            {
                pixel.cor[BLUE] = sepBLUE;
            }
            recolorePixel(img, i, j, pixel);
        }
    }
    liberaImagem(copySepia);
}
