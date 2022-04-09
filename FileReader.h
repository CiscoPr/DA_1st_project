#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <climits>
#include "Parcel.h"
#include "Courier.h"

using namespace std;

class FileReader {
    vector<string> temp;

public:
    FileReader();
    void readFile(const string& txt);
    void iniParcels(vector<Parcel> *parcels, const string& txt);
    void iniCouriers(vector<Courier> *couriers, const string& txt);
};