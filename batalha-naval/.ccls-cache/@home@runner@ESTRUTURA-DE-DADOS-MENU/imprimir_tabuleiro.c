void imprimir_tabuleiro(char tabuleiroJ1 [15][15]){
  printf("[X] ""[1]""[2]""[3]""[4]""[5]""[6]""[7]""[8]""[9]""[10]""[11]""[12]""[13]""[14]""[15]");
      printf("\n");

      char letra = 'A';
      for (int i = 0; i < 15; i++) {
        printf("[%c] ", letra);
        letra++;

        for (int j = 0; j < 15; j++) {
          if(j >= 9){
          printf("[%2c]", tabuleiroJ1 [i][j]);}else{
  printf("[%c]", tabuleiroJ1 [i][j]);

          }
        }
        printf("\n");
      }
}
