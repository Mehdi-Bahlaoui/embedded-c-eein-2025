#include "all.c"
#include <stdio.h>


int main() {


    //TC1 - Initialize variables
    Cnt=0, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=1, output=1;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 0 && Cnt == 1) printf("Test1 passed\n"); else printf("Test1 Failed\n");

    //TC2 - Initialize variables
    Cnt=0, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=0, output=1;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 0 && Cnt == 2) printf("Test2 passed\n"); else printf("Test2 Failed\n");

    //TC3 - Initialize variables
    Cnt=0, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=1, output=0;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 1 && Cnt == 3) printf("Test3 passed\n"); else printf("Test3 Failed\n");
    
    //TC4 - Initialize variables
    Cnt=3, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=1, output=1;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 0 && Cnt == 3) printf("Test4 passed\n"); else printf("Test4 Failed\n");

    //TC5 - Initialize variables
    Cnt=3, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=0, output=1;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 0 && Cnt == 3) printf("Test5 passed\n"); else printf("Test5 Failed\n");

    //TC6 - Initialize variables
    Cnt=3, R=0, b0=0, b1=0, b2=0, bitField=0, input=0, upper=0, lower=1, output=0;
    //Call of MUT
    all();
    //Checking Output
    if (bitField == 0 && output == 1 && Cnt == 3) printf("Test6 passed\n"); else printf("Test6 Failed\n");



    return 0;
}
