#include "Scenario2.h"

Scenario2::Scenario2( vector<Van> &vans, vector<Parcel> &parcels) : vans(vans), parcels(parcels) {
    balance = 0;
}

void Scenario2::start() {

    sort(parcels.begin(), parcels.end());
    sort(vans.begin(), vans.end());

    while (!parcels.empty() && !vans.empty()) {
        if (used.insert(vans[0]).second) balance -= vans[0].getCost();
        if (!checkVan(vans[0], parcels[0])) {
            for (auto it = parcels.begin(); it != parcels.end(); it++) {
                if (checkVan(vans[0], *it)) it = parcels.begin();
            }
            vans.erase(vans.begin());
        }
    }
    /*while (p1 != parcels.end()) {
        if (v1 == vans.end()) break;
        if (used.insert(*v1).second) balance -= v1->getCost();
        if (v1->checkVol(p1->getVol()) && v1->checkWeight(p1->getWeight())) {
            if (delivered.insert(*p1).second) {
                v1->occupySpace(*p1);
                balance += p1->getCost();
            }
            p1++;
        }
        else {
            for (auto it = copy_p.begin(); it != copy_p.end(); it++) {
                if (v1->checkVol(it->getVol()) && v1->checkWeight(it->getWeight())) {
                    if (delivered.insert(*it).second) {
                        v1->occupySpace(*it);
                        balance += it->getCost();
                        it = copy_p.begin();
                    }
                }
            }
            v1++;
        }
    }*/
    checkBalance();
}

void Scenario2::checkBalance() {
    vector<Van> temp;

    if (balance >= 0) return;

    for (const auto& x : used) temp.push_back(x);
    sort(temp.begin(), temp.end(), [] (const Van& v1, const Van& v2) {
        return v1.getProfit() < v2.getProfit();
    });

    while (balance < 0) {
        while (!temp[0].getOccupied().empty()) {
            balance -= temp[0].getOccupied().top().getCost();
            temp[0].getOccupied().pop();
        }
        balance += temp[0].getCost();
        temp.erase(temp.begin());
    }
}

bool Scenario2::checkVan(Van& van, Parcel& parcel) {
    if (van.checkVol(parcel.getVol()) && van.checkWeight(parcel.getWeight())) {
        delivered.insert(parcel);
        van.occupySpace(parcel);
        balance += parcel.getCost();
        parcels.erase(find(parcels.begin(), parcels.end(), parcel));
        return true;
    }
    return false;
}

void Scenario2::show() const {
    cout << "The profit the company made was: " << balance << "€" << endl;
}
