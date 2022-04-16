#ifndef DA_PROJECT1_SCENARIO1_H
#define DA_PROJECT1_SCENARIO1_H

#include <list>
#include "Van.h"
#include "parcel.h"

class Scenario1 {

protected:
    std::list<Van> vans;
    std::list<Parcel> dels;
public:
    Scenario1();
    void minOfVans();
};


#endif //DA_PROJECT1_SCENARIO1_H
