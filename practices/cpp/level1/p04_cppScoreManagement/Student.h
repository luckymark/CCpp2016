#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
using namespace std;
class Student
{
    public:
        Student();
        virtual ~Student();
        void SetName(string name);
        void SetId(int id);
        void SetScore(int score);
        string GetName();
        int GetId();
        int GetScore();
    protected:
    private:
        string name;
        int score;
        int id;
};

#endif // STUDENT_H
