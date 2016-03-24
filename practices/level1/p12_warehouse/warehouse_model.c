#include <string.h>
#include "warehouse_model.h"

Good *look_up_type(Warehouse *pwarehouse, char *type) {
    int length = pwarehouse->amount;
    for (int i = 0; i < length; i++) {
        Good *pgood = &(pwarehouse->good_list[i]);
        if (strcmp(pgood->type, type) == 0) {
            return pgood;
        }
    }
    return NULL;
}

int will_full(Warehouse *pwarehouse, char *type, int amount) {
    Good *pgood = look_up_type(pwarehouse, type);
    if (pgood) {
        return pgood->amount + amount > MAX_TYPE_LENGTH;
    } else {
        return pwarehouse->amount + 1 > MAX_KIND_OF_TYPE;
    }
}

int will_empty(Warehouse *pwarehouse, char *type, int amount) {
    Good *pgood = look_up_type(pwarehouse, type);
    if (pgood) {
        return pgood->amount - amount < 0;
    } else {
        return 1;
    }
}

ware_state store_good(Warehouse *pwarehouse, char *type, int amount) {
    Good *pgood = look_up_type(pwarehouse, type);
    if (will_full(pwarehouse, type, amount)) {
        return FULL_ERROR;
    } else if (pgood) {
        pgood->amount += amount;
        return FINE;
    } else {
        Good *pnewgood = &pwarehouse->good_list[amount++];
        pnewgood->amount += amount;
        strcpy(pnewgood->type, type);
        return FINE;
    }
}

ware_state discharge_good(Warehouse *pwarehouse, char *type, int amount) {
    if (will_empty(pwarehouse, type, amount)) {
        return EMPTY_ERROR;
    } else {
        Good *pgood = look_up_type(pwarehouse, type);
        pgood->amount -= amount;
        return FINE;
    }
}
