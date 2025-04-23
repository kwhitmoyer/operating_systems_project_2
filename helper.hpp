#include "header.hpp"


void initalizeNeed(int neededResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES]){
    for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
        for(int resourceNumber = 0; resourceNumber < NUM_OF_RESOURCES; ++resourceNumber){
            neededResources[processNumber][resourceNumber] = 0; 
        }
    }
}

void calculateNeededResources(int neededResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES], int maxResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES], int allocatedResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES]){
    //Set neededResources matrix to zero
    initalizeNeed(neededResources); 

    //Calculate actual neededResources matrix 
    for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
        for(int resourceNumber = 0; resourceNumber < NUM_OF_RESOURCES; ++resourceNumber){
            neededResources[processNumber][resourceNumber] = maxResources[processNumber][resourceNumber] - allocatedResources[processNumber][resourceNumber]; 
        }
    }
}


void printNeededResources(int neededResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES]){
    std::cout << "Needed Resources Matrix: " << std::endl; 
    for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
        std::cout << "Needed resources for Process " << processNumber << ": "; 
        for(int resourceNumber = 0; resourceNumber < NUM_OF_RESOURCES; ++resourceNumber){
            std::cout << neededResources[processNumber][resourceNumber] << ", "; 
        }
        std::cout << std::endl;
    }
}