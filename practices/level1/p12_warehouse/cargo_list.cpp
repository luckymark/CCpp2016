#include "cargo_system_def.h"
#include "cargo_helper.h"

#include <iostream>

using namespace std;

CARGO_SYSTEM_ACTION(cargo_list, "Display Cargoes") {
    vector<string> models = retrieveFormatedCargoModels(CARGO_SYSTEM_PERSISTENCE_GET("models"));
    for (auto i : models) {
        cout << i << " : " << CARGO_SYSTEM_PERSISTENCE_GET("model " + i) << endl;
    }
}
