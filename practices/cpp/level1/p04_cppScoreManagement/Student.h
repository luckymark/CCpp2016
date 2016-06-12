#ifndef SCOREMANAGEMENT_STUDENT_H
#define SCOREMANAGEMENT_STUDENT_H

#include <string>
#include <iostream>
class Student {
private:
    std::string name;
    int score = 0;
public:
    Student(std::string name) {
        this->name = name;
    }

    void show() {
        std::cout << "Name:" << name << " Score: " << score << std::endl;
    }

    void setScore() {
        int score = 0;
        printf("Please Input Score:");
        scanf("%d", &score);
        this->score = score;
    }
};


#endif //SCOREMANAGEMENT_STUDENT_H
