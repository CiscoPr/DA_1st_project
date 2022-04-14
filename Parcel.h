#pragma once

#include <iostream>

using namespace std;

class Parcel {
    int vol, weight, cost, duration;
public:
    Parcel(int vol, int weight, int cost, int duration);

    int getVol() const;

    int getWeight() const;

    int getCost() const;

    int getDuration() const;

    bool operator<(const Parcel& parcel) const;
    bool operator==(const Parcel& parcel) const;
};