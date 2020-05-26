#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

void printT();            //Imprime o tabuleiro
void moveP1(int m[4][4]); //Move o primeiro jogador (a raposa)
void moveP2(int m[4][4]); //Move o segundo jogador (o ganso)
void actF();              //A��o do primeiro jogador (a raposa)
void actG();              //A��o do segundo jogador (o ganso)

fasfsafsa
fas
fsa
f
a
fsa
f
saf
a
f



int i, j, r = 0, x = 2, y = 3, w = 0, p = 0, g = 0, xo, yo, q = 0;
char n[7][7], s;

int main () {
	int m[4][4], x1, y1;

	//Construindo o tabuleiro:
	for (i = 0; i <= 6; i++) {
		for (j = 0; j <= 6; j++) {
			n[i][j] = '.';
		}
	}
	n[2][0] = 'A'; n[2][3] = 'Z'; n[2][6] = 'K'; n[3][0] = 'B'; n[3][6] = 'J'; n[4][0] = 'C'; n[4][1] = 'D'; n[4][2] = 'E';
    n[4][3] = 'F'; n[4][4] = 'G'; n[4][5] = 'H'; n[4][6] = 'I'; n[5][2] = 'L'; n[5][3] = 'M'; n[5][4] = 'N'; n[6][2] = 'O';
    n[6][3] = 'P'; n[6][4] = 'Q';

	printT();

    //Inicio do jogo.
	while(!GetAsyncKeyState(VK_ESCAPE) && w == 0) {

		m[0][0] = GetAsyncKeyState(0x64);
		m[0][1] = GetAsyncKeyState(0x66);
		m[0][2] = GetAsyncKeyState(0x62);
		m[0][3] = GetAsyncKeyState(0x68);
		m[1][0] = GetAsyncKeyState(0x61);
		m[1][1] = GetAsyncKeyState(0x63);
		m[1][2] = GetAsyncKeyState(0x67);
		m[1][3] = GetAsyncKeyState(0x69);
		m[2][0] = GetAsyncKeyState(0x41);
		m[2][1] = GetAsyncKeyState(0x44);
		m[2][2] = GetAsyncKeyState(0x58);
		m[2][3] = GetAsyncKeyState(0x57);
		m[3][0] = GetAsyncKeyState(0x5A);
		m[3][1] = GetAsyncKeyState(0x43);
		m[3][2] = GetAsyncKeyState(0x51);
		m[3][3] = GetAsyncKeyState(0x45);

		if (q == 0) moveP1(m);
		if (q == 0) actF();
		if (q == 1) moveP2(m);
      if (q == 1) actG();

        for (i = 0; i <= 4; i++) {
		    for (j = 0; j <= 4; j++) {
			    m[i][j] = 0;
		    }
	    }

        //Verifica se alguem ganhou:
        for (i = 0; i <= 6; i++) {
			for (j = 0; j <= 6; j++) {
				if (n[i][j] != '.') g++;
			}
		}
		if (g <= 5) w = 1;
		else g = 0;

        /*for (i = 0; i <= 6; i++) {
			for (j = 0; j <= 6; j++) {
			    if (n[i][j] == 'Z') {
					x1 = i;
					y1 = j;
			    }
			}
		}

		if (n[x1-1][y1-1] != '.' && n[x1-1][y1] != '.' && n[x1-1][y1+1] != '.' && n[x1][y1-1] != '.') {
			if (n[x1][y1+1] != '.' && n[x1+1][y1+1] != '.' && n[x1+1][y1] != '.' && n[x1+1][y1+1] != '.') w = 2;
		}*/
    } //Fim do jogo.

    //Verificando quem ganhou:
	if (w == 1) {
		system("color 0a");
		printf("\n     A RAPOSA GANHOU!!!\n");
	}
	if (w == 2) {
		system("color 0a");
		printf("\n     O GANSO GANHOU!!!\n");
	}

	getch();
}

void printT() { //Imprime o tabuleiro
	system("color 0c");
	system("clear||cls");

	//Primeira parte do tabuleiro:
	for (i = 0; i <= 1; i++) {
		printf("        ");
		for (j = 2; j <= 4; j++) {
			if (i == x && j == y) printf("[%c]", n[i][j]);
			else printf(" %c ", n[i][j]);
			if (j < 4) printf("-");
			}
			printf("\n");
			printf("         ");
		if (i == 0) printf("| \\ | / | \n");
		if (i == 1) printf("| / | \\ | \n");
	}

    //Segunda parte do tabuleiro:
	for (i = 2; i <= 4; i++) {
		for (j = 0; j <= 6; j++) {
			if (i == x && j == y) printf("[%c]", n[i][j]);
			else printf(" %c ", n[i][j]);
			if (j < 6) printf("-");
			}
			printf("\n");
		if (i == 2) printf(" | \\ | / | \\ | / | \\ | / |\n");
		if (i == 3) printf(" | / | \\ | / | \\ | / | \\ |\n");
	}

	//Terceira parte do tabuleiro:
	for (i = 5; i <= 6; i++) {
		printf("         ");
		if (i == 5) printf("| \\ | / | \n");
		if (i == 6) printf("| / | \\ | \n");
		printf("        ");
		for (j = 2; j <= 4; j++) {
			if (i == x && j == y) printf("[%c]", n[i][j]);
			else printf(" %c ", n[i][j]);
			if (j < 4) printf("-");
			}
			printf("\n");
	}
}

void moveP1(int m[4][4]) { //Move o primeiro jogador (a raposa)
	if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) { //Esquerda
		if (m[0][0] != 0 && y > 0) { y--; printT(); }
	}
	if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) { //Direita
		if (m[0][1] != 0 && y < 6) { y++; printT(); }
	}
	if (x != 4 || y != 0 && y != 1 && y != 5 && y != 6) { //Baixo
		if (m[0][2] != 0 && x < 6) { x++; printT(); }
	}
	if (x != 2 || y != 0 && y != 1 && y != 5 && y != 6) { //Cima
		if (m[0][3] != 0 && x > 0) { x--; printT(); }
	}
	if ((x + y)%2 == 0) {
		if (x != 4 || y != 0 && y != 1 && y != 2 && y != 5 && y != 6) { //Baixo-Esquerda
		    if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[1][0] != 0 && x < 6 && y > 0) { x++; y--; printT(); }
		    }
	    }
	    if (x != 4 || y != 0 && y != 1 && y != 4 && y != 5 && y != 6) { //Baixo-Direita
		    if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[1][1] != 0 && x < 6 && y < 6) { x++; y++; printT(); }
		    }
	    }
	    if (x != 2 || y != 0 && y != 1 && y != 2 && y != 5 && y != 6) { //Cima-Esquerda
	        if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[1][2] != 0 && x > 0 && y > 0) { x--; y--; printT(); }
		    }
	    }
	    if (x != 2 || y != 0 && y != 1 && y != 4 && y != 5 && y != 6) { //Cima-Direita
		    if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[1][3] != 0 && x > 0 && y < 6) { x--; y++; printT(); }
		    }
	    }
    }
}

void moveP2(int m[4][4]) { //Move o segundo jogador (o ganso)
	if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) { //Esquerda
		if (m[2][0] != 0 && y > 0) { y--; printT(); }
	}
	if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) { //Direita
		if (m[2][1] != 0 && y < 6) { y++; printT(); }
	}
	if (x != 4 || y != 0 && y != 1 && y != 5 && y != 6) { //Baixo
		if (m[2][2] != 0 && x < 6) { x++; printT(); }
	}
	if (x != 2 || y != 0 && y != 1 && y != 5 && y != 6) { //Cima
		if (m[2][3] != 0 && x > 0) { x--; printT(); }
	}
	if ((x + y)%2 == 0) {
	    if (x != 4 || y != 0 && y != 1 && y != 2 && y != 5 && y != 6) { //Baixo-Esquerda
		    if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[3][0] != 0 && x < 6 && y > 0) { x++; y--; printT(); }
		    }
	    }
	    if (x != 4 || y != 0 && y != 1 && y != 4 && y != 5 && y != 6) { //Baixo-Direita
		    if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[3][1] != 0 && x < 6 && y < 6) { x++; y++; printT(); }
		    }
	    }
	    if (x != 2 || y != 0 && y != 1 && y != 2 && y != 5 && y != 6) { //Cima-Esquerda
	        if (y != 2 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[3][2] != 0 && x > 0 && y > 0) { x--; y--; printT(); }
		    }
	    }
	    if (x != 2 || y != 0 && y != 1 && y != 4 && y != 5 && y != 6) { //Cima-Direita
		    if (y != 4 || x != 0 && x != 1 && x != 5 && x != 6) {
		        if (m[3][3] != 0 && x > 0 && y < 6) { x--; y++; printT(); }
		    }
	    }
    }
}

void actF() { //A��o do primeiro jogador (a raposa)
	if (GetAsyncKeyState(VK_SPACE) != 0 && p == 0 && n[x][y] == 'Z') {
		s = n[x][y];
		xo = x;
		yo = y;
		p = 1;
		printT();
	}
	if (GetAsyncKeyState(VK_SPACE) != 0 && p == 1 && n[x][y] == '.') {
		//if(x >= xo - 1 && x <= xo + 1 && y >= yo - 1 && y <= yo + 1) {
		   n[x][y] = s;
		   n[xo][yo] = '.';
		   p = 0;
		   printT();
		   q = 1;
		//}
    }
}

void actG() { //A��o do segundo jogador (o ganso)
	if (GetAsyncKeyState(VK_SPACE) != 0 && p == 0 && n[x][y] != '.' && n[x][y] != 'Z') {
		s = n[x][y];
		xo = x;
		yo = y;
		p = 1;
		printT();
	}
	if (GetAsyncKeyState(VK_SPACE) != 0 && p == 1 && n[x][y] == '.') {
		//if(x >= xo - 1 && x <= xo + 1 && y >= yo - 1 && y <= yo + 1/* && (xo + yo)%2 == 0*/) {
		   n[x][y] = s;
		   n[xo][yo] = '.';
		   p = 0;
		   printT();
		   q = 0;
		//}
    }
}
