#include "FileReader.h"
#include "Menu.h"

int main() {
    vector<Parcel> parcels;
    vector<Van> vans;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniVans(&vans, "carrinhas.txt");
    Menu::start(vans, parcels);
    return 0;
}