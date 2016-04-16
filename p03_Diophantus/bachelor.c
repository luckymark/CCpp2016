#include<stdio.h>

int main(void) {
	for (int age = 1; age <= 100; age++){
		if (!(age % (7*12))) {  //!((age % 6) || (age % 7) || (age % 12))
			int single = age / 6 + age / 7 + age / 12 + 5;
			if (age>single){
				int age_child = age - single -4;
				if (age_child == (age / 2)){
					printf("%d\n", age);
					break;
				}
			}
		}
	}
	return 0;
}