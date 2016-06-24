//
// Created by Administrator on 2016/6/7.
//

#include "Student.h"

string Student::Get_name() {
    return name;
}

int Student::Get_score() {
    return score;
}

void Student::Set_name() {
    cout << "Name: ";
    getline(cin, name);
}
void Student::Set_name(string Name) {
    name=Name;
}
void Student::Set_score() {
    cout << "Score: ";
    cin >> score;
}