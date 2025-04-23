#include "header.hpp"
#include "helper.hpp"


int main(){
    std::cout << "Begin banker's algorithm safety check." << std::endl; 

    calculateNeededResources(neededResources, maxResources, allocatedResources);
    printNeededResources(neededResources); 

    safetyAlgorithm(resourcesAvailable, neededResources); 

}