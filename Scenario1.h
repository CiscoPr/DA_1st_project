#pragma once

#include <vector>
#include "Van.h"
#include "Parcel.h"

/**
 * Class of scenario 1
 */
class Scenario1 {
    std::vector<Van> vans;
    std::vector<Parcel> dels;
public:
    /**
     * Constructor
     * @param v Vector of vans
     * @param p Vector of parcels
     */
    Scenario1(std::vector<Van> v, std::vector<Parcel> p);
    /**
     * This function prints the minimum
     * number of vans needed to deliver
     * all the packages available for
     * delivery in a certain day.
     * Algorithm: Greedy
     * */
    void minOfVans();
};