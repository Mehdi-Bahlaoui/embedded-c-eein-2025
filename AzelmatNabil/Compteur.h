#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int32_t t;
    int32_t Cnt;
} ClockState;

int32_t conditionalCounter(bool R, int32_t Cst, ClockState* S) {
    const int8_t DT = 1;

    bool E = (Cst > S->Cnt);

    if (E) {
        S->t += DT;
    }

    if (R) {
        S->Cnt = 0;
    } else {
        S->Cnt = S->t;
    }

    return S->Cnt;
}