#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <sstream>



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
void Scenario3::setCombinations(std::list<std::list<int>> combinations) {
    possible_combinations = combinations;
}


/* this function gets all the possible expresso deliveries
 * aka, all the deliveries with less then 480 minutes (8h) of duration
 * in the form of a list
 * */
std::list<int> Scenario3::getDeliveries() {
     std::list<int> deliveries_list;
     std::ifstream deliveries;
     int number_of_deliveries = 0;                                                                      //number of lines from the dataset
     std::string first_line, data;                              //encomendas.txt - 1
     deliveries.open("../res/encomendas.txt");                                                  //open the file
     getline(deliveries, first_line);
     while(!deliveries.eof()) {
         number_of_deliveries++;
         std::string volume;
         getline(deliveries, volume, ' ');
         std::string peso;
         getline(deliveries, peso, ' ');
         std::string recompensa;
         getline(deliveries, recompensa, ' ');
         std::string duracao;
         getline(deliveries, duracao);
         if (std::stoi(duracao) <= 480){
             std::cout << "The " << number_of_deliveries << "th package has " << duracao << " minutes of duration\n";
             deliveries_list.push_back(stoi(duracao));
         }
     }

     std::cout << "There are " << number_of_deliveries << " of possible expresso delieveries in total!";

     setTimers(deliveries_list);
     return deliveries_list;
}



/* this function will get all the possible
 * combinations of deliveries the truck
 * can do
 * */
std::list<std::list<int>> Scenario3::possibleCombinations(){
    std::list<int> combination;
    std::list<std::list<int>> combination_of_combinations;
    std::list<int>::iterator i,j;
    int sum_time = 0, mean_time, minimum_time, max_time = 480;




}