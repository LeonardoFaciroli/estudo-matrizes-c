#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int contJ1 = 0;
  int contJ2 = 0;
  int parar;
  printf("Você escolheu a opção P x P\n");
  char tabuleiroJ1[15][15];
  char tabuleiroJ2[15][15];
  char tabuleiroComp[15][15];
  char tabuleiroComp2[15][15];
  int linha, coluna;
  char letraMinuscula = 'a';
  char letraMaiuscula = toupper(letraMinuscula);
  char letraMaiusculaJ2;
  // PRECISO RESOLVER O PROBLEMA DE LETRAS MINÚSCULAS
  char nomeJ1[30];
  char nomeJ2[30];

  printf("Digite o nome do jogador 1:");
  scanf("%30s", &nomeJ1);
  limpar_buffer();
  printf("Digite o nome do jogador 2:");
  scanf("%30s", &nomeJ2);
  limpar_buffer();
  printf("|----------------------------------------------|\n");
  printf("| As regras são as seguintes:                  |\n");
  printf("| 1.O jogador %s", nomeJ1);
  printf(" que começa, ele sera o X|\n");
  printf("| 2.O jogador %s", nomeJ2);
  printf("   sera o Y             |\n");
  printf("| 3.Os jogadores ganham ao ABATER 5 navios     |\n");
  printf("|----------------------------------------------|\n");
  printf("| Agora vamos começar o jogo!                  |\n\n");
  printf("|----------------------------------------------|\n");

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      tabuleiroJ1[i][j] = ' ';
    }
  }
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      tabuleiroJ2[i][j] = ' ';
    }
  }
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      tabuleiroComp[i][j] = ' ';
    }
  }

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      tabuleiroComp2[i][j] = ' ';
    }
  }

  // tabuleiro do jogador 1
  // SUBMARINOS
  for (int posiJ1 = 1; posiJ1 <= 1; posiJ1++) {
    do {
      printf("Jogador %s", nomeJ1);
      printf(" escolha uma posição do SUBMARINO %d.\n", posiJ1);
      printf("Digite a linha de A a O:\n\n");
      scanf(" %c", &letraMaiuscula);
      limpar_buffer();
      linha = letraMaiuscula - 'A';
      if (linha < 0 || linha >= 15) {
        printf("Linha inválida tente novamente !\n");
        continue;
      }
      do {
        printf("Jogador %s", nomeJ1);
        printf(" digite a coluna de 1 a 15:\n\n");
        scanf("%d", &coluna);
        limpar_buffer();
        coluna--;

      } while (coluna < 0 || coluna >= 15);
      if (coluna < 0 || coluna >= 15) {
        printf("Coluna inválida tente novamente");
        continue;
      }

      if (tabuleiroJ1[linha][coluna] != ' ') {
        printf("Posição já ocupada, escolha outra posição.\n");
      }
    } while (linha < 0 || linha >= 15 || coluna < 0 || coluna >= 15 ||
             tabuleiroJ1[linha][coluna] != ' ');

    tabuleiroJ1[linha][coluna] = 'S';
  }
  // system("clear");  apagar

  // A verificação para saber se a casa esta ocupada esta
  // funcionando, e a verificação para delimitar o tamanho da matriz
  // também está funcionando. Agora preciso implementar os
  // diferentes tipos de navios
  imprimir_tabuleiro(tabuleiroJ1);

  for (int posiJ1 = 1; posiJ1 <= 2; posiJ1++) {
    int posihidro;
    do {
      printf("Jogador %s", nomeJ1);
      printf("Escolha a direção do hidroavião %d.\n", posiJ1);
      printf("Posições possíveis:\n");
      printf("|   1. Acima Λ \n");
      printf("|   2. Abaixo ∨ \n");
      printf("|   3. Direita ᐵ \n");
      printf("|   4. Esquerda ᑈ \n");
      scanf("%d", &posihidro);
      limpar_buffer();

      if (posihidro < 1 || posihidro > 4) {
        printf("A posição escolhida não está disponível, tente "
               "novamente! Para escolher uma posição escolha um "
               "número de 1 a 4.\n");
        continue;
      }

      printf("Agora que você escolheu a direção %d, escolha a posição "
             "na matriz onde deseja colocar o hidroavião %d.\n",
             posihidro, posiJ1);

      printf("Digite a linha de A a O:\n\n");
      scanf(" %c", &letraMaiuscula);
      limpar_buffer();
      linha = letraMaiuscula - 'A';

      if (linha < 0 || linha >= 15) {
        printf("Linha inválida, tente novamente! Sua escolha pode "
               "estar fora dos padrões da matriz 15x15!\n");
        continue;
      }

      printf("Jogador %s", nomeJ1);
      printf("Digite a coluna de 1 a 15:\n\n");
      scanf("%d", &coluna);
      limpar_buffer();
      coluna--;

      if (coluna < 0 || coluna >= 15) {
        printf("Coluna inválida, tente novamente! Sua escolha pode "
               "estar fora dos padrões da matriz 15x15!\n");
        continue;
      }

      if (tabuleiroJ1[linha][coluna] != ' ') {
        printf("Posição já ocupada, escolha outra posição.\n");
        continue;
      }

      // Validação e colocação do HIDROAVIAO
      int validacima = 1, validabaixo = 1, validadireita = 1,
          validaesquerda = 1;

      switch (posihidro) {
      case 1: // Cima
        if (linha + 1 >= 15 || coluna - 1 < 0 || coluna + 1 >= 15 ||
            tabuleiroJ1[linha + 1][coluna - 1] != ' ' ||
            tabuleiroJ1[linha + 1][coluna + 1] != ' ') {
          validacima = 0;
        }
        if (validacima) {
          tabuleiroJ1[linha][coluna] = 'H';
          tabuleiroJ1[linha + 1][coluna - 1] = 'H';
          tabuleiroJ1[linha + 1][coluna + 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ1);
        }
        break;
      case 2: // Baixo
        if (linha - 1 < 0 || coluna - 1 < 0 || coluna + 1 >= 15 ||
            tabuleiroJ1[linha - 1][coluna - 1] != ' ' ||
            tabuleiroJ1[linha - 1][coluna + 1] != ' ') {
          validabaixo = 0;
        }
        if (validabaixo) {
          tabuleiroJ1[linha][coluna] = 'H';
          tabuleiroJ1[linha - 1][coluna - 1] = 'H';
          tabuleiroJ1[linha - 1][coluna + 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ1);
        }
        break;
      case 3: // Direita
        if (linha - 1 < 0 || linha + 1 >= 15 || coluna - 1 < 0 ||
            tabuleiroJ1[linha - 1][coluna - 1] != ' ' ||
            tabuleiroJ1[linha + 1][coluna - 1] != ' ') {
          validadireita = 0;
        }
        if (validadireita) {
          tabuleiroJ1[linha][coluna] = 'H';
          tabuleiroJ1[linha - 1][coluna - 1] = 'H';
          tabuleiroJ1[linha + 1][coluna - 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ1);
        }
        break;
      case 4: // Esquerda
        if (linha - 1 < 0 || linha + 1 >= 15 || coluna + 1 >= 15 ||
            tabuleiroJ1[linha - 1][coluna + 1] != ' ' ||
            tabuleiroJ1[linha + 1][coluna + 1] != ' ') {
          validaesquerda = 0;
        }
        if (validaesquerda) {
          tabuleiroJ1[linha][coluna] = 'H';
          tabuleiroJ1[linha - 1][coluna + 1] = 'H';
          tabuleiroJ1[linha + 1][coluna + 1] = 'H';
        }
        break;
      }

      if ((posihidro == 1 && !validacima) || (posihidro == 2 && !validabaixo) ||
          (posihidro == 3 && !validadireita) ||
          (posihidro == 4 && !validaesquerda)) {
        printf("Posição inválida, tente novamente. As asas do "
               "hidroavião não estão dentro da matriz ou já estão "
               "ocupadas.\n");
        continue;
      }
      break;

    } while (1);
  }

  // tabuleiro do jogador 2
  // SUBMARINO QUATRO UNIDADES

  for (int posiJ2 = 1; posiJ2 <= 1; posiJ2++) {
    do {
      printf("Jogador %s", nomeJ2);
      printf(" escolha uma posição do SUBMARINO %d.\n", posiJ2);
      printf("Digite a linha de A a O:\n\n");
      scanf(" %c", &letraMaiuscula);
      limpar_buffer();
      linha = letraMaiuscula - 'A';
      if (linha < 0 || linha >= 15) {
        printf("Linha inválida tente novamente !\n");
        continue;
      }
      do {
        printf("Jogador %s", nomeJ2);
        printf(" digite a coluna de 1 a 15:\n\n");
        scanf("%d", &coluna);
        limpar_buffer();
        coluna--;

      } while (coluna < 0 || coluna >= 15);
      if (coluna < 0 || coluna >= 15) {
        printf("Coluna inválida tente novamente");
        continue;
      }

      if (tabuleiroJ2[linha][coluna] != ' ') {
        printf("Posição já ocupada, escolha outra posição.\n");
      }
    } while (linha < 0 || linha >= 15 || coluna < 0 || coluna >= 15 ||
             tabuleiroJ2[linha][coluna] != ' ');

    tabuleiroJ2[linha][coluna] = 'S';
  }
  // system("clear");  apagar

  // A verificação para saber se a casa esta ocupada esta
  // funcionando, e a verificação para delimitar o tamanho da matriz
  // também está funcionando. Agora preciso implementar os
  // diferentes tipos de navios
  imprimir_tabuleiro(tabuleiroJ2);

  // hidroaviões cinco unidades
  for (int posiJ2 = 1; posiJ2 <= 2; posiJ2++) {
    int posihidro;
    do {
      printf("Jogador %s", nomeJ2);
      printf("Escolha a direção do hidroavião %d.\n", posiJ2);
      printf("Posições possíveis:\n");
      printf("|   1. Acima Λ \n");
      printf("|   2. Abaixo ∨ \n");
      printf("|   3. Direita ᐵ \n");
      printf("|   4. Esquerda ᑈ \n");
      scanf("%d", &posihidro);
      limpar_buffer();

      if (posihidro < 1 || posihidro > 4) {
        printf("A posição escolhida não está disponível, tente "
               "novamente! Para escolher uma posição escolha um "
               "número de 1 a 4.\n");
        continue;
      }

      printf("Agora que você escolheu a direção %d, escolha a posição "
             "na matriz onde deseja colocar o hidroavião %d.\n",
             posihidro, posiJ2);

      printf("Digite a linha de A a O:\n\n");
      scanf(" %c", &letraMaiuscula);
      limpar_buffer();
      linha = letraMaiuscula - 'A';

      if (linha < 0 || linha >= 15) {
        printf("Linha inválida, tente novamente! Sua escolha pode "
               "estar fora dos padrões da matriz 15x15!\n");
        continue;
      }

      printf("Jogador %s", nomeJ2);
      printf("Digite a coluna de 1 a 15:\n\n");
      scanf("%d", &coluna);
      limpar_buffer();
      coluna--;

      if (coluna < 0 || coluna >= 15) {
        printf("Coluna inválida, tente novamente! Sua escolha pode "
               "estar fora dos padrões da matriz 15x15!\n");
        continue;
      }

      if (tabuleiroJ2[linha][coluna] != ' ') {
        printf("Posição já ocupada, escolha outra posição.\n");
        continue;
      }

      // Validação e colocação do HIDROAVIAO
      int validacima = 1, validabaixo = 1, validadireita = 1,
          validaesquerda = 1;

      switch (posihidro) {
      case 1: // Cima
        if (linha + 1 >= 15 || coluna - 1 < 0 || coluna + 1 >= 15 ||
            tabuleiroJ2[linha + 1][coluna - 1] != ' ' ||
            tabuleiroJ2[linha + 1][coluna + 1] != ' ') {
          validacima = 0;
        }
        if (validacima) {
          tabuleiroJ2[linha][coluna] = 'H';
          tabuleiroJ2[linha + 1][coluna - 1] = 'H';
          tabuleiroJ2[linha + 1][coluna + 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ2);
        }
        break;
      case 2: // Baixo
        if (linha - 1 < 0 || coluna - 1 < 0 || coluna + 1 >= 15 ||
            tabuleiroJ2[linha - 1][coluna - 1] != ' ' ||
            tabuleiroJ2[linha - 1][coluna + 1] != ' ') {
          validabaixo = 0;
        }
        if (validabaixo) {
          tabuleiroJ2[linha][coluna] = 'H';
          tabuleiroJ2[linha - 1][coluna - 1] = 'H';
          tabuleiroJ2[linha - 1][coluna + 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ2);
        }
        break;
      case 3: // Direita
        if (linha - 1 < 0 || linha + 1 >= 15 || coluna - 1 < 0 ||
            tabuleiroJ2[linha - 1][coluna - 1] != ' ' ||
            tabuleiroJ2[linha + 1][coluna - 1] != ' ') {
          validadireita = 0;
        }
        if (validadireita) {
          tabuleiroJ2[linha][coluna] = 'H';
          tabuleiroJ2[linha - 1][coluna - 1] = 'H';
          tabuleiroJ2[linha + 1][coluna - 1] = 'H';
          imprimir_tabuleiro(tabuleiroJ2);
        }
        break;
      case 4: // Esquerda
        if (linha - 1 < 0 || linha + 1 >= 15 || coluna + 1 >= 15 ||
            tabuleiroJ2[linha - 1][coluna + 1] != ' ' ||
            tabuleiroJ2[linha + 1][coluna + 1] != ' ') {
          validaesquerda = 0;
        }
        if (validaesquerda) {
          tabuleiroJ2[linha][coluna] = 'H';
          tabuleiroJ2[linha - 1][coluna + 1] = 'H';
          tabuleiroJ2[linha + 1][coluna + 1] = 'H';
        }
        break;
      }

      if ((posihidro == 1 && !validacima) || (posihidro == 2 && !validabaixo) ||
          (posihidro == 3 && !validadireita) ||
          (posihidro == 4 && !validaesquerda)) {
        printf("Posição inválida, tente novamente. As asas do "
               "hidroavião não estão dentro da matriz ou já estão "
               "ocupadas.\n");
        continue;
      }
      break;

    } while (1);

    // ATAQUE do jogador 1
    // verificações de jagadas  repetidas na mesma coordenada
    //
    do {
      printf("AGORA É A HORA DE ATACAR !!! CADA JOGADOR TEM DIREITO A "
             "DOIS TIROS CONSECUTIVOS\n");
      for (int tiro = 1; tiro <= 2; tiro++) {
        while (1) {
          printf("|| Ataque de núemro %d || Jogador %s, é a sua vez de "
                 "atacar!\n\n",
                 tiro, nomeJ1);

          printf("Digite a linha de A a O:\n\n");
          scanf(" %c", &letraMaiuscula);
          limpar_buffer();
          linha = letraMaiuscula - 'A';
          printf("Digite a coluna de 1 a 15:\n");
          scanf(" %d", &coluna);
          coluna--;

          if (linha < 0 || linha >= 15 || coluna < 0 || coluna >= 15 ||
              tabuleiroJ2[linha][coluna] != '#') {
            printf("A COORDENADA selecionada para o ataque não esta "
                   "dentro "
                   "da matriz 15x15 ou essa posição já foi atacada. "
                   "Selecione um valor válido!\n");
            continue;
          }
          if (tabuleiroJ2[linha][coluna] == '~~') {
            printf("Essa posição já foi atacada, tente novamente!\n");
            continue;
          }
          if (tabuleiroJ2[linha][coluna] == ' ') {
            printf("Você errou o tiro!\n");
            tabuleiroJ2[linha][coluna] = '~~';
            tabuleiroCompara2(tabuleiroComp2);
            break;
          }

          if (tabuleiroJ2[linha][coluna] != ' ') {
            printf("Você acertou o tiro!\n");
            tabuleiroComp2[linha][coluna] = '#';
            contJ1++;
            tabuleiroCompara2(tabuleiroComp2);
            if (tiro == 2) {
              system("clear");
            }

            if (contJ1 == 7) {
              int parar;
              printf("***********************************************"
                     "******"
                     "********\n");
              printf("**  P  ******************* -> V <- "
                     "*******************  ꟼ  **\n");
              printf("***  A  ****************** -> I <- "
                     "******************  A  ***\n");
              printf("****  R  ***************** -> T <- "
                     "***************** "
                     " Я  ****\n");
              printf("*****  A  **************** -> Ó <- "
                     "****************  "
                     "A  *****\n");
              printf("*******  É  ************** -> R <- "
                     "***************  "
                     "Ǝ̀  ******\n");
              printf("********  N  ************* -> I <- "
                     "**************  И "
                     " *******\n");
              printf("*********  S  ************ -> A <- "
                     "*************  Ƨ  "
                     "********\n");
              printf("******************** jogador %s venceu "
                     "**********************\n\n\n",
                     nomeJ1);
              printf("Caso você queira finalizar o jogo digite 1 !! \n");
              scanf("%d", &parar);
              if (parar == 1) {
                break;
              }
            }
          }
          break;
        }
      }

      // vitória jogador 2
      printf("AGORA É A HORA DE ATACAR !!! CADA JOGADOR TEM DIREITO A "
             "DOIS TIROS CONSECUTIVOS\n");
      for (int tiro = 1; tiro <= 2; tiro++) {
        while (1) {
          printf("|| Ataque de núemro %d || Jogador %s, é a sua vez "
                 "de atacar!\n\n",
                 tiro, nomeJ2);

          printf("Digite a linha de A a O:\n\n");
          scanf(" %c", &letraMaiuscula);
          limpar_buffer();
          linha = letraMaiuscula - 'A';
          printf("Digite a coluna de 1 a 15:\n");
          scanf(" %d", &coluna);
          coluna--;

          if (linha < 0 || linha >= 15 || coluna < 0 || coluna >= 15 ||
              tabuleiroJ1[linha][coluna] == '#') {
            printf("A COORDENADA selecionada para o ataque não esta "
                   "dentro "
                   "da matriz 15x15! Selecione um valor válido.\n");
            continue;
          }
          if (tabuleiroJ1[linha][coluna] == '~~') {
            printf("Essa posição já foi atacada, tente novamente!\n");
            continue;
          }
          if (tabuleiroJ1[linha][coluna] == ' ') {
            printf("Você errou o tiro!\n");
            tabuleiroJ1[linha][coluna] = '~~';
            tabuleiroCompara(tabuleiroComp);
            break;
          }

          if (tabuleiroJ1[linha][coluna] != ' ') {
            printf("Você acertou o tiro!\n");
            tabuleiroComp[linha][coluna] = '#';
            contJ2++;
            tabuleiroCompara(tabuleiroComp);

            if (contJ2 == 7) {
              int parar;
              printf("*********************************************"
                     "******"
                     "**********\n");
              printf("**  P  ******************* -> V <- "
                     "*******************  ꟼ  **\n");
              printf("***  A  ****************** -> I <- "
                     "******************  A  ***\n");
              printf("****  R  ***************** -> T <- "
                     "*****************  Я  ****\n");
              printf("*****  A  **************** -> Ó <- "
                     "****************  A  *****\n");
              printf("*******  É  ************** -> R <- "
                     "*************** "
                     " Ǝ̀  *******\n");
              printf("********  N  ************* -> I <- "
                     "**************  "
                     "И  ********\n");
              printf("*********  S  ************ -> A <- "
                     "*************  "
                     "Ƨ  *********\n");
              printf("********************* jogador %s venceu "
                     "**********************\n\n\n",
                     nomeJ2);
            }
          }
          break;
        }
      }
      if (contJ1 == 15 || contJ2 == 15) {
        printf("Caso você queira finalizar o jogo digite 1 caso "
               "queirar jogar novamente digite 0. "
               "!! \n");
        scanf("%d", &parar);
        if (parar == 1) {
          break;
        } else {
          continue;
        }
      }
    } while (1);
  }
}