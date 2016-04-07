#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>

class StudentInfo
{
private:
	unsigned id;
	std::string name;
	unsigned score;
public:
	StudentInfo(unsigned sourceId, std::string sourceName) : id(sourceId),
		name(sourceName), score(0) {};
	bool inputScore(unsigned score);
};
#endif