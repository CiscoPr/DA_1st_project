#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <climits>

#include "Parcel.h"
#include "Van.h"

using namespace std;

class FileReader {
    vector<string> temp;

public:
    FileReader();
    void readFile(const string& txt);
    void iniParcels(vector<Parcel> *parcels, const string& txt);
    void iniVans(vector<Van> *vans, const string& txt);
};