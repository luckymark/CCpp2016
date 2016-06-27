#pragma once
#include "State.h"
#include <map>
#include "Student.h"
#include <vector>
#include <fstream>
class Mainmenu :
	public State
{
public:
	void showInformation(std::map<Student,int>&);
	void getInformation(std::map<Student, int>&,State*&);
	void outputStudent(std::map<Student, int>&);
	static Mainmenu* instance();
	~Mainmenu();
protected:
	Mainmenu();
private:
	static Mainmenu* _instance;
	std::ofstream outputData;
	std::vector<State*>alternativeStates;
};

