
#include "FileReader.h"
#include "Menu.h"

int main() {
    vector<Parcel> parcels;
    vector<Courier> couriers;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniCouriers(&couriers, "carrinhas.txt");
    Menu menu = Menu();
    menu.start();
    return 0;
}