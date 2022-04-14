#pragma once

#include <stack>

#include "Parcel.h"

using namespace std;

class Van {
    int maxVol, maxWeight, cost;
    stack<Parcel> occupied;
    int profit;

public:
    Van(int maxVol, int maxWeight, int cost);

    int getMaxVol() const;

    void setMaxVol(int maxVol);

    int getMaxWeight() const;

    void setMaxWeight(int maxWeight);

    int getCost() const;

    void setCost(int cost);

    stack<Parcel> getOccupied();

    void setOccupied(const stack<Parcel> &occupied);

    int getProfit() const;

    void setProfit(int profit);

    bool checkVol(int vol);
    bool checkWeight(int weight);
    void occupySpace(Parcel& parcel);
};