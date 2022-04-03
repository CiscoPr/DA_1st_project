#pragma once

class Van {
    int maxVol, maxWeight, cost;
public:
    Van(int maxVol, int maxWeight, int cost);

    int getMaxVol() const;

    void setMaxVol(int maxVol);

    int getMaxWeight() const;

    void setMaxWeight(int maxWeight);

    int getCost() const;

    void setCost(int cost);
};