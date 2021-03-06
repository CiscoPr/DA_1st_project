#include <algorithm>
#include "Scenario2.h"

Scenario2::Scenario2( vector<Van> vans, vector<Parcel> parcels) : vans(move(vans)), parcels(move(parcels)) {
    balance = 0;
}

void Scenario2::start() {

    sort(parcels.begin(), parcels.end());
    sort(vans.begin(), vans.end());

    balance -= vans[0].getCost();
    used.push_back(vans[0]);
    while (!parcels.empty() && !vans.empty()) {
        if (!checkVan(vans[0], parcels[0])) {
            for (auto it = parcels.begin(); it != parcels.end(); it++) {
                if (checkVan(vans[0], *it)) it = parcels.begin();
            }
            vans.erase(vans.begin());
            used.push_back(vans[0]);
            balance -= vans[0].getCost();
        }
    }
    checkBalance();
}

bool Scenario2::checkVan(Van& van, Parcel& parcel) {
    if (van.checkVol(parcel.getVol()) && van.checkWeight(parcel.getWeight())) {
        delivered.insert(parcel);
        van.occupySpace(parcel);
        balance += parcel.getCost();
        parcels.erase(parcels.begin());
        return true;
    }
    return false;
}

void Scenario2::checkBalance() {

    if (balance >= 0) return;

    vans.clear();

    for (const auto& x : used) vans.push_back(x);
    sort(vans.begin(), vans.end(), [] (const Van& v1, const Van& v2) {
        return v1.getProfit() < v2.getProfit();
    });

    while (balance < 0 && !vans.empty()) {
        balance -= vans[0].getProfit();
        vans.erase(vans.begin());
    }
    if (balance < 0 ) {
        used.clear();
        balance = 0;
    }
}

void Scenario2::show() const {
    cout << "The profit the company made was: " << balance << "€" << endl;
}