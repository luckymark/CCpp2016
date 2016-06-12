#include <iostream>
#include "ScoreManagement.h"
using namespace std;

int main() {
    ScoreManagement myScoreManagement;
    myScoreManagement.add((string) "德玛西亚");
    myScoreManagement.add((string) "为了部落");
    myScoreManagement.setScore(0);
    myScoreManagement.show();
    myScoreManagement.detele(1);
    myScoreManagement.show();
    return 0;
}
