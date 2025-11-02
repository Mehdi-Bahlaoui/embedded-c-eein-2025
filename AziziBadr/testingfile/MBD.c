#include <stdio.h>

// Global variables
int b0, b1, b2;
unsigned int upper, lower;
int input;
unsigned char R;

short BitField;
unsigned int output;
unsigned char Cnt;

void MBD(void)
{
    int DT = 1;
    const int cst = 2;
    static int t;

    // Block 1
    BitField = b0 + (b1 << 1) + (b2 << 2);

    // Block 2
    switch (R)
    {
    case 0:
        if (cst > Cnt)
        {
            t += DT;
            Cnt = t;
        }
        break;
    case 1:
        Cnt = 0;
        break;
    }

    // Block 3
    output += input;

    if ((!(upper >= output)) || (!(output >= lower)))
    {
        if (output >= lower)
            output = upper;
        else
            output = lower;
    }
}
