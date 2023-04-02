#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define lp 1000

double c_od, c_do;

double f3(double x) {
    return pow((x - 2), 3);
}

double f4(double x) {
    return pow((x - M_PI), 3);
}


double prostokaty(double( *f)(double)) {
    double s = 0;
    double dx = (c_do - c_od) / lp;

    for (int i = 1; i <= lp; i++) {
        s += (*f)(c_od + i * dx);
    }

    s *= dx;

    return s;
}

double trapezy(double (*f)(double)) {
    double s = 0;
    double dx = (c_do - c_od) / lp;

    for (int i = 1; i < lp; i++) {
        s += f(c_od + i * dx);
    }

    s = (s + (*f)(c_od) + (*f)(c_do) / 2) * dx;

    return s;
}

double mc(double (*f)(double)) {
    double krok, min = 0, max = 0, x, y, pole, randX, randY;
    int n = 0;

    krok = (c_do - c_od) / lp;

    for (double i = c_od; i <= c_do; i += krok) {
        if ((*f)(i) > max)
            max = (*f)(i);
        else if ((*f)(i) < min)
            min = (*f)(i);
    }

    x = c_do - c_od;
    y = max - min;
    pole = x * y;

    for (int i = 1; i <= lp; i++) {
        randX = c_od + (double) rand() / RAND_MAX * x;
        randY = min + (double) rand() / RAND_MAX * y;
        if (randY > 0 && (*f)(randX) > randY)
            n++;
        else if (randY < 0 && (*f)(randX) < randY)
            n--;
    }

    return n * pole / lp;
}

