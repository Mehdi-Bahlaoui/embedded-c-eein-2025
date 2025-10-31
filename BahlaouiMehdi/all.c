#include <stdint.h>
#include <stdbool.h>

const unsigned short CST = 2;
const unsigned short DT = 1;
unsigned short T = 0;
short bitField;



int32_t  all(unsigned char Cnt, unsigned char R, short b0, short b1, short b2)
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
    }



}

