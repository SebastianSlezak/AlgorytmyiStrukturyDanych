#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define lp 1000

double c_od, c_do;

double f3(double x) {
    return pow((x-2),3);
}

double f4(double x) {
    return pow((x-M_PI),3);
}


double prostokaty(double( *f)(double)) {
//    const int N = 1000;
    double s = 0;
    double dx = (c_do - c_od) / lp;

    for (int i = 1; i <= lp; i++) {
        s += (*f)(c_od + i * dx);
    }

    s *= dx;

    return s;
}

double trapezy(double (*f)(double)) {
//    const int N = 1000;
    double s = 0;
    double dx = (c_do - c_od) / lp;

    for (int i = 1; i < lp; i++){
        s += f(c_od + i * dx);
    }

    s = (s + (*f)(c_od) + (*f)(c_do) / 2) * dx;

    return s;
}

double mc(double(*f)(double)) {
//    const int N = 1000;
    double s = 0;
    double dx = c_do - c_od;

    for (int i = 1; i <= lp; i++) {
        s += (*f)(c_od + ((double)rand()/(double)(RAND_MAX + 1)*dx));
    }

    s = dx * s / lp;

    return s;
}

