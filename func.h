#ifndef FUNC
#define FUNC
#include <stdbool.h>

typedef struct 
{
    int l;
    int c;    
}dimensoes;

typedef struct 
{
    char** mat;
    char* frase;
    int achou;
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
int procuraVertical(int col, char** mat, char* frase, dimensoes dimensao, int result);
int procuraHorizontal(int lin, char** mat, char* frase, dimensoes dimensao, int result);
int procuraPalavra(char** mat, char* vet, dimensoes dimensao);
void mostraPosicao();
bool querContinuar();

#endif