#ifndef CARGO_SYSTEM_DEF_H_INCLUDED
#define CARGO_SYSTEM_DEF_H_INCLUDED

#include <vector>
#include <string>
#include <cstdlib>

class CargoAction {
public:
    std::string desc;
    virtual void run() {}
};

template <class ActionClass>
class CargoActionFactory {
public:
    CargoAction *create() {
        return new ActionClass;
    }
};

class CargoActionPool {
public:
    std::vector<CargoAction *> actions;
    void registerAction(CargoAction *action) {
        actions.push_back(action);
    }
};

extern CargoActionPool __global__cargoActionPool;

class CargoActionRegister {
public:
    CargoActionRegister(CargoAction *action) {
        __global__cargoActionPool.registerAction(action);
    }
};

#define CARGO_SYSTEM_ACTION_META CargoActionPool __global__cargoActionPool;

#define CARGO_SYSTEM_ACTION(name, description) \
class __CARGO__ACTION__##name : public CargoAction {\
public:\
    __CARGO__ACTION__##name() {desc = description;}\
    virtual void run();\
};\
CargoActionRegister __CARGO_ACTION_REGISTER__##name(CargoActionFactory<__CARGO__ACTION__##name>().create());\
void __CARGO__ACTION__##name::run()

#define CARGO_SYSTEM_LOOP\
{\
    while (1) {\
        std::cout << "Cargo Management System" << std::endl;\
        std::cout << "Menu: " << std::endl;\
        for (int __CG_i = 0; __CG_i < __global__cargoActionPool.actions.size(); ++__CG_i) {\
            std::cout << __CG_i << ": " << __global__cargoActionPool.actions[__CG_i]->desc << std::endl;\
        }\
        int selected;\
        std::cin >> selected;\
        __global__cargoActionPool.actions[selected]->run();\
        std::system("pause");\
        std::system("cls");\
    }\
}


#endif // CARGO_SYSTEM_DEF_H_INCLUDED
