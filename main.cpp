
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
    scenario3.getMeanTime();
    end = std::chrono::high_resolution_clock::now();

    std::cout << '\n' << "total of " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " elapsed nanoseconds";
    /*
     * antes: 70106800 ns
     * depois:11013700 ns
     */
    return 0;
}