#include "headers/Circuit.hpp"

Circuit::~Circuit() {
    for (auto e : m_electrical_equipments) {
        delete e;
        e = NULL;
    }
}
