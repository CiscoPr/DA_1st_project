#include "Courier.h"

Courier::Courier(int mVol, int mWgt, int cost) : mVol(mVol), mWgt(mWgt), cost(cost) {}

int Courier::getMVol() const {return mVol;}

void Courier::setMVol(int mVol) {Courier::mVol = mVol;}

int Courier::getMWgt() const {return mWgt;}

void Courier::setMWgt(int mWgt) {Courier::mWgt = mWgt;}

int Courier::getCost() const {return cost;}

void Courier::setCost(int cost) {Courier::cost = cost;}

/*void Courier::show() {
    std::cout << "Vol:" << maxVol << " " << "Weight:" << maxWeight << " " << "Cost:" << rwd << std::endl;
}*/