#include <stdio.h>
#include <stdlib.h>
void showMap();
int move();
void pass();
char map[10][30] = {
"------------------------------",
"-$ ----------          ---  --",
"--        ------------      --",
"---------        -------- ----",
"---------- ----- ----     ----",
"---------- ----- ---- --------",
"------     -----         -----",
"--     ---     --------- -----",
"-- ---------------------    --",
"---------------------------#--",
};
int PositionX = 1,PositionY = 1;

int main()
{
    showMap();
    if(move())
        pass();
    return 0;
}

void showMap(){
    system("cls");
    for(int i=0;i<10;i++){
        for(int j=0;j<30;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }

}
//走到终点返回1
int move(){
    char keycode ;
    while(1){
        keycode = getch();
        if(keycode == 'w'){
            //上
            if(map[PositionY-1][PositionX]==' '){
                map[PositionY-1][PositionX]='$';
                map[PositionY][PositionX]=' ';
                PositionY = PositionY - 1;
                showMap();
            }
        }
        if(keycode == 's'){
            //下
            if(map[PositionY+1][PositionX]==' '){
                map[PositionY+1][PositionX]='$';
                map[PositionY][PositionX]=' ';
                PositionY = PositionY + 1;
                showMap();
            }
            if(map[PositionY+1][PositionX]=='#')
                return 1;
        }
        if(keycode == 'a'){
            //左
            if(map[PositionY][PositionX-1]==' '){
                map[PositionY][PositionX-1]='$';
                map[PositionY][PositionX]=' ';
                PositionX = PositionX - 1;
                showMap();
            }
        }
        if(keycode == 'd'){
            //右
            if(map[PositionY][PositionX+1]==' '){
                map[PositionY][PositionX+1]='$';
                map[PositionY][PositionX]=' ';
                PositionX = PositionX + 1;
                showMap();
            }
        }
    }
    return 0;
}

void pass(){
    system("cls");
    printf("过关了666");
}
