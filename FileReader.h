#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <climits>
#include <utility>
#include "Parcel.h"
#include "Van.h"

using namespace std;
/**
 * Class that reads files
 */
class FileReader {
    vector<string> temp;            /**!< Vector used to save objects read in file */

public:
    /**
     * Constructor
     */
    FileReader();
    /**
     * Reads file and saves it in vector
     * @param txt File's name
     */
    void readFile(const string& txt);
    /**
     * Saves all parcels to vector
     * @param parcels Pointer to vector containing all parcels
     * @param txt File's name
     */
    void iniParcels(vector<Parcel> *parcels, const string& txt);
    /**
     * Saves all vans to vector
     * @param vans Pointer to vector containing all vans
     * @param txt File's name
     */
    void iniVans(vector<Van> *vans, const string& txt);
};