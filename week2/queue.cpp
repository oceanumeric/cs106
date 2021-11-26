#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include "random.h"


/*
This program simulates a checkout line.
Customers arrive at the checkout stand and get in line. Those customers wait
in the line until the cashier is free, at which point they are served and 
occupy the cashier for some period 
In each unit of time, up to the constant SIMULATION_TIME, the following
operations are performed: 

1. determine whether a new customer has arrived randomly 
2. if the cashier is busy, wait and enqueue 
3. if the cashier is free serve 

We want to find 
    the number of customers served 
    the averate time spent in line
    the average number of people in line 
*/

// a customer arrived once every 20 seconds
const double ARRIVAL_PROBABILITY = 0.1; 
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15; 
const int SIMULATION_TIME = 2000;  // number of simulation


void runSimulation(int & n_served, int & total_wait, int & total_length);
void printReport(int n_served, int total_wait, int total_length);


int main() {
    int n_served;
    int total_wait;
    int total_length;
    runSimulation(n_served, total_wait, total_length);
    printReport(n_served, total_wait, total_length); 
    return 0; 
}


void runSimulation(int & n_served, int & total_wait, int & total_length) {
    std::queue<int> market_queue; 
    int waiting_time = 0; 
    n_served = 0; 
    total_wait = 0; 
    total_length = 0; 

    for (int t = 0; t < SIMULATION_TIME; t++) {
        if(randomChance(ARRIVAL_PROBABILITY)) {
            market_queue.push(t); 
        }
        if (waiting_time > 0) {
            waiting_time --; 
        } else if (!market_queue.empty()) {
            total_wait += t - market_queue.front();
            market_queue.pop();
            n_served ++;
            waiting_time = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }

        total_length += market_queue.size();
    }

}


void printReport(int n_served, int total_wait, int total_length) {
    std::cout << "Simulation results given the following constants:" << std::endl;
    std::cout << std::fixed << std::setprecision(2); 
    std::cout << " SIMULATION_TIME:   " << std::setw(4)
              << SIMULATION_TIME << std::endl; 
    std::cout << " ARRIVAL_PROBABILITY :   " << std::setw(7)
              << ARRIVAL_PROBABILITY << std::endl; 
    std::cout << " MIN_SERVICE_TIME:   " << std::setw(4)
              << MIN_SERVICE_TIME << std::endl; 
    std::cout << " MAX_SERVICE_TIME:   " << std::setw(4)
              << MAX_SERVICE_TIME << std::endl;  
    std::cout << std::endl;
    std::cout << "Customers served:    " << std::setw(4) << n_served << std::endl;
    std::cout << "Average waiting time:  " << std::setw(7)
              << double(total_wait) / n_served << std::endl; 
    std::cout << "Average queue length:  " << std::setw(7)
              << double(total_length)/SIMULATION_TIME << std::endl; 
}