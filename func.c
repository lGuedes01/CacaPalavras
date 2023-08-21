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
    for (i = 0; i < nCarac; i++)
    {
        if (vet[i+j] == ' ')
            j++;
        vetAux[i] = vet[i+j];
        if (vet[i+j] == '\0')
        {
            break;
        }
        
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
    for (int i = 0; i < dimensao.l; i++)
    {
        for (int j = 0; j < dimensao.c; j++)
        {
            if (mat[i][j] == '\0')
                break;
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

bool acharPrimeiraLetra(char l1, char l2)
{
    if (l1 == l2)
        return true;
    return false;
    
}

int procuraVertical(int col, char** mat, char* frase, dimensoes dimensao, int result)
{
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    for (int i = 0; i < dimensao.l; i++)
    {
        fraseAux[i] = mat[i][col];
    }
    if (strstr(fraseAux, frase) != NULL)
        result = 1;
    if (strstr(strrev(fraseAux), frase) != NULL)
        result = 2;
    return result;      
}

int procuraHorizontal(int lin, char** mat, char* frase, dimensoes dimensao, int result)
{
    char* fraseAux;
    fraseAux = alocaVetor(dimensao);
    strcpy(fraseAux, mat[lin]);
    if (strstr(fraseAux, frase) != NULL)
        result = 3;
    if (strstr(strrev(fraseAux), frase) != NULL)
        result = 4;
    return result;  
}

int procuraPalavra(char** mat, char* vet, dimensoes dimensao)
{
    int result = 0;
    for (int i = 0; i < dimensao.l; i++)
    {
        for (int j = 0; j < dimensao.c; j++)
        {
            if (acharPrimeiraLetra(mat[i][j],vet[0]))
            {
                result = procuraVertical(j, mat, vet, dimensao, result);
                result = procuraHorizontal(i, mat,vet, dimensao, result);
                // result = procuraDiagonal();
                if (result)
                    return result;
                
            }
        }
    }
    return result;
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
