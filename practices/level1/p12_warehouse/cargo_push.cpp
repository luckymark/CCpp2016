#include "cargo_system_def.h"
#include "cargo_helper.h"

#include <iostream>
#include <algorithm>

using namespace std;

CARGO_SYSTEM_ACTION(cargo_push, "Push Cargoes") {
    cout << "Model: " << endl;
    string model;
    cin >> model;
    cout << "Amount: " << endl;
    unsigned long amount;
    cin >> amount;
    vector<string> models = retrieveFormatedCargoModels(CARGO_SYSTEM_PERSISTENCE_GET("models"));

    if (find(models.begin(), models.end(), model) == models.end()) {
        models.push_back(model);
        CARGO_SYSTEM_PERSISTENCE_SET("models", formatCargoModels(models));
        CARGO_SYSTEM_PERSISTENCE_SET("model " + model, "0");
    }

    unsigned long preAmount = stoul(CARGO_SYSTEM_PERSISTENCE_GET("model " + model));
    amount += preAmount;
    CARGO_SYSTEM_PERSISTENCE_SET("model " + model, to_string(amount));
}
