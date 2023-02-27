#pragma once
#ifndef MMY
#define MMY_H
#include <string>
#include <vector>

struct MMYData {
    std::string make;
    std::string model;
    std::string year;
};

class MMY {
public:
    MMY(); // constructor

private:
    std::vector<MMYData> data; // private member variable
};

#endif // !MMY
