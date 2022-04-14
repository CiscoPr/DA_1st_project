#include "Scenario3.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>


Scenario3::Scenario3(){}

/* Merge-Sort (divide and conquer)
 * */
void Scenario3::merge(int array[], int p, int q, int r) {
    int subArrayOne = q - p +1;
    int subArrayTwo = r-q;
    int left[subArrayOne], right[subArrayTwo];
    for(int i = 0; i <subArrayOne; i++)
        left[i] = array[p + i];
    for(int j = 0; j <subArrayTwo ; j++)
        right[j]= array[q+1+j];

    int i = 0, j = 0, k=p;
    while(i<subArrayOne && j < subArrayTwo) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < subArrayOne) {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < subArrayTwo){
        array[k] = right[j];
        j++;
        k++;
    }
}
void Scenario3::merge_sort(int array[], int p, int r) {
    if(p < r){
        int q = (p+r) / 2;
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q, r);
    }
}







/* this function gets the solution by creating a
 * list of all the deliveries with less than 8h of delivery time,
 * transforms it into an array, applies merge_sort to it
 * and
 * Algorithm: greedy implementation and devide and conquer
 * */
float Scenario3::getMeanTime() {

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
    int deliveries_array[deliveries_list.size()];
    int i =0;
    for(int const &it: deliveries_list)
        deliveries_array[i++] = it;


    int size = sizeof(deliveries_array) / sizeof(deliveries_array[0]);

    merge_sort(deliveries_array, 0, size -1);

    float total = 0;
    int counter = 0;
    for(auto it: deliveries_array){
        if(total + it <= max_time){
            total += it;
            counter ++;
            std::cout << it << " ";
        }
        else
            break;
    }
    float mean_time = total/counter;
    std::cout << "the total time spent by the express delivery truck is " << total << " seconds, which is about " << total / 60 << " minutes, or " << total / 60 / 60 << " hours\nThe mean time is about " << mean_time << " seconds or " << mean_time/60 << " minutes." ;

    return mean_time;
}
