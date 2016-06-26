#include "CppScoreManagement.h"
#include <fstream>
#include <vector>
int main()
{
	CppScoreManagement* builder=CppScoreManagement::instance();
	while (1)
	{
		builder->showInformation();
		builder->getInformation();
	}
	return 0;
}