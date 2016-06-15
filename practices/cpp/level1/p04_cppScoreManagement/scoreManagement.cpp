#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
class Student{
public:
    char name[10];
    int score,age,number;
    Student(char getName[10],int getAge,int getNumber)
    {
        for (int i=0;i<10;i++)
        {
            name[i]=getName[i];
        }
        age=getAge;
        number=getNumber;
    }
};
vector <Student> course;
char name[10],op[10];
int now,score,age,number,n,i,j;
int main()
{
    scanf("%d",&n);//有N个学生
    for (i=1;i<=n;i++)
    {
        scanf("%s%d%d",&name,&age,&number);
        course.push_back(Student(name,age,number));//学生选入课程s
    }
    for (i=1;i<=n;i++)
    {
        scanf("%s",&op);
        if (op[0]=='N')
        {
            course.erase(course.begin()+now);
        } else
        {
            now++;
        }//退选课程
    }
    for (i=0;i<course.size();i++)
    {
        scanf("%d%d",&number,&score);//录入学号为number的学生的成绩
        for (j=0;j<course.size();j++)
        if (course[j].number==number)
        {
            course[j].score=score;
            break;
        }
    }
}
