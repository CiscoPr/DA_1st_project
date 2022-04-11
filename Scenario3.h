#pragma once

#include <string>
#include <vector>
#include <list>
class Scenario3{
    int duration;
public:
    Scenario3();
    std::list<int> getDeliveries();
    std::vector<std::pair<int, int>> possibleCombination();
};