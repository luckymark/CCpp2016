#pragma once
#include <string>
class Student
{
public:
	Student(){}
	Student(std::string studyNumber,std::string sex,std::string name,double score=-1.0) :studyNumber(studyNumber), sex(sex), name(name), score(score){}
	void showInformation()const;
	Student* setScore(double _score);
	std::string getStuID()const;
	std::string getSex()const;
	std::string getName()const;
	double getScore()const;
	bool operator<(const Student&rhs)const
	{
		return studyNumber < rhs.studyNumber;
	}
	~Student();
private:
	std::string studyNumber;
	std::string sex;
	std::string name;
	double score;
};

