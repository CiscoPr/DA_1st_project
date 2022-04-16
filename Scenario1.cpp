#include <fstream>
#include <vector>
#include "Scenario1.h"
#include "FileReader.h"

Scenario1::Scenario1() {}

/*
 * This function returns a list with
 * the minimum amount of vans of those
 * available to deliver all the deliveries
 * in a day if possible
 *
 * Algorithm: Greedy
 * */

void Scenario1::minOfVans() {

    std::list<Van> availableVans;

    for(std::vector<Van>::iterator itr1 = vans.begin() ; itr1 != vans.end() ; itr1++) {

        Van carrinha = vans.front();

        for(std::vector<Courier>::iterator itr2 = dels.begin() ; itr2 != dels.end() ; itr2++) {

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
        for(std::vector<Courier>::iterator itr3 = dels.begin() ;
            itr3 != dels.end() ;
            itr3++) {
            dels.erase(itr3);
        }
    }

    return availableVans;
}