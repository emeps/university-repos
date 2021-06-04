#ifndef IMAGEM_H_INCLUDED
#define IMAGEM_H_INCLUDED

typedef struct{
    char typeImagem [3];
    char comentImagem [200];
    int widthImagem;
    int heightImagem;
    int maxPixel;
    int matrixPixel[719][719]; 
} Image;

Image *copy(Image *pnm);
void sobel(Image *pnm);
void laplace(Image *pnm);
void darken (Image *pnm); 
void lighten (Image *pnm); 
void save(Image *pnm); 
void open(Image *pnm); 


#endif // IMAGEM_H_INCLUDED
