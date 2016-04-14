#include "cargo_system_def.h"

#include <iostream>
#include <fstream>

using namespace std;

void cargo_system_loop() {
    while (1) {
        std::cout << "Cargo Management System" << std::endl;
        std::cout << "Menu: " << std::endl;
        for (int __CG_i = 0; __CG_i < __global__cargoActionPool.actions.size(); ++__CG_i) {
            std::cout << __CG_i << ": " << __global__cargoActionPool.actions[__CG_i]->desc << std::endl;
        }
        int selected;
        std::cin >> selected;
        __global__cargoActionPool.actions[selected]->run();
        std::system("pause");
        std::system("cls");
    }\
}

Persistence::Persistence(std::string fn) {
    this->fn = fn;
    ifstream ifs;
    ifs.open(fn, ios::in);
    string line;
    while (getline(ifs, line)) {
        size_t sp = line.find(':');
        cl[line.substr(0, sp)] = line.substr(sp + 1);
    }
    ifs.close();
}

string Persistence::get(string key) {
    if (cl.find(key) == cl.end()) {
        return "";
    }
    return cl[key];
}
void Persistence::set(string key, string value) {
    cl[key] = value;
    ofstream ofs;
    ofs.open(fn, ios::out | ios::trunc);
    for (auto& kv : cl) {
        ofs << kv.first << ':' << kv.second << std::endl;
    }
    ofs.close();
}
