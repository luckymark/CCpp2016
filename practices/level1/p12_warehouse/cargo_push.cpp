#include "cargo_system_def.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

extern vector<string> cargos;

CARGO_SYSTEM_ACTION(cargo_push, "Push Cargos") {
    cout << "Model: " << endl;
    string model;
    cin >> model;
    cout << "Amount: " << endl;
    int amount;
    cin >> amount;
    for (int i = 0; i < amount; ++i) {
        cargos.push_back(model);
    }
}
