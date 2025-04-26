#include "header.hpp"


bool safetyAlgorithm(int resourcesAvailable[NUM_OF_RESOURCES], int resourceNeeded[NUM_OF_PROCESSES][NUM_OF_RESOURCES]){
    int work[NUM_OF_RESOURCES] = {0, 0, 0};
    for(int resourceNumber = 0; resourceNumber < NUM_OF_RESOURCES; ++resourceNumber){
        work[resourceNumber] = resourcesAvailable[resourceNumber];
    }

    bool finish[NUM_OF_PROCESSES] = {false, false, false, false, false}; 

    int processesFinished = 0;
    std::string safeProcessSequence = "";
    
    while(processesFinished < NUM_OF_PROCESSES){
        bool foundProcess = false; 
        for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
            if (!finish[processNumber]){
                bool allResourcesAvailable = true; 
                for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
                    if(resourceNeeded[processNumber][resourceType] > work[resourceType]){
                        allResourcesAvailable = false; 
                        std::cout << "Unsafe sequence found for process: " << processNumber << ". Not enough of resource: " << resourceType << std::endl;  
                        break; 
                    } else {
                        std::cout << "Enough of resource type: " << resourceType <<  " has been found for process: " << processNumber << std::endl;
                    } 
                }
                if(allResourcesAvailable) {
                    std::cout << "There were enough resources to run process: " << processNumber << std::endl; 
                    for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
                        work[resourceType] += allocatedResources[processNumber][resourceType];
                    }

                    finish[processNumber] = true; 
                    foundProcess = true; 
                    processesFinished++; 
                    safeProcessSequence += "P" + std::to_string(processNumber) + "->"; 
                }
            }
        }
        if(!foundProcess){ //if no process can run that would keep the system in a safe state. 
            std::cout << "The system is not in a safe state." << std::endl; 
            return false; 
        }
    }
    std::cout << "System is in a safe state." << std::endl;
    std::cout << "The safe process sequence is " << safeProcessSequence << std::endl;
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