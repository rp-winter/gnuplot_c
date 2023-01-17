#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <string.h>

struct gnuplot
{
    char title[20];
    char w[3];
    char type[7];
    int keepSet;
    int lw;
    int dt;
    int plotting;
    int no_arrPlot;
    FILE *cmd;
};



void init(struct gnuplot *a, char type[]) {
    a->title[0] = '\0';
    strcpy(a->w, "lp");
    strcpy(a->type, "plot");
    a->keepSet = 0;
    a->lw = 2;
    a->dt = 3;
    a->plotting = 0;
    a->no_arrPlot = 0;
    a->cmd = fopen("gnuplot_cmd.gp", "w");
}

void fplot(struct gnuplot *a, char filename[], int x, int y) {
    if(a->plotting != 1) {
        fprintf(a->cmd, "%s ", a->type);
    }
    char title[30];
    if(a->title[0] == '\0') {
        strcpy(title, filename);
    }
    else {
        strcpy(title, a->title);
    }
    fprintf(a->cmd, "\"%s\" using %d:%d t '%s' w %s lw %d dt %d,", filename, x, y, title, a->w, a->lw, a->dt);
    if(a->keepSet != 1) {
        strcpy(a->title, "");
        strcpy(a->w, "lp");
        a->lw = 2;
        a->dt = 1;
    }
    a->plotting = 1;
}

void yplot(struct gnuplot *a, char equation[50]) {
    fprintf(a->cmd, "%s w %s lw %d dt %d,", equation, a->w, a->lw, a->dt);
}

void display(struct gnuplot *a) {
    FILE *fp;
    fclose(a->cmd);
    fp = popen("gnuplot", "w");
    fprintf(fp, "load \"gnuplot_cmd.gp\"\n");
    fflush(fp);
    printf("Press Ctrl+C to exit!");
    getchar();
    pclose(fp);
}

void arrPlot2d(struct gnuplot *a, int n, double x[n], double y[n]) {
    int i;
    FILE *tf;
    char fn[20];
    sprintf(fn, "arrayPoints%d.txt", a->no_arrPlot);
    tf = fopen(fn, "w");
    for (i=0; i<n; i++) {
        fprintf(tf, "%lf %lf\n", x[i], y[i]);
    }
    fclose(tf);
    fplot(a, fn, 1, 2);
}
#endif