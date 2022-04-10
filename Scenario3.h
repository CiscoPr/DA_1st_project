#pragma once

#include <string>
#include <vector>
#include <list>
class Scenario3{
    int duration;
public:
    Scenario3();
    std::list<std::pair<int, int>> getDeliveries();
    int getTime();
    int meanTime();
};