
#include "FileReader.h"
#include "Menu.h"
#include "Scenario3.h"
int main() {/*
    vector<Parcel> parcels;
    vector<Courier> couriers;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniCouriers(&couriers, "carrinhas.txt");
    Menu menu = Menu();
    menu.start();
    */
    Scenario3 scenario3;
    scenario3.getDeliveries();
    scenario3.test();
    return 0;
}