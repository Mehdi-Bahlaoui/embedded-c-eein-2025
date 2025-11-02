#include <stdio.h>

// External declarations
extern int b0, b1, b2;
extern unsigned int upper, lower;
extern int input;
extern unsigned char R;
extern short BitField;
extern unsigned int output;
extern unsigned char Cnt;

void MBD(void);

int main()
{
    unsigned int test_case = 1;

    printf("=== BEGIN TESTS ===\n");

    /********************* Test Case 1 ***********************************/
    b0=0; b1=0; b2=0;
    upper=5; lower=2; input=1;
    output=3; R=0; Cnt=0;

    MBD();
    printf("\nTest case %d executed.\n", test_case);
    if((BitField==0) && (output==4) && (Cnt==1))
        printf("Test %d PASSED\n", test_case);
    else {
        printf("Test %d FAILED\n", test_case);
        printf("Expected: BitField=0, Output=4, Cnt=1\n");
        printf("Got:      BitField=%d, Output=%d, Cnt=%d\n", BitField, output, Cnt);
    }

    /********************* Test Case 2 ***********************************/
    test_case++;
    b0=1; b1=0; b2=0;
    upper=5; lower=2; input=1;
    output=0; R=0; Cnt=1;

    MBD();
    printf("\nTest case %d executed.\n", test_case);
    if((BitField==1) && (output==2) && (Cnt==2))
        printf("Test %d PASSED\n", test_case);
    else {
        printf("Test %d FAILED\n", test_case);
        printf("Expected: BitField=1, Output=2, Cnt=2\n");
        printf("Got:      BitField=%d, Output=%d, Cnt=%d\n", BitField, output, Cnt);
    }

    /********************* Test Case 3 ***********************************/
    test_case++;
    b0=1; b1=1; b2=0;
    upper=5; lower=2; input=1;
    output=6; R=0; Cnt=2;

    MBD();
    printf("\nTest case %d executed.\n", test_case);
    if((BitField==3) && (output==5) && (Cnt==2))
        printf("Test %d PASSED\n", test_case);
    else {
        printf("Test %d FAILED\n", test_case);
        printf("Expected: BitField=3, Output=5, Cnt=2\n");
        printf("Got:      BitField=%d, Output=%d, Cnt=%d\n", BitField, output, Cnt);
    }

    /********************* Test Case 4 ***********************************/
    test_case++;
    b0=0; b1=0; b2=1;
    upper=5; lower=2; input=1;
    output=2; R=0; Cnt=2;

    MBD();
    printf("\nTest case %d executed.\n", test_case);
    if((BitField==4) && (output==3) && (Cnt==2))
        printf("Test %d PASSED\n", test_case);
    else {
        printf("Test %d FAILED\n", test_case);
        printf("Expected: BitField=4, Output=3, Cnt=2\n");
        printf("Got:      BitField=%d, Output=%d, Cnt=%d\n", BitField, output, Cnt);
    }

    /********************* Test Case 5 ***********************************/
    test_case++;
    b0=0; b1=2; b2=1;
    upper=5; lower=2; input=1;
    output=1; R=1; Cnt=2;

    MBD();
    printf("\nTest case %d executed.\n", test_case);
    if((BitField==8) && (output==2) && (Cnt==0))
        printf("Test %d PASSED\n", test_case);
    else {
        printf("Test %d FAILED\n", test_case);
        printf("Expected: BitField=8, Output=2, Cnt=0\n");
        printf("Got:      BitField=%d, Output=%d, Cnt=%d\n", BitField, output, Cnt);
    }

    printf("\n=== END OF 5 TESTS ===\n");
    return 0;
}
