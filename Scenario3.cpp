#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <sstream>




Scenario3::Scenario3(){}


/* this function gets all the possible expresso deliveries
 * aka, all the deliveries with less then 480 minutes (8h) of duration
 * in the form of a list
 * */

std::list<std::pair<int, int>> Scenario3::getDeliveries() {
     std::list<std::pair<int, int>> deliveries_list;
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
             deliveries_list.push_back(std::make_pair(number_of_deliveries, stoi(duracao)));
         }
     }

     std::cout << "There are " << number_of_deliveries << " of possible expresso delieveries in total!";
     return deliveries_list;
}

