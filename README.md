# Turbo Timer
    Turbo Timer is a program that tests the execution time of an application.
    
#### Requirements

* C compiler
* A Linux Operating System

##### Using Turbo Timer:
    General Usage:
    $ ./turbotimer [Application] [Number of Cycles] [Wait Time in Miliseconds]
    
    Application:
        For the application field enter the command to execute the application from terminal.
        Such as if you wanted to run bash you would type /usr/bin/bash in the application field as such ...
        
        $ ./turbotimer /usr/bin/bash
        
    Number of Cycles:
        This is the amount of times you want the application to be executed.
        If you wanted to run bash 2 times this is how you would do it ...
        
        $ ./turbotimer /usr/bin/bash 2
        
        By default if no argument is given for the number of cycles it is defaulted to 1.
        
    Wait Time:
        The wait time is tje time delay inbetween execution if the cycle is more than 1.
        The wait time is in miliseconds and by default is set to 50 if no value is specified.
        
        For Example if you wanted to run 3 instances of bash with 100 miliseconds inbetween each execution ...
        
        $ ./turbotimer /usr/bin/bash 3 100
