#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define lp 1000

double c_od, c_do;

double f3(double x) {
    return exp(-x * x);
}

double f4(double x) {
    return sin(x) / x;
}


double prostokaty(double( *f)(double)) {
    const int N = 1000;
    double s = 0;
    double dx = (c_do - c_od) / N;

    for (int i = 1; i <= N; i++) {
        s += (*f)(c_od + i * dx);
    }

    s *= dx;

    return s;
}

double trapezy(double (*f)(double)) {
    const int N = 1000;
    double s = 0;
    double dx = (c_do - c_od) / N;

    for (int i = 1; i < N; i++){
        s += f(c_od + i * dx);
    }

    s = (s + (*f)(c_od) + (*f)(c_do) / 2) * dx;

    return s;
}

double mc(double(*f)(double)) {
    const int N = 10000;
    double s = 0;
    double dx = c_do - c_od;

    for (int i = 1; i <= N; i++) {
        s += (*f)(c_od + ((double)rand()/(double)(RAND_MAX + 1)*dx));
    }

    s = dx * s / N;

    return s;
}

