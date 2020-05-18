#include <stdio.h>
void imprime_tabuleiro(char tabuleiro[7][7]) {
    system("cls"); // para linux: system("clear");
    printf("        %c - %c - %c\n", tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4]);
    printf("        |  \\ /  |\n");
    printf("        %c - %c - %c\n", tabuleiro[1][2], tabuleiro[0][3], tabuleiro[0][4]);
    printf("        |  / \\  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4], tabuleiro[2][5], tabuleiro[2][6]);
    printf("|  \\ /  |  \\ /  |  \\ /  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5], tabuleiro[3][6]);
    printf("|  / \\  |  / \\  |  / \\  |\n");
    printf("%c - %c - %c - % c - %c - %c - %c\n", tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4], tabuleiro[4][5], tabuleiro[4][6]);
    printf("        |  \\ /  |\n");
    printf("        %c - %c - %c\n", tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4]);
    printf("        |  / \\  |\n");
    printf("        %c - %c - %c\n", tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4]);
  return;
}



int main() {
    int i, j;
    char tabuleiro[7][7];



    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
        tabuleiro[i][j] = 'x';
        }
    }
    imprime_tabuleiro(tabuleiro);



return(0);
}
