#include <stdio.h>
#include <stdlib.h>
#include "MBD_all.h"

unsigned int test_case=1;
void MBD(void);

OUT out ;
IN in;
static int t=0;

int main(int argc, char *argv[]) {

    printf("=== DEBUT DES TESTS MCDC + CAS LIMITES ===\n");

/********************* Test Case 1 ***********************************/
    printf("\n--- Test Case %d: MCDC (Sat: Non) + (Cnt: Inc) ---\n", test_case);
    in.b0=0; in.b1=0; in.b2=0; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=3;
    in.R=0; out.Cnt=0;

    MBD();
    
    if((out.BitField==0) && (out.output==4) && (out.Cnt==1)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=0, output=4, Cnt=1\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }
    
/********************* Test Case 2 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: MCDC (Sat: Basse) + (Cnt: Inc) ---\n", test_case);
    in.b0=1; in.b1=0; in.b2=0; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=0;
    in.R=0; out.Cnt=1;
	
    MBD();

    if((out.BitField==1) && (out.output==2) && (out.Cnt==2)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=1, output=2, Cnt=2\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }
    
/********************* Test Case 3 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: MCDC (Sat: Haute) + (Cnt: Maintien) ---\n", test_case);
    in.b0=1; in.b1=1; in.b2=0; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=6;
    in.R=0; out.Cnt=2;
	
    MBD();

    if((out.BitField==3) && (out.output==5) && (out.Cnt==2)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=3, output=5, Cnt=2\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 4 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: MCDC (Sat: Non) + (Cnt: Maintien) ---\n", test_case);
    in.b0=0; in.b1=0; in.b2=1; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=2;
    in.R=0; out.Cnt=2;

    MBD();

    if((out.BitField==4) && (out.output==3) && (out.Cnt==2)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=4, output=3, Cnt=2\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }
    
/********************* Test Case 5 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: MCDC (Sat: Basse) + (Cnt: Reset) ---\n", test_case);
    in.b0=0; in.b1=2; in.b2=1; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=1;
    in.R=1; out.Cnt=2;

    MBD();

    if((out.BitField==8) && (out.output==2) && (out.Cnt==0)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=8, output=2, Cnt=0\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 6 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: MCDC (Sat: Haute) + (Cnt: Reset) ---\n", test_case);
    in.b0=1; in.b1=2; in.b2=0; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=5;
    in.R=1; out.Cnt=0;
	
    MBD();

    if((out.BitField==5) && (out.output==5) && (out.Cnt==0)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=5, output=5, Cnt=0\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 7 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: Limite (Sat: sum == upper) ---\n", test_case);
    in.b0=1; in.b1=0; in.b2=1; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=4;
    in.R=0; out.Cnt=2;
	
    MBD();

    if((out.BitField==5) && (out.output==5) && (out.Cnt==2)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=5, output=5, Cnt=2\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 8 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: Limite (Sat: sum == lower) ---\n", test_case);
    in.b0=0; in.b1=0; in.b2=0; out.BitField=0;
    in.upper=5; in.lower=2; in.input=1; out.output=1;
    in.R=0; out.Cnt=0;
	
    MBD();

    if((out.BitField==0) && (out.output==2) && (out.Cnt==1)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=0, output=2, Cnt=1\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 9 ***********************************/
    test_case++;
    printf("\n--- Test Case %d: Classe (input=0, prev_out=0) ---\n", test_case);
    in.b0=0; in.b1=1; in.b2=1; out.BitField=0;
    in.upper=5; in.lower=2; in.input=0; out.output=0;
    in.R=1; out.Cnt=2;
	
    MBD();

    if((out.BitField==6) && (out.output==2) && (out.Cnt==0)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=6, output=2, Cnt=0\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

/********************* Test Case 10 **********************************/
    test_case++;
    printf("\n--- Test Case %d: Classe (Inputs Negatifs) ---\n", test_case);
    in.b0=-15; in.b1=1; in.b2=-25; out.BitField=0;
    in.upper=5; in.lower=2; in.input=-5; out.output=3;
    in.R=0; out.Cnt=2;
	
    MBD();

    if((out.BitField==-113) && (out.output==2) && (out.Cnt==2)){
        printf("Test Case %d passed\n", test_case);
    } else {
        printf("Test Case %d FAILED\n", test_case);
        printf("  Expected: BitField=-113, output=2, Cnt=2\n");
        printf("  Got:      BitField=%d, output=%d, Cnt=%d\n", out.BitField, out.output, out.Cnt);
    }

    printf("\n=== FIN DES 10 TESTS ===\n");
	return 0;
}
