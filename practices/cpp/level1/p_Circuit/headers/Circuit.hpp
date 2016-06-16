#ifndef CIRCUIT_HPP__
#define CIRCUIT_HPP__

#include <vector>
#include "Turnable.hpp"

class Circuit {
private:
    std::vector<Turnable *> m_electrical_equipments;
public:
    ~Circuit();
    void add(Turnable *);
};

#endif
