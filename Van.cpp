#include "Van.h"

Van::Van(int maxVol, int maxWeight, int cost) : maxVol(maxVol), maxWeight(maxWeight), cost(cost) {}

int Van::getMaxVol() const {return maxVol;}

void Van::setMaxVol(int maxVol) {Van::maxVol = maxVol;}

int Van::getMaxWeight() const {return maxWeight;}

void Van::setMaxWeight(int maxWeight) {Van::maxWeight = maxWeight;}

int Van::getCost() const {return cost;}

void Van::setCost(int cost) {Van::cost = cost;}