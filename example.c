#include <stdio.h>
#include <string.h>
#include "gnuplot.h"

int main() {
    struct gnuplot *a;
    init(a, "plot");
    fplot(a, "data.txt", 1, 2);
    strcpy(a->w, "l");
    a->lw = 10;
    a->dt = 3;
    fplot(a, "data.txt", 1, 3);
    double arrx[] = {1, 2, 3, 4};
    double arry[] = {1, 4, 9, 16};
    arrPlot2d(a, 4, arrx, arry);
    yplot(a, "sin(x)");
    display(a);
}