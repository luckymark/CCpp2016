#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <assert.h>
#define DISPLAY 1
#define INBOUND 2
#define OUTBOUND 3
#define QUIT 4
#define MY_LOCAL_FILE_POSITION "stock.txt"
using namespace std;
struct Machine {
    string name = "";
    int number = 0;

    bool operator==(const Machine &other) const {
        return name == other.name;
    }

    void operator+=(const Machine &other) {
        this->number += other.number;
    }

    void operator-=(const Machine &other) {
        number -= other.number;
        assert(number >= 0);
    }
};
Machine getMachine();
void welcome();
vector<Machine> getStock();
void updateStock(vector<Machine> stock);
void menu();
void displayMenu();
void displayStock();
void inBound();
void outBound();
int main(){
    welcome();
    menu();
    return 0;
}
void welcome() {
    puts("Welcome !");
}
void menu() {
    while (1) {
        displayMenu();
        int operation = QUIT;
        cin>>operation;
        switch (operation) {
            case DISPLAY:
                displayStock();
                break;
            case INBOUND:
                inBound();
                break;
            case OUTBOUND:
                outBound();
                break;
            case QUIT:
                exit(0);
            default:
                break;
        }
    }
}
void displayMenu() {
    system("cls");
    puts("1. Display your stocks");
    puts("2. Inbound");
    puts("3. Outbound");
    puts("4. Quit");
}
Machine getMachine(){
    Machine machine;
    cout << "please input the name of machine :";
    getchar();
    getline(cin, machine.name);
    cout << "please input the number of machine :";
    cin >> machine.number;
    return machine;
}
vector<Machine> getStock() {
    vector<Machine> stock;
    stock.clear();
    ifstream in(MyLocalFilePosition);
    Machine machine;
    while (getline(in, machine.name)) {
        in >> machine.number;
        stock.push_back(machine);
        getline(in, machine.name);
    }
    in.close();
    return stock;
}
void displayStock() {
    vector<Machine> stock = getStock();
    for (int i = 0; i < stock.size(); ++i) {
        cout << "Name:" << stock[i].name << " Number:" << stock[i].number << endl;
    }
    system("pause");
}
void updateStock(vector<Machine> stock) {
    ofstream out(MY_LOCAL_FILE_POSITION);
    bool flag = 1;
    for (int i = 0; i < stock.size(); ++i) {
        if (stock[i].number == 0)continue;
        if (flag) {
            flag = 0;
        } else {
            out << endl;
        }
        out << stock[i].name << endl;
        out << stock[i].number;
    }
    cout << "Finish!" << endl;
    system("pause");
    out.close();
}
void inBound() {
    vector<Machine> stock = getStock();
    Machine machine = getMachine();
    for (int i = 0; i < stock.size(); ++i) {
        if (stock[i] == machine) {
            stock[i] += machine;
            updateStock(stock);
            return;
        }
    }
    stock.push_back(machine);
    updateStock(stock);
}
void outBound() {
    vector<Machine> stock = getStock();
    Machine machine = getMachine();
    for (int i = 0; i < stock.size(); ++i) {
        if (stock[i] == machine) {
            stock[i] -= machine;
            updateStock(stock);
            return;
        }
    }
    assert(0);
}
