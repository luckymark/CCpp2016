#include <windows.h>
#include <stdio.h>
#define width 58
int abs(int num){
	return num>0?num:-num;
}

int main(int argc, char const *argv[]) {
  for(int i=-width;i<=width;i++){
	register int temp=width-abs(i);
	for(int j=0;j<temp;j++){
		printf(" ");
	}
    printf("A");
    Sleep(200);
    system("cls");
  }
  return 0;
}
