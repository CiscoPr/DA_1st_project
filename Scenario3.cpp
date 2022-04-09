#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Scenario3::Scenario3(){}


int Scenario3::getDeliveries() {
     std::ifstream deliveries;
     int number_of_deliveries = 0;                                                                      //number of lines from the dataset
     std::string first_line, data;                              //encomendas.txt - 1
     deliveries.open("../res/encomendas.txt");                                                  //open the file
     getline(deliveries, first_line);
     while(getline(deliveries, data)){
         number_of_deliveries++;
         std::string volume;
         getline(deliveries, volume, ' ');
         std::string peso;
         getline(deliveries, peso, ' ');
         std::string recompensa;
         getline(deliveries, recompensa, ' ');
         std::string duracao;
         getline(deliveries, duracao);
         if(std::stoi(duracao) <= 480)
            std::cout << "The " << number_of_deliveries << "th package has " << duracao << " minutes of duration\n";
     }

     std::cout << "There are " << number_of_deliveries << " of possible expresso delieveries in total!";
     return number_of_deliveries;
}