#include <stdio.h>
#include <math.h>

void imprime_tabuleiro(char tabuleiro[7][7]) {
    system("cls");
    printf("        %c - %c - %c\n", tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4]);
    printf("        |  \\ /  |\n");
    printf("        %c - %c - %c\n", tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4]);
    printf("        |  / \\  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4], tabuleiro[2][5], tabuleiro[2][6]);
    printf("|  \\ /  |  \\ /  |  \\ /  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5], tabuleiro[3][6]);
    printf("|  / \\  |  / \\  |  / \\  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4], tabuleiro[4][5], tabuleiro[4][6]);
    printf("        |  \\ /  |\n");
    printf("        %c - %c - %c\n", tabuleiro[5][2], tabuleiro[5][3], tabuleiro[5][4]);
    printf("        |  / \\  |\n");
    printf("        %c - %c - %c\n", tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4]);
  return;
}

void proibido (char tabuleiro[7][7]) {
    int i, j;
    for (i = 0; i < 2 || (i > 4 && i < 7); i++) {
        for (j = 0; j < 2 || (j > 4 && j < 7); j++) {
        tabuleiro[i][j] = 'z';
        }
    }
}



void posicao_inicial (char tabuleiro[7][7]) {
    tabuleiro [2][0] = 'A';
    tabuleiro [3][0] = 'B';
    tabuleiro [4][0] = 'C';
    tabuleiro [4][1] = 'D';
    tabuleiro [4][2] = 'E';
    tabuleiro [4][3] = 'F';
    tabuleiro [4][4] = 'G';
    tabuleiro [4][5] = 'H';
    tabuleiro [4][6] = 'I';
    tabuleiro [3][6] = 'J';
    tabuleiro [2][6] = 'K';
    tabuleiro [5][2] = 'L';
    tabuleiro [5][3] = 'M';
    tabuleiro [5][4] = 'N';
    tabuleiro [6][2] = 'O';
    tabuleiro [6][3] = 'P';
    tabuleiro [6][4] = 'Q';
    tabuleiro [2][3] = 'Z';
}

void fox(char tabuleiro[7][7], int fox_i, int fox_j) {
    int fox_i, fox_j;
    int i, j;

    do {
    printf("Escolha uma linha e coluna validos (de 1 a 7) para mover a raposa:\n");
    scanf("%d %d", &i, &j);
    i = i - 1;
    j = j - 1;
    } while (i < 0  || j < 0);

//situacao para mover a raposa em 1 unidade valida
    if (tabuleiro[i][j] == 'x' && tabuleiro[i][j] != 'z') {
        if (fox_i - i = abs(1) && fox_j - i = abs(1) {
            tabuleiro[fox_i][fox_j] = x
            tabuleiro[i][j] = Z
            fox_i = i;
            fox_j = j;
         } 


//raposa come ganso
         if (abs(fox_i - i)  = 2 && abs(fox_j - i) = 2) && (fox_i + i / 2 == GOOSE POSITION && fox_j + j = GOOSE POSITION) {
             tabuleiro[(fox_i + i)/2][(fox_j + 1) /2] = x;
        tabuleiro[fox_i][fox_j] = x;
        tabuleiro[i][j] = Z;
        fox_i = i;
        fox_j = j;

        }
    }

    else {
        do {
             printf("Escolha uma linha e coluna validos (de 1 a 7) para mover a raposa:\n");
             scanf("%d %d", &i, &j);
         } while (i < 0  || j < 0);

    }

}




int main() {
    int i, j;
    char tabuleiro[7][7];

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
        tabuleiro[i][j] = 'x';
        }
    }

    fox_i = 2;
    fox_j = 3;

    posicao_inicial(tabuleiro);
    imprime_tabuleiro(tabuleiro);
    fox(tabuleiro, fox_i, fox_j);

return(0);
}