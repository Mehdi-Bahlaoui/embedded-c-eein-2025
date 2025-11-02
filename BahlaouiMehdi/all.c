#include <stdint.h>
#include <stdbool.h>

const unsigned short CST = 2;
const unsigned short DT = 1;
unsigned short T = 0;




unsigned char Cnt, R;
short b0, b1, b2, bitField;
int input;
unsigned int upper, lower, output;




void  all(void)
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

