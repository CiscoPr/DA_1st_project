#pragma once

#include <string>
#include <vector>
#include <list>
class Scenario3{
protected:
    std::list<int> possible_timers;
    std::list<std::list<int>> possible_combinations;
public:
    Scenario3();
    void setTimers(std::list<int> timers);
    void setCombinations(std::list<std::list<int>> combinations);
    std::list<int> getDeliveries();
    std::list<std::list<int>> possibleCombinations();
    int test();
};