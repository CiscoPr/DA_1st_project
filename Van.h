#pragma once

#include <stack>
#include <iostream>

#include "Parcel.h"

using namespace std;

class Van {
    int maxVol, maxWeight, cost, profit{};
    stack<Parcel> occupied;

public:
    Van(int maxVol, int maxWeight, int cost);

    int getMaxVol() const;

    int getMaxWeight() const;

    int getCost() const;

    stack<Parcel> getOccupied();

    int getProfit() const;

    bool checkVol(int vol) const;

    bool checkWeight(int weight) const;

    void occupySpace(Parcel& parcel);

    bool operator<(const Van& van) const;
};