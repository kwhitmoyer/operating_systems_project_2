#ifndef HEADER_CPP
#define HEADER_CPP

#include <iostream>

//Data Structures for the Banker's Algorithm
const int NUM_OF_PROCESSES = 5;
const int NUM_OF_RESOURCES = 3;

// P0, P1, P2, P3, P4, P
int processes[] = {0, 1, 2, 3, 4};

// A = 3, B = 3, C = 2
int resourcesAvailable[NUM_OF_RESOURCES] = {3, 3, 2};

int allocatedResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES] = {{0, 1, 0},
                                                              {2, 0, 0},
                                                              {3, 0, 2},
                                                              {2, 1, 1},
                                                              {0, 0, 2}};

int maxResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES] = {{7, 5, 3},
                                                        {3, 2, 2},
                                                        {9, 0, 2},
                                                        {2, 2, 2},
                                                        {4, 3, 3}};

int neededResources[NUM_OF_PROCESSES][NUM_OF_RESOURCES]; 


#endif 