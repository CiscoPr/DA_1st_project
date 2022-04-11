#pragma once

#include <string>
#include <vector>
#include <list>
class Scenario3{
protected:
    std::list<int> possible_timers;
public:
    Scenario3();
    void setTimers(std::list<int> timers);
    std::list<int> getDeliveries();
    std::vector<std::pair<int, int>> possibleCombination();
    int test();
};