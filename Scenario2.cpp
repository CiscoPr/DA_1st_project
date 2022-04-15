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
            vans.erase(vans.begin());
        }
    }
    for (auto x : used) {
        for (auto it = parcels.begin(); it != parcels.end(); it++) {
            if (checkVan(vans[0], *it)) it = parcels.begin();
        }
    }
    checkBalance();
}

void Scenario2::checkBalance() {
    vans.clear();

    if (balance >= 0) return;

    for (const auto& x : used) vans.push_back(x);
    sort(vans.begin(), vans.end(), [] (const Van& v1, const Van& v2) {
        return v1.getProfit() < v2.getProfit();
    });

    while (balance < 0) {
        while (!vans[0].getOccupied().empty()) {
            balance -= vans[0].getOccupied().top().getCost();
            vans[0].getOccupied().pop();
        }
        balance += vans[0].getCost();
        vans.erase(vans.begin());
    }
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

void Scenario2::show() const {
    cout << "The profit the company made was: " << balance << "€" << endl;
}
