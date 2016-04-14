#include "cargo_system_def.h"
#include "cargo_helper.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

CARGO_SYSTEM_ACTION(cargo_pop, "Pop Cargoes") {
    cout << "Model: " << endl;
    string model;
    cin >> model;
    cout << "Amount: " << endl;
    unsigned long amount;
    cin >> amount;
    vector<string> models = retrieveFormatedCargoModels(CARGO_SYSTEM_PERSISTENCE_GET("models"));

    if (find(models.begin(), models.end(), model) == models.end()) {
        cout << "No such cargo" << endl;
        return;
    }

    unsigned long preAmount = stoul(CARGO_SYSTEM_PERSISTENCE_GET("model " + model));
    if (preAmount < amount) {
        cout << "Not available" << endl;
        return;
    }
    amount -= preAmount;
    CARGO_SYSTEM_PERSISTENCE_SET("model " + model, to_string(amount));
    if (amount == 0) {
        models.erase(find(models.begin(), models.end(), model));
        CARGO_SYSTEM_PERSISTENCE_SET("models", formatCargoModels(models));
    }
}
