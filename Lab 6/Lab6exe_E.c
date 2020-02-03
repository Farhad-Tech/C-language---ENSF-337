/*
 *  File: lab6_exe_A.c
 *  ENSF 337 Fall 2018 - lab 6, Exercise E
 */
#include <stdio.h>
#include <stdlib.h>

// This is a simple C program that is supposed to create an array of type double,
// (dynamically on the heap), filling it with some arbitrary numbers and then
// using the array as needed. But the program doesn't do anything useful because of
// some flaws in the function main function and improper design of the function
// create_array.

double* create_array(double * x, unsigned long n);
void populate_array(double *array, int n);

int main(void) {
    printf("\nProgram started...\n");
    double *array = NULL;
    int n = 20;
    array = create_array(array, n);
    double *new = array;

    //IT became NULL
    if(array != NULL) {
        populate_array(array, n);

        // displays half of the values of the array
        for(int i = 0; i < n/2; i++){
            printf("%f\n", *array++);
        }

        // According to C standard, the program's behaviour, after the following
        // call to the function free is considered "Undefined" and needs to be fixed.
        free(new);
    }
    printf("Program terminated...\n");
    return 0;
}

// THE FOLLOWING FUNCTION IS NOT PROPERLY DESINGED AND NEEDS TO BE FIXED

double* create_array(double *x, unsigned long n) { //array is NULL HERE

    x = malloc(n * sizeof(double)); //array -> 20doubles
                                    //ARRAY IS NOT NULL ANYMORE
    if(x == NULL){
        printf("Sorry Memory Not Available. Program Terminated.\n");
        exit(1);
    }
    return x;
}

void populate_array(double *array, int n) { //if array is not NULL
    int i;
    for(i = 0; i < n; i++)
        array[i] = (i + 1) * 100;
}
