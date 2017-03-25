#include "cargo_system_def.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> cargos;

CARGO_SYSTEM_ACTION(cargo_list, "Display Cargos") {
    for (auto c : cargos) {
        cout << c << endl;
    }
}
