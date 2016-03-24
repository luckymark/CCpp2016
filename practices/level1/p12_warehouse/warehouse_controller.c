#include <stdio.h>

#include "warehouse_model.h"
#include "warehouse_controller.h"
#include "warehouse_view.h"

void create_fake_ware(Warehouse *pwarehouse) {
    store_good(pwarehouse, "西瓜", 100);
    store_good(pwarehouse, "香蕉", 100);
    store_good(pwarehouse, "橘子", 100);
}

enum option {
    DISPLAY = 1,
    STORE,
    DISCHARGE,
    QUIT
};

int main(int argc, char const *argv[]) {
    int input = 0;
    char type[MAX_TYPE_LENGTH] = {0};
    int amount = 0;
    int loop_state = 1;
    Warehouse warehouse;
    init_warehouse(&warehouse);
    create_fake_ware(&warehouse);

    while (loop_state) {
        display_help_info();
        scanf("%d", &input);
        switch (input) {
            case DISPLAY:
                display_ware(&warehouse);
                break;
            case STORE:
                scanf("%s %d", type, &amount);
                store_good(&warehouse, type, amount);
                break;
            case DISCHARGE:
                scanf("%s %d", type, &amount);
                discharge_good(&warehouse, type, amount);
                break;
            case QUIT:
                loop_state = 0;
                break;
        }
    }
    return 0;
}
