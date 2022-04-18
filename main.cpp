#include "FileReader.h"
#include "Menu.h"

#include <chrono>
int main() {
    vector<Parcel> parcels;
    vector<Van> vans;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniVans(&vans, "carrinhas.txt");
    Menu::start(vans, parcels);
     /*
     * antes: 70106800 ns
     * depois:11013700 ns
     */
    return 0;
}