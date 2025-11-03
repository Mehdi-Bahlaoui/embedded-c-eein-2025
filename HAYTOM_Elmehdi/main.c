#include <stdint.h>
#include<stdio.h>


unsigned int prevOutput;

const int8_t DT = 1, CST = 2;
 unsigned char t = 0;
 unsigned char Cnt = 0;
unsigned int sum;


short bitField = 0;

char R; short b0; short b1; short b2; unsigned int upper; unsigned int lower; int input;

void func()
{

    bitField = b0 + (b1 << 1) + (b2 << 2);

    switch (R)
    {
    case 1:
        Cnt = 0;
        break;
    default:
        if (CST > Cnt)
        {
            t += DT;
            Cnt = t;
        }
        break;
    }

    sum = prevOutput + input;

    if (sum >= lower && sum <= upper)
    {
        prevOutput = sum;
    }

    prevOutput = (sum > upper) ? upper : lower;
}


void main(void)
{
    
    // ===== TEST 1: R == 1 =====
    prevOutput = 0; t = 0; Cnt = 5; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 1;
    R = 1; upper = 10; lower = 0;input = 3;
    func();

    if ((bitField == 5) && (Cnt == 0) && (prevOutput == 0)) {
        printf("T1 passed :)\n");
    }
    else {
        printf("T1 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 2: R != 1 && CST > Cnt =====
    prevOutput = 0; t = 0; Cnt = 1; sum = 0;
    bitField = 0; b0 = 0; b1 = 1; b2 = 0;
    R = 0; upper = 10; lower = 0; input = 1;

    func();

    if ((bitField == 2) && (Cnt == 1) && (prevOutput == 1)) {
        printf("T2 passed :)\n");
    }
    else {
        printf("T2 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 3: R != 1 && CST <= Cnt =====
    prevOutput = 0; t = 0; Cnt = 3; sum = 0;
    bitField = 0; b0 = 1; b1 = 1; b2 = 1;
    R = 0; upper = 10; lower = 0; input = 1;

    func();

    if ((bitField == 7) && (Cnt == 3) && (prevOutput == 1)) {
        printf("T3 passed :)\n");
    }
    else {
        printf("T3 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 4: sum < lower =====
    prevOutput = 1; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 0;
    R = 0; upper = 5; lower = 3; input = 1;

    func();

    if ((bitField == 1) && (Cnt == 1) && (prevOutput == 3)) {
        printf("T4 passed :)\n");
    }
    else {
        printf("T4 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 5: sum in range [lower, upper] =====
    prevOutput = 3; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 0; b1 = 1; b2 = 0;
    R = 0; upper = 5; lower = 2; input = 1;

    func();

    if ((bitField == 2) && (Cnt == 1) && (prevOutput == 2)) {
        printf("T5 passed :)\n");
    }
    else {
        printf("T5 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 6: sum > upper =====
    prevOutput = 5; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 0; b1 = 0; b2 = 1;
    R = 0; upper = 4; lower = 2; input = 2;

    func();

    if ((bitField == 4) && (Cnt == 1) && (prevOutput == 4)) {
        printf("T6 passed :)\n");
    }
    else {
        printf("T6 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 7: sum > upper  =====
    prevOutput = 3; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 0;
    R = 0; upper = 3; lower = 1; input = 2;

    func();

    if ((bitField == 1) && (Cnt == 1) && (prevOutput == 3)) {
        printf("T7 passed :)\n");
    }
    else {
        printf("T7 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

    // ===== TEST 8: sum <= upper =====
    prevOutput = 1; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 1; b2 = 0;
    R = 0; upper = 5; lower = 2; input = 1;

    func();

    if ((bitField == 3) && (Cnt == 1) && (prevOutput == 2)) {
        printf("T8 passed :)\n");
    }
    else {
        printf("T8 failed :(\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }

}
