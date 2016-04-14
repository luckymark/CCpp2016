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
    vector<string> models = retrieveFormatedCargoModels(CARGO_SYSTEM_PERSISTENCE_GET("models"));
    if (find(models.begin(), models.end(), model) == models.end()) {
        models.push_back(model);
        CARGO_SYSTEM_PERSISTENCE_SET("models", formatCargoModels(models));
    }
}
