#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
using namespace std;
class Student
{
    public:
        Student();
        Student(int ID,string name,int score);
        int setScore(int score);
        virtual ~Student();
        void showImformation();
        void setImformation();
        int getID(){
            return ID;
        }
    protected:
    private:
        int ID;
        std::string name;
        int score;
};

#endif // STUDENT_H
