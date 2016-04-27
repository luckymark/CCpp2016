#ifndef CARGO_SYSTEM_DEF_H_INCLUDED
#define CARGO_SYSTEM_DEF_H_INCLUDED

#include <vector>
#include <map>
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

class Persistence {
private:
    std::string fn;
    std::map<std::string, std::string> cl;
public:
    Persistence(std::string fn);

    std::string get(std::string key);
    void set(std::string key, std::string value);
};

class CargoActionPool {
public:
    Persistence *cp;

    CargoActionPool(std::string fn = "ps.dat") {
        cp = new Persistence(fn);
    }

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

#define CARGO_SYSTEM_ACTION(name, description) \
class __CARGO__ACTION__##name : public CargoAction {\
public:\
    __CARGO__ACTION__##name() {desc = description;}\
    virtual void run();\
};\
CargoActionRegister __CARGO_ACTION_REGISTER__##name(CargoActionFactory<__CARGO__ACTION__##name>().create());\
void __CARGO__ACTION__##name::run()

#define CARGO_SYSTEM_PERSISTENCE_GET(key) __global__cargoActionPool.cp->get(key)
#define CARGO_SYSTEM_PERSISTENCE_SET(key, value) __global__cargoActionPool.cp->set(key, value)


void cargo_system_loop();


#endif // CARGO_SYSTEM_DEF_H_INCLUDED
