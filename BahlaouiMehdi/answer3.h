#include <stdint.h>
#include <stdbool.h>



int32_t bottom_left(int32_t input, int32_t upper, int32_t lower, int32_t* prevOutput)
{
    int32_t candidate = *prevOutput + input;

    if (candidate <= upper && candidate >= lower)
    {
        *prevOutput = candidate;
        return candidate;
    }

    int32_t limit;
    if (candidate > upper)      limit = upper;
    else limit = lower;

    *prevOutput = limit;
    return limit;
}
