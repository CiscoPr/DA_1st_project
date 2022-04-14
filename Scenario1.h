//
// Created by ricar on 13/04/2022.
//

#ifndef DA_PROJECT1_SCENARIO1_H
#define DA_PROJECT1_SCENARIO1_H

#include <list>
#include "Van.h"
#include "Courier.h"

class Scenario1 {

protected:
    std::list<Van> vans;
    std::list<Courier> dels;
public:
    Scenario1();
    std::list<Van> getVans();
    std::list<Courier> getDels();
    std::list<Van> minOfVans();

};


#endif //DA_PROJECT1_SCENARIO1_H
