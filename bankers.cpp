#include "header.hpp"
#include "helper.hpp"


int main(){
    std::cout << "Begin banker's algorithm safety check." << std::endl; 

    std::ifstream initialSystemState("inputdata.txt");
    if(!initialSystemState) {
        std::cout << "Can't open file" << std::endl; 
    }

    //Read in available resources
    for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
        initialSystemState >> resourcesAvailable[resourceType];
    }

    //read in max resources per process 
    for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
        for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
            initialSystemState >> maxResources[processNumber][resourceType];
        }
    }

    //read in allocated resources per process 
    for(int processNumber = 0; processNumber < NUM_OF_PROCESSES; ++processNumber){
        for(int resourceType = 0; resourceType < NUM_OF_RESOURCES; ++resourceType){
            initialSystemState >> allocatedResources[processNumber][resourceType];
        }
    }


    std::cout << "----------------------- [LOG]: Calculating Resources -----------------------" << std::endl << std::endl; 
    calculateNeededResources(neededResources, maxResources, allocatedResources);
    printNeededResources(neededResources); 

    std::cout << "----------------------- [LOG]: Beginning Safety Check ----------------------" << std::endl << std::endl; 
    bool safetyCheckResult = safetyAlgorithm(resourcesAvailable, neededResources); 
    std::cout << "----------------------- [LOG]: Finished Safety Check ----------------------" << std::endl << std::endl; 

    if (safetyCheckResult){
        std::cout << "----------------------- [DECISION]: System is in a safe state! ----------------------" << std::endl << std::endl; 
    } else {
        std::cout << "----------------------- [DECISION]: System is in unsafe state!  ----------------------" << std::endl << std::endl; 
    }
}