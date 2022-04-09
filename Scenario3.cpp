#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Scenario3::Scenario3(){}


int Scenario3::getDeliveries() {
     std::ifstream deliveries;
     int number_of_deliveries;                                                                      //number of lines from the dataset
     std::string first_line, data;                              //encomendas.txt - 1
     deliveries.open("../res/encomendas.txt");                                                  //open the file
     getline(deliveries, first_line);
     while(getline(deliveries, data)){
         std::stringstream volume;
         std::stringstream peso;
         std::stringstream recompensa;
         std::stringstream duracao;
         

     }
     std::cout << "There are " << number_of_deliveries << " of possible expresso delieveries in total!";
     return number_of_deliveries;
}