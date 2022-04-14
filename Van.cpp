#include "Van.h"

Van::Van(int maxVol, int maxWeight, int cost) : maxVol(maxVol), maxWeight(maxWeight), cost(cost) {
    profit -= cost;
}

int Van::getMaxVol() const {return maxVol;}

void Van::setMaxVol(int maxVol) {Van::maxVol = maxVol;}

int Van::getMaxWeight() const {return maxWeight;}

void Van::setMaxWeight(int maxWeight) {Van::maxWeight = maxWeight;}

int Van::getCost() const {return cost;}

void Van::setCost(int cost) {Van::cost = cost;}

bool Van::checkVol(int vol) { return maxVol > vol;}

bool Van::checkWeight(int weight) { return maxWeight > weight;}

void Van::occupySpace(Parcel& parcel) {
    maxVol -= parcel.getVol();
    maxWeight -= parcel.getWeight();
    occupied.push(parcel);
    profit += parcel.getCost();
}

stack<Parcel> Van::getOccupied() {
    return occupied;
}

void Van::setOccupied(const stack<Parcel> &occupied) {
    Van::occupied = occupied;
}

int Van::getProfit() const {
    return profit;
}

void Van::setProfit(int profit) {
    Van::profit = profit;
}
