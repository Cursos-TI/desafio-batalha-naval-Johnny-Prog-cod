#include <stdio.h>

int posNavio(int tabuleiro[10][10], int linha, int coluna, int tam, int direcao, int idNavio) {
    // direcao: 0 = horizontal, 1 = vertical, 2 = diagonal, 3 = diagonal

    for (int i = 0; i < tam; i++) {
        int l = linha, c = coluna;

        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        if (l < 0 || l >= 10 || c < 0 || c >= 10 || tabuleiro[l][c] != 0) {
            return 0; // Fora do limite ou sobreposição
        }
    }

    // Posiciona
    for (int i = 0; i < tam; i++) {
        int l = linha, c = coluna;

        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        tabuleiro[l][c] = idNavio;
    }

    return 1; // Sucesso
}

int main() {
    int tabuleiro[10][10];
    int sequencia = 1;
    int tamNavio = 3;

    // Inicializa o tabuleiro
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Posiciona os navios
    // Tabuleiro: l, c
    // TamNavio: ID Navio, Numero que ele representa no tabuleiro
    sequencia = posNavio(tabuleiro, 5, 0, tamNavio, 0, 1); // Navio Horizontal
    if (sequencia) sequencia = posNavio(tabuleiro, 4, 6, tamNavio, 1, 2); // Navio Vertical
    if (sequencia) sequencia = posNavio(tabuleiro, 2, 2, tamNavio, 2, 3); // Navio Diagonal 
    if (sequencia) sequencia = posNavio(tabuleiro, 0, 9, tamNavio, 3, 4); // Navio Diagonal 

    if (sequencia) {
        printf("\n*************************************************\n");
        printf("       Batalha Naval Tabuleiro 10x10 \n");
        printf("       Navio 1: Horizontal (1)\n");
        printf("       Navio 2: Vertical (2)\n");
        printf("       Navio 3: Diagonal (3)\n");
        printf("       Navio 4: Diagonal (4)\n");
        printf("*************************************************\n");

        // Cabeçalho
        printf("      ");
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", coluna);
        }
        printf("\n      ");
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" c ");
        }
        printf("\n      ");
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("___");
        }
        printf("\n");

        // Tabuleiro
        for (int linha = 0; linha < 10; linha++) {
            printf(" %d l |", linha);
            for (int coluna = 0; coluna < 10; coluna++) {
                printf(" %d ", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }
    } else {
        printf("\nErro ao posicionar os navios. Verifique limites e sobreposições.\n");
    }

    return 0;
}