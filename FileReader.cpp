#include "FileReader.h"

#include <utility>

FileReader::FileReader() = default;

void FileReader::readFile(const string& txt) {
    ifstream f("../res/" + txt);
    string line;

    if (!f.is_open()) cerr << "File couldn't be find." << endl;

    f.ignore(INT_MAX, '\n');
    while (getline(f, line)) {
        temp.push_back(line);
    }
    f.close();
}

void FileReader::iniParcels(vector<Parcel> *parcels, const string& txt) {

    temp.clear();
    readFile(txt);

    for (const string& line : temp) {

        size_t pos1 = line.find(' ');
        int vol = stoi(line.substr(0, pos1));

        size_t pos2 = line.find(' ', pos1 + 1);
        int weight = stoi(line.substr(pos1 + 1, pos2));

        pos1 = line.find(' ', pos2 + 1);
        int reward = stoi(line.substr(pos2 + 1, pos1));

        int duration = stoi(line.substr(pos1 + 1, line.length()));

        Parcel parcel = Parcel(vol, weight, reward, duration);
        parcels->push_back(parcel);
    }
}

void FileReader::iniVans(vector<Van> *vans, const string& txt) {

    temp.clear();
    readFile(txt);

    for (const string& line : temp) {

        size_t pos1 = line.find(' ');
        int maxVol = stoi(line.substr(0, pos1));

        size_t pos2 = line.find(' ', pos1 + 1);
        int maxWeight = stoi(line.substr(pos1 + 1, pos2));

        int cost = stoi(line.substr(pos2 + 1, line.length()));

        Van van = Van(maxVol, maxWeight, cost);
        vans->push_back(van);
    }
}