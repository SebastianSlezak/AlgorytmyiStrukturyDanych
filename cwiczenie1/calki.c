//ten plik trzeba edytować

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define lp 1000

double c_od, c_do;

double f3(double x) {
    return -1;
}

double f4(double x) {
    return 1;
}


double prostokaty(double( *f)(double)) {
    double krok, p, suma = 0;
    krok = (c_do - c_od) / lp;
    for (p = c_od; p < c_do; p += krok)
        suma += (*f)(p) * krok;
    return suma;
}

double trapezy(double (*f)(double)) {
    //liczba trapezów podziałowych
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

