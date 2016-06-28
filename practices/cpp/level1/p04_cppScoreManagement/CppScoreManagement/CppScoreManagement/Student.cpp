#include "Student.h"
#include <iostream>

void Student::showInformation()const
{
	int totLen = 0;
	std::cout << studyNumber;
	totLen = studyNumber.size();
	for (;totLen <= 15;totLen++)
		std::cout << ' ';
	std::cout << name;
	totLen += name.size();
	for (;totLen <= 35;totLen++)
		std::cout << ' ';
	std::cout << sex;
	for (;totLen <= 43;totLen++)
		std::cout << ' ';
	std::cout << score << std::endl;
}

Student* Student::setScore(double _score)
{
	score = _score;
	return this;
}

std::string Student::getStuID() const
{
	return studyNumber;
}

std::string Student::getSex() const
{
	return sex;
}

std::string Student::getName() const
{
	return name;
}

double Student::getScore() const
{
	return score;
}

Student::~Student()
{
}
