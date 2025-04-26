#include "header.hpp"
#include "helper.hpp"


int main(){
    std::cout << "Begin banker's algorithm safety check." << std::endl; 

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