#pragma once

#include <iostream>

using namespace std;
/**
 * Class representing parcels.
 */
class Parcel {
    int vol;                    /**!< Volume */
    int weight;                 /**!< Weight */
    int cost;                   /**!< Reward of delivering parcel */
    int duration;               /**!< Maximum duration delivery must be delivered */
public:
    /**
     * Constructor
     * @param vol Volume
     * @param weight Weight
     * @param cost Reward of delivering parcel
     * @param duration Maximum duration delivery must be delivered
     */
    Parcel(int vol, int weight, int cost, int duration);
    /**
     * Getter for volume
     * @return volume
     */
    int getVol() const;
    /**
     * Getter for weight
     * @return weight
     */
    int getWeight() const;
    /**
     * Getter for cost
     * @return cost
     */
    int getCost() const;
    /**
     * Getter for duration
     * @return duration
     */
    int getDuration() const;
    /**
     * Overloaded operator <
     */
    bool operator<(const Parcel& parcel) const;
    /**
     * Overloaded operator ==
     */
    bool operator==(const Parcel& parcel) const;
};