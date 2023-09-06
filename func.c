#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include <stdbool.h>

dimensoes leDimensoes()
{
    dimensoes dimensao;
    printf("\nQuantas linhas: ");
    scanf("%d", &dimensao.l);
    printf("\nQuantas colunas: ");
    scanf("%d", &dimensao.c);
    return dimensao;
}

char** alocaMatriz(dimensoes dimensao)
{
    char** mat;
    mat = (char**) malloc(dimensao.l*sizeof(char*));
    for (int i = 0; i < dimensao.l; i++)
    {
        mat[i] = (char*) malloc(dimensao.c*sizeof(char));
    }
    return mat;
}

char* alocaVetor(dimensoes dimensao)
{
    char* vet;
    vet = (char*) malloc(dimensao.l*dimensao.c*sizeof(char));
    return vet;
}

char* leFrase(char* vet, dimensoes dimensao)
{
    int nCarac = dimensao.l*dimensao.c;
    printf("\nDigite uma frase com %d caracteres: ",nCarac);
    scanf(" %[^\n]s", vet);
    return vet;
}

char* tiraEspacos(char* vet, dimensoes dimensao)
{
    char* vetAux;
    int i,j;
    j = 0;
    vetAux = alocaVetor(dimensao);
    
    int nCarac = dimensao.l*dimensao.c;
    for (int i = 0; i < nCarac; i++)
    {
        vetAux[i] = ' ';
    }
    for (i = 0; i < nCarac; i++)
    {
        if (vet[i+j] == ' ')
            j++;
        if (vet[i+j] == '\0')
            break;
        vetAux[i] = vet[i+j];
    }
    return vetAux;
}

char** colocaFraseNaMatriz(char** mat, char* vet, dimensoes dimensao)
{
    for (int i = 0; i < dimensao.l; i++)
    {
        for (int j = 0; j < dimensao.c; j++)
        {
            int k = i*dimensao.c+j;
            mat[i][j] = vet[k];
        }
    }
    return mat;
}

void mostraMatriz(char** mat, dimensoes dimensao)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < dimensao.l; i++)
    {
        for (j = 0; j < dimensao.c; j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

bool acharPrimeiraLetra(char l1, char l2)
{
    return l1 == l2;    
}

void coordenadaDaUltimaLetra(coordenadas* coordenada, int numY, int numX)
{
    coordenada->y1 = coordenada->y0 + numY;
    coordenada->x1 = coordenada->x0 + numX;
}

bool procuraHorizontal(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->x0, k=0; i < dimensao.c; i++,k++)
    {
        fraseAux[k] = mat[coordenada->y0][i];
    }
    if (strstr(fraseAux, frase) != NULL)
    {
        coordenadaDaUltimaLetra(coordenada, 0, tamFrase-1);
        return true;
    }
    return result;  
}

bool procuraHorizontalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->x0, k=0; i >= 0; i--,k++)
    {
        fraseAux[k] = mat[coordenada->y0][i];
    }
    if (strstr(fraseAux, frase) != NULL)
    {
        coordenadaDaUltimaLetra(coordenada, 0, 1-tamFrase);
        return true;
    }
    return result; 
}

bool procuraVertical(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0, k=0; i < dimensao.l; i++, k++)
    {
        fraseAux[k] = mat[i][coordenada->x0];
    }
    if (strstr(fraseAux, frase) != NULL)
    {
        coordenadaDaUltimaLetra(coordenada,tamFrase-1, 0);
        return true;
    } 
    return result;      
}

bool procuraVerticalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0,k=0; i >= 0; i--,k++)
    {
        fraseAux[k] = mat[i][coordenada->x0];
    }
    if (strstr(fraseAux, frase) != NULL)
    {
        coordenadaDaUltimaLetra(coordenada,1-tamFrase, 0);
        return true;
    }
    return result;      
}

bool procuraDiagonalPrincipal(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0, j = coordenada->x0, k = 0;i<dimensao.l && j<dimensao.c; i++,j++,k++)
    {
        fraseAux[k] = mat[i][j];
    }
    
    if (strstr(fraseAux, frase) != NULL )
    {
        coordenadaDaUltimaLetra(coordenada, tamFrase - 1, tamFrase-1);
        return true;
    }
    
    return result;
}

bool procuraDiagonalPrincipalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0, j = coordenada->x0, k = 0;i>=0 && j>=0; i--,j--,k++)
    {
        fraseAux[k] = mat[i][j];
    }

    if (strstr(fraseAux, frase) != NULL)
    {
        coordenadaDaUltimaLetra(coordenada, 1-tamFrase, 1-tamFrase);
        return true;
    }
    
    return result;
}

bool procuraDiagonalSecundaria(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0, j = coordenada->x0, k = 0;i>=0 && j<dimensao.c; i--,j++,k++)
    {
        fraseAux[k] = mat[i][j];
    }
    
    if (strstr(fraseAux, frase) != NULL )
    {
        coordenadaDaUltimaLetra(coordenada, 1-tamFrase, tamFrase-1);
        return true;
    }
    
    return result;
}

bool procuraDiagonalSecundariaInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada)
{
    int tamFrase = strlen(frase);
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = coordenada->y0, j = coordenada->x0, k = 0;i<dimensao.l && j>=0; i++,j--,k++)
    {
        fraseAux[k] = mat[i][j];
    }
    
    if (strstr(fraseAux, frase) != NULL )
    {
        coordenadaDaUltimaLetra(coordenada, tamFrase-1, 1-tamFrase);
        return true;
    }
    
    return result;
}

bool procuraPalavra(char** mat, char* vet, dimensoes dimensao, coordenadas* coordenada)
{
    bool result = false;
    for (int i = 0; i < dimensao.l; i++)
    {
        for (int j = 0; j < dimensao.c; j++)
        {
            if (acharPrimeiraLetra(mat[i][j],vet[0]))
            {
                coordenada->y0 = i;
                coordenada->x0 = j;
                result = procuraHorizontal(mat,vet, dimensao, result, coordenada);
                result = procuraHorizontalInversa(mat,vet, dimensao, result, coordenada);
                result = procuraVertical(mat, vet, dimensao, result, coordenada);
                result = procuraVerticalInversa(mat, vet, dimensao, result, coordenada);
                result = procuraDiagonalPrincipal(mat, vet, dimensao, result, coordenada);
                result = procuraDiagonalPrincipalInversa(mat, vet, dimensao, result, coordenada);
                result = procuraDiagonalSecundaria(mat, vet, dimensao, result, coordenada);
                result = procuraDiagonalSecundariaInversa(mat, vet, dimensao, result, coordenada);
                if (result)
                    return result;          
            }
        }
    }
    return result;
}

void mostraPosicao(char* frase,coordenadas coordenada)
{
    printf("A frase %s inicia na posicao [%d,%d] e termina na posicao [%d,%d]",frase, coordenada.y0+1,coordenada.x0+1,
    coordenada.y1+1,coordenada.x1+1);
}

bool querContinuar()
{
    char resp;
    printf("\nQuer continuar procurando[s|n]: ");
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S')
        return true;
    return false;
    
}
