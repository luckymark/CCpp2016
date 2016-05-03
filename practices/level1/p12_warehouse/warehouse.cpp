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
            default:cout<<"wrong input  please retry"<<endl;return 0;
        }
    }
    return 0;
}
//解析文件为所需结构
goods paser(char buffer[40]) {
    goods temp;
    string sbuffer = buffer;
    sbuffer += '\0';
    int i = 0;
        while(true){
            if(sbuffer[i]==(':')) {
                break;
            }
            temp.name+=sbuffer[i];//解析名字
            i++;
        }
        while(true) {
            if(sbuffer[i]==('\n'|'\0')) {
                break;
            }
            if(sbuffer[i]!=' ') {
                temp.num = atoi(sbuffer.substr(i+1,sbuffer.length()).c_str());//解析为int便于后续处理
                break;
            }
        }
    return temp;
}
//文件读入
int readFile(ifstream &file) {
    int i = 0;
    while(true) {
        char buffer[40];
        file.getline(buffer,30);
        if(file.eof()){
            break;
        }
        data[i] = paser(buffer);
        i++;
    }
    return i;
}
//打印仓库
void showList(ifstream &file) {
    cout<<"-------------------"<<endl;
    for(int i = 0;i<numOfGoods;i++){
        cout<<data[i].name<<":"<<data[i].num<<endl;
    }
    cout<<"-------------------"<<endl;
}
//入库
void addToWare(ifstream &file) {
    goods newGood;
    cout<<"type name: ";
    cin>>newGood.name;
    cout<<"add amount: ";
    cin>>newGood.num;
    for(int i = 0;i<=numOfGoods;i++) {
        if(data[i].name == newGood.name){
            data[i].num += newGood.num;//已存在则增加数量
        }else{
            data[numOfGoods] = newGood;//未存在则新建
            numOfGoods++;
        }
        break;
    }
    cout<<"-------------------"<<endl;
}
//出库
void outWare(ifstream &file) {
    goods outGoods;
    cout<<"which one you want to get out Warehouse?"<<endl;
    cin>>outGoods.name;
    cout<<"how much?"<<endl;
    cin>>outGoods.num;
    for(int i = 0;i<numOfGoods;i++) {
        if(data[i].name == outGoods.name) {
            if(data[i].num < outGoods.num) {
                cout<<"there are only "<<data[i].num<<",not enough please retry";//货存不够
                break;
            }
            data[i].num -= outGoods.num;
        }
    }
    cout<<"-------------------"<<endl;
}
//退出时写入文件，库存为0则抛弃；
void  exitProgram() {
    ofstream fileout("data.txt",ios::out | ios::trunc);//trunc表示删除原来文件，重新创建
    for(int i = 0;i<numOfGoods;i++) {
            if(data[i].num != 0){
            fileout<<data[i].name<<":"<<data[i].num<<"\n";
        }
    }
    fileout.close();
}
