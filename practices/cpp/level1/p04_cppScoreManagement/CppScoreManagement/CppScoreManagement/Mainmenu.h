#pragma once
#include "State.h"
#include <map>
#include "Student.h"
#include <vector>
class Mainmenu :
	public State
{
public:
	void showInformation(std::map<Student,int>&);
	void getInformation(std::map<Student, int>&);
	static Mainmenu* instance();
	~Mainmenu();
protected:
	Mainmenu();
private:
	static Mainmenu* _instance;
	std::vector<State*>alternativeStates;
};

