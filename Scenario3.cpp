#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>


Scenario3::Scenario3(){}

/*this function sets the protected list of
 * pointers as the result of the possible
 * timers, given by the second function
 * */
void Scenario3::setTimers(std::list<int> timers) {
    possible_timers = timers;
}


/*this function sets the protected list of lists
 * of all the possible combinations of
 * deliveries
 * */
void Scenario3::setCombinations(std::list<std::list<float>> combinations) {
    possible_combinations_list = combinations;
}


/* this function gets all the possible expresso deliveries
 * aka, all the deliveries with less then 480 minutes (8h) of duration
 * in the form of a list
 * */
std::list<int> Scenario3::getDeliveries() {
     std::list<int> deliveries_list;
     std::ifstream deliveries;
     int max_time = 480*60;
     int number_of_deliveries = 0;                                                                      //number of lines from the dataset
     std::string first_line, data;                              //encomendas.txt - 1
     deliveries.open("../res/encomendas.txt");                                                  //open the file
     getline(deliveries, first_line);
     while(!deliveries.eof()) {

         std::string volume;
         getline(deliveries, volume, ' ');
         std::string peso;
         getline(deliveries, peso, ' ');
         std::string recompensa;
         getline(deliveries, recompensa, ' ');
         std::string duracao;
         getline(deliveries, duracao);
         if (std::stoi(duracao) <= max_time){
             number_of_deliveries++;
             //std::cout << "The " << number_of_deliveries << "th package has " << duracao << " seconds of duration\n";
             deliveries_list.push_back(stoi(duracao));
         }
     }

     //std::cout << "There are " << number_of_deliveries << " of possible express deliveries in total!\n";

     setTimers(deliveries_list);
     return deliveries_list;
}



/* this function will get all the possible
 * combinations of deliveries the truck
 * can do
 * */
std::list<std::list<float>> Scenario3::possibleCombinations(){
    std::list<int> copy_of_timers = possible_timers;
    std::list<float> combination;
    std::list<std::list<float>> combination_of_combinations;
    std::list<int>::iterator i,j;
    int sum_time = 0, counter;
    int max_time = 480* 60;
    float mean_time;
    while(!copy_of_timers.empty()){
        counter = 1;
        combination.clear();
        int item1 = copy_of_timers.front();
        combination.push_back(item1);
        copy_of_timers.pop_front();
        sum_time += item1;
        for(auto it2: copy_of_timers){
            if(sum_time + it2 <= max_time){
                sum_time += it2;
                counter ++;
                combination.push_back(it2);
            }

        }
        mean_time = (float) sum_time/ (float) counter;
        combination.push_back(mean_time);
        sum_time =0;
        combination_of_combinations.push_back(combination);
    }
    for(auto it: combination_of_combinations){
        for(auto it2: it){
            //std::cout << it2 << " ";
        }
        //std::cout << "\n";

    }
    setCombinations(combination_of_combinations);
    return combination_of_combinations;
}


std::list<float> Scenario3::result(){

    std::list<float> final_result;
    float minimum_mean = INT_MAX;
    float maximum_size = 0;
    int timer = 0;
    for(auto it: possible_combinations_list){
        if(it.back() <= minimum_mean && it.size() >= maximum_size){
            minimum_mean = it.back();
            maximum_size = it.size();
            final_result = it;
        }
    }
    std::cout << "The best possible scenario here is if the express truck delivers: \n";
    int counter = 1;
    final_result.pop_back();
    for(auto it2: final_result){
        std::cout << "- The " << counter << "th deliver is the one with " << it2 << " seconds of duration\n";
        counter++;
        timer+=it2;
    }
    /*float minutes = ((float) timer / 60);
    float hours = minutes / 60;
     */
    std::cout << "The total minimum time is " << timer << " seconds, which correspond to " << (float)timer/60 <<" minutes or " << (float)timer/60/60 << " hours.\n";

    std::cout << "The mean time of this order is of " << minimum_mean << " seconds.\n";
    return final_result;

};