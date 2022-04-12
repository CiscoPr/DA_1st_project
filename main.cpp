
#include "FileReader.h"
#include "Menu.h"
#include "Scenario3.h"
#include <chrono>
int main() {/*
    vector<Parcel> parcels;
    vector<Courier> couriers;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniCouriers(&couriers, "carrinhas.txt");
    Menu menu = Menu();
    menu.start();
    */

    std::chrono::high_resolution_clock::time_point start, end;

    Scenario3 scenario3;
    start = std::chrono::high_resolution_clock::now();
    scenario3.getDeliveries();
    scenario3.possibleCombinations();
    scenario3.result();
    end = std::chrono::high_resolution_clock::now();

    std::cout << '\n' << "total of " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " elapsed miliseconds";
    return 0;
}