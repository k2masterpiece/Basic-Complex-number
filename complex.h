#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

typedef struct Complex Complex;


void cPrint(Complex z);

double cReal(Complex z);

double cImag(Complex z);

double cArg(Complex z);

double cAbs(Complex z);

Complex cConj(Complex z);



Complex cAdd(Complex z1, Complex z2);

Complex cSubstact(Complex z1, Complex z2);

Complex cMultiply(Complex z1, Complex z2);

Complex cDivision(Complex z1, Complex z2);




Complex cPowD(Complex z, double exp);

Complex cPowC(Complex z, Complex exp);

Complex cSqrtD(double n);

Complex cSqrtC(Complex z);





Complex cSinC(Complex z);

Complex cCosC(Complex z);

Complex cTanC(Complex z);



Complex cLnD(double n);

Complex cLog10D(double n);

Complex cLogBaseD(double n, double base);



Complex cLnC(Complex z);

Complex cLog10C(Complex z);

Complex cLogBaseC(Complex z,double base);

Complex cLogBaseIsC(Complex z,Complex base);



Complex cAsinC(Complex z);

Complex cAcosC(Complex z);

Complex cAtanC(Complex z);




Complex cSinhC(Complex z);

Complex cCoshC(Complex z);

Complex cTanhC(Complex z);



Complex cAsinhC(Complex z);

Complex cAcoshC(Complex z);

Complex cAtanhC(Complex z);


#endif // COMPLEX_H

