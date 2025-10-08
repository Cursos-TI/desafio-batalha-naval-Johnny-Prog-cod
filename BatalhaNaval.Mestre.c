#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tamTab 10
#define linCone 3
#define colCone 5
#define linCruz 3
#define colCruz 5
#define tamOct 3

// Posiciona navio no tabuleiro
int posNavio(int tabuleiro[tamTab][tamTab], int linha, int coluna, int tam, int direcao) {
    for (int i = 0; i < tam; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        if (l < 0 || l >= tamTab || c < 0 || c >= tamTab || tabuleiro[l][c] != 0) {
            return 0;
        }
    }

    for (int i = 0; i < tam; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        tabuleiro[l][c] = 3;
    }

    return 1;
}

// Construir matriz Cone 3x5
void construirCone(int matriz[linCone][colCone]) {
    for (int i = 0; i < linCone; i++) {
        for (int j = 0; j < colCone; j++) {
            if (i == 0)
                matriz[i][j] = (j == 2) ? 1 : 0;
            else if (i == 1)
                matriz[i][j] = (j >= 1 && j <= 3) ? 1 : 0;
            else
                matriz[i][j] = 1;
        }
    }
}

// Construir matriz Cruz 3x5
void construirCruz(int matriz[linCruz][colCruz]) {
    int centroL = linCruz / 2;
    int centroC = colCruz / 2;
    for (int i = 0; i < linCruz; i++) {
        for (int j = 0; j < colCruz; j++) {
            matriz[i][j] = (i == centroL || j == centroC) ? 1 : 0;
        }
    }
}

// Construir matriz Octaedro 3x3
void construirOctaedro(int matriz[tamOct][tamOct]) {
    int centro = tamOct / 2;
    for (int i = 0; i < tamOct; i++) {
        for (int j = 0; j < tamOct; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            matriz[i][j] = (distancia <= 1) ? 1 : 0;
        }
    }
}

// Aplicar matriz genérica no tabuleiro
void aplicarMatriz(int tabuleiro[tamTab][tamTab], int linhas, int colunas, int matriz[linhas][colunas], int origemLinha, int origemColuna) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int l = origemLinha - linhas / 2 + i;
            int c = origemColuna - colunas / 2 + j;

            if (l >= 0 && l < tamTab && c >= 0 && c < tamTab && matriz[i][j] == 1 && tabuleiro[l][c] != 3) {
                tabuleiro[l][c] = 5;
            }
        }
    }
}

// Imprimir matriz de habilidade
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas], const char* nome) {
//  printf("\nExemplo de saída de habilidade em %s:\n\n", nome);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
//          printf(" %d ", matriz[i][j] == 1 ? 3 : 0);
        }
//      printf("\n");
    }
}

// Imprimir tabuleiro
void imprimirTabuleiro(int tabuleiro[tamTab][tamTab]) {
    printf("\n      ");
    for (int c = 0; c < tamTab; c++) printf(" %d ", c);
    printf("\n      ");
    for (int c = 0; c < tamTab; c++) printf(" c ");
    printf("\n      ");
    for (int c = 0; c < tamTab; c++) printf("___");
    printf("\n");

    for (int l = 0; l < tamTab; l++) {
        printf(" %d l |", l);
        for (int c = 0; c < tamTab; c++) {
            if (tabuleiro[l][c] == 0) printf(" 0 ");
            else if (tabuleiro[l][c] == 3) printf(" 3 ");
            else if (tabuleiro[l][c] == 5) printf(" 5 ");
            else printf(" ? ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[tamTab][tamTab] = {0};
    int sucesso = 1;

    // Posiciona navios
    // Tabuleiro( Linha, Coluna, Tamanho do navio, ID )
    sucesso = posNavio(tabuleiro, 9, 3, 3, 0); // Horizontal
    if (sucesso) sucesso = posNavio(tabuleiro, 2, 0, 3, 1); // Vertical
    if (sucesso) sucesso = posNavio(tabuleiro, 7, 0, 3, 2); // Diagonal
    if (sucesso) sucesso = posNavio(tabuleiro, 0, 4, 3, 3); // Diagonal

    if (!sucesso) {
        printf("\nErro ao posicionar os navios.\n");
        return 1;
    }

    // Matrizes de habilidade
    int cone[linCone][colCone], cruz[linCruz][colCruz], octaedro[tamOct][tamOct];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    imprimirMatriz(linCone, colCone, cone, "cone");
    imprimirMatriz(linCruz, colCruz, cruz, "cruz");
    imprimirMatriz(tamOct, tamOct, octaedro, "octaedro");

    // Aplicar habilidades no tabuleiro
    aplicarMatriz(tabuleiro, linCone, colCone, cone, 2, 6);
    aplicarMatriz(tabuleiro, linCruz, colCruz, cruz, 6, 3);
    aplicarMatriz(tabuleiro, tamOct, tamOct, octaedro, 7, 7);

    // Exibir tabuleiro final
    printf("\n*************************************************\n");
    printf("       Batalha Naval com Habilidades Especiais\n");
    printf("       Navio: 3 | Água: 0 | Habilidade: 5\n");
    printf("*************************************************\n");

    imprimirTabuleiro(tabuleiro);

    return 0;
}