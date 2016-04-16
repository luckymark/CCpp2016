//Eric 2016-03-06 00:44:35
//p09_pushBoxes
//windows

#include <stdio.h>
#include <conio.h>	//use the _getch() function
#include <stdlib.h>	//use system() function
#include <string.h>

#define MAPLENGTH 10
#define PASSMAX 3

int word2number[2][200] = { 0 };

void commandList(void);
void startGame(void);
void loadBox(int numPass);
void game(void);
void gameRuning(int countGamePass);
int getCheckCommand(int *humanRow, int *humanColumn, int *score);	//1 成功
void showMapScore(int score);
void getHumanLocation(int *humanRow, int *humanColumn);
int succeedCheck(void);
void scoreStore(int score, int countGamePass);

#define BLANK 0
#define BLOCK 1
#define HUMAN 2
#define BOX 3
#define BASE 1
#define MAPROLE 2
int _boxMap[MAPLENGTH][MAPLENGTH][MAPROLE];
/*在[0]中 0 空白 1 墙 * 2 人 O 3 箱子 @
[1]1 终点 +*/

int main(void)
{
	commandList();
	startGame();

	system("pause");
	return 0;
}

void commandList(void)
{
	printf("a.Start Game\nq.quit: ");
}

void startGame(void)
{
	switch (getchar())
	{
	case 'a':
		game();
	case 'q':
		printf("Done.");
		break;
	default:
		printf("Error : Wrong Command");
	}
}

void game(void)
{
	int countGamePass;
	for (countGamePass = 0; countGamePass < PASSMAX; countGamePass++)
	{
		loadBox(countGamePass);
		gameRuning(countGamePass);
		system("cls");
		printf("Will you continue the game?(y/n): ");
		while (getchar() != '\n');
		switch (getchar())
		{
		case 'y':
			break;
		case 'n':
			printf("Done!");
			return;
		default:
			printf("Error : Wrong Command.");
			break;
		}
	}
	printf("Sorry, no more game.");
}

void loadBox(int numPass)
{
	FILE *boxMap;
	boxMap = fopen("boxMap.txt", "r");
	if (boxMap == NULL)
	{
		printf("ERROR : There is no map files!");
		return;
	}
	//定位指针到相应关卡
	fseek(boxMap, numPass * MAPLENGTH * MAPLENGTH * MAPROLE, 0);
	//清空map
	memset(_boxMap, 0, sizeof(_boxMap));
	//加载
	for (int mapRole = 0; mapRole < MAPROLE; mapRole++)
	{
		for (int mapRow = 0; mapRow < MAPLENGTH; mapRow++)
		{
			for (int mapColumn = 0; mapColumn < MAPLENGTH; mapColumn++)
			{
				//_boxMap[mapRow][mapColumn][mapRole] = fgetc(boxMap);
				fscanf(boxMap, "%1d", &_boxMap[mapRow][mapColumn][mapRole]);
			}
		}
	}
	fclose(boxMap);
}

void gameRuning(int countGamePass)
{
	word2number[0]['w'] = -1;
	word2number[0]['s'] = 1;
	word2number[1]['a'] = -1;
	word2number[1]['d'] = 1;

	int humanLocationRow, humanLocationColumn, score = 0;

	getHumanLocation(&humanLocationRow, &humanLocationColumn);
	while (1)
	{
		showMapScore(score);
		if (getCheckCommand(&humanLocationRow, &humanLocationColumn, &score))
		{
			//写入成绩
			scoreStore(score, countGamePass);
			printf("Done!");
			system("pause");
			return;
		}
	}
}
void getHumanLocation(int *humanRow, int *humanColumn)
{
	for (int row = 0; row < MAPLENGTH; row++)
	{
		for (int column = 0; column < MAPLENGTH; column++)
		{
			if (_boxMap[row][column][0] == HUMAN)
			{
				(*humanRow) = row;
				(*humanColumn) = column;
				return;
			}
		}
	}
}

void showMapScore(int score)
{
	system("cls");
	//show map
	for (int row = 0; row < MAPLENGTH; row++)
	{
		for (int column = 0; column < MAPLENGTH; column++)
		{
			switch (_boxMap[row][column][0])
			{
			case BLANK:
				if (_boxMap[row][column][1] == BASE)
				{
					printf("+");
				}
				else
				{
					printf(" ");
				}
				break;
			case BOX:
				printf("@");
				break;
			case BLOCK:
				printf("*");
				break;
			case HUMAN:
				printf("O");
				break;
			default:

				printf("ERROR : WRONG MAP");
			}
		}
		printf("\n");
	}
	//show score
	printf("Score : %d\n", score);
}

int getCheckCommand(int *humanRow, int *humanColumn, int *score)
{
	char tempOrder;
	tempOrder = _getch();
	int tempLocationRow = (*humanRow), tempLocationColumn = (*humanColumn);
	tempLocationRow += word2number[0][tempOrder];
	tempLocationColumn += word2number[1][tempOrder];
	switch (_boxMap[tempLocationRow][tempLocationColumn][0])
	{
	case BOX:
		if (_boxMap[tempLocationRow + word2number[0][tempOrder]][tempLocationColumn + word2number[1][tempOrder]][0] == BLANK)
			//判断箱子之前的状态 通过四周都有墙来避免对范围的检查
		{
			//向前推箱子
			_boxMap[tempLocationRow + word2number[0][tempOrder]][tempLocationColumn + word2number[1][tempOrder]][0] = BOX;
		}
		else
		{
			return 0;
		}
	case BLANK:
		//移动人 并把原来的位置定为空
		_boxMap[tempLocationRow][tempLocationColumn][0] = HUMAN;
		_boxMap[(*humanRow)][(*humanColumn)][0] = BLANK;
		//移动标识
		(*humanRow) = tempLocationRow;
		(*humanColumn) = tempLocationColumn;
		//移动步数加分 虽然不合常理 但是推箱子怎么按步数计分？_(:-|_|)==
		(*score)++;
		//检查游戏是否完成
		if (succeedCheck())
		{
			return 1;
		}
	case BLOCK:
		break;
	default:
		printf("ERROR : getCheckCommand switch wrong");
	}

	return 0;
}
int succeedCheck(void)
{
	for (int row = 0; row < MAPLENGTH; row++)
	{
		for (int column = 0; column < MAPLENGTH; column++)
		{
			if (_boxMap[row][column][1] == BASE && _boxMap[row][column][0] != BOX)
			{
				return 0;
			}
		}
	}
	return 1;
}

void scoreStore(int score, int countGamePass)
{
	FILE *scoreFile;
	scoreFile = fopen("score.txt", "a");
	if (scoreFile == NULL)
	{
		printf("Can't write the score into file.");
		return;
	}
	else
	{
		fseek(scoreFile, 0, SEEK_END);
		fprintf(scoreFile, "The No.%02d Pass : %d\n", countGamePass + 1, score);
		fclose(scoreFile);
	}
}