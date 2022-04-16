#include <fstream>
#include <utility>
#include "Scenario1.h"
#include "FileReader.h"

Scenario1::Scenario1(std::vector<Van> v, std::vector<Parcel> p) : vans(std::move(v)), dels(std::move(p)) {}

/*
 * This function prints the minimum
 * number of vans needed to deliver
 * all the packages available for
 * delivery in a certain day.
 *
 * Algorithm: Greedy
 * */

void Scenario1::minOfVans() {

    std::vector<Van> availableVans;

    for(auto itr1 = vans.begin() ; itr1 != vans.end() ; itr1++) {

        Van carrinha = *itr1;

        for(auto itr2 = dels.begin() ; itr2 != dels.end() ; ) {

            Parcel encomenda = *itr2;

            if((carrinha.getMaxWeight() - encomenda.getWeight()) > 0 && (carrinha.getMaxVol() - encomenda.getVol()) > 0){
                carrinha.setMaxWeight(carrinha.getMaxWeight() - encomenda.getWeight());
                carrinha.setMaxVol(carrinha.getMaxVol() - encomenda.getVol());
                dels.erase(itr2);
            } else {
                itr2++;
                availableVans.push_back(carrinha);
                break;
            }
        }
    }

    for(auto itr4 = availableVans.begin() ; itr4 != availableVans.end() ; itr4++) {
        std::cout << itr4->getMaxWeight() << " " << itr4->getMaxVol() << std::endl;
    }

    std::cout << "The minimum number of vans needed to deliver all packages is " << availableVans.size() << std::endl;
}