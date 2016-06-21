#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

char sellectMaps();
void openMap(int mapold[][21],char choose);
void changeType(int mapold[][21],char map[][21], int *w, int *z);
void showMap(char mapold[][21]);
int Scores();
bool Move(char direction, char map[][21], int* x, int* y);
void Record(int score,int map[][21],char choose);

int main()
{
	//变量声明
	int mapold[20][21];
	char map[20][21];
	int x = 0, y = 0;
	int *w = &x;
	int *z = &y;
	char direction;
	bool end = 0;

	char choose = sellectMaps();
	openMap(mapold, choose);
	changeType(mapold, map,w,z);//将map转码，并找出I的位置
	showMap(map);
	while (1)
	{
		cin >> direction;
		end = Move(direction, map, w, z);
		if (end==1)
		{
			cout << "Congratulations!" << endl;
			cout << "You have won!" << endl;
			cout << "Your score is:" << Scores();
			system("pause");
			Record(Scores() + 1,mapold,choose);
			return 0;
		}
	}
}

char sellectMaps()
{
	cout << "1 2" << endl << "please input the map number you choose:";
	char choose;
	cin >> choose;
	return choose;
}

void openMap(int mapold[][21],char choose)
{
	ifstream file;
	switch (choose)
	{
	case '1':
		file.open("1.txt");
		system("cls");
		break;
	case '2':
		file.open("2.txt");
		system("cls");
		break;
	default:
		cout << "error!";
		break;
	}
	if (file)
	{
		for (size_t i = 0; i < 20; i++)
		{
			for (size_t j = 0; j < 20; j++)
			{
				file >> mapold[i][j];
			}
		}
	}
	file.close();
}

void changeType(int mapold[][21], char map[][21],int *w,int *z)//将地图的格式由int转变为char,并确定I的位置
{
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 21; j++)
		{
			switch (mapold[i][j])
			{
			case 8:
				map[i][j] = '#';
				break;
			case 4:
				map[i][j] = ' ';
				break;
			case 3:
				map[i][j] = 'B';
				break;
			case 2:
				map[i][j] = 'X';
				break;
			case 1:
				map[i][j] = 'I';
				*w = i;
				*z = j;
				break;
			default:
				break;
			}

		}
	}
};

void showMap(char map[][21]) {
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "Please input 'w','s','a','d' to move yourself:";
}

int Scores()
{
	static int k = 1;
	k++;
	return 500-k+1;
}

bool Move(char direction, char map[][21], int * x, int * y)
{
	Scores();
	int i = 0, j = 0;
	switch (direction)
	{
	case 'w':
		i = -1;
		j = 0;
		break;
	case 's':
		i = 1;
		j = 0;
		break;
	case 'a':
		i = 0;
		j = -1;
		break;
	case 'd':
		i = 0;
		j = 1;
		break;
	default:
		cout << "error!" << endl;
		system("pause");
		break;
	}
	switch (map[*x + i][*y + j])
	{
	case ' ':
		map[*x + i][*y + j] = 'I';
		if (map[*x][*y] == 'T')
			map[*x][*y] = 'X';
		else
			map[*x][*y] = ' ';
		*x += i;
		*y += j;
		break;
	case 'B':
		if (map[*x + i + i][*y + j + j] == ' ')//1.3.1
		{
			map[*x + i + i][*y + j + j] = 'B';
			map[*x + i][*y + j] = 'I';
			if (map[*x][*y] == 'T')
				map[*x][*y] = 'X';
			else
				map[*x][*y] = ' ';
			*x += i;
			*y += j;
		}
		else
		{
			if (map[*x + i + i][*y + j + j] == 'X')//1.3.2
			{
				map[*x + i + i][*y + j + j] = 'R';
				map[*x + i][*y + j] = 'I';
				if (map[*x][*y] == 'T')
					map[*x][*y] = 'X';
				else
					map[*x][*y] = ' ';
				*x += i;
				*y += j;
			}
		}
		break;
	case 'X':
		if (map[*x + i][*y + j] == 'X')//1.2
		{
			map[*x + i][*y + j] = 'T';
			if (map[*x][*y] == 'T')
				map[*x][*y] = 'X';
			else
				map[*x][*y] = ' ';
			*x += i;
			*y += j;
		}
		break;
	case 'R':
		if (map[*x + i][*y + j] == 'R')//1.4
			if (map[*x + i + i][*y + j + j] == ' ')//1.4.1
			{
				map[*x + i + i][*y + j + j] = 'B';
				map[*x + i][*y + j] = 'T';
				if (map[*x][*y] == 'T')
					map[*x][*y] = 'X';
				else
					map[*x][*y] = ' ';
				*x += i;
				*y += j;
			}
			else
			{
				if (map[*x + i + i][*y + j + j] == 'X')//1.4.2
				{
					map[*x + i + i][*y + j + j] = 'R';
					map[*x + i][*y + j] = 'T';
					if (map[*x][*y] == 'T')
						map[*x][*y] = 'X';
					else
						map[*x][*y] = ' ';
					*x += i;
					*y += j;
				}
			}
	default:
		break;
	}
	system("cls");
	int end = 0;//2.
	for (size_t i = 0; i < 20; i++)
		for (size_t j = 0; j < 20; j++)
			if (map[i][j] =='R')
				end++;
	if (end == 3)
		return 1;
	showMap(map);
	return 0;
}

void Record(int score,int mapold[][21],char choose)
{
	ofstream file;
	if (choose=='1')
		file.open("1.txt");
	else
		file.open("2.txt");
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			file << mapold[i][j];
			file << ' ';
		}
		file << endl;
	}
	file << score;
	file.close();
}