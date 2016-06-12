#pragma once

#include<iostream>
#include<string>

class Student
{
public:
	Student();
	~Student();
	void set_name(std::string str);
	void set_ID(int ID);
	void set_score(int score);
	std::string get_name();
	int get_ID();
	int get_score();

private:
	std::string name;
	int ID;
	int score;

};

Student::Student()
{
	std::string str;
	int his_ID;
	std::cout << "Please input the name and ID of the student" << std::endl << ":";
	std::cin >> str >> his_ID;
	set_name(str);
	set_ID(his_ID);

}

Student::~Student()
{
}

inline void Student::set_name(std::string str)
{
	name = str;
}

inline void Student::set_ID(int ID)
{
	Student::ID = ID;
}

inline void Student::set_score(int score)
{
	Student::score = score;
}

inline std::string Student::get_name()
{
	return name;
}

inline int Student::get_ID()
{
	return ID;
}

inline int Student::get_score()
{
	return score;
}
