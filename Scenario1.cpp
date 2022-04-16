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

    for(auto itr1 = vans.begin() ; itr1 != vans.end() ; itr1++) {

        Van carrinha = vans.front();

        for(auto itr2 = dels.begin() ; itr2 != dels.end() ; itr2++) {

            Parcel encomenda = dels.front();

            if((carrinha.getMaxWeight() - encomenda.getWeight()) > 0 || (carrinha.getMaxVol() - encomenda.getVol()) > 0){
                carrinha.setMaxWeight(carrinha.getMaxWeight() - encomenda.getWeight());
                carrinha.setMaxVol(carrinha.getMaxVol() - encomenda.getVol());
                dels.erase(itr2);
            } else {
                vans.erase(itr1);
            }
        }
        availableVans.push_back(carrinha);
    }

    if(dels.size() > 0) {
        for(auto itr3 = dels.begin() ;
            itr3 != dels.end();
            itr3++) {
            dels.erase(itr3);
        }
    }

    std::cout << "The minimum number of vans needed to deliver all packages is " << availableVans.size() << std::endl;
}