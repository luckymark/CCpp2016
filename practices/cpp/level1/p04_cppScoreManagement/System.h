#ifndef SYSTEM_H
#define SYSTEM_H
#include<vector>
#include<Student.h>
class System
{
    public:
        System();
        virtual ~System();
        void addNewStudent();
        void addStudent(Student newStudent);
        void delateStudent();
        void enteringScore();
        void showAllStudent();

    protected:
    private:
        vector<Student> StudentList;
};

#endif // SYSTEM_H
