#ifndef CARGO_HELPER_H_INCLUDED
#define CARGO_HELPER_H_INCLUDED

#include <string>
#include <vector>
#include <sstream>

inline std::vector<std::string> retrieveFormatedCargoModels(std::string str) {
    std::stringstream ss(str);
    std::vector<std::string> arr;
    std::string item;
    while (ss >> item) {
        arr.push_back(item);
    }
    return arr;
}

inline std::string formatCargoModels(std::vector<std::string> models) {
    std::string res;
    for (auto i : models) {
        res += i + " ";
    }
    return res.substr(res.length() - 1);
}


#endif // CARGO_HELPER_H_INCLUDED
