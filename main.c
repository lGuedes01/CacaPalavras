#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include <stdbool.h>


int main()
{
    achaPalavras jogo;
    jogo.continuar = true;
    dimensoes dimensao;
    coordenadas coordenadaPalavra;
    dimensao = leDimensoes();
    jogo.mat = alocaMatriz(dimensao);
    jogo.frase = alocaVetor(dimensao);
    jogo.frase = leFrase(jogo.frase, dimensao);
    jogo.frase = tiraEspacos(jogo.frase, dimensao);
    jogo.mat = colocaFraseNaMatriz(jogo.mat, jogo.frase, dimensao);
    free(jogo.frase);
    while (jogo.continuar)
    {
        mostraMatriz(jogo.mat, dimensao);
        jogo.frase = alocaVetor(dimensao);
        jogo.frase = leFrase(jogo.frase, dimensao);
        jogo.achou = procuraPalavra(jogo.mat,jogo.frase,dimensao, &coordenadaPalavra);
        if (jogo.achou)
            mostraPosicao(jogo.frase,coordenadaPalavra);
            // printf("ACHOU\n");
        else
            printf("Nao tem essa palavra na matriz\n");
        jogo.continuar = querContinuar();
        free(jogo.frase);
    }
        system("pause");
    return 0;
}
