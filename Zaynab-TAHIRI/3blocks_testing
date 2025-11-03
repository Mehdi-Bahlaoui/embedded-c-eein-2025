#include <stdint.h>
#include <stdio.h>

unsigned int prevOutput;
const int8_t DT = 1, CST = 2;
unsigned char t = 0;
unsigned char Cnt = 0;
unsigned int sum;
short bitField = 0;
char R; 
short b0; 
short b1; 
short b2; 
unsigned int upper; 
unsigned int lower; 
int input;

void func()
{
    // Construct bitField from individual bit components
    bitField = b0 + (b1 << 1) + (b2 << 2);
    
    switch (R)
    {
    case 1:
        // Reset counter when R equals 1
        Cnt = 0;
        break;
    default:
        // Increment time and update counter if within threshold
        if (CST > Cnt)
        {
            t += DT;
            Cnt = t;
        }
        break;
    }
    
    // Calculate new sum from previous output and current input
    sum = prevOutput + input;
    
    // Check if sum is within acceptable bounds
    if (sum >= lower && sum <= upper)
    {
        prevOutput = sum;
    }
    
    // Clamp output to boundary limits
    prevOutput = (sum > upper) ? upper : lower;
}

void main(void)
{
    
    // ===== SCENARIO 1: Reset condition triggered =====
    prevOutput = 0; t = 0; Cnt = 5; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 1;
    R = 1; upper = 10; lower = 0; input = 3;
    func();
    if ((bitField == 5) && (Cnt == 0) && (prevOutput == 0)) {
        printf("Test case 1 successful!\n");
    }
    else {
        printf("Test case 1 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 2: Counter below threshold, increment active =====
    prevOutput = 0; t = 0; Cnt = 1; sum = 0;
    bitField = 0; b0 = 0; b1 = 1; b2 = 0;
    R = 0; upper = 10; lower = 0; input = 1;
    func();
    if ((bitField == 2) && (Cnt == 1) && (prevOutput == 1)) {
        printf("Test case 2 successful!\n");
    }
    else {
        printf("Test case 2 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 3: Counter at or above threshold, no increment =====
    prevOutput = 0; t = 0; Cnt = 3; sum = 0;
    bitField = 0; b0 = 1; b1 = 1; b2 = 1;
    R = 0; upper = 10; lower = 0; input = 1;
    func();
    if ((bitField == 7) && (Cnt == 3) && (prevOutput == 1)) {
        printf("Test case 3 successful!\n");
    }
    else {
        printf("Test case 3 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 4: Sum falls below minimum boundary =====
    prevOutput = 1; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 0;
    R = 0; upper = 5; lower = 3; input = 1;
    func();
    if ((bitField == 1) && (Cnt == 1) && (prevOutput == 3)) {
        printf("Test case 4 successful!\n");
    }
    else {
        printf("Test case 4 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 5: Sum within valid range boundaries =====
    prevOutput = 3; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 0; b1 = 1; b2 = 0;
    R = 0; upper = 5; lower = 2; input = 1;
    func();
    if ((bitField == 2) && (Cnt == 1) && (prevOutput == 2)) {
        printf("Test case 5 successful!\n");
    }
    else {
        printf("Test case 5 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 6: Sum exceeds maximum boundary =====
    prevOutput = 5; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 0; b1 = 0; b2 = 1;
    R = 0; upper = 4; lower = 2; input = 2;
    func();
    if ((bitField == 4) && (Cnt == 1) && (prevOutput == 4)) {
        printf("Test case 6 successful!\n");
    }
    else {
        printf("Test case 6 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 7: Ternary operator upper limit enforcement =====
    prevOutput = 3; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 0; b2 = 0;
    R = 0; upper = 3; lower = 1; input = 2;
    func();
    if ((bitField == 1) && (Cnt == 1) && (prevOutput == 3)) {
        printf("Test case 7 successful!\n");
    }
    else {
        printf("Test case 7 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
    
    // ===== SCENARIO 8: Ternary operator lower limit enforcement =====
    prevOutput = 1; t = 0; Cnt = 0; sum = 0;
    bitField = 0; b0 = 1; b1 = 1; b2 = 0;
    R = 0; upper = 5; lower = 2; input = 1;
    func();
    if ((bitField == 3) && (Cnt == 1) && (prevOutput == 2)) {
        printf("Test case 8 successful!\n");
    }
    else {
        printf("Test case 8 unsuccessful!\nbitField=%d ; Cnt=%d ; prevOutput=%d\n", bitField, Cnt, prevOutput);
    }
}
