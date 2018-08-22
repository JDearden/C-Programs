/******************************************************
* Name: time.c                                        *
* Purpose: Calculate the time based off an int        *
* Author: Justin Dearden		                      *
* Date: June 3, 2018				                  *
*******************************************************/

#include <stdio.h>

int main() {

    int time;
    int hours, minutes;
    int true;

    while (true) {
        //Collects the value from the user and stores it in the "time" int
        printf("Enter a non-negative integer number: ");
        scanf("%d", &time);

        //If the user enters 0 the program will terminate
        if (time == 0) {
            printf("END");
            return 0;
        }
        //If the user enters a negative number the program will terminate
        if (time < 0) {
            printf("Invalid input!\n");
            continue;
        }

        //Prints the starting time for each use
        printf("Start time: 12:00pm\n");

        //Calculates the hours and minutes from the value entered
        hours = (time / 60 + 12) % 24;

        minutes = time % 60;

        //If else series to print out different results based on the time calculation
        if (hours == 0) {
            //Change the single minute location if the value is under 10
            if (minutes < 10)
                printf("End time: 12:0%dam\n", minutes);

                //Changes the double minute location if the value is above 10
            else {
                printf("End time: 12:%dam\n", minutes);
            }
            //Changes the hour if its less than 12 and first minute location if they are under 10
        } else if (hours < 12) {
            if (minutes < 12) {
                printf("End time: %d:0%dam\n", hours, minutes);
            } else {
                //Changes the hour and both minute locations if they are above 10
                printf("End time: %d:%dam\n", hours, minutes);
            }
            //Changes the hour if it equals 12 and the first minute location
        } else if (hours == 12) {
            if (minutes < 10) {
                printf("End time: %d:0%dpm\n", hours, minutes);
                //Changes the hour and both minute locations
            } else {
                printf("End time: %d:%dpm\n", hours, minutes);
            }
            //Changes the hour if its greater or equal to 12 and the first minute location
        } else if (hours >= 12) {
            if (minutes < 10) {
                printf("End time: %d:0%dpm\n", (hours - 12), minutes);
            } else {
                //Changes the hour and both minute locations
                printf("End time: %d:%dpm\n", (hours - 12), minutes);
            }
        }
    }

    return 0;
}