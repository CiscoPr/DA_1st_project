#pragma once

class Parcel {
    int vol, weight, cost, duration;
public:
    Parcel(int vol, int weight, int cost, int duration);

    int getVol() const;

    void setVol(int vol);

    int getWeight() const;

    void setWeight(int weight);

    int getCost() const;

    void setCost(int cost);

    int getDuration() const;

    void setDuration(int duration);
};