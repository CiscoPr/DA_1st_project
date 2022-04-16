#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * Class of scenario 3
 */
class Scenario3 {

protected:
    std::list<int> possible_timers;
    std::list<std::list<float>> possible_combinations_list;
    std::multimap<int,int> mapping_deliveries;
    int timer_array[];

public:
    /**
     * Constructor
     */
    Scenario3();
    /**
     * Merge-Sort (divide and conquer)
     * @param array
     * @param p
     * @param q
     * @param r
 */
    void merge(int array[], int p, int q, int r);
    /**
     *
     * @param array
     * @param p
     * @param r
     */
    void merge_sort(int array[], int p, int r);
    /**
     * Creates a list of all the deliveries with less than 8h of delivery time,
     * transforms it into an array and applies merge_sort to it (greedy implementation and divide and conquer)
     * @return
     */
    float getMeanTime();

};