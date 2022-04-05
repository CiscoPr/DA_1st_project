#pragma once

class Courier {
    int mVol, mWgt, cost;
public:
    Courier(int mVol, int mWgt, int cost);

    int getMVol() const;
    void setMVol(int mVol);
    int getMWgt() const;
    void setMWgt(int mWgt);
    int getCost() const;
    void setCost(int cost);

    //void show();
};