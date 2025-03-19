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
    int naviod1_linha = 1, naviod1_coluna = 1;
    int naviod2_linha = 1, naviod2_coluna =  8;
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

    // Colocando o diagonal1
    for (int k = 0; k < tamanho_navio ; k++){
        if (naviod1_linha + k <10 && naviod1_coluna + k < 10){
            tabuleiro[naviod1_linha + k][naviod1_coluna + k] = 3;
        } 
    }
    
    // Colocando o diagonal2
    for (int l = 0; l < tamanho_navio ; l++){
        if (naviod2_linha + l < 10 && naviod2_coluna - l >= 0){
            tabuleiro[naviod2_linha + l][naviod2_coluna - l] = 3;
        }
    }
    
    // Habilidades
    int origem_cone_linha = 6, origem_cone_coluna = 5;
    int origem_cruz_linha = 4, origem_cruz_coluna = 4;
    int origem_octaedro_linha = 7, origem_octaedro_coluna = 7;
    
    // Habilidade Cone
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (origem_cone_linha + i < 10 && origem_cone_coluna + j >= 0 && origem_cone_coluna + j < 10) {
                tabuleiro[origem_cone_linha + i][origem_cone_coluna + j] = 5;
            }
        }
    }
    
    // Habilidade Cruz
    for (int i = -2; i <= 2; i++) {
        if (origem_cruz_linha + i >= 0 && origem_cruz_linha + i < 10) {
            tabuleiro[origem_cruz_linha + i][origem_cruz_coluna] = 5;
        }
        if (origem_cruz_coluna + i >= 0 && origem_cruz_coluna + i < 10) {
            tabuleiro[origem_cruz_linha][origem_cruz_coluna + i] = 5;
        }
    }
    
    // Habilidade Octaedro
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++){
            if ((i + j >= -2 && i + j <= 2) && (i - j >= -2 && i - j <= 2)) {
                if (origem_octaedro_linha + i >= 0 && origem_octaedro_linha + i < 10 &&
                        origem_octaedro_coluna + j >= 0 && origem_octaedro_coluna + j < 10) {
                            tabuleiro[origem_octaedro_linha + i][origem_octaedro_coluna + j] = 5;
                }
            }
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
