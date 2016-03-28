#include <stdio.h>

#include "warehouse_model.h"
#include "warehouse_view.h"

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
    load_from_file(&warehouse, FILENAME);

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
    
    save_data(&warehouse, FILENAME);
    return 0;
}
