#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define O 2
#define M 5
#define R 4
#define B 1
#define W 9

void paint(void);

//绘制地图
int actions(void);

//接受人物动作
void change(int act);

//改变地图信息
int judge(void);//判断胜利条件


int map_1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, W, W, W, 0, 0, 0, 0},
                     {0, 0, 0, W, O, W, 0, 0, 0, 0},
                     {0, 0, 0, W, R, W, W, W, W, 0},
                     {0, W, W, W, B, M, B, O, W, 0},
                     {0, W, O, R, B, B, W, W, W, 0},
                     {0, W, W, W, W, R, W, 0, 0, 0},
                     {0, 0, 0, 0, W, O, W, 0, 0, 0},
                     {0, 0, 0, 0, W, W, W, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int map_2[10][10] = {{0, W, W, W, W, W, 0, 0, 0, 0},
                     {0, W, R, R, M, W, 0, 0, 0, 0},
                     {0, W, R, B, B, W, W, W, W, W},
                     {0, W, R, B, R, R, R, R, O, W},
                     {0, W, W, W, R, R, R, R, W, W},
                     {0, 0, W, W, R, R, R, R, O, W},
                     {0, 0, W, R, R, R, W, R, W, W},
                     {0, 0, W, R, R, R, W, R, W, W},
                     {0, 0, W, W, W, W, W, O, W, 0},
                     {0, 0, 0, 0, 0, 0, W, W, W, 0}};
int map_3[10][10] = {{0, 0, W, W, W, 0, 0, 0, 0, 0},
                     {0, 0, W, O, W, 0, 0, 0, 0, 0},
                     {0, 0, W, R, W, W, W, W, 0, 0},
                     {0, W, R, R, R, B, M, W, W, 0},
                     {0, W, B, R, R, B, R, R, W, 0},
                     {0, W, R, W, R, W, R, R, W, 0},
                     {0, W, R, R, R, W, R, W, W, 0},
                     {0, W, O, R, R, R, R, W, 0, 0},
                     {0, W, W, O, W, W, W, W, 0, 0},
                     {0, W, W, W, W, 0, 0, 0, 0, 0},};


int main(void) {
    int i = 1;
    int ch;
    int score = 0;
    FILE *fp = fopen("save.txt", "r+");
    printf("读取数据？（Y/N）\n");
    ch = getch();
    if (ch == 'y' || ch == 'Y') {
        fscanf(fp, "%1d%2d", &i, &score);
        if (i == 2) { memcpy(&map_1[0][0], &map_2[0][0], 400); }
        if (i == 3) { memcpy(&map_1[0][0], &map_3[0][0], 400); }
    }
    paint();//绘制地图，初始化
    for (; ;) {
        //接受人物动作（包含存盘操作）
        change(actions());//改变数据
        score++;
        system("cls");//先清空console
        paint();//绘制地图
        printf("分数：%2d", score);
        int x = judge();
        if (!x) {
            i++;
            system("cls");
            switch (i) {
                case 2:
                    printf("是否存档？\n");
                    ch = getch();
                    if (ch == 'y' || ch == 'Y') {
                        fprintf(fp, "%1d%2d", i, score);
                        exit(0);
                    }
                    memcpy(&map_1[0][0], &map_2[0][0], 400);
                    paint();
                    break;
                case 3:
                    printf("是否存档？\n");
                    ch = getch();
                    if (ch == 'y' || ch == 'Y') {
                        fprintf(fp, "%1d%2d", i, score);
                        exit(0);
                    }
                    memcpy(&map_1[0][0], &map_3[0][0], 400);
                    paint();
                    break;
                case 4:
                    printf("You win.\n");
                    getchar();
                    exit(0);
                default:
                    continue;
            }

        }
    }//判断是否胜利
}


void paint(void) {
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (map_1[i][j] == 0) { printf("×"); }
            if (map_1[i][j] == W) { printf("█"); }
            if (map_1[i][j] == R) { printf("□"); }
            if (map_1[i][j] == B) { printf("▓"); }
            if (map_1[i][j] == O) { printf("○"); }
            if (map_1[i][j] == M) { printf("★"); }
        }
        printf("\n");
    }
}

int actions(void) {
    int c;
    while ((c = getch())) {
        if (c == 27) return -1; //Esc
        c = getch();
        if (c == 72) return 8; //Up
        if (c == 80) return 2; //Down
        if (c == 75) return 4; //Left
        if (c == 77) return 6; //Right
    }
    return 0;
}

void change(int act) {
    int x = 0, y = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (map_1[i][j] == M) {
                x = i;
                y = j;
            }
        }
    }
    if (act == -1) { exit(0); }
    if (act == 4) {
        if ((map_1[x][y - 1] == B) && ((map_1[x][y - 2] == R) || (map_1[x][y - 2] == O))) {
            map_1[x][y - 1] = M;
            map_1[x][y] = R;
            map_1[x][y - 2] = B;
        }
        else if ((map_1[x][y - 1] == R) || (map_1[x][y - 1] == O)) {
            map_1[x][y - 1] = M;
            map_1[x][y] = R;
        }
    }
    if (act == 6) {
        if ((map_1[x][y + 1] == B) && ((map_1[x][y + 2] == R) || (map_1[x][y + 2] == O))) {
            map_1[x][y + 1] = M;
            map_1[x][y] = R;
            map_1[x][y + 2] = B;
        }
        else if ((map_1[x][y + 1] == R) || (map_1[x][y + 1] == O)) {
            map_1[x][y + 1] = M;
            map_1[x][y] = R;
        }
    }
    if (act == 8) {
        if ((map_1[x - 1][y] == B) && ((map_1[x - 2][y] == R) || (map_1[x - 2][y] == O))) {
            map_1[x - 1][y] = M;
            map_1[x][y] = R;
            map_1[x - 2][y] = B;
        }
        else if ((map_1[x - 1][y] == R) || (map_1[x - 1][y] == O)) {
            map_1[x - 1][y] = M;
            map_1[x][y] = R;
        }
    }
    if (act == 2) {
        if ((map_1[x + 1][y] == B) && ((map_1[x + 2][y] == R) || (map_1[x + 2][y] == O))) {
            map_1[x + 1][y] = M;
            map_1[x][y] = R;
            map_1[x + 2][y] = B;
        }
        else if ((map_1[x + 1][y] == R) || (map_1[x + 1][y] == O)) {
            map_1[x + 1][y] = M;
            map_1[x][y] = R;
        }
    }
}


int judge(void) {
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (map_1[i][j] == O) {
                return 1;
            }
        }
    }
    return 0;
}