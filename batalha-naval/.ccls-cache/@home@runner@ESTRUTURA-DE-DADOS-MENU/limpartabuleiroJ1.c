#include <stdio.h>

#define TAM 15

void limparmatriz(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}