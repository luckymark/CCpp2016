#include <glut.h>
#include <windows.h>
#include <stdlib.h>
#include "Point.h"
#include "Circle.h"
#define CENTER 400,300
Circle circle(Point(CENTER),50);
int x0,y0;
int x2,y2;
int width=800;
int height=600;
int first=-1;
void myReshape(int w,int h);
void display();
void move(int x,int y);
void mouse(int button,int state, int x,int y);
int main(int argc,char **argv)
{
    glutInit(&argc,argv);//初始化
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//显示方式
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("画矩形");
    glutReshapeFunc(myReshape);//窗口改变的时候调用的函数，在这个里面可以根据缩放后的窗口重新设置
    glutDisplayFunc(display);//画图
    glutMotionFunc(move);
    glutMouseFunc(mouse);
    glutMainLoop();//窗口结束关闭
    return 0;
}
void myReshape(int w,int h)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glViewport(0,0,w,h);
    width=w;
    height=h;
    glMatrixMode(GL_PROJECTION);//投影矩阵
    glLoadIdentity();
    gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
    glMatrixMode(GL_MODELVIEW);//矩阵堆栈
}
void display()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_COLOR_LOGIC_OP);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}
void move(int x,int y)
{
    x2=x;
    y2=height-y;
    glClear(GL_COLOR_BUFFER_BIT);
    if(first == 1)
    {
       circle.draw();
    }
    circle.trans(x2-x0,y2-y0);
    circle.draw();
    first = 1;
}
void mouse(int button,int state, int x,int y)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LOGIC_OP);
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x0=x;
        y0=height-y;
        x2=x0;
        y2=y0;
        glColor3f(0.0,1.0,0.0);
        glLogicOp(GL_XOR);
        first=0;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        circle.draw();
        circle.put_trans(x2-x0,y2-y0);
        glFlush();
        glColor3f(0.0,0.0,1.0);
        glLogicOp(GL_COPY);
        circle.draw();
    }
}
