#include "StudentInfo.h"
#include "StudentList.h"
#include <vector>
#include <iostream>
#include <algorithm>

void StudentList::showFuncList()
{
	while (1)
	{
		int command;
		std::cout << "==== score management ====" << std::endl;
		std::cout << "1.add student\n2.delete student\n3.input score\n4.show student list\n5.quit" << std::endl;
		std::cout << "command : ";
		std::cin >> command;
		std::cin.sync();
		switch (command)
		{
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			inputScore();
			break;
		case 4:
			showList();
			break;
		case 5:
			return;
		default:
			std::cerr << "ERROR : Incorrect command." << std::endl;
		}
	}
}
void StudentList::addStudent()
{
	StudentInfo tempStudentInfo = getStudentInfo();
	//check the student existed or not
	if (findStudent(tempStudentInfo.showId()) == -1)
	{
		studentList.push_back(tempStudentInfo);
		std::sort(studentList.begin(), studentList.end(), compareId);
	}
	else
	{
		std::cerr << "ERROR : The ID has been existed." << std::endl;
	}
}
bool StudentList::deleteStudent()
{
	unsigned targetId;
	//get ID to delete
	std::cout << "Please input the ID to delete : ";
	std::cin >> targetId;
	int studentPos = findStudent(targetId);
	if (studentPos == -1)
	{
		std::cerr << "ERROR : There is no No." << targetId << " student." << std::endl;
		return 1;
	}
	studentList.erase(studentList.begin() + studentPos);
	return 0;
}
bool StudentList::inputScore()
{
	while (1)
	{
		std::cout << "Please input the id to set score (0 to quit): ";
		unsigned id2Score;
		std::cin >> id2Score;
		if (id2Score != 0)
		{
			unsigned sourceScore;
			std::cout << "Please input the score of " << id2Score << " : ";
			std::cin >> sourceScore;
			_inputScore(id2Score, sourceScore);
		}
		else
		{
			return 0;
		}
	}
}
bool StudentList::_inputScore(unsigned targetId, unsigned sourceScore)
{
	int studentPos = findStudent(targetId);
	if (studentPos == -1)
	{
		std::cerr << "ERROR : There is no No." << targetId << " student." << std::endl;
		return 1;
	}
	studentList[studentPos].setScore(sourceScore);
	return 0;
}
void StudentList::showList()
{
	std::cout << "ID        name        score" << std::endl;
	for (auto ite = studentList.begin(); ite != studentList.end(); ite++)
	{
		ite->printAllInfo();
	}
	std::cout << "========ALL=========" << std::endl;
}
int StudentList::findStudent(unsigned targetId)
{
	int count = 0;
	for (auto ite = studentList.begin(); ite != studentList.end(); ite++, count++)
	{
		if (ite->showId() == targetId)
		{
			return count;
		}
	}
	return -1;
}
StudentInfo StudentList::getStudentInfo()
{
	std::string sourceName;
	unsigned sourceId;
	std::cout << "student's name : ";
	std::cin >> sourceName;
	std::cout << "student's id : ";
	std::cin >> sourceId;
	StudentInfo newStudentInfo(sourceId, sourceName);
	return newStudentInfo;
}
bool compareId(StudentInfo comp1, StudentInfo comp2)
{
	return comp1.showId() > comp2.showId();
}