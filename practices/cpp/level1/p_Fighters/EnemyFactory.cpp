#include "EnemyFactory.hpp"
#include "EnemyFive.hpp"
#include "EnemyFour.hpp"
#include "EnemyOne.hpp"
#include "EnemySix.hpp"
#include "EnemyThree.hpp"
#include "EnemyTwo.hpp"
Enemy *EnemyFactory::createEnemy(int type) {
    switch (type) {
    case 0:
        return new EnemyOne(rand() % 1100);
    case 1:
        return new EnemyTwo(rand() % 1100);
    case 2:
        return new EnemyThree(rand() % 1100);
    case 3:
        return new EnemyFour(rand() % 1100);
    case 4:
        return new EnemyFive(rand() % 1100);
    case 5:
        return new EnemySix(rand() % 1100);
    default:
        return new EnemyOne(rand() % 1100);
    }
}