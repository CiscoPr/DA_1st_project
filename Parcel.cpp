#include "Parcel.h"

Parcel::Parcel(int vol, int weight, int cost, int duration) : vol(vol), weight(weight), cost(cost), duration(duration) {}

int Parcel::getVol() const {return vol;}

int Parcel::getWeight() const {return weight;}

int Parcel::getCost() const {return cost;}

int Parcel::getDuration() const {return duration;}

bool Parcel::operator<(const Parcel &parcel) const {
    if (cost == parcel.cost) return vol * weight < parcel.vol * parcel.weight;
    return cost > parcel.cost;
}

bool Parcel::operator==(const Parcel &parcel) const {
    return vol == parcel.vol && weight == parcel.weight && cost == parcel.cost && duration == parcel.duration;
}

ostream& operator<<(ostream& out, Parcel& p1) {
    out << p1.getVol() << " " << p1.getWeight() << " " << p1.getCost() << " " << p1.getDuration() << endl;
    return out;
}