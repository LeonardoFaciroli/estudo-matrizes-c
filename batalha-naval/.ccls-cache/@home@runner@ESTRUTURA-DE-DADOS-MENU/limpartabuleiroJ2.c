#include <stdio.h>
void limparmatriz(char tabuleiroJ2[15][15]){
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++){
      tabuleiroJ2[i][j] = ' ';
      }
    }
}