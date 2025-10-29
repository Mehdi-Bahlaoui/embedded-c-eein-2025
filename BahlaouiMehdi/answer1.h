#include <stdint.h>
#include <stdbool.h>


typedef struct {
    int32_t t;       // internal timer accumulator
    int32_t Cnt;       // previous output 
} ClockState;


int32_t  top_left(bool  R, ClockState* S)
{
    const int8_t DT = 1, CST = 2; // const variables

    bool E = CST > S->Cnt;

    if (E) S->t += DT;


    if (R == 1) {
        S->Cnt = 0;
        return 0;

    } else if (R == 0) {
        S->Cnt = S->t;
        return S->t;
    }

}

