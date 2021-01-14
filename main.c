#include <stdio.h>
#include "complex.h"



int main() {

    Complex c = {1.64,-6.4};
    //Complex d = {2.34,3.64};

    Complex z = cPowC(c,(Complex){3.4,6});
    cPrint(z);
    printf("\n");
    return 0;
}
