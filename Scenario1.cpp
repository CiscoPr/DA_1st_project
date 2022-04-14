#include <fstream>
#include <vector>
#include "Scenario1.h"
#include "FileReader.h"

Scenario1::Scenario1() {}

/*
 * This function returns a list with
 * the available vans to do deliveries.
 * They are read from a file that contains
 * each van's maximum weight, volume and cost.
 * */

void Scenario1::getVans() {
    ifstream file;
    FileReader reader;
    file.open("../res/carrinhas.txt");
    reader.iniCouriers(vans,file);
    file.close();
}


/*
 * This function returns a list with
 * the packages ready to deliver in
 * a certain day. They are read from a
 * file that contains each package's weight,
 * volume, price paid to the company for doing
 * the delivery and the estimated time to deliver
 * the package.
 */

void Scenario1::getDels(){
    ifstream file;
    FileReader reader;
    file.open("../res/encomendas.txt");
    reader.iniParcels(dels,file);
    file.close();
}

/*
 * This function returns a list with
 * the minimum amount of vans of those
 * available to deliver all the deliveries
 * in a day if possible
 *
 * Algorithm: Greedy
 * */

std::list<Van> Scenario1::minOfVans() {

    getVans();
    getDels();
    std::list<Van> availableVans;

    for(std::list<Van>::iterator itr1 = vans.begin() ; itr1 != vans.end() ; itr1++) {

        Van carrinha = vans.front();

        for(std::list<Courier>::iterator itr2 = dels.begin() ; itr2 != dels.end() ; itr2++) {

            Courier encomenda = dels.front();

            if((carrinha.getMaxWeight() - encomenda.getMWgt()) > 0 || (carrinha.getMaxVol() - encomenda.getMVol()) > 0){
                carrinha.setMaxWeight(carrinha.getMaxWeight() - encomenda.getMWgt());
                carrinha.setMaxVol(carrinha.getMaxVol() - encomenda.getMVol());
                dels.erase(itr2);
            } else {
                vans.erase(itr1);
            }
        }
        availableVans.push_back(carrinha);
    }

    if(dels.size() > 0) {
        for(std::list<Courier>::iterator itr3 = dels.begin() ;
            itr3 != dels.end() ;
            itr3++) {
            dels.erase(itr3);
        }
    }

    return availableVans;
}