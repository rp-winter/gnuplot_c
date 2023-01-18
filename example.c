#include <stdio.h>
#include <string.h>
#include "gnuplot.h"

int main() {
    struct gnuplot *a; // Creating new structure
    init(a, "plot"); // Intializing the structure
    fplot(a, "data.txt", 1, 2); // Plotting the stored in file with column 1 as x axis and column 2 as y axis
    strcpy(a->w, "l"); // Changing the stype of the plot
    a->lw = 10; // Changing the line width of the plot
    a->dt = 3; // Changing the dash type of the plot
    fplot(a, "data.dat", 1, 3); // Plotting the stored in file with column 1 as x axis and column 2 as y axis
    strcpy(a->t, "y=x^2"); // Changing the title of the plot
    double arrx[] = {1, 2, 3, 4};
    double arry[] = {1, 4, 9, 16};
    arrPlot2d(a, 4, arrx, arry); // Plotting an array of length 4
    yplot(a, "sin(x)"); // Plotting the equation y = sin(x)
    display(a);
}