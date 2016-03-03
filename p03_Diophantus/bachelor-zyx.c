#include<stdio.h>

int main(void) {
	int age, age_child, single=0;

	for (age = 1; age <= 100; age++){
		if (!(age % (7*12))) {  //!((age % 6) || (age % 7) || (age % 12))
			single = age / 6 + age / 7 + age / 12 + 5;
			if (age>single){
				age_child = age - single -4;
				if (age_child == (age / 2)){
					printf("%d\n", age);
					break;
				}
			}
		}
	}
	return 0;
}