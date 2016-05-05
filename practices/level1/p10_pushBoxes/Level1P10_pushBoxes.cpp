#include <stdio.h>
#include <stdlib.h>
#include <string>

#define ROAD 0
#define POINT 1
#define BOX 4
#define MAN 2
#define WALL 13
#define MAPLENGTH 21
#define BOXONPOINT 40

int map[21][21];
int manX, manY,totalBox,totalStep,minStep,mapNum;
int manOnPoint = 0, boxOK = 0;
char ch;		//���ch���ƶ��ã��ֲ����������������Ϊʲô = =#
void printMap();
void refreshScore();
void chooseMap();
void readMap(int choice);
void refresh();
void control();
void move(int dx,int dy);


int main() {
	chooseMap();
	printMap();
	control();
	return 0;
}

void control() {
	printf("ʹ��wasd���Ƴ���������\n");
	printf("������ٲ�����%d\t�ܲ�����%d\n", minStep,totalStep);
	scanf("%s", &ch);
	totalStep++;
	switch (ch)
	{
	case 'w':
		move(-1,0);
		break;
	case 's':
		move(1, 0);
		break;
	case 'a':
		move(0, -1);
		break;
	case 'd':
		move(0, 1);
		break;
	default:
		break;
	}
	refresh();
}

void refresh() {
	system("cls");
	if (totalBox == boxOK)
	{
		if (totalStep < minStep)
		{
			refreshScore();
		}
		printf("��л���Ŭ�������������ɹ��ˣ�\n");
		printf("���س����ص�ͼѡ��\n");
		getchar();
		getchar();
		system("cls");
		chooseMap();
	}
	else
	{
		printMap();
		control();
	}
}


void chooseMap() {
	printf("��ѡ���ͼ(1~2)��\n");
	int choice;
	scanf("%d",&choice);
	readMap(choice);
	system("cls");
}

void readMap(int choice) {
	FILE *fp;
	switch (choice)
	{
	case 1:
		fp = fopen("map1.txt", "rt");
		mapNum = 1;
		break;
	case 2:
		fp = fopen("map2.txt", "rt");
		mapNum = 2;
		break;

	default:
		fp = fopen("map1.txt", "rt");
		mapNum = 1;
		break;
	}
	char buff[1000], buff2[1000];
	char *tem;
	fgets(buff, 1000, fp);
	strcpy(buff2, buff);
	tem = strtok(buff2, ",");
	minStep = atoi(tem);
	tem = strtok(NULL, ",");
	totalBox = atoi(tem);
	tem = strtok(NULL, ",");
	manX = atoi(tem);
	tem = strtok(NULL, ",");
	manY = atoi(tem);
	for (int i = 0; i < MAPLENGTH; i++)
	{
		for (int j = 0; j < MAPLENGTH; j++)
		{
			tem = strtok(NULL, ",");
			map[i][j] = atoi(tem);
		}
	}
	fclose(fp);
}

void printMap() {
	for (int i = 0; i < MAPLENGTH; i++)
	{
		for (int j = 0; j < MAPLENGTH; j++)
		{
			switch (map[i][j]) {
			case ROAD:
				printf("  ");
				break;
			case WALL:
				printf("�~");
				break;
			case MAN:
				printf("��");
				break;
			case BOX:
				printf("��");
				break;
			case POINT:
				printf("��");
				break;
			case BOXONPOINT:
				printf("+1");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
} 

void refreshScore() {
	FILE *fp;
	switch (mapNum)
	{
	case 1:
		readMap(1);
		remove("map1.txt");
		fp = fopen("map1.txt", "a+");
		break;
	case 2:
		readMap(2);
		remove("map2.txt");
		fp = fopen("map2.txt", "a+");
		break;
	default:
		readMap(1);
		remove("map1.txt");
		fp = fopen("map1.txt", "a+");
		break;

	}
	fprintf(fp, "%d,", totalStep);
	fprintf(fp, "%d,", totalBox);
	fprintf(fp, "%d,", manX);
	fprintf(fp, "%d,", manY);
	for (int i = 0; i < MAPLENGTH; i++)
	{
		for (int j = 0; j < MAPLENGTH; j++)
		{
			fprintf(fp, "%d,", map[i][j]);
		}
	}
	fclose(fp);
}


//����Ϊ�˶�������һ��28�����
void move(int dx,int dy) {
	int type = map[manX+dx][manY + dy] + 2 * map[manX+2*dx][manY+2*dy] + manOnPoint;
	switch (type)
	{
	case 0:		//��··
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 1:		//�˵�·
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 2:		//��·��
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 3:		//�˵��
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 4:		//����·
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOX;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 6:		//�����
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOXONPOINT;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		boxOK++;
		break;

	case 8:		//��·��
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;	
	case 9:		//�˵���
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 26:	//��·ǽ
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 27:		//�˵�ǽ
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 40:		//��+1·
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOX;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		boxOK--;
		break;
	case 42:		//��+1��
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOXONPOINT;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 96:		//��·+1
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 81:		//�˵�+1
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 100:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 101:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 102:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 103:
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 104:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOX;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 106:		//�����2
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOXONPOINT;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		boxOK++;
		break;
	case 108:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 109:		//�˵���2
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 126:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 127:
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 140:		//��+1·2
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOX;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		boxOK--;
		break;
	case 142:		//��+1��2
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		map[manX + 2 * dx][manY + 2 * dy] = BOXONPOINT;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	case 180:		//��·+12
		map[manX][manY] = POINT;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 0;
		break;
	case 181:		//�˵�+1
		map[manX][manY] = ROAD;
		map[manX + dx][manY + dy] = MAN;
		manX = manX + dx;
		manY = manY + dy;
		manOnPoint = 100;
		break;
	default:
		break;
	}
}