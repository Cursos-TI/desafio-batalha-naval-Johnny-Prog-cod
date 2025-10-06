#include<stdio.h>

int main(){

    int tabuleiro[10][10];
    int sequencia = 1;

    // Definição do Tabuleiro
    for(int linha = 0; linha < 10; linha++) {
        for(int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Tamanho do Navio
    int tamNavio = 3;

    // Coordenadas 1° Navio Horizintal
    int linhaHor = 1;
    int colunaHor = 0;

    // Verifica se cabe no tabuleiro
    if (colunaHor + tamNavio <= 10) {
        // Posiciona navio horizontal
        for (int i = 0; i < tamNavio; i++) {
            tabuleiro[linhaHor][colunaHor + i] = 1;
        }
    } else {
        printf("Fora do limite do tabuleiro.\n");
        sequencia = 0;
    }

    // Coordenadas 2° Navio Vertical
    int linhaVert = 4;
    int colunaVert = 6;

    // Verifica se cabe no tabuleiro e se não há sobreposição
    if (linhaVert + tamNavio <= 10) {
        for (int i = 0; i < tamNavio; i++) {
            if (tabuleiro[linhaVert + i][colunaVert] != 0) {
                printf("Navio sobrepoe o outro.\n");
                sequencia = 0;
                break;
            }
        }

        // Se tudo certo, posiciona
        if (sequencia) {
            for (int i = 0; i < tamNavio; i++) {
                tabuleiro[linhaVert + i][colunaVert] = 2;
            }
        }
    } else {
        printf("Fora do limite do tabuleiro.\n");
        sequencia = 0;
    }

    if (sequencia) {
    // Tabuleiro
        printf("\n*************************************************\n");
        printf("       Batalha Naval Tabuleiro 10x10 \n");
        printf("       Primeiro Navio representado por '1' \n");
        printf("       Segundo Navio representado por '2' \n");
        printf("\n*************************************************\n");
    // Exibe coordenadas da coluna
    printf("      ");
    for (int coluna = 0; coluna < 10; coluna++) {
        printf(" %d ", coluna);
    }
    printf("\n");

    printf("      ");
    for (int coluna = 0; coluna < 10; coluna++) {
        printf(" c ");
    }
    printf("\n");

    printf("      ");
    for (int coluna = 0; coluna < 10; coluna++) {
        printf("___");
    }
    printf("\n");

    // Exibe o tabuleiro com coordenadas de linha
    for (int linha = 0; linha < 10; linha++) {
        printf(" %d l |", linha);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    }

    return 0;
}