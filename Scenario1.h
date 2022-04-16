#ifndef DA_PROJECT1_SCENARIO1_H
#define DA_PROJECT1_SCENARIO1_H

#include <vector>
#include "Van.h"
#include "Parcel.h"

class Scenario1 {
    std::vector<Van> vans;
    std::vector<Parcel> dels;
public:
    Scenario1(std::vector<Van> v, std::vector<Parcel> p);
    void minOfVans();
};


#endif //DA_PROJECT1_SCENARIO1_H
