#include "complex.h"

#include <math.h>

void cPrint(Complex z) {
    if(z.imag==0) {
        printf("%lf  ",z.real);
    }
    else if(z.real==0) {
        printf("%lf i",z.imag);
    }
    else {
        printf("%lf  ",z.real);
        printf("%lf i",z.imag);
    }
}

double cReal(Complex z) {
    return z.real;
}

double cImag(Complex z) {
    return z.imag;
}

double cArg(Complex z) {
    double num = atan(z.imag/z.real);
    if(z.real>0)
        return num;
    else if(z.real<0 && z.imag>=0)
        return num+M_PI;
    else if(z.real<0 && z.imag<0)
        return num-M_PI;
    else if(z.real==0 && z.imag>0)
        return M_PI/2;
    else if(z.real==0 && z.imag<0)
        return -M_PI/2;
    else
        return 0;
}

double cAbs(Complex z) {
    return sqrt(z.real * z.real + z.imag * z.imag);
}

Complex cConj(Complex z) {
    return (Complex){z.real,-z.imag};
}

Complex cAdd(Complex z1, Complex z2) {
    return (Complex){z1.real + z2.real,z1.imag + z2.imag};
}

Complex cSubstact(Complex z1, Complex z2) {
    return (Complex){z1.real - z2.real,z1.imag - z2.imag};
}

Complex cMultiply(Complex z1, Complex z2) {
    return (Complex){z1.real * z2.real - z1.imag * z2.imag,
                z1.real * z2.imag + z1.imag * z2.real};
}

Complex cDivision(Complex z1, Complex z2) {
    return (Complex){(z1.real*z2.real+z1.imag*z2.imag)/(pow(z2.real,2)+pow(z2.imag,2)),
                (z2.real*z1.imag-z1.real*z2.imag)/(pow(z2.real,2)+pow(z2.imag,2))};
}

Complex cPowD(Complex z, double exp) {
    return (Complex){pow(cAbs(z),exp)*cos(cArg(z)*exp),
                pow(cAbs(z),exp)*sin(cArg(z)*exp)};
}

Complex cPowC(Complex z, Complex e) {
    double exponent = exp(e.real*log(cAbs(z))-e.imag*cArg(z));
    double argument = e.real*cArg(z)+e.imag*log(cAbs(z));
    return (Complex){exponent*cos(argument),exponent*sin(argument)};
}

Complex cSqrtD(double n) {
    return (n<0) ? ((Complex){0,sqrt(-n)}) : ((Complex){sqrt(n),0});
}


Complex cSqrtC(Complex z) {
    return (Complex){sqrt(cAbs(z))*cos(cArg(z)/2),
                sqrt(cAbs(z))*sin(cArg(z)/2)};
}

Complex cSinC(Complex z) {
    return (Complex){sin(z.real)*cosh(z.imag),
                cos(z.real)*sinh(z.imag)};
}

Complex cCosC(Complex z) {
    return (Complex){cos(z.real)*cosh(z.imag),
                -sin(z.real)*sinh(z.imag)};
}

Complex cTanC(Complex z) {
    return cDivision(cSinC(z),cCosC(z));
}


Complex cLnD(double n) {
    return (n<0) ? ((Complex){log(-n),M_PI}) : ((Complex){log(n),0});
}

Complex cLog10D(double n) {
    return (n<0) ? ((Complex){log(-n)/log(10),M_PI/log(10)}) :
                   ((Complex){log(n)/log(10),0});
}

Complex cLogBaseD(double n, double base) {
    return (n<0) ? ((Complex){log(-n)/log(base),M_PI/log(base)}) :
                   ((Complex){log(n)/log(base),0});
}

Complex cLnC(Complex z) {
    return (Complex){log(cAbs(z)),cArg(z)};
}

Complex cLog10C(Complex z) {
    return (Complex){log(cAbs(z))/log(10),cArg(z)/log(10)};
}

Complex cLogBaseC(Complex z,double base) {
    return (Complex){log(cAbs(z))/log(base),cArg(z)/log(base)};
}

Complex cLogBaseIsC(Complex z,Complex base) {
    return cDivision(cLnC(z),cLnC(base));
}

Complex cAsinC(Complex z) {
    Complex sqrtPart = cSqrtC(cSubstact((Complex){1,0},cPowD(z,2)));//sqrt(1-z^2)
    Complex lnPart = cLnC(cAdd(cMultiply((Complex){0,1},z),sqrtPart));//ln(iz+sqrt(1-z^2))
    return cMultiply((Complex){0,-1},lnPart);
}

Complex cAcosC(Complex z) {
    Complex sqrtPart = cSqrtC(cSubstact((Complex){1,0},cPowD(z,2)));//sqrt(1-z^2)
    Complex lnPart = cLnC(cAdd(cMultiply((Complex){0,1},z),sqrtPart));//ln(iz+sqrt(1-z^2))
    return cAdd((Complex){M_PI/2,0},(Complex)cMultiply((Complex){0,1},lnPart));
}

Complex cAtanC(Complex z) {
    Complex fLn = cLnC(cSubstact((Complex){1,0},cMultiply((Complex){0,1},z)));//ln(1-iz)
    Complex sLn = cLnC(cAdd((Complex){1,0},cMultiply((Complex){0,1},z)));//ln(1-iz)
    return cMultiply((Complex){0,0.5},cSubstact(fLn,sLn));
}

Complex cSinhC(Complex z) {
    return (Complex){sinh(z.real)*cos(z.imag),cosh(z.real)*sin(z.imag)};
}

Complex cCoshC(Complex z) {
    return (Complex){cosh(z.real)*cos(z.imag),sinh(z.real)*sin(z.imag)};
}

Complex cTanhC(Complex z) {
    return cDivision(cSinhC(z),cCoshC(z));
}


Complex cAsinhC(Complex z) {
    return cLnC(cAdd(z,cSqrtC(cAdd(cPowD(z,2),(Complex){1,0}))));
}

Complex cAcoshC(Complex z) {
    return cLnC(cAdd(z,cMultiply(cSqrtC(cSubstact(z,(Complex){1,0})),
                               cSqrtC(cAdd(z,(Complex){1,0})))));
}

Complex cAtanhC(Complex z) {
    return cMultiply((Complex){0.50,0},cSubstact(cLnC(cAdd((Complex){1,0},z)),
                                                 cLnC(cSubstact((Complex){1,0},z))));
}




