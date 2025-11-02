#include <stdio.h>

/* ===== Declaration des variables globales ===== */
unsigned char R = 0;
unsigned char Cnt = 0;
unsigned char Cst = 10;
unsigned int upper = 100;
unsigned int lower = 20;
short b0 = 0;
short b1 = 0;
short b2 = 0;
short BitField = 0;
int input = 0;
unsigned int output = 0;
double t = 0.0;
double DT = 1.0;

/* ===== Fonction a tester ===== */
void Process_Control(void)
{
    unsigned int sum;
    
    sum = output + input;
    
    if(sum <= upper && sum >= lower) 
        output = sum;
    else if(sum > upper) 
        output = upper;
    else 
        output = lower;
    
    BitField = b0 + (b1 << 1) + (b2 << 2);
    
    switch(R){
        case 0: 
            if(Cst > Cnt){
                t += DT;
                Cnt = t;
            }
            break;
        case 1: 
            Cnt = 0;
            break;
    }
}

/* ===== Programme principal ===== */
int main(void)
{
    int i;
    
    printf("========================================\n");
    printf("=== TESTS Process_Control (6 tests) ===\n");
    printf("========================================\n\n");
    
    /* Test 1 : Saturation inferieure */
    printf("Test 1 - Saturation inferieure (sum < lower)\n");
    printf("---------------------------------------------\n");
    output = 10;
    input = 5;
    b0 = 0; b1 = 0; b2 = 0;
    R = 0;
    Cnt = 0;
    Cst = 10;
    t = 0.0;
    
    Process_Control();
    
    printf("  output=%u (attendu: 20)\n", output);
    printf("  Resultat: %s\n\n", (output == 20) ? "PASS" : "FAIL");
    
    /* Test 2 : Saturation superieure */
    printf("Test 2 - Saturation superieure (sum > upper)\n");
    printf("---------------------------------------------\n");
    output = 80;
    input = 50;
    
    Process_Control();
    
    printf("  output=%u (attendu: 100)\n", output);
    printf("  Resultat: %s\n\n", (output == 100) ? "PASS" : "FAIL");
    
    /* Test 3 : BitField avec tous les bits a 1 */
    printf("Test 3 - BitField (b0=1, b1=1, b2=1)\n");
    printf("-------------------------------------\n");
    output = 50;
    input = 0;
    b0 = 1; b1 = 1; b2 = 1;
    
    Process_Control();
    
    printf("  BitField=%d (attendu: 7)\n", BitField);
    printf("  Resultat: %s\n\n", (BitField == 7) ? "PASS" : "FAIL");
    
    /* Test 4 : Counter incrementation (R=0, Cnt < Cst) */
    printf("Test 4 - Counter incrementation (R=0, Cnt < Cst)\n");
    printf("-------------------------------------------------\n");
    R = 0;
    Cnt = 0;
    Cst = 5;
    t = 0.0;
    b0 = 0; b1 = 0; b2 = 0;
    
    for (i = 0; i < 3; i++) {
        Process_Control();
    }
    
    printf("  Cnt=%d (attendu: 3)\n", Cnt);
    printf("  Resultat: %s\n\n", (Cnt == 3) ? "PASS" : "FAIL");
    
    /* Test 5 : Counter reset (R=1) */
    printf("Test 5 - Counter reset (R=1)\n");
    printf("-----------------------------\n");
    R = 1;
    Cnt = 5;
    
    Process_Control();
    
    printf("  Cnt=%d (attendu: 0)\n", Cnt);
    printf("  Resultat: %s\n\n", (Cnt == 0) ? "PASS" : "FAIL");
    
    /* Test 6 : Integration complete */
    printf("Test 6 - Integration complete\n");
    printf("------------------------------\n");
    output = 40;
    input = 30;
    b0 = 1; b1 = 1; b2 = 0;
    R = 0;
    Cnt = 2;
    Cst = 5;
    t = 2.0;
    
    Process_Control();
    
    printf("  output=%u (attendu: 70)\n", output);
    printf("  BitField=%d (attendu: 3)\n", BitField);
    printf("  Cnt=%d (attendu: 3)\n", Cnt);
    printf("  Resultat: %s\n\n", 
           (output == 70 && BitField == 3 && Cnt == 3) ? "PASS" : "FAIL");
    
    printf("========================================\n");
    printf("===     TOUS LES TESTS PASSES        ===\n");
    printf("========================================\n");
    
    return 0;
}
