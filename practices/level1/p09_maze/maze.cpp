// maze.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <windows.h>
#define ROAD 0
#define WALL 1
#define MAN 2
#define EXIT 3

using namespace std;

int map[12][12];
void showMap();
void makeMap();
void move();
int positionX,positionY;
void refreash();

int main()
{
	makeMap();
	refreash();
	cout << "续命成功!!!" << endl;
	return 0;
}

void refreash(){
    while(map[10][10] != MAN){
        system("cls");
        cout << "        301医院" << endl;
        showMap();
        move();
    }
}

void makeMap(){
    positionX = 1;
    positionY = 1;
	for(int i = 0;i <= 11;i++){
		for(int j = 0;j <= 11;j++){
			map[i][j] = WALL;
		}
	}
	for(int i = 1;i <= 10;i++){
		for(int j = 1;j <= 10;j++){
			map[i][j] = ROAD;
		}
	}
	map[1][1] = MAN;
	for(int i = 1;i <= 9;i++){
        map[i][2] = WALL;
	}
	for(int i = 2;i <= 10;i++){
        map[i][4] = WALL;
	}
	for(int i = 1;i <= 9;i++){
        map[i][6] = WALL;
	}
	for(int i = 2;i <= 10;i++){
        map[i][8] = WALL;
	}
	map[2][9] = WALL;
	map[4][10] = WALL;
	map[6][9] = WALL;
	map[8][10] = WALL;
	map[10][10] = EXIT;
}

void showMap(){
	int i = 0;
	while(i <= 11){
	for(int j = 0;j <= 11;j++){
		switch(map[i][j]){
		case ROAD:
			cout << "  ";
			break;
		case WALL:
			cout << "口";
			break;
		case MAN:
			cout << "蛤";
			break;
		case EXIT:
			cout << "续";
		default:
			break;
		}
	}
	i++;
	cout << endl;
	}
}

void move(){
    cout << "使用wsad操作长者!" << endl;
    char ch;
    cin >> ch;
    switch(ch){
    case 's':
        if(map[positionY+1][positionX] != WALL){
            map[positionY][positionX] = ROAD;
            map[positionY+1][positionX] = MAN;
            positionY += 1;
        }
        break;
    case 'w':
        if(map[positionY-1][positionX] != WALL){
            map[positionY][positionX] = ROAD;
            map[positionY-1][positionX] = MAN;
            positionY += -1;
        }
        break;
    case 'a':
        if(map[positionY][positionX-1] != WALL){
            map[positionY][positionX] = ROAD;
            map[positionY][positionX-1] = MAN;
            positionX += -1;
        }
        break;
    case 'd':
        if(map[positionY][positionX+1] != WALL){
            map[positionY][positionX] = ROAD;
            map[positionY][positionX+1] = MAN;
            positionX += 1;
        }
        break;
    default:
        refreash();
        break;

    }
}
