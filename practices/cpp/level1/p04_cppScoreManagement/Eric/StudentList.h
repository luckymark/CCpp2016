#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "StudentInfo.h"
#include <vector>

class StudentList
{
public:
	void showFuncList();
private:
	std::vector<StudentInfo> studentList;
	int findStudent(unsigned targetId);
	StudentInfo getStudentInfo();
	void addStudent();
	bool deleteStudent();
	bool inputScore();
	bool _inputScore(unsigned targetId, unsigned sourceScore);
	void showList();
};
bool compareId(StudentInfo comp1, StudentInfo comp2);
#endif