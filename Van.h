#pragma once

#include <stack>
#include <iostream>

#include "Parcel.h"

using namespace std;
/**
 * Class representing delivery vans.
 */
class Van {
    int maxVol;                                   /**!< Max volume */
    int maxWeight;                                /**!< Max weight */
    int cost;                                     /**!< Cost of van's usage */
    int profit;                                   /**!< Balance of van's usage */
    stack<Parcel> occupied;                       /**!< Parcel's inside van */

public:
    /**
     * Constructor
     * @param maxVol max supported volume
     * @param maxWeight max supported weight
     * @param cost cost of using van
     */
    Van(int maxVol, int maxWeight, int cost);
    /**
     * Getter for max volume
     * @return max volume
     */
    int getMaxVol() const;
    /**
     * Setter for max volume
     * @param maxVol max volume
     */
    void setMaxVol(int maxVol);
    /**
     * Getter for max weight
     * @return max weight
     */
    int getMaxWeight() const;
    /**
     * Setter for max weight
     * @param maxWeight max weight
     */
    void setMaxWeight(int maxWeight);
    /**
     * Getter for cost
     * @return cost
     */
    int getCost() const;
    /**
     * Getter for van's occupation
     * @return van's occupation
     */
    stack<Parcel> getOccupied();
    /**
     * Getter for profit
     * @return profit
     */
    int getProfit() const;
    /**
     * Checks if the max volume has been reached
     * @param vol volume of parcel to be put in van
     * @return True or false depending on whether it's possible or not
     */
    bool checkVol(int vol) const;
    /**
     * Checks if the max weight has been reached
     * @param weight weight of parcel to be put in van
     * @return True or false depending on whether it's possible or not
     */
    bool checkWeight(int weight) const;
    /**
     * Puts parcel in van
     * @param parcel Parcel to be put in van
     */
    void occupySpace(Parcel& parcel);
    /**
     * Overloaded operator <
     */
    bool operator<(const Van& van) const;
};