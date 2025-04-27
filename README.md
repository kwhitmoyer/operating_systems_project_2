## About 
This is an implementation of the Banker's Algorithm in C++. The Banker's Algorithm is an algorithm that helps systems to avoid deadlock by testing for safety before allocating resource to a given process. This safety check consists of simulating allocating those resources to a given process, and then checking that a order of resource allocation exists where all pending resources can be run. 

This assignment was completed for CS 33211: Operating Systems to furfill the requirements of Project 2. 

## Running The Program
This program can be run by the following command inside the main directory: 

`g++ bankers.cpp -o banker`

`./banker`       

## Example Output

### Example output when the system is in a safe state
![Output Example](.images/stafestate.png)

In this example output, the system is safe as a finite sequence of processes exists were each process has the nessuary requirements to finish running. 

### Example output when the system is in an unsafe state 
![Output Example](.images/unsafestate.png)

In this example output, the matrix containing available resourceshas been intitalized so that there are zero A, B, or C type resources available. Since there are zero resources to be allocated. As a result, the system is in an unsafe state as no processes can be executed. 

A system can also be in an unsafe safe when the number of available resources is non-zero. In this case, this simply means that running a given process will result in not having enough resources to run one of the remaining processes, regardless of sequence. 

## Initial State and Data Structure Representation

For this assignment, a concrete system state was given, represented in this image below:

![Concrete System State](.images/initialsystemstate.png)
