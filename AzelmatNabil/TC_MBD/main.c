#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const unsigned short CST = 2;
const unsigned short DT = 1;
unsigned short T = 0;

unsigned char Cnt, R;
short b0, b1, b2, bitField;
int input;
unsigned int upper, lower, output;

void MBD(void)
{
    bitField = b0 + (b1<<1) + (b2<<2);

    switch (R)
    {
    case 0:
        if(CST > Cnt){
            T += DT;
            Cnt = T;
        };
        break;
    default:
        Cnt = 0;
        break;
    };

    if ((output + input) <= upper && (output + input) >= lower)
    {
        output += input;
    }
    else
    {
        if ((output + input) >= lower)
        {
            output = upper;
        }
        else
        {
            output = lower;
        }
    }
}

int main() {

    printf("=== DEBUT DES TESTS SIMPLES (Logique du Collegue) ===\n\n");

    Cnt=0; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=1; output=1;
    MBD();
    if (bitField == 0 && output == 0 && Cnt == 1) printf("Test1 passed\n"); else printf("Test1 Failed\n");

    Cnt=0; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=0; output=1;
    MBD();
    if (bitField == 0 && output == 0 && Cnt == 2) printf("Test2 passed\n"); else printf("Test2 Failed\n");

    Cnt=0; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=1; output=0;
    MBD();
    if (bitField == 0 && output == 1 && Cnt == 3) printf("Test3 passed\n"); else printf("Test3 Failed\n");
    
    Cnt=3; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=1; output=1;
    MBD();
    if (bitField == 0 && output == 0 && Cnt == 3) printf("Test4 passed\n"); else printf("Test4 Failed\n");

    Cnt=3; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=0; output=1;
    MBD();
    if (bitField == 0 && output == 0 && Cnt == 3) printf("Test5 passed\n"); else printf("Test5 Failed\n");

    Cnt=3; R=0; b0=0; b1=0; b2=0; bitField=0; input=0; upper=0; lower=1; output=0;
    MBD();
    if (bitField == 0 && output == 1 && Cnt == 3) printf("Test6 passed\n"); else printf("Test6 Failed\n");

    printf("\n=== FIN DES TESTS ===\n");

    return 0;
}
