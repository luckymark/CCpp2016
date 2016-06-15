#include <iostream>
#include <string>
#include <list>
#include "Student.h"

using namespace std;

void reminder();

void View();

void Add();

void Delete();

void Add_score();

list <Student> linkedlist;
list<Student>::iterator i;

int main() {
    int ch;

    while (1) {
        reminder();
        cin >> ch;
        switch (ch) {
            case 1:
                View();
                break;
            case 2:
                Add();
                break;
            case 3:
                Delete();
                break;
            case 4:
                Add_score();
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}

void reminder() {
    cout << "1. View Student List\n"
    << "2. Add Student\n"
    << "3. Delete Student\n"
    << "4. Add Score\n"
    << "5. Quit"
    << endl;
}

void Add() {
    string name;
    cout << "Name: ";
    cin >> name;
    Student *p = new Student(name);
    linkedlist.push_back(*p);
    (*p).Set_name(name);
    cout << "Succeed!" << endl;
    cout << endl;
}

void View() {
    cout << "Name" << "\t" << "Score" << endl;
    for (Student &s : linkedlist) {
        cout << s.Get_name() << "\t" << s.Get_score() << endl;
    }
    cout << endl;
}

void Delete() {
    string name;
    cout << "Name: ";
    cin >> name;
    for (Student &s : linkedlist) {
        if (s.Get_name() == name) {
            delete &s;
            cout << "Succeed!" << endl;
        }
    }
}

void Add_score() {
    string name;
    cout << "Name: ";
    cin >> name;
    for (Student &s : linkedlist) {
        if (s.Get_name() == name) {
            s.Set_score();
            cout << "Succeed!" << endl;
        }
    }
}