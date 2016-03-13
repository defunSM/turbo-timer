#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdio>
#include <ctime>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>

#define Display(x) std::cout << x << std::end1

double sum = 0.0;
int average;

int atoi(char *p)  // Converts string to integer.
{
    int num = 0;

    for(int i=0;i<strlen(p);i++)  // Loops through each element in string and adds to num.
    {

        if(p[i]=='1') { num+= 1*pow(10, i) ; }
        if(p[i]=='2') { num+= 2*pow(10, i) ; }
        if(p[i]=='3') { num+= 3*pow(10, i) ; }
        if(p[i]=='4') { num+= 4*pow(10, i) ; }
        if(p[i]=='5') { num+= 5*pow(10, i) ; }
        if(p[i]=='6') { num+= 6*pow(10, i) ; }
        if(p[i]=='7') { num+= 7*pow(10, i) ; }
        if(p[i]=='8') { num+= 8*pow(10, i) ; }
        if(p[i]=='9') { num+= 9*pow(10, i) ; }

    }

    return num;
}

void wFile(char text[]) // Writes to the file
{
    std::fstream fs;
    fs.open("test1010.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    char tex[256];
    strcpy(tex, text);
    fs << tex;

    fs.close();
}

void test(char application[], int waitTime, int i) // Function that tests the application execution speed.
{
    std::clock_t start;  // variable for the time is initalized.
    double duration;
    start = std::clock(); // The time is set for the variable in this line.

    /*** APPLICATION TESTING AREA ***/

    system(application);

    /*** APPLICATION TESTING AREA ***/

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;  // Returns a new time substracting it with the original time set in start
    sum+= duration;  // Adds to the sum
    std::cout<<"\tExecution Time "<< i+1 << ": " << duration << " (s)" << std::endl;

    usleep(waitTime); // Adds a wait time if the user specifies one.
}

int main(int argc, char *argv[]) // Main function allows for additional arguments to control various parts of the test function.
{
    int cycles, waitTime; // Cycle is the number of times that the application is executed. waitTime is the delay between execution.

    if(!argv[1]){ printf("PROPER USAGE: ./testshell (application) (numberofcycles) (waittime in miliseconds)"); return 0; }
    if(!argv[2]){ cycles=1; } else { cycles=atoi(argv[2]); }  // Default is 1.
    if(!argv[3]){ waitTime=0; } else { waitTime=atoi(argv[3]); } // Default is 0.

    std::cout << "\n------------------- TESTING: [" << argv[1] << "] -------------------\n" << std::endl;

    for(int i=0;i<cycles;i++){
        test(argv[1], waitTime, i);
    }
                                    // Displays the processed data.
    std::cout << "\n\t\tTotal Execution Time for " << cycles << ": " << sum << " (s)" << std::endl;
    std::cout << "\t\tAverage Execution Time: " << sum/cycles << " (s)\n" << std::endl;
    std::cout << "\nInitial Conditions:\n\tApplication: " << argv[1] << "\n\tCycles: " << cycles << std::endl;

    system("rm test1010.txt");

    return 1;
}
