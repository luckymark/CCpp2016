#include <stdio.h>
#include <stdlib.h>
void map();
void move();
int judge(int m,int n);
int victory(int m,int n);

char position[10][11] = { "**********",
						  "**     I**",
					      "** *******",
						  "**    ****",
						  "*  ** ****",
						  "* ***   **",
						  "* **  ****",
						  "* **    **",
						  "* ***** **",
						  "******  o*\n" };
int main()
{


	printf("w:向上 s:向下 a:向左 d:向右\n o为终点处\n");
	printf("按下任意键开始游戏\n");
	system("pause");
	system("cls");
	map();
	move();



}
void map() {

	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			printf("%c", position[i][j]);
		}
		printf("\n");
	}

}
void move() {
	char I;
	int m = 1, n = 7;
	while (1) {

		I = getch();
		switch (I) {

		case 'w': {int y1 = judge(m - 1, n);
			if (y1 != 0) {
				position[m][n] = ' ';
				m = m - 1;
				position[m][n] = 'I';
				system("cls");
				map();
				printf("w:向上 s:向下 a:向左 d:向右\n o为终点处");

			}
			else {
				break;
			}
			break;
		}

		case 's': { int y2 = judge(m + 1, n);
			if (y2 != 0) {

				position[m][n] = ' ';
				m = m + 1;
				position[m][n] = 'I';
				system("cls");
				map();
				printf("w:向上 s:向下 a:向左 d:向右\n按enter确认指令 o为终点处");

			}
			else {
				break;
			}
			break;
		}
		case 'a': { int y3 = judge(m, n - 1);
			if (y3 != 0) {

				position[m][n] = ' ';
				n = n - 1;
				position[m][n] = 'I';
				system("cls");
				map();
				printf("w:向上 s:向下 a:向左 d:向右\n按enter确认指令 o为终点处");

			}
			else {
				break;
			}
			break;
		}
		case 'd': { int y4 = judge(m, n + 1);
			if (y4 != 0) {

				position[m][n] = ' ';
				n = n + 1;
				position[m][n] = 'I';
				system("cls");
				map();
				printf("w:向上 s:向下 a:向左 d:向右\n按enter确认指令 o为终点处");

			}
			else {
				break;
			}
			break;
		}
        default:
            break;
		}


        victory(m,n);

	}
}
int judge(int m, int n) {

	if (position[m][n] == '*') {
		return 0;
	}
}
int victory(int m,int n){
    if(m==8,n==8){
        system("cls");
        printf("victory!\n按下任意键退出游戏");
        exit(0);
    }
}
