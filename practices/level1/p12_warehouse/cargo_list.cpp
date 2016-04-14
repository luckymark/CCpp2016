#include "cargo_system_def.h"

#include <vector>
#include <string>
#include <iostream>

#include "cargo_helper.h"

using namespace std;

CARGO_SYSTEM_ACTION(cargo_list, "Display Cargos") {
    vector<string> models = retrieveFormatedCargoModels(CARGO_SYSTEM_PERSISTENCE_GET("models"));
    for (auto i : models) {
        cout << i << " : " << CARGO_SYSTEM_PERSISTENCE_GET("model " + i) << endl;
    }
}
