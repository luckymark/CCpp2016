#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include <sstream>
using namespace std;
//--------------------------------------
struct goods{
    string name;
    int num;
};

goods data[1000];
int numOfGoods = 0;
//----------------------------------------
void showList(ifstream &file);
void addToWare(ifstream &file);
void outWare(ifstream &file);
int readFile(ifstream &file);
void exitProgram();
goods paser(char buffer[40]);
//--------------------------------------
int main() {
    int option;
    ifstream file;
    file.open("data.txt",ios::in);
    numOfGoods = readFile(file);
    while (true) {
        cout<<"1.showList\n2.add goods\n3.out warehouse\n4.exit"<<endl;
        cin>>option;
        switch (option) {
            case 1:showList(file);break;
            case 2:addToWare(file);break;
            case 3:outWare(file);break;
            case 4:file.close();exitProgram();return 0;break;
            default:cout<<"wrong input"<<endl;
        }
    }
    return 0;
}
goods paser(char buffer[40]) {
    goods temp;
    string sbuffer = buffer;
    int i = 0;
        while(true){
            if(sbuffer[i]==(':')) {
                break;
            }
            temp.name+=sbuffer[i];
            i++;
        }
        while(true) {
            if(sbuffer[i]==('\n'|'\0')) {
                break;
            }
            if(sbuffer[i]!=' ') {
                istringstream stream1;
                stream1.str(sbuffer.substr(i,sbuffer.length()));
                int i;
                stream1 >> i;
                break;
            }
            i++;
        }
    return temp;
}
int readFile(ifstream &file) {
    char buffer[40];
    int i = 0;
    while(!file.eof()) {
        file.getline(buffer,30);
        data[i] = paser(buffer);
        i++;
    }
    return i;
}
void showList(ifstream &file) {
    char buffer[40];
    while(!file.eof()){
        file.getline(buffer,30);
        cout<<buffer<<endl;
    }
}
void addToWare(ifstream &file) {
    goods newGood;
    cout<<"type name: ";
    cin>>newGood.name;
    cout<<"add amount: ";
    cin>>newGood.num;
    for(int i = 0;i<numOfGoods;i++) {
        if(data[i].name == newGood.name){
            data[i].num += newGood.num;
        }else{
            data[numOfGoods] = newGood;
            numOfGoods++;
        }
        break;
    }
}
void outWare(ifstream &file) {
    goods outGoods;
    cout<<"which one you want to get out Warehouse?"<<endl;
    cin>>outGoods.name;
    cout<<"how much?"<<endl;
    cin>>outGoods.num;
    for(int i = 0;i<numOfGoods;i++) {
        if(data[i].name == outGoods.name) {
            data[i].num -= outGoods.num;
        }
    }
}
void  exitProgram() {
    ofstream fileout("data.txt",ios::out | ios::trunc);
    for(int i = 0;i<numOfGoods;i++) {
            if(data[i].num != 0){
            fileout<<data[i].name<<":"<<data[i].num<<"\n";
        }
    }
    fileout.close();
}
