#pragma once

#include <vector>
#include <set>
#include <iostream>
#include <utility>
#include "Van.h"
#include "Parcel.h"

using namespace std;
/**
 * Class for scenario 2
 */
class Scenario2 {
    vector<Van> vans;                    /**!< Vector containing all vans */
    vector<Parcel> parcels;              /**!< Vector containing all parcels */
    int balance;                         /**!< Balance of the deliveries of the day */
    set<Parcel> delivered;            /**!< Set containing delivered parcels */
    vector<Van> used;                    /**!< Set containing used vans */

public:
    /**
     * Constructor
     * @param vans Set containing delivered parcels
     * @param parcels Set containing used vans
     */
    Scenario2(vector<Van> vans, vector<Parcel> parcels);
    /**
     * Starts the algorithm for the scenario
     */
    void start();
    /**
     * Checks if van is full, if not, places parcel in it
     * @param v Van that is being analysed
     * @param p Parcel to be put in van
     * @return True or false depending if it is possible or not
     */
    bool checkVan(Van& v, Parcel& p);
    /**
     * Checks if balance is positive and, if not, makes it so
     */
    void checkBalance();
    /**
     * Shows in terminal balance
     */
    void show() const;
};