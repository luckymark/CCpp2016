#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#define BUF_SIZE 1000

map<string,int> goodslist;

void readData();
void saveData();
void printList();
void printMenu();
void putIn();
void getOut();

int main(){
	char sta ;
	readData();
	while(1){
		printMenu();
		sta = getch();
		if(sta == '1'){
			printList();
		}else if(sta == '2'){
			putIn();
		}else if(sta == '3'){
			getOut();
		}else if(sta == '4'){
			break;
		}else{
			printf("Input ERROR,please Correct it\n");
		}
	}
	saveData();
	return 0;
}

void printMenu(){
  system("cls");
	printf("Please Input Your select\n1)Print List\n2)Put in\n3)Get out\n4)Exit\n\n");
}

void readData(){
	FILE* ip = fopen("data.dat","r");
	if(ip == NULL){ // Open File False
		return ;
	}
	int number = 0,size;
	char buf[BUF_SIZE];
	fscanf(ip,"%d",&number);
	for(int i = 1; i <= number; ++i){
		fscanf(ip,"%s %d",buf,&size);
		if(size == 0)
			continue;
		goodslist[string(buf)] = size;
	}
	fclose(ip);
}
void saveData(){
	FILE* op = fopen("data.dat","w");
	map<string,int>::iterator it = goodslist.begin();
	fprintf(op,"%d\n",goodslist.size());
	for(;it != goodslist.end();++it){
    if(it->second == 0)
      continue;
		fprintf(op,"%s %d\n",it->first.c_str(),it->second);
	}
}

void printList(){
  map<string,int>::iterator it = goodslist.begin();
	printf("Have %d type goods\n",goodslist.size());
	for(;it != goodslist.end();++it){
		printf("%s\t%d\n",it->first.c_str(),it->second);
	}
	getch();
}

void putIn(){
    char buf[BUF_SIZE];
    int temp;
    printf("Please input your goods' name\n");
    scanf("%s",buf);
    printf("Please input your goods' number\n");
    scanf("%d",&temp);
    if(temp > 0){
        goodslist[string(buf)] += temp;
    }
}

void getOut(){
    char buf[BUF_SIZE];
    int temp,numb;
    printf("Please input your goods' name\n");
    scanf("%s",buf);
    string stemp(buf);
    if(goodslist.count(stemp)==0){
        printf("Haven't this good\n");
        getch();
        return ;
    }
    numb = goodslist[stemp];
    printf("Please input your goods' number\n");
    scanf("%d",&temp);
    if(numb < temp){
        printf("Haven't so many goods\n");
        getch();
        return ;
    }
    goodslist[stemp] -= temp;
    if(numb == temp){
        // If any good goto 0,delete it
        goodslist.erase(goodslist.find(stemp));
    }
    return ;
}
