#ifndef warehouse_model_h__
#define warehouse_model_h__

#define MAX_TYPE_LENGTH 100
#define MAX_KIND_OF_TYPE 100

typedef enum _ware_state {
    FINE,
    FULL_ERROR,
    KEY_ERROR,
    EMPTY_ERROR
} ware_state;

typedef struct _good {
    char type[MAX_TYPE_LENGTH+1];
    int amount;
} Good;

typedef struct _warehouse {
    Good good_list[MAX_KIND_OF_TYPE];
    int amount;
} Warehouse;

void init_warehouse(Warehouse *pwarehouse);

ware_state discharge_good(Warehouse *pwarehouse, const char *type, int amount);

ware_state store_good(Warehouse *pwarehouse, const char *type, int amount);

#endif
