#include "Parcel.h"

Parcel::Parcel(int vol, int weight, int cost, int duration) : vol(vol), weight(weight), cost(cost), duration(duration) {}

int Parcel::getVol() const {return vol;}

void Parcel::setVol(int vol) {Parcel::vol = vol;}

int Parcel::getWeight() const {return weight;}

void Parcel::setWeight(int weight) {Parcel::weight = weight;}

int Parcel::getCost() const {return cost;}

void Parcel::setCost(int cost) {Parcel::cost = cost;}

int Parcel::getDuration() const {return duration;}

void Parcel::setDuration(int duration) {Parcel::duration = duration;}
