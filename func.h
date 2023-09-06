#ifndef FUNC
#define FUNC
#include <stdbool.h>

typedef struct
{
    int x0;
    int y0;
    int x1;
    int y1;
}coordenadas;

typedef struct 
{
    int l;
    int c;    
}dimensoes;

typedef struct 
{
    char** mat;
    char* frase;
    bool achou;
    bool continuar;
}achaPalavras;

dimensoes leDimensoes();
char** alocaMatriz(dimensoes dimensao);
char* alocaVetor(dimensoes dimensao);
char* leFrase(char* vet, dimensoes dimensao);
char* tiraEspacos(char* vet, dimensoes dimensao);
char** colocaFraseNaMatriz(char** mat, char* vet, dimensoes dimensao);
void mostraMatriz(char** mat, dimensoes dimensao);
bool acharPrimeiraLetra(char l1, char l2);
bool procuraHorizontal(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraHorizontalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraVertical(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraVerticalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraDiagonalPrincipal(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraDiagonalPrincipalInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraDiagonalSecundaria(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraDiagonalSecundariaInversa(char** mat, char* frase, dimensoes dimensao, bool result, coordenadas* coordenada);
bool procuraPalavra(char** mat, char* vet, dimensoes dimensao, coordenadas* coordenada);
int menor(dimensoes dimensao);
void mostraPosicao(char* frase,coordenadas coordenada);
bool querContinuar();

#endif