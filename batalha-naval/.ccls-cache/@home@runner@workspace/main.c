#include <ctype.h>
#include <stdio.h>
void tabuleiroCompara(char tabuleiroComp[15][15]);
void tabuleiroCompara2(char tabuleiroComp2[15][15]);
#define TAM 15
void limparmatriz(char tabuleiro[TAM][TAM]);
int main(void) {
  int escolha_programa = 0;

  do {
    printf("|----------------------------|\n");
    printf("|     ESTRUTURA DE DADOS     |\n");
    printf("| Escolha a opção que deseja |\n\n");
    printf("| Programa I  : 1            |\n");
    printf("| Programa II : 2            |\n");
    printf("| Programa III : 3           |\n");
    printf("|----------------------------|\n");
    scanf("%d", &escolha_programa);
    limpar_buffer();
    system("clear"); // apagar

    if (escolha_programa == 0) {
      break;
    }

    switch (escolha_programa) {
    case 1: {
      int escolha_matrizes = 0;
      do {
        printf("Programa I\n");
        printf("|------------------------------|\n");
        printf("|     ESTRUTURA DE DADOS       |\n");
        printf("| Escolha a opção que deseja   |\n\n");
        printf("|        * MATRIZES *          |\n");
        printf("| opção 1: Matrizes e vetores  |\n");
        printf("| opção 2: FILA & PILHA        |\n");
        printf("| opção 3:                     |\n");
        printf("| opção 0: SAIR da página atual|\n");
        printf("|------------------------------|\n");
        scanf("%d", &escolha_matrizes);
        limpar_buffer();
        system("clear"); // apagar

        if (escolha_matrizes == 0) {
          break;
        }

        switch (escolha_matrizes) {
        case 1: {
          int escolha = 0;
          do {
            printf("|------------------------------|\n");
            printf("|     ESTRUTURA DE DADOS       |\n");
            printf("| Escolha a opção que deseja   |\n\n");
            printf("| opção 1: PxP                 |\n");
            printf("| opção 2: PxCPU               |\n");
            printf("| opção 3: CPUxCPU             |\n");
            printf("| opção 0: SAIR da página atual|\n");
            printf("|------------------------------|\n");
            scanf("%d", &escolha);
            limpar_buffer();
            system("clear"); // apagar
            if (escolha == 0) {
              break;
            }

            switch (escolha) {
            case 1: {
              int jogar_novamente = 1;
              printf("Você escolheu a opção P x P\n");
              do {
                // Código do jogo começa aqui
                // Inicializa as variáveis do jogo
                int contJ1 = 0;
                int contJ2 = 0;
                int linha, coluna;
                char letraMaiuscula;
                char nomeJ1[30];
                char nomeJ2[30];

                // Inicializa os tabuleiros
                char tabuleiroJ1[TAM][TAM];
                char tabuleiroJ2[TAM][TAM];
                char tabuleiroComp[TAM][TAM];
                char tabuleiroComp2[TAM][TAM];

                // Limpa os tabuleiros
                for (int i = 0; i < TAM; i++) {
                  for (int j = 0; j < TAM; j++) {
                    tabuleiroJ1[i][j] = ' ';
                    tabuleiroJ2[i][j] = ' ';
                    tabuleiroComp[i][j] = ' ';
                    tabuleiroComp2[i][j] = ' ';
                  }
                }

                // Recebe os nomes dos jogadores
                printf("Digite o nome do jogador 1: ");
                scanf("%30s", nomeJ1);
                limpar_buffer();
                printf("Digite o nome do jogador 2: ");
                scanf("%30s", nomeJ2);
                limpar_buffer();

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
                for (int posiJ1 = 1; posiJ1 <= 4; posiJ1++) {
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
                  } while (linha < 0 || linha >= 15 || coluna < 0 ||
                           coluna >= 15 || tabuleiroJ1[linha][coluna] != ' ');

                  tabuleiroJ1[linha][coluna] = 'S';
                }
                // system("clear");  apagar

                // A verificação para saber se a casa esta ocupada esta
                // funcionando, e a verificação para delimitar o tamanho da
                // matriz também está funcionando. Agora preciso implementar os
                // diferentes tipos de navios
                imprimir_tabuleiro(tabuleiroJ1);

                for (int posiJ1 = 1; posiJ1 <= 5; posiJ1++) {
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

                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o hidroavião %d.\n",
                           posihidro, posiJ1);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ1);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
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
                      if (linha + 1 >= 15 || coluna - 1 < 0 ||
                          coluna + 1 >= 15 ||
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
                      if (linha - 1 < 0 || linha + 1 >= 15 ||
                          coluna + 1 >= 15 ||
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

                    if ((posihidro == 1 && !validacima) ||
                        (posihidro == 2 && !validabaixo) ||
                        (posihidro == 3 && !validadireita) ||
                        (posihidro == 4 && !validaesquerda)) {
                      printf(
                          "Posição inválida, tente novamente. As asas do "
                          "hidroavião não estão dentro da matriz ou já estão "
                          "ocupadas.\n");
                      continue;
                    }
                    break;

                  } while (1);
                }
                // VERIFICAR A IMPRESSÃO, A DIREÇÃO 'ACIMA' ESTA IMPRIMINDO PARA
                // A ESQUERDA
                imprimir_tabuleiro(tabuleiroJ1);

                for (int posiJ1 = 1; posiJ1 <= 2; posiJ1++) {

                  int posiencoura;
                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação, \na"
                        "posição acima começará a contruir o encouraçado de "
                        "cima para baixo, diferente da posição abaixo \n, "
                        "então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ1);
                    printf("Escolha a direção do ENCOURAÇADO %d.\n", posiJ1);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posiencoura);
                    limpar_buffer();
                    if (posiencoura < 1 || posiencoura > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o ENCOURAÇADO %d.\n",
                           posiencoura, posiJ1);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ1);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ1[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    // validação e colocação do encouraçado [] [] [] []
                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;

                    switch (posiencoura) {
                    case 1: // CIMA
                      if (linha - 1 < 0 || linha - 2 < 0 || linha - 3 < 0 ||
                          tabuleiroJ1[linha - 1][coluna] != ' ' ||
                          tabuleiroJ1[linha - 2][coluna] != ' ' ||
                          tabuleiroJ1[linha - 3][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ1[linha][coluna] = 'E';
                        tabuleiroJ1[linha - 1][coluna] = 'E';
                        tabuleiroJ1[linha - 2][coluna] = 'E';
                        tabuleiroJ1[linha - 3][coluna] = 'E';
                      }
                      break;

                    case 2: // BAIXO
                      if (linha + 1 >= 15 || linha + 2 >= 15 ||
                          linha + 3 >= 15 ||
                          tabuleiroJ1[linha + 1][coluna] != ' ' ||
                          tabuleiroJ1[linha + 2][coluna] != ' ' ||
                          tabuleiroJ1[linha + 3][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ1[linha][coluna] = 'E';
                        tabuleiroJ1[linha + 1][coluna] = 'E';
                        tabuleiroJ1[linha + 2][coluna] = 'E';
                        tabuleiroJ1[linha + 3][coluna] = 'E';
                      }
                      break;

                    case 3: // DIREITA
                      if (coluna + 1 >= 15 || coluna + 2 >= 15 ||
                          coluna + 3 >= 15 ||
                          tabuleiroJ1[linha][coluna + 1] != ' ' ||
                          tabuleiroJ1[linha][coluna + 2] != ' ' ||
                          tabuleiroJ1[linha][coluna + 3] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ1[linha][coluna] = 'E';
                        tabuleiroJ1[linha][coluna + 1] = 'E';
                        tabuleiroJ1[linha][coluna + 2] = 'E';
                        tabuleiroJ1[linha][coluna + 3] = 'E';
                      }
                      break;

                    case 4: // ESQUERDA
                      if (coluna - 1 < 0 || coluna - 2 < 0 || coluna - 3 < 0 ||
                          tabuleiroJ1[linha][coluna - 1] != ' ' ||
                          tabuleiroJ1[linha][coluna - 2] != ' ' ||
                          tabuleiroJ1[linha][coluna - 3] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ1[linha][coluna] = 'E';
                        tabuleiroJ1[linha][coluna - 1] = 'E';
                        tabuleiroJ1[linha][coluna - 2] = 'E';
                        tabuleiroJ1[linha][coluna - 3] = 'E';
                      }
                      break;
                    }

                    // aqui eu verifico se a posição escolhida é valida negando
                    // o valor dado na logica no codigo acnima
                    if ((posiencoura == 1 && !validacima) ||
                        (posiencoura == 2 && !validabaixo) ||
                        (posiencoura == 3 && !validadireita) ||
                        (posiencoura == 4 && !validaesquerda)) {
                      printf(
                          "Posição inválida, tente novamente. O tamanho do "
                          "ENCOURAÇADO não esta dentro da matriz ou já estão "
                          "ocupadas.\n");
                      continue;
                    }
                    break;
                    imprimir_tabuleiro(tabuleiroJ1);
                  } while (1);
                }
                imprimir_tabuleiro(tabuleiroJ1);

                // Porta-Aviões UMA UNIDADE
                for (int posiJ1 = 1; posiJ1 <= 1; posiJ1++) {
                  int posiportavioes;

                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação,\n a "
                        "posição acima começará a contruir o PORTA-AVIÕES de "
                        "cima para baixo, diferente da posição abaixo,\n então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ1);
                    printf("Escolha a direção do PORTA-AVIÕES %d.\n", posiJ1);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posiportavioes);
                    limpar_buffer();
                    if (posiportavioes < 1 || posiportavioes > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    //-----
                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o PORTA-AVIÕES %d.\n",
                           posiportavioes, posiJ1);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ1);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ1[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;

                    switch (posiportavioes) {
                    case 1: // CIMA
                      if (linha - 1 < 0 || linha - 2 < 0 || linha - 3 < 0 ||
                          linha - 4 < 0 ||
                          tabuleiroJ1[linha - 1][coluna] != ' ' ||
                          tabuleiroJ1[linha - 2][coluna] != ' ' ||
                          tabuleiroJ1[linha - 3][coluna] != ' ' ||
                          tabuleiroJ1[linha - 4][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ1[linha][coluna] = 'P';
                        tabuleiroJ1[linha - 1][coluna] = 'P';
                        tabuleiroJ1[linha - 2][coluna] = 'P';
                        tabuleiroJ1[linha - 3][coluna] = 'P';
                        tabuleiroJ1[linha - 4][coluna] = 'P';
                      }
                      break;

                    case 2: // BAIXO
                      if (linha + 1 >= 15 || linha + 2 >= 15 ||
                          linha + 3 >= 15 || linha + 4 >= 15 ||
                          tabuleiroJ1[linha + 1][coluna] != ' ' ||
                          tabuleiroJ1[linha + 2][coluna] != ' ' ||
                          tabuleiroJ1[linha + 3][coluna] != ' ' ||
                          tabuleiroJ1[linha + 4][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ1[linha][coluna] = 'P';
                        tabuleiroJ1[linha + 1][coluna] = 'P';
                        tabuleiroJ1[linha + 2][coluna] = 'P';
                        tabuleiroJ1[linha + 3][coluna] = 'P';
                        tabuleiroJ1[linha + 4][coluna] = 'P';
                      }
                      break;

                    case 3: // DIREITA
                      if (coluna + 1 >= 15 || coluna + 2 >= 15 ||
                          coluna + 3 >= 15 || coluna + 4 >= 15 ||
                          tabuleiroJ1[linha][coluna + 1] != ' ' ||
                          tabuleiroJ1[linha][coluna + 2] != ' ' ||
                          tabuleiroJ1[linha][coluna + 3] != ' ' ||
                          tabuleiroJ1[linha][coluna + 4] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ1[linha][coluna] = 'P';
                        tabuleiroJ1[linha][coluna + 1] = 'P';
                        tabuleiroJ1[linha][coluna + 2] = 'P';
                        tabuleiroJ1[linha][coluna + 3] = 'P';
                        tabuleiroJ1[linha][coluna + 4] = 'P';
                      }
                      break;

                    case 4: // ESQUERAA
                      if (coluna - 1 < 0 || coluna - 2 < 0 || coluna - 3 < 0 ||
                          coluna - 4 < 0 ||
                          tabuleiroJ1[linha][coluna - 1] != ' ' ||
                          tabuleiroJ1[linha][coluna - 2] != ' ' ||
                          tabuleiroJ1[linha][coluna - 3] != ' ' ||
                          tabuleiroJ1[linha][coluna - 4] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ1[linha][coluna] = 'P';
                        tabuleiroJ1[linha][coluna - 1] = 'P';
                        tabuleiroJ1[linha][coluna - 2] = 'P';
                        tabuleiroJ1[linha][coluna - 3] = 'P';
                        tabuleiroJ1[linha][coluna - 4] = 'P';
                      }
                      break;
                    }

                    // aqui eu verifico se a posição escolhida é valida
                    // negando o valor dado na logica no codigo acnima
                    if ((posiportavioes == 1 && !validacima) ||
                        (posiportavioes == 2 && !validabaixo) ||
                        (posiportavioes == 3 && !validadireita) ||
                        (posiportavioes == 4 && !validaesquerda)) {
                      printf("Posição inválida, tente novamente. O tamanho do "
                             "PORTA-AVIÕES não esta dentro da matriz ou já "
                             "estão "
                             "ocupadas.\n");
                      continue;
                    }
                    break;
                  } while (1);
                }

                imprimir_tabuleiro(tabuleiroJ1);

                // CRUZADORES TRES UNIDADES
                for (int posiJ1 = 1; posiJ1 <= 3; posiJ1++) {
                  int posicruza;
                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação,\n a "
                        "posição acima começará a contruir o porat-aviões de "
                        "cima para baixo, diferente da posição abaixo,\n então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ1);
                    printf("Escolha a direção do CRUZADORES %d.\n", posiJ1);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posicruza);
                    limpar_buffer();
                    if (posicruza < 1 || posicruza > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    //-----
                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar os CRUZADORES %d.\n",
                           posicruza, posiJ1);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ1);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ1[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;
                    switch (posicruza) {

                    case 1:
                      if (linha - 1 < 0 || tabuleiroJ1[linha][coluna] != ' ' ||
                          tabuleiroJ1[linha - 1][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ1[linha][coluna] = 'C';
                        tabuleiroJ1[linha - 1][coluna] = 'C';
                        imprimir_tabuleiro(tabuleiroJ1);
                      }
                      break;

                    case 2:
                      if (linha + 1 >= 15 ||
                          tabuleiroJ1[linha][coluna] != ' ' ||
                          tabuleiroJ1[linha + 1][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ1[linha][coluna] = 'C';
                        tabuleiroJ1[linha + 1][coluna] = 'C';
                        imprimir_tabuleiro(tabuleiroJ1);
                      }
                      break;

                    case 3:
                      if (coluna + 1 >= 15 ||
                          tabuleiroJ1[linha][coluna] != ' ' ||
                          tabuleiroJ1[linha][coluna + 1] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ1[linha][coluna] = 'C';
                        tabuleiroJ1[linha][coluna + 1] = 'C';
                        imprimir_tabuleiro(tabuleiroJ1);
                      }
                      break;

                    case 4:
                      if (coluna - 1 < 0 || tabuleiroJ1[linha][coluna] != ' ' ||
                          tabuleiroJ1[linha][coluna - 1] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ1[linha][coluna] = 'C';
                        tabuleiroJ1[linha][coluna - 1] = 'C';
                      }
                      break;
                    }
                    if ((posicruza == 1 && !validacima) ||
                        (posicruza == 2 && !validabaixo) ||
                        (posicruza == 3 && !validadireita) ||
                        (posicruza == 4 && !validaesquerda)) {
                      printf("Posição inválida, tente novamente. O tamanho do "
                             "CRUZADORES não esta dentro da matriz ou já "
                             "estão "
                             "ocupadas.\n");
                      continue;
                    }
                    break;
                  } while (1);
                }

                imprimir_tabuleiro(tabuleiroJ1);

                system("clear");

                // tabuleiro do jogador 2
                // SUBMARINO QUATRO UNIDADES

                for (int posiJ2 = 1; posiJ2 <= 4; posiJ2++) {
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
                  } while (linha < 0 || linha >= 15 || coluna < 0 ||
                           coluna >= 15 || tabuleiroJ2[linha][coluna] != ' ');

                  tabuleiroJ2[linha][coluna] = 'S';
                }
                // system("clear");  apagar

                // A verificação para saber se a casa esta ocupada esta
                // funcionando, e a verificação para delimitar o tamanho da
                // matriz também está funcionando. Agora preciso implementar os
                // diferentes tipos de navios
                imprimir_tabuleiro(tabuleiroJ2);

                // hidroaviões cinco unidades
                for (int posiJ2 = 1; posiJ2 <= 5; posiJ2++) {
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

                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o hidroavião %d.\n",
                           posihidro, posiJ2);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ2);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
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
                      if (linha + 1 >= 15 || coluna - 1 < 0 ||
                          coluna + 1 >= 15 ||
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
                      if (linha - 1 < 0 || linha + 1 >= 15 ||
                          coluna + 1 >= 15 ||
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

                    if ((posihidro == 1 && !validacima) ||
                        (posihidro == 2 && !validabaixo) ||
                        (posihidro == 3 && !validadireita) ||
                        (posihidro == 4 && !validaesquerda)) {
                      printf(
                          "Posição inválida, tente novamente. As asas do "
                          "hidroavião não estão dentro da matriz ou já estão "
                          "ocupadas.\n");
                      continue;
                    }
                    break;

                  } while (1);
                }
                // VERIFICAR A IMPRESSÃO, A DIREÇÃO 'ACIMA' ESTA IMPRIMINDO PARA
                // A ESQUERDA
                imprimir_tabuleiro(tabuleiroJ2);

                // ENCOURAÇADO DUAS UNIDADES
                for (int posiJ2 = 1; posiJ2 <= 2; posiJ2++) {

                  int posiencoura;
                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação,\n a "
                        "posição acima começará a contruir o encouraçado de "
                        "cima para baixo, diferente da posição abaixo,\n então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ2);
                    printf("Escolha a direção do ENCOURAÇADO %d.\n", posiJ2);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posiencoura);
                    limpar_buffer();
                    if (posiencoura < 1 || posiencoura > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o hidroavião %d.\n",
                           posiencoura, posiJ2);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s ", nomeJ2);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ2[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    // validação e colocação do encouraçado [] [] [] []
                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;

                    switch (posiencoura) {
                    case 1: // CIMA
                      if (linha - 1 < 0 || linha - 2 < 0 || linha - 3 < 0 ||
                          tabuleiroJ2[linha - 1][coluna] != ' ' ||
                          tabuleiroJ2[linha - 2][coluna] != ' ' ||
                          tabuleiroJ2[linha - 3][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ2[linha][coluna] = 'E';
                        tabuleiroJ2[linha - 1][coluna] = 'E';
                        tabuleiroJ2[linha - 2][coluna] = 'E';
                        tabuleiroJ2[linha - 3][coluna] = 'E';
                      }
                      break;

                    case 2: // BAIXO
                      if (linha + 1 >= 15 || linha + 2 >= 15 ||
                          linha + 3 >= 15 ||
                          tabuleiroJ2[linha + 1][coluna] != ' ' ||
                          tabuleiroJ2[linha + 2][coluna] != ' ' ||
                          tabuleiroJ2[linha + 3][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ2[linha][coluna] = 'E';
                        tabuleiroJ2[linha + 1][coluna] = 'E';
                        tabuleiroJ2[linha + 2][coluna] = 'E';
                        tabuleiroJ2[linha + 3][coluna] = 'E';
                      }
                      break;

                    case 3: // DIREITA
                      if (coluna + 1 >= 15 || coluna + 2 >= 15 ||
                          coluna + 3 >= 15 ||
                          tabuleiroJ2[linha][coluna + 1] != ' ' ||
                          tabuleiroJ2[linha][coluna + 2] != ' ' ||
                          tabuleiroJ2[linha][coluna + 3] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ2[linha][coluna] = 'E';
                        tabuleiroJ2[linha][coluna + 1] = 'E';
                        tabuleiroJ2[linha][coluna + 2] = 'E';
                        tabuleiroJ2[linha][coluna + 3] = 'E';
                      }
                      break;

                    case 4: // ESQUERDA
                      if (coluna - 1 < 0 || coluna - 2 < 0 || coluna - 3 < 0 ||
                          tabuleiroJ2[linha][coluna - 1] != ' ' ||
                          tabuleiroJ2[linha][coluna - 2] != ' ' ||
                          tabuleiroJ2[linha][coluna - 3] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ2[linha][coluna] = 'E';
                        tabuleiroJ2[linha][coluna - 1] = 'E';
                        tabuleiroJ2[linha][coluna - 2] = 'E';
                        tabuleiroJ2[linha][coluna - 3] = 'E';
                      }
                      break;
                    }

                    // aqui eu verifico se a posição escolhida é valida negando
                    // o valor dado na logica no codigo acnima
                    if ((posiencoura == 1 && !validacima) ||
                        (posiencoura == 2 && !validabaixo) ||
                        (posiencoura == 3 && !validadireita) ||
                        (posiencoura == 4 && !validaesquerda)) {
                      printf(
                          "Posição inválida, tente novamente. O tamanho do "
                          "ENCOURAÇADO não esta dentro da matriz ou já estão "
                          "ocupadas.\n");
                      continue;
                    }
                    break;

                  } while (1);
                }
                imprimir_tabuleiro(tabuleiroJ2);

                // Porta-Aviões UMA UNIDADE
                for (int posiJ2 = 1; posiJ2 <= 1; posiJ2++) {
                  int posiportavioes;

                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação,\n a "
                        "posição acima começará a contruir o porat-aviões de "
                        "cima para baixo, diferente da posição abaixo,\n então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ2);
                    printf("Escolha a direção do PORTA-AVIÕES %d.\n", posiJ2);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posiportavioes);
                    limpar_buffer();
                    if (posiportavioes < 1 || posiportavioes > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    //-----
                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar o PORTA-AVIÕES %d.\n",
                           posiportavioes, posiJ2);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ2);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ2[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;

                    switch (posiportavioes) {
                    case 1: // CIMA
                      if (linha - 1 < 0 || linha - 2 < 0 || linha - 3 < 0 ||
                          linha - 4 < 0 ||
                          tabuleiroJ2[linha - 1][coluna] != ' ' ||
                          tabuleiroJ2[linha - 2][coluna] != ' ' ||
                          tabuleiroJ2[linha - 3][coluna] != ' ' ||
                          tabuleiroJ2[linha - 4][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ2[linha][coluna] = 'P';
                        tabuleiroJ2[linha - 1][coluna] = 'P';
                        tabuleiroJ2[linha - 2][coluna] = 'P';
                        tabuleiroJ2[linha - 3][coluna] = 'P';
                        tabuleiroJ2[linha - 4][coluna] = 'P';
                      }
                      break;

                    case 2: // BAIXO
                      if (linha + 1 >= 15 || linha + 2 >= 15 ||
                          linha + 3 >= 15 || linha + 4 >= 15 ||
                          tabuleiroJ2[linha + 1][coluna] != ' ' ||
                          tabuleiroJ2[linha + 2][coluna] != ' ' ||
                          tabuleiroJ2[linha + 3][coluna] != ' ' ||
                          tabuleiroJ2[linha + 4][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ2[linha][coluna] = 'P';
                        tabuleiroJ2[linha + 1][coluna] = 'P';
                        tabuleiroJ2[linha + 2][coluna] = 'P';
                        tabuleiroJ2[linha + 3][coluna] = 'P';
                        tabuleiroJ2[linha + 4][coluna] = 'P';
                      }
                      break;

                    case 3: // DIREITA
                      if (coluna + 1 >= 15 || coluna + 2 >= 15 ||
                          coluna + 3 >= 15 || coluna + 4 >= 15 ||
                          tabuleiroJ2[linha][coluna + 1] != ' ' ||
                          tabuleiroJ2[linha][coluna + 2] != ' ' ||
                          tabuleiroJ2[linha][coluna + 3] != ' ' ||
                          tabuleiroJ2[linha][coluna + 4] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ2[linha][coluna] = 'P';
                        tabuleiroJ2[linha][coluna + 1] = 'P';
                        tabuleiroJ2[linha][coluna + 2] = 'P';
                        tabuleiroJ2[linha][coluna + 3] = 'P';
                        tabuleiroJ2[linha][coluna + 4] = 'P';
                      }
                      break;

                    case 4: // ESQUERAA
                      if (coluna - 1 < 0 || coluna - 2 < 0 || coluna - 3 < 0 ||
                          coluna - 4 < 0 ||
                          tabuleiroJ2[linha][coluna - 1] != ' ' ||
                          tabuleiroJ2[linha][coluna - 2] != ' ' ||
                          tabuleiroJ2[linha][coluna - 3] != ' ' ||
                          tabuleiroJ2[linha][coluna - 4] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ2[linha][coluna] = 'P';
                        tabuleiroJ2[linha][coluna - 1] = 'P';
                        tabuleiroJ2[linha][coluna - 2] = 'P';
                        tabuleiroJ2[linha][coluna - 3] = 'P';
                        tabuleiroJ2[linha][coluna - 4] = 'P';
                      }
                      break;
                    }

                    // aqui eu verifico se a posição escolhida é valida
                    // negando o valor dado na logica no codigo acnima
                    if ((posiportavioes == 1 && !validacima) ||
                        (posiportavioes == 2 && !validabaixo) ||
                        (posiportavioes == 3 && !validadireita) ||
                        (posiportavioes == 4 && !validaesquerda)) {
                      printf("Posição inválida, tente novamente. O tamanho do "
                             "ENCOURAÇADO não esta dentro da matriz ou já "
                             "estão "
                             "ocupadas.\n");
                      continue;
                    }
                    break;
                  } while (1);
                }

                imprimir_tabuleiro(tabuleiroJ2);
                printf("\n\n");
                // CRUZADORES TRES UNIDADES
                for (int posiJ2 = 1; posiJ2 <= 3; posiJ2++) {
                  int posicruza;
                  do {
                    printf(
                        "Jogador %s \n Lembre-se a diferença da posição "
                        "'acima' e 'baixo' é o ponto de ferificação,\n a "
                        "posição acima começará a contruir o porat-aviões de "
                        "cima para baixo, diferente da posição abaixo,\n então "
                        "quando você for escolher o lugar da matriz que quer "
                        "posicionar o navio, leve isso em consideração.\n A "
                        "diferença de esquerda e direita é a mesma !\n\n",
                        nomeJ2);
                    printf("Escolha a direção do CRUZADORES %d.\n", posiJ2);
                    printf("Posições possíveis:\n");
                    printf("|   1. Acima ↑ \n");
                    printf("|   2. Abaixo ↓ \n");
                    printf("|   3. Direita ╍╍> \n");
                    printf("|   4. Esquerda <╍╍ \n");
                    scanf("%d", &posicruza);
                    limpar_buffer();
                    if (posicruza < 1 || posicruza > 4) {
                      printf("A posição escolhida não está disponível, tente "
                             "novamente! Para escolher uma posição escolha um "
                             "número de 1 a 4.\n");
                      continue;
                    }

                    //-----
                    printf("Agora que você escolheu a direção %d, escolha a "
                           "posição "
                           "na matriz onde deseja colocar os CRUZADORES %d.\n",
                           posicruza, posiJ2);

                    printf("Digite a linha de A a O:\n\n");
                    scanf(" %c", &letraMaiuscula);
                    limpar_buffer();
                    linha = letraMaiuscula - 'A';

                    if (linha < 0 || linha >= 15) {
                      printf(
                          "Linha inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    printf("Jogador %s", nomeJ2);
                    printf("Digite a coluna de 1 a 15:\n\n");
                    scanf("%d", &coluna);
                    limpar_buffer();
                    coluna--;

                    if (coluna < 0 || coluna >= 15) {
                      printf(
                          "Coluna inválida, tente novamente! Sua escolha pode "
                          "estar fora dos padrões da matriz 15x15!\n");
                      continue;
                    }

                    if (tabuleiroJ2[linha][coluna] != ' ') {
                      printf("Posição já ocupada, escolha outra posição.\n");
                      continue;
                    }

                    int validacima = 1, validabaixo = 1, validadireita = 1,
                        validaesquerda = 1;
                    switch (posicruza) {

                    case 1:
                      if (linha - 1 < 0 || linha - 2 < 0 ||
                          tabuleiroJ2[linha - 1][coluna] != ' ' ||
                          tabuleiroJ2[linha - 2][coluna] != ' ') {
                        validacima = 0;
                      }
                      if (validacima) {
                        tabuleiroJ2[linha][coluna] = 'C';
                        tabuleiroJ2[linha - 1][coluna] = 'C';
                        imprimir_tabuleiro(tabuleiroJ2);
                      }
                      break;

                    case 2:
                      if (linha + 1 >= 15 || linha + 2 >= 15 ||
                          tabuleiroJ2[linha + 1][coluna] != ' ' ||
                          tabuleiroJ2[linha + 2][coluna] != ' ') {
                        validabaixo = 0;
                      }
                      if (validabaixo) {
                        tabuleiroJ2[linha][coluna] = 'C';
                        tabuleiroJ2[linha + 1][coluna] = 'C';
                        imprimir_tabuleiro(tabuleiroJ2);
                      }
                      break;

                    case 3:
                      if (coluna + 1 >= 15 || coluna + 2 >= 15 ||
                          tabuleiroJ2[linha][coluna + 1] != ' ' ||
                          tabuleiroJ2[linha][coluna + 2] != ' ') {
                        validadireita = 0;
                      }
                      if (validadireita) {
                        tabuleiroJ2[linha][coluna] = 'C';
                        tabuleiroJ2[linha][coluna + 1] = 'C';
                        imprimir_tabuleiro(tabuleiroJ2);
                      }
                      break;

                    case 4:
                      if (coluna - 1 < 0 || coluna - 2 < 0 ||
                          tabuleiroJ2[linha][coluna - 1] != ' ' ||
                          tabuleiroJ2[linha][coluna - 2] != ' ') {
                        validaesquerda = 0;
                      }
                      if (validaesquerda) {
                        tabuleiroJ2[linha][coluna] = 'C';
                        tabuleiroJ2[linha][coluna - 1] = 'C';
                      }
                      break;
                    }
                    if ((posicruza == 1 && !validacima) ||
                        (posicruza == 2 && !validabaixo) ||
                        (posicruza == 3 && !validadireita) ||
                        (posicruza == 4 && !validaesquerda)) {
                      printf("Posição inválida, tente novamente. O tamanho do "
                             "ENCOURAÇADO não esta dentro da matriz ou já "
                             "estão "
                             "ocupadas.\n");
                      continue;
                    }
                    break;
                  } while (1);
                }

                system("clear");

                do {
                  system("clear");
                  // Turno do Jogador 1
                  tabuleiroCompara2(tabuleiroComp2);
                  printf("Jogador %s, é a sua vez de atacar!\n", nomeJ1);
                  printf("Digite a linha (A a O): ");
                  scanf(" %c", &letraMaiuscula);
                  limpar_buffer();
                  linha = toupper(letraMaiuscula) - 'A';
                  printf("Digite a coluna (1 a 15): ");
                  scanf("%d", &coluna);
                  limpar_buffer();
                  coluna--;

                  if (tabuleiroJ2[linha][coluna] != ' ') {
                    printf("Você acertou um navio!\n");
                    tabuleiroComp2[linha][coluna] = '#';
                    contJ1++;
                  } else {
                    printf("Você errou!\n");
                    tabuleiroComp2[linha][coluna] = '~';
                  }
                  tabuleiroCompara2(tabuleiroComp2);

                  if (contJ1 == 4) {
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
                    break;
                  }

                  system("clear");
                  tabuleiroCompara(tabuleiroComp);
                  // Turno do Jogador 2
                  printf("Jogador %s, é a sua vez de atacar!\n", nomeJ2);
                  printf("Digite a linha (A a O): ");
                  scanf(" %c", &letraMaiuscula);
                  limpar_buffer();
                  linha = toupper(letraMaiuscula) - 'A';
                  printf("Digite a coluna (1 a 15): ");
                  scanf("%d", &coluna);
                  limpar_buffer();
                  coluna--;

                  if (tabuleiroJ1[linha][coluna] != ' ') {
                    printf("Você acertou um navio!\n");
                    tabuleiroComp[linha][coluna] = '#';
                    contJ2++;
                  } else {
                    printf("Você errou!\n");
                    tabuleiroComp[linha][coluna] = '~';
                  }
                  tabuleiroCompara(tabuleiroComp);

                  if (contJ2 == 4) {
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
                    break;
                  }

                } while (contJ1 < 4 && contJ2 < 4);

                printf("Deseja jogar novamente?\n1 - Sim\n2 - Não, mudar de "
                       "modo\n");
                scanf("%d", &jogar_novamente);
                limpar_buffer();

                if (jogar_novamente == 1) {
                  
                  
                  continue;
                } else if (jogar_novamente == 2) {
                  // Sai do loop de jogar novamente e volta ao menu de modos
                  break;
                }
              } while (jogar_novamente == 1);
              break;
            }
            case 2:
              printf("Você escolheu a opção P x CPU\n");




              
              break;
            case 3:
              printf("Você escolheu a opção CPU x CPU\n");
              // Implementação da opção CPU x CPU
              break;
            default:
              printf("Opção inválida!\n");
              break;
            }
          } while (escolha != 0);
          break;
        }
        default:
          printf("Opção inválida!\n");
          break;
        }
      } while (escolha_matrizes != 0);
      break;
    }
    case 2:
      printf("Programa II\n");
      
      
      break;
    case 3:
      printf("Programa III\n");
      // Implementação do Programa III
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }
  } while (escolha_programa != 0);

  return 0;
}