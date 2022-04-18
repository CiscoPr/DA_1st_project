#include "Van.h"

Van::Van(int maxVol, int maxWeight, int cost) : maxVol(maxVol), maxWeight(maxWeight), cost(cost) {
    profit -= cost;
}

int Van::getMaxVol() const {return maxVol;}

void Van::setMaxVol(int maxVol) {Van::maxVol = maxVol;}

int Van::getMaxWeight() const {return maxWeight;}

void Van::setMaxWeight(int maxWeight) {Van::maxWeight = maxWeight;}

int Van::getCost() const {return cost;}

stack<Parcel> Van::getOccupied() {return occupied;}

int Van::getProfit() const {return profit;}

bool Van::checkVol(int vol) const { return maxVol > vol;}

bool Van::checkWeight(int weight) const { return maxWeight > weight;}

void Van::occupySpace(Parcel& parcel) {
    maxVol -= parcel.getVol();
    maxWeight -= parcel.getWeight();
    occupied.push(parcel);
    profit += parcel.getCost();
}

bool Van::operator<(const Van &van) const {
    return maxVol * maxWeight / cost > van.maxVol * van.maxWeight / van.cost;
}

ostream& operator<<(ostream& out, Van& v1) {
    out << v1.getMaxVol() << " " << v1.getMaxWeight() << " " << v1.getCost() << " " << v1.getProfit() << endl;
    return out;
}