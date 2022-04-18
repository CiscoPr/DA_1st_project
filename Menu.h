
#pragma once

#include <iostream>
#include <limits>
#include "Scenario1.h"
#include "Scenario2.h"
#include "Scenario3.h"

using namespace std;
/**
 * Class of user's interface
 */
class Menu {
public:
    /**
     * Constructor
     */
    Menu();
    /**
     * Starts user interface
     */
    static void start(vector<Van> vans, vector<Parcel> parcels);
};