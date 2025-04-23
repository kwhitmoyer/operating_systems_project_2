#include "header.hpp"


bool safetyAlgorithm(int resourcesAvailable[NUM_OF_RESOURCES], int resourceNeeded[NUM_OF_PROCESSES][NUM_OF_RESOURCES]){
    int work[NUM_OF_RESOURCES] = {0, 0, 0};
    for(int resourceNumber = 0; resourceNumber < NUM_OF_RESOURCES; ++resourceNumber){
        work[resourceNumber] = resourcesAvailable[resourceNumber];
    }

    bool finish[NUM_OF_PROCESSES] = {false, false, false, false, false}; 

    int processesFinished = 0;

    while(processesFinished < NUM_OF_PROCESSES){
        bool foundProcess = false; 
        for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
            if (!finish[processNumber]){
                bool allResourcesAvailable = false; 
                for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
                    if(resourceNeeded[processNumber][resourceType] > work[resourceType]){
                        allResourcesAvailable = false; 
                        std::cout << "Unsafe sequence found for process: " << processNumber << ". Not enough of resource: " << resourceType << std::endl;  
                        break; 
                    }
                    allResourcesAvailable = true; 
                    std::cout << "Enough of resource type: " << resourceType <<  " has been found for process: " << processNumber << std::endl;
                }

            }
            ++processesFinished; //temp 
        }
    }
    return true; 
}


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