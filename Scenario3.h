#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
class Scenario3{
protected:
    std::list<int> possible_timers;
    std::list<std::list<float>> possible_combinations_list;
    std::multimap<int,int> mapping_deliveries;
    int timer_array[];
public:
    Scenario3();
    void merge_sort(int array[], int p, int r);
    void merge(int array[], int p, int q, int r);
    float getMeanTime();

};