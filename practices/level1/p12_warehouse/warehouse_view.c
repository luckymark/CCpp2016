#include <stdio.h>
#include "warehouse_view.h"


void display_help_info(void) {
    putchar('\n');
    printf("1. 显示存货列表\n2. 入库\n3. 出库\n4. 退出程序\n");
}

void display_ware(const Warehouse *pwarehouse) {
    for (int i = 0; i < pwarehouse->amount; i++) {
        printf("%s: %d\n", pwarehouse->good_list[i].type, pwarehouse->good_list[i].amount);
    }
}
