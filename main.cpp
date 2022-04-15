
#include "FileReader.h"
#include "Menu.h"
#include "Scenario3.h"
#include "Scenario2.h"

#include <chrono>
int main() {
    vector<Parcel> parcels;
    vector<Van> vans;
    FileReader fileReader  = FileReader();
    fileReader.iniParcels(&parcels, "encomendas.txt");
    fileReader.iniVans(&vans, "carrinhas.txt");
    //Menu::start();

    std::chrono::high_resolution_clock::time_point start2, end2;
    Scenario2 s2 = Scenario2(vans, parcels);
    start2 = std::chrono::high_resolution_clock::now();
    s2.start();
    s2.show();
    end2 = std::chrono::high_resolution_clock::now();

    std::cout << '\n' << "total of " << std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count() << " elapsed miliseconds";


    /*std::chrono::high_resolution_clock::time_point start, end;

    Scenario3 scenario3;
    start = std::chrono::high_resolution_clock::now();
    scenario3.getDeliveries();
    scenario3.possibleCombinations();
    scenario3.result();
    end = std::chrono::high_resolution_clock::now();

    std::cout << '\n' << "total of " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " elapsed miliseconds";
    */return 0;
}