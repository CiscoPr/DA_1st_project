#include "Scenario2.h"

Scenario2::Scenario2(const vector<Van> &vans, const vector<Parcel> &parcels) : vans(vans), parcels(parcels) {
    balance = 0;
}

void Scenario2::start() {
    vector<Parcel> copy_p(parcels);
    vector<Van> copy_v(vans);

    delivered.clear();
    used.clear();

    sort(copy_p.begin(), copy_p.end(), [] (const Parcel& p1, const Parcel& p2) {
        return p1.getCost() > p2.getCost();
    });

    sort(copy_v.begin(), copy_v.end(), [] (const Van& v1, const Van& v2) {
        return v1.getMaxVol() + v1.getMaxWeight() / v1.getCost() > v2.getMaxVol() + v2.getMaxWeight() / v2.getCost();
    });

    auto v1 = copy_v.begin();
    auto p1 = copy_p.begin();

    while (p1 != copy_p.end()) {
        if (v1 == copy_v.end()) break;
        /*if (used.insert(*v1).second) balance -= v1->getCost();
        if (v1->checkVol(p1->getVol()) && v1->checkWeight(p1->getWeight())) {
            if (delivered.insert(*p1).second) {
                v1->occupySpace(*p1);
                balance += p1->getCost();
            }
            p1++;
        }
        else {
            bool tmp = false;
            while (!tmp) {
                for (auto it = p1; it != copy_p.end(); it++) {
                    if (v1->checkVol(it->getVol()) && v1->checkWeight(it->getWeight())) {
                        if (delivered.insert(*it).second) {
                            v1->occupySpace(*it);
                            balance += it->getCost();
                            tmp = true;
                        }
                    }
                }
                if (tmp) tmp = false;
            }
            v1++;
        }*/
    }
    checkBalance();
}

void Scenario2::checkBalance() {
    vector<Van> temp;

    if (balance >= 0) return;

    for (auto x : used) temp.push_back(x);
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

void Scenario2::show() {
    cout << balance << endl;
}