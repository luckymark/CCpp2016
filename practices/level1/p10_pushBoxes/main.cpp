#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int point = 0;
int steps = -1;
int score = 0;
int wrong = 0;
void start();
void move1();
void move2();
void move3();
int main() {
	start();
	system("cls");
	printf("your total steps are %d\n", steps);
	printf("your final score is %d\n", score - steps);
	printf("enter any key to exit ");
	system("pause");

}
void start() {
	printf("plese read before you play!\nI for you;T for goods;B for box,\n");
	printf("now you should help push away the goods in box\nbut make sure that \nyou won't stand on the goods;for it is crispy!");
	system("pause");
	while ((wrong == 0) || (point == 3)) {
		if (point == 0) {
			system("cls");
			printf("level 1\n");
			system("pause");
			move1();
		}
		if (point == 1) {
			system("cls");
			score = score + 10;
			printf("level 2\n");
			system("pause");
			move2();

		}
		if (point == 2) {
			system("cls");
			printf("level 3\n");
			system("pause");
			score = score + 20;
			move3();

		}
		score = score + 30;
	}
}
void move1() {
	int i = 1, j = 1;
	char map[8][8] = { "*******",
		 	   "*I  T *",
			   "*   B *",
			   "*     *",
			   "*  B T*",
		     	   "*     *",
			   "*     *",
			  "*******" };
	while (1) {
		steps++;
		int countO = 0, countX = 0;
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				if (map[k][q] == 'X') {
					countX++;
				}
				else if (map[k][q] == 'O') {
					countO++;
				}
			}
		}
		if (countX != 0) {
			wrong++;
			system("cls");
			printf("move wrong!\n game over\n");
			getch();
			break;
		}
		if (countO == 2) {
			system("cls");
			printf("victory\n");
			point++;
			system("pause");
			break;
		}
		system("cls");
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				printf("%c", map[k][q]);

			}
			printf("\n");
		}
		char X = getch();
		switch (X) {
		default:
			break;
		case'd':
			if (map[i][j + 1] != '*')
			{
				if (map[i][j + 1] == ' ') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j + 1] == 'B') && (map[i][j + 2] != '*')) {
					if (map[i][j + 2] != 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'B';
					}
					else if (map[i][j + 2] == 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'O';
					}
				}
				else if (map[i][j + 1] == 'T') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}

		case'a':
			if (map[i][j - 1] != '*')
			{
				if (map[i][j - 1] == ' ') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j - 2] != '*') && (map[i][j - 1] == 'B')) {
					if (map[i][j - 2] != 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'B';
					}
					else if (map[i][j - 2] == 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'O';
					}

				}

				else if (map[i][j - 1] == 'T') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}
		case'w':
			if (map[i - 1][j] != '*') {
				if (map[i - 1][j] == ' ') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i - 2][j] != '*') && (map[i - 1][j] == 'B')) {
					if (map[i - 2][j] != 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'B';
					}
					else if (map[i - 2][j] == 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'O';
					}
				}
				else if (map[i - 1][j] == 'T') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;

		case's':
			if (map[i + 1][j] != '*')
			{
				if (map[i][j + 1] == ' ') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
				}
			}
			else if ((map[i + 2][j] != '*') && (map[i + 1][j] == 'B')) {
				if (map[i + 2][j] != 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'B';
				}
				else if (map[i + 2][j] == 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'O';
				}
			}
			else if (map[i + 1][j] == 'T') {
				i++;
				map[i - 1][j] = ' ';
				map[i][j] = 'X';
			}
			system("cls");
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					printf("%c", map[k][q]);

				}
				printf("\n");
			}
			break;
			}
		}
	}
}
void move2() {
	int i = 1, j = 1;
	char map[8][8] = { "*******",
			   "*I *T *",
			   "*     *",
			   "*     *",
			   "*  *B *",
			   "*     *",
			   "*******" };
	while (1) {
		steps++;
		int countO = 0, countX = 0;
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				if (map[k][q] == 'X') {
					countX++;
				}
				else if (map[k][q] == 'O') {
					countO++;
				}
			}
		}
		if (countX != 0) {
			wrong++;
			system("cls");
			printf("move wrong!\n game over\n");
			getch();
			break;
		}
		if (countO == 1) {
			system("cls");
			point++;
			printf("victory\n");
			printf("\n");
			system("pause");
			break;
		}
		system("cls");
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				printf("%c", map[k][q]);

			}
			printf("\n");
		}
		
		char X = getch();
		switch (X) {
		default:
			break;
		case'd':
			if (map[i][j + 1] != '*')
			{
				if (map[i][j + 1] == ' ') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j + 1] == 'B') && (map[i][j + 2] != '*')) {
					if (map[i][j + 2] != 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'B';
					}
					else if (map[i][j + 2] == 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'O';
					}
				}
				else if (map[i][j + 1] == 'T') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}

		case'a':
			if (map[i][j - 1] != '*')
			{
				if (map[i][j - 1] == ' ') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j - 2] != '*') && (map[i][j - 1] == 'B')) {
					if (map[i][j - 2] != 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'B';
					}
					else if (map[i][j - 2] == 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'O';
					}

				}

				else if (map[i][j - 1] == 'T') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}
		case'w':
			if (map[i - 1][j] != '*') {
				if (map[i - 1][j] == ' ') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i - 2][j] != '*') && (map[i - 1][j] == 'B')) {
					if (map[i - 2][j] != 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'B';
					}
					else if (map[i - 2][j] == 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'O';
					}
				}
				else if (map[i - 1][j] == 'T') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;

		case's':
			if (map[i + 1][j] != '*')
			{
				if (map[i][j + 1] == ' ') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
				}
			}
			else if ((map[i + 2][j] != '*') && (map[i + 1][j] == 'B')) {
				if (map[i + 2][j] != 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'B';
				}
				else if (map[i + 2][j] == 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'O';
				}
			}
			else if (map[i + 1][j] == 'T') {
				i++;
				map[i - 1][j] = ' ';
				map[i][j] = 'X';
			}
			system("cls");
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					printf("%c", map[k][q]);

				}
				printf("\n");
			}
			break;
			}
		}
	
	}
	
}
void move3() {
	int i = 1, j = 1;
	char map[8][8] = { "*******",
			   "*I B T*",
			   "*  B T*",
		   	   "*  * T*",
			   "*  * B*",
			   "*     *",
			   "*******" };
	while (1) {
		steps++;
		int countO = 0, countX = 0;
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				if (map[k][q] == 'X') {
					countX++;
				}
				else if (map[k][q] == 'O') {
					countO++;
				}
			}
		}
		if (countX != 0) {
			wrong++;
			system("cls");
			printf("move wrong!\n game over\n");
			getch();
			break;
		}
		if (countO == 3) {
			system("cls");
			point++;
			printf("victory\n");
			system("pause");
			break;
		}
		system("cls");
		for (int k = 0; k < 8; k++) {
			for (int q = 0; q < 8; q++) {
				printf("%c", map[k][q]);

			}
			printf("\n");
		}
		char X = getch();
		switch (X) {
		default:
			break;
		case'd':
			if (map[i][j + 1] != '*')
			{
				if (map[i][j + 1] == ' ') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j + 1] == 'B') && (map[i][j + 2] != '*')) {
					if (map[i][j + 2] != 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'B';
					}
					else if (map[i][j + 2] == 'T') {
						j++;
						map[i][j - 1] = ' ';
						map[i][j] = 'I';
						map[i][j + 1] = 'O';
					}
				}
				else if (map[i][j + 1] == 'T') {
					j++;
					map[i][j - 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}

		case'a':
			if (map[i][j - 1] != '*')
			{
				if (map[i][j - 1] == ' ') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i][j - 2] != '*') && (map[i][j - 1] == 'B')) {
					if (map[i][j - 2] != 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'B';
					}
					else if (map[i][j - 2] == 'T') {
						j--;
						map[i][j + 1] = ' ';
						map[i][j] = 'I';
						map[i][j - 1] = 'O';
					}

				}

				else if (map[i][j - 1] == 'T') {
					j--;
					map[i][j + 1] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;
			}
		case'w':
			if (map[i - 1][j] != '*') {
				if (map[i - 1][j] == ' ') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'I';
				}
				else if ((map[i - 2][j] != '*') && (map[i - 1][j] == 'B')) {
					if (map[i - 2][j] != 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'B';
					}
					else if (map[i - 2][j] == 'T') {
						i--;
						map[i + 1][j] = ' ';
						map[i][j] = 'I';
						map[i - 1][j] = 'O';
					}
				}
				else if (map[i - 1][j] == 'T') {
					i--;
					map[i + 1][j] = ' ';
					map[i][j] = 'X';
				}
				system("cls");
				for (int k = 0; k < 8; k++) {
					for (int q = 0; q < 8; q++) {
						printf("%c", map[k][q]);

					}
					printf("\n");
				}
				break;

		case's':
			if (map[i + 1][j] != '*')
			{
				if (map[i][j + 1] == ' ') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
				}
			}
			else if ((map[i + 2][j] != '*') && (map[i + 1][j] == 'B')) {
				if (map[i + 2][j] != 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'B';
				}
				else if (map[i + 2][j] == 'T') {
					i++;
					map[i - 1][j] = ' ';
					map[i][j] = 'I';
					map[i + 1][j] = 'O';
				}
			}
			else if (map[i + 1][j] == 'T') {
				i++;
				map[i - 1][j] = ' ';
				map[i][j] = 'X';
			}
			system("cls");
			for (int k = 0; k < 8; k++) {
				for (int q = 0; q < 8; q++) {
					printf("%c", map[k][q]);

				}
				printf("\n");
			}
			break;
			}
		}
	}
}
