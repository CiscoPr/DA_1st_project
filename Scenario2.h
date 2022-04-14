#pragma once

#include "Van.h"
#include "Parcel.h"

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Scenario2 {
    vector<Van> vans;
    vector<Parcel> parcels;
    int balance;
    set<Parcel> delivered;
    set<Van> used;

public:
    Scenario2(const vector<Van> &vans, const vector<Parcel> &parcels);
    void start();
    void checkBalance();
    void show();
};