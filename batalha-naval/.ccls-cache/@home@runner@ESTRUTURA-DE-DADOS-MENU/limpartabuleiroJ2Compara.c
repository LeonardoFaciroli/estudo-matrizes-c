#include <stdio.h>
void limparmatriz(char tabuleiroCompara2[15][15]){
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++){
      tabuleiroCompara2[i][j] = ' ';
      }
    }
}