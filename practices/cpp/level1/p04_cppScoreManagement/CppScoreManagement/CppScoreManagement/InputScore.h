#pragma once
#include "State.h"
#include "Student.h"
#include <map>
#include <fstream>
class InputScore :
	public State
{
public:
	static InputScore* instance();
	void showInformation(std::map<Student, int>&);
	void getInformation(std::map<Student, int>&, State*&);
	~InputScore();
protected:
	InputScore();
private:
	static InputScore* _instance;
	bool isInputScoreFinish = false;
	Student nowStudent;
};

