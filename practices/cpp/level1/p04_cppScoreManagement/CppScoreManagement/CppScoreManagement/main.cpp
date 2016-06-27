#include "CppScoreManagement.h"
#include <fstream>
#include <vector>
int main()
{

	CppScoreManagement* manager=CppScoreManagement::instance();
	manager->inputStudent();
	while (1)
	{
		manager->showInformation();
		manager->getInformation();
	}
	return 0;
}