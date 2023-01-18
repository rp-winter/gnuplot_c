# gnuplot_c
A C header file (gnuplot.h) to easily plot data using gnuplot. Example code displaying all the functionality can be found in "example.c".  
Created By: Ritik Pal, rp.ritikpalavatar@gmail.com  
Created On: 17 Jan 2023.  

# Requirements
Gnuplot must be installed on your machine, and the application directory must be included in PATH environment variables, so that you can call gnuplot through the terminal.

# Getting Started
To be able to plot graph using the header file, you can:
1. Either copy the gnuplot.h to the system header files directory.  
2. Or copy the gnuplot.h inside the folder containing the codes you would like to use the header file with.  
After that, in your code you can include the header file using  
```
#include <gnuplot.h>
```
or
```
#include "gnuplot.h"
```
This will allow you to use the functions and objects defined in the header file.  

# Plotting Graph
To plot a graph, you will need to create a pointer to a new gnuplot structure which stores the different options (like linewidth, title etc) for plotting the graph.  
After creating the structure initialize the options of the new structure using init() function. init() functions needs arguments (1) pointer to the structure you are initializing, (2) type of plot ("plot" for 2d plot, and "splot" for 3d plot).  
```
struct gnuplot *a;
init(a, "plot);
```
After the gnuplot structure has been initialized, you can use several other functions and options to plot graph. After specifying all the plots and its options you can display the graph at the end of your code.  
To display the graph, display() function is used. The use of display function is explained below.

## Plotting graph using array
If you have two arrays x[] and y[] of the same length. You can plot the points using the command arrPlot2d(). This function takes the argument (1) pointer to the gnuplot structure, (2) size of array, (3) array x[] and (4) array y[].
```
double arrx[] = {1, 2, 3, 4};
double arry[] = {1, 4, 9, 16};
arrPlot2d(a, 4, arrx, arry);
```

## Plotting function of the form y = f(x).
We can plot function of the form y = f(x) using yplot(). This function takes the arguments (1) pointer to the gnuplot structure, (2) functional form inside quotation mark.
```
yplot(a, sin(x));
```
## Plotting graph from a data file.
We can plot data stored in data file using fplot(). This function takes the arguments (1) pointer to the gnuplot structure, (2) data file name, (3) column position of the x data in the data file, and (4) column position of the y data.  
For example, if the data file named "data.txt" is as shown:
```
0 0 1
1 0.84 0.54
2 0.9 -0.4
3 0.14 -0.98
4 -0.75 -0.65
5 -0.95 0.28
```
We can plot graph with x data with column 1 (1, 2, 3, 4, 5) and y data with column 2 (0, 0.84, 0.9, 0.14, -0.75, -0.95) using the command,
```
fplot(a, "data.txt", 1, 2);
```
## Displaying the Graph
Finally after specifying all the plots you can display the graph using display() function. This function takes the pointer to the gnuplot structure as its arguments.
```
display(a);
```

# Changing the style and other options

1) Legend Title:
To change the legend title of a graph.
```
strcpy(a->t, "title of the graph");
```
Maximum character in the title = 20.

2) Style of graph: 
To change the type of graph (line, linepoints, point):
```
strcpy(a->w, "lp"); //linepoints
strcpy(a->w, "p"); //points
strcpy(a->w, "l"); //line
```
Details of different style of graph can be obtained in Gnuplot documentation.  

3) Line width: 
Line width of a line graph can be set using,
```
a->lw = 2;
```

4) Dash Type: 
To plot dashed line, or dotted lines.
```
a->dt = 3;
```
The type of lines corresponding to different values can be found in gnuplot documentation.

# PS
Currently only these functionalities has been added. I plan to add more functionalities if time permits.
