#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
using namespace std;
//------------------------------
const int width = 10;//尺寸暂定为10x10
const int height = 10;
int boxMap[height][width];
struct object{
    int positionX;
    int positionY;
} player,box,goal;
//-----------------------------
bool readFile(int level);
void move(object ob,char direction);
void play();
void showMap();
char shape(int i);
void bind(object ob,int x,int y);
bool can_move(object ob,char direction);
//-----------------------------

int main() {
    int level;
    cout <<"please choice a level (1-3)"<<endl;
    while(true){
        cin >>level;
        if(level>=1&&level<=3) {
            break;
        }
        cout <<"wrong input please retry (1-3)"<<endl;
    }
    readFile(level);
    play();
    return 0;
}
//读入关卡
bool readFile(int level) {
    ifstream mapFile;
    switch (level) {
        case 1:mapFile.open("1.level",ios::in);break;
        case 2:mapFile.open("2.level",ios::in);break;
        case 3:mapFile.open("3.level",ios::in);break;
        default:cout<<"program err";return false;break;
    }
    for(int i = 0;i < height; i++){
        int j = 0;
        while(true) {
            char temp;
            mapFile.get(temp);
            if(temp == '\n') {
                break;
            }
            boxMap[i][j] = temp-'0';
            switch(boxMap[i][j]) {
                case 2:bind(player,j,i);boxMap[i][j] = 0;break;
                case 3:bind(goal,j,i);break;
                case 5:bind(box,j,i);boxMap[i][j] = 0;break;
            }
            j++;
        }
    }
    return true;
}
//输出当前图形
void showMap() {
    system("cls");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if((j == box.positionX)&&(i == box.positionY)) {
                cout << shape(5);
            }else if((j == player.positionX)&&(i == player.positionY)) {
                cout << shape(2);
            }else{
                cout << shape(boxMap[i][j]);
            }
            if(j == (width-1)) {
                cout << endl;
            }
        }
    }
}
//对应形状
char shape(int i) {
    char shapeChar;
    switch (i) {
        case 0:shapeChar = ' ';break;//blank
        case 1:shapeChar = '#';break;//wall
        case 2:shapeChar = 'i';break;//player
        case 3:shapeChar = 'o';break;//goal
        case 4:shapeChar = '*';break;//achived
        case 5:shapeChar = '@';break;//box
    }
    return shapeChar;
}
//游戏开始
void play() {
    while(true) {
        char direction;
        showMap();
        direction = getch();
        move(player,direction);
    }
}
void move(object ob,char direction) {
    if(can_move(ob,direction)){
        switch (direction) {
            case 'w':ob.positionY --;break;
            case 's':ob.positionY ++;break;
            case 'a':ob.positionX --;break;
            case 'd':ob.positionX ++;break;
        }
    }
}
//绑定位置
void bind(object ob,int x,int y) {
    ob.positionX = x;
    ob.positionY = y;
}
//是否有阻碍
bool can_move(object ob,char direction) {
    bool flag = 1;
    switch (direction) {
        case 'w':if(boxMap[ob.positionY-1][ob.positionX] == 1)flag = 0;break;
        case 's':if(boxMap[ob.positionY+1][ob.positionX] == 1)flag = 0;break;
        case 'a':if(boxMap[ob.positionY][ob.positionX-1] == 1)flag = 0;break;
        case 'd':if(boxMap[ob.positionY][ob.positionX+1] == 1)flag = 0;break;
    }
    return flag;
}
