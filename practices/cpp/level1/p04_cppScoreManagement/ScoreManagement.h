#ifndef SCOREMANAGEMENT_SCOREMANAGEMENT_H
#define SCOREMANAGEMENT_SCOREMANAGEMENT_H

#include <list>
#include "Student.h"
#include <cstring>
#include <assert.h>
class ScoreManagement {
private:
    std::list<Student> list;
public:
    void add(std::string name) {
        list.push_back((name));
    }

    void detele(int number) {
        assert(number < list.size());
        auto i = list.begin();
        std::advance(i, number);
        list.erase(i);
    }

    void show() {
        for (auto &i:list) {
            i.show();
        }
        printf("END\n");
    }

    void setScore(int number) {
        assert(number < list.size());
        auto i = list.begin();
        std::advance(i, number);
        do {
            i->setScore();
            i++;
            if (i != list.end()) {
                printf("continue?[y/n]\n");
                int c = getchar();
                while (c != 'y' && c != 'n')c = getchar();
                if (c == 'n')break;
            }
        } while (i != list.end());
        printf("END\n");
    }
};


#endif //SCOREMANAGEMENT_SCOREMANAGEMENT_H
