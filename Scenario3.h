#pragma once

#include <string>
#include <vector>
#include <list>
class Scenario3{
protected:
    std::list<int> possible_timers;
    std::list<std::list<float>> possible_combinations_list;
public:
    Scenario3();
    void setTimers(std::list<int> timers);
    void setCombinations(std::list<std::list<float>> combinations);
    std::list<int> getDeliveries();
    std::list<std::list<float>> possibleCombinations();
    int test();

    std::list<float> result();
};