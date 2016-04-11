#include "Salesperson.h"

int main()
{
	Salesperson newSalesperson("Eric", 18, 2);
	newSalesperson.showInfo();
	newSalesperson.setSalesVolume(100);
	newSalesperson.showInfo();
	newSalesperson.setRank(1);
	newSalesperson.showInfo();
	return 0;
}