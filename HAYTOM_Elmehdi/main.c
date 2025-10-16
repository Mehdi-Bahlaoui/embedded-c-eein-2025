#include <stdint.h>
uint8_t  bitField = 0;

const uint8_t cst = 2;
uint8_t Dt = 0;
uint8_t timer = 0;
uint8_t test = 0;
uint8_t counter = 0;



 int32_t* prevOutput;

void setBitField(uint8_t  b0, uint8_t  b1, uint8_t  b2)
{
    bitField = b0 + (b1 << 1) + (b2 << 2); // set bit 0
}




int32_t top_left(uint8_t R)
{
    const int8_t DT = 1, CST = 2; 
    static int32_t t = 0;           
    static int32_t Cnt = 0;         

    uint8_t E = CST > Cnt;

    if (1==E) t += DT;

    if (1==R) 
    {
        Cnt = 0;
        return 0;
    } 
    else 
    {
        Cnt = t;
        return t;
    }
}

int32_t bottom_left(int32_t input, int32_t upper, int32_t lower)
{
    int32_t sum = *prevOutput + input;

    if (sum >= lower && sum <= upper) 
    {
        *prevOutput = sum;
        return sum;
    }

    *prevOutput = (sum > upper) ? upper : lower;
    return *prevOutput;
}