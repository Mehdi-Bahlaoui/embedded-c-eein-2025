#include <stdio.h>
#include <stdint.h>

// --- Variables Globales ---
unsigned short Cst;
unsigned short DT;
unsigned short t;
unsigned char R;
unsigned char Cnt;

unsigned int upper;
unsigned int lower;
int input;
unsigned int output;
int previous_output;

short b0;
short b1;
short b2;
short BitField;

// --- Fonction all() ---
void all(void) {
    // Logique du Timer
    switch (R) {
    case 0:
        if (Cst > t) {
            t += DT;
            Cnt = t;
        } else {
            Cnt = 0;
        }
        break;
    default:
        t = 0;
        Cnt = 0;
        break;
    }
    
    // Logique de la Saturation
    int sum_input_and_previous_output = input + previous_output;
    if (sum_input_and_previous_output >= (int)upper) {
        output = upper;
    } else if (sum_input_and_previous_output <= (int)lower) {
        output = lower;
    } else {
        output = (unsigned int)sum_input_and_previous_output;
    }
    previous_output = (int)output;
    
    // Logique du BitField
    short effective_b0 = (b0 > 0) ? 1 : 0;
    short effective_b1 = (b1 > 0) ? 1 : 0;
    short effective_b2 = (b2 > 0) ? 1 : 0;
    BitField = effective_b0 + (effective_b1 << 1) + (effective_b2 << 2);
}

void reset_globals() {
    Cst = 0; DT = 0; t = 0; R = 0; Cnt = 0;
    upper = 0; lower = 0; input = 0; output = 0; previous_output = 0;
    b0 = 0; b1 = 0; b2 = 0; BitField = 0;
}

int main() {
    printf("=== CAS DE TEST COMBINÉS POUR LES TROIS BLOCS ===\n\n");
    
    /*------------------------- Cas de test 1. -------------------------*/
    /* Timer: Incrément normal | Saturation: Normal | BitField: 000 */
    printf("\n--- CT1: Timer Inc + Sat Normal + BitField 000 ---\n");
    reset_globals();
    // Timer: Incrémentation normale
    Cst = 100; DT = 10; t = 0; R = 0;
    // Saturation: Cas normal
    input = 15; previous_output = 20; upper = 100; lower = 0;
    // BitField: Tous à 0
    b0 = 0; b1 = 0; b2 = 0;
    
    all();
    
    if((Cnt == 10) && (output == 35) && (BitField == 0)){
        printf("CT1 passed :)\n");
    } else {
        printf("CT1 failed :(\n");
        printf("  Expected: Cnt=10, output=35, BitField=0\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 2. -------------------------*/
    /* Timer: Reset | Saturation: Upper limit | BitField: 111 */
    printf("\n--- CT2: Timer Reset + Sat Upper + BitField 111 ---\n");
    reset_globals();
    // Timer: Reset actif
    Cst = 100; DT = 10; t = 50; R = 1;
    // Saturation: Limite supérieure
    input = 60; previous_output = 50; upper = 80; lower = 0;
    // BitField: Tous à 1
    b0 = 1; b1 = 1; b2 = 1;
    
    all();
    
    if((Cnt == 0) && (t == 0) && (output == 80) && (BitField == 7)){
        printf("CT2 passed :)\n");
    } else {
        printf("CT2 failed :(\n");
        printf("  Expected: Cnt=0, t=0, output=80, BitField=7\n");
        printf("  Got: Cnt=%d, t=%d, output=%d, BitField=%d\n", Cnt, t, output, BitField);
    }
    
    /*------------------------- Cas de test 3. -------------------------*/
    /* Timer: Incrément | Saturation: Lower limit | BitField: 001 */
    printf("\n--- CT3: Timer Inc + Sat Lower + BitField 001 ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 80; DT = 5; t = 30; R = 0;
    // Saturation: Limite inférieure
    input = -15; previous_output = 10; upper = 100; lower = 5;
    // BitField: b0 seulement
    b0 = 1; b1 = 0; b2 = 0;
    
    all();
    
    if((Cnt == 35) && (output == 5) && (BitField == 1)){
        printf("CT3 passed :)\n");
    } else {
        printf("CT3 failed :(\n");
        printf("  Expected: Cnt=35, output=5, BitField=1\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 4. -------------------------*/
    /* Timer: Cnt=0 (t>=Cst) | Saturation: Normal | BitField: 010 */
    printf("\n--- CT4: Timer Cnt=0 + Sat Normal + BitField 010 ---\n");
    reset_globals();
    // Timer: t >= Cst donc Cnt = 0
    Cst = 50; DT = 10; t = 50; R = 0;
    // Saturation: Normal
    input = 10; previous_output = 15; upper = 50; lower = 0;
    // BitField: b1 seulement
    b0 = 0; b1 = 1; b2 = 0;
    
    all();
    
    if((Cnt == 0) && (output == 25) && (BitField == 2)){
        printf("CT4 passed :)\n");
    } else {
        printf("CT4 failed :(\n");
        printf("  Expected: Cnt=0, output=25, BitField=2\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 5. -------------------------*/
    /* Timer: Incrément | Saturation: Upper | BitField: 100 */
    printf("\n--- CT5: Timer Inc + Sat Upper + BitField 100 ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 200; DT = 20; t = 0; R = 0;
    // Saturation: Upper limit
    input = 70; previous_output = 40; upper = 90; lower = 0;
    // BitField: b2 seulement
    b0 = 0; b1 = 0; b2 = 1;
    
    all();
    
    if((Cnt == 20) && (output == 90) && (BitField == 4)){
        printf("CT5 passed :)\n");
    } else {
        printf("CT5 failed :(\n");
        printf("  Expected: Cnt=20, output=90, BitField=4\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 6. -------------------------*/
    /* Timer: Reset | Saturation: Lower | BitField: 011 */
    printf("\n--- CT6: Timer Reset + Sat Lower + BitField 011 ---\n");
    reset_globals();
    // Timer: Reset
    Cst = 100; DT = 10; t = 75; R = 5;
    // Saturation: Lower limit
    input = 0; previous_output = 3; upper = 50; lower = 10;
    // BitField: b0 et b1
    b0 = 1; b1 = 1; b2 = 0;
    
    all();
    
    if((Cnt == 0) && (t == 0) && (output == 10) && (BitField == 3)){
        printf("CT6 passed :)\n");
    } else {
        printf("CT6 failed :(\n");
        printf("  Expected: Cnt=0, t=0, output=10, BitField=3\n");
        printf("  Got: Cnt=%d, t=%d, output=%d, BitField=%d\n", Cnt, t, output, BitField);
    }
    
    /*------------------------- Cas de test 7. -------------------------*/
    /* Timer: Incrément | Saturation: Normal | BitField: 101 */
    printf("\n--- CT7: Timer Inc + Sat Normal + BitField 101 ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 150; DT = 15; t = 60; R = 0;
    // Saturation: Normal
    input = 12; previous_output = 18; upper = 100; lower = 5;
    // BitField: b0 et b2
    b0 = 1; b1 = 0; b2 = 1;
    
    all();
    
    if((Cnt == 75) && (output == 30) && (BitField == 5)){
        printf("CT7 passed :)\n");
    } else {
        printf("CT7 failed :(\n");
        printf("  Expected: Cnt=75, output=30, BitField=5\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 8. -------------------------*/
    /* Timer: Cnt=0 | Saturation: Upper | BitField: 110 */
    printf("\n--- CT8: Timer Cnt=0 + Sat Upper + BitField 110 ---\n");
    reset_globals();
    // Timer: Cnt = 0 (t >= Cst)
    Cst = 40; DT = 10; t = 60; R = 0;
    // Saturation: Upper limit
    input = 45; previous_output = 35; upper = 70; lower = 0;
    // BitField: b1 et b2
    b0 = 0; b1 = 1; b2 = 1;
    
    all();
    
    if((Cnt == 0) && (output == 70) && (BitField == 6)){
        printf("CT8 passed :)\n");
    } else {
        printf("CT8 failed :(\n");
        printf("  Expected: Cnt=0, output=70, BitField=6\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    
    /*------------------------- Cas de test 9. -------------------------*/
    /* Timer: Cnt=0 | Saturation: Upper | BitField: b2 négatif */
    printf("\n--- CT9: Timer Cnt=0 + Sat Upper + BitField b2 neg ---\n");
    reset_globals();
    // Timer: Cnt = 0
    Cst = 30; DT = 10; t = 45; R = 0;
    // Saturation: Upper limit
    input = 55; previous_output = 30; upper = 75; lower = 0;
    // BitField: b2 négatif, b0 et b1 positifs
    b0 = 1; b1 = 1; b2 = -7;
    
    all();
    
    if((Cnt == 0) && (output == 75) && (BitField == 3)){
        printf("CT9 passed :)\n");
    } else {
        printf("CT9 failed :(\n");
        printf("  Expected: Cnt=0, output=75, BitField=3\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
  
    /*------------------------- Cas de test 10. -------------------------*/
    /* Timer: Incrément | Saturation: Boundary = upper | BitField: 001 */
    printf("\n--- CT10: Timer Inc + Sat Boundary Upper + BitField 001 ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 120; DT = 12; t = 36; R = 0;
    // Saturation: sum = upper (boundary)
    input = 30; previous_output = 20; upper = 50; lower = 0;
    // BitField: b0 seulement
    b0 = 1; b1 = 0; b2 = 0;
    
    all();
    
    if((Cnt == 48) && (output == 50) && (BitField == 1)){
        printf("CT10 passed :)\n");
    } else {
        printf("CT10 failed :(\n");
        printf("  Expected: Cnt=48, output=50, BitField=1\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 11. -------------------------*/
    /* Timer: Cnt=0 | Saturation: Boundary = lower | BitField: 010 */
    printf("\n--- CT11: Timer Cnt=0 + Sat Boundary Lower + BitField 010 ---\n");
    reset_globals();
    // Timer: Cnt = 0
    Cst = 50; DT = 5; t = 50; R = 0;
    // Saturation: sum = lower (boundary)
    input = 5; previous_output = 10; upper = 100; lower = 15;
    // BitField: b1 seulement
    b0 = 0; b1 = 1; b2 = 0;
    
    all();
    
    if((Cnt == 0) && (output == 15) && (BitField == 2)){
        printf("CT11 passed :)\n");
    } else {
        printf("CT11 failed :(\n");
        printf("  Expected: Cnt=0, output=15, BitField=2\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 12. -------------------------*/
    /* Timer: Boundary Cst=t | Saturation: Normal | BitField: 111 */
    printf("\n--- CT12: Timer Boundary Cst=t + Sat Normal + BitField 111 ---\n");
    reset_globals();
    // Timer: Cst = t (boundary)
    Cst = 100; DT = 0; t = 100; R = 0;
    // Saturation: Normal
    input = 20; previous_output = 25; upper = 100; lower = 0;
    // BitField: Tous à 1
    b0 = 1; b1 = 1; b2 = 1;
    
    all();
    
    if((Cnt == 0) && (t == 100) && (output == 45) && (BitField == 7)){
        printf("CT12 passed :)\n");
    } else {
        printf("CT12 failed :(\n");
        printf("  Expected: Cnt=0, t=100, output=45, BitField=7\n");
        printf("  Got: Cnt=%d, t=%d, output=%d, BitField=%d\n", Cnt, t, output, BitField);
    }
    
    /*------------------------- Cas de test 13. -------------------------*/
    /* Timer: Reset | Saturation: Upper | BitField: b0,b1 négatifs */
    printf("\n--- CT13: Timer Reset + Sat Upper + BitField b0,b1 neg ---\n");
    reset_globals();
    // Timer: Reset
    Cst = 80; DT = 8; t = 64; R = 2;
    // Saturation: Upper limit
    input = 50; previous_output = 60; upper = 95; lower = 5;
    // BitField: b0,b1 négatifs, b2 positif
    b0 = -10; b1 = -20; b2 = 1;
    
    all();
    
    if((Cnt == 0) && (t == 0) && (output == 95) && (BitField == 4)){
        printf("CT13 passed :)\n");
    } else {
        printf("CT13 failed :(\n");
        printf("  Expected: Cnt=0, t=0, output=95, BitField=4\n");
        printf("  Got: Cnt=%d, t=%d, output=%d, BitField=%d\n", Cnt, t, output, BitField);
    }
    
    /*------------------------- Cas de test 14. -------------------------*/
    /* Timer: Incrément | Saturation: Lower | BitField: b0,b2 négatifs */
    printf("\n--- CT14: Timer Inc + Sat Lower + BitField b0,b2 neg ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 140; DT = 14; t = 70; R = 0;
    // Saturation: Lower limit
    input = -5; previous_output = 2; upper = 80; lower = 0;
    // BitField: b0,b2 négatifs, b1 positif
    b0 = -15; b1 = 1; b2 = -25;
    
    all();
    
    if((Cnt == 84) && (output == 0) && (BitField == 2)){
        printf("CT14 passed :)\n");
    } else {
        printf("CT14 failed :(\n");
        printf("  Expected: Cnt=84, output=0, BitField=2\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 15. -------------------------*/
    /* Timer: Cnt=0 | Saturation: Normal | BitField: b1,b2 négatifs */
    printf("\n--- CT15: Timer Cnt=0 + Sat Normal + BitField b1,b2 neg ---\n");
    reset_globals();
    // Timer: Cnt = 0
    Cst = 60; DT = 6; t = 72; R = 0;
    // Saturation: Normal
    input = 18; previous_output = 22; upper = 90; lower = 10;
    // BitField: b1,b2 négatifs, b0 positif
    b0 = 1; b1 = -8; b2 = -9;
    
    all();
    
    if((Cnt == 0) && (output == 40) && (BitField == 1)){
        printf("CT15 passed :)\n");
    } else {
        printf("CT15 failed :(\n");
        printf("  Expected: Cnt=0, output=40, BitField=1\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 16. -------------------------*/
    /* Timer: Incrément | Saturation: input=0, prev=0 | BitField: Mixed */
    printf("\n--- CT19: Timer Inc + Sat Zero + BitField Mixed ---\n");
    reset_globals();
    // Timer: Incrémentation
    Cst = 200; DT = 25; t = 50; R = 0;
    // Saturation: input=0, previous_output=0
    input = 0; previous_output = 0; upper = 50; lower = 0;
    // BitField: Mixed (b0=neg, b1=pos, b2=0)
    b0 = -5; b1 = 2; b2 = 0;
    
    all();
    
    if((Cnt == 75) && (output == 0) && (BitField == 2)){
        printf("CT16 passed :)\n");
    } else {
        printf("CT16 failed :(\n");
        printf("  Expected: Cnt=75, output=0, BitField=2\n");
        printf("  Got: Cnt=%d, output=%d, BitField=%d\n", Cnt, output, BitField);
    }
    
    /*------------------------- Cas de test 17. -------------------------*/
    /* Timer: Reset | Saturation: Max values | BitField: All positive */
    printf("\n--- CT17: Timer Reset + Sat Max + BitField All Pos ---\n");
    reset_globals();
    // Timer: Reset avec valeurs maximales
    Cst = 65535; DT = 1000; t = 32000; R = 100;
    // Saturation: Valeurs maximales
    input = 1000; previous_output = 2000; upper = 2500; lower = 100;
    // BitField: Tous positifs avec grandes valeurs
    b0 = 100; b1 = 200; b2 = 300;
    
    all();
    
    if((Cnt == 0) && (t == 0) && (output == 2500) && (BitField == 7)){
        printf("CT17 passed :)\n");
    } else {
        printf("CT17 failed :(\n");
        printf("  Expected: Cnt=0, t=0, output=2500, BitField=7\n");
        printf("  Got: Cnt=%d, t=%d, output=%d, BitField=%d\n", Cnt, t, output, BitField);
    }
    
    printf("\n=== FIN DES TESTS  ===\n");
    return 0;
}
