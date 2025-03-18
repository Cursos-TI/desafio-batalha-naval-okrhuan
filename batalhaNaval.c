#include <stdio.h>

int main() {
    // Variáveis
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];
    
    // Tabuleiro cheio de água -- 0
    // Inicia todas as células com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Coordenadas dos navios
    int navioh_linha = 2, navioh_coluna = 3; // Navio horizontal
    int naviov_linha = 5, naviov_coluna = 7; // Navio vertical
    int tamanho_navio = 3;
    
    // Colocando o horizontal
    for (int j = 0; j < tamanho_navio; j++) {
        if (navioh_coluna + j < 10) {
            tabuleiro[navioh_linha][navioh_coluna + j] = 3;
        }
    }
    
    // Colocando o vertical
    for (int i = 0; i < tamanho_navio; i++) {
        if (naviov_linha + i < 10) {
            tabuleiro[naviov_linha + i][naviov_coluna] = 3;
        }
    }
    
    // Exibindo o tabuleiro
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
