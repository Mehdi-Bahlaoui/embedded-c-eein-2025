#include <stdint.h>


int32_t  bitField(int32_t* b0, int32_t* b1, int32_t* b2)
{
    return (*b0 + (*b1)*2 + (*b2)*4);
}