#include <stdio.h>
#include <stdlib.h>
#include "MBD_all.h"

unsigned int test_case=1;
void MBD(void);

OUT out ;
IN in;
static int t=0;

int main(int argc, char *argv[]) {

/*********************test case 1***********************************/
//initialisation
    in.b0=0;
    in.b1=0;
    in.b2=0;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=3;
	
    in.R=0;
	out.Cnt=0;

//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==0) && (out.output==4) && out.Cnt==1 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }
    
/*********************test case 2***********************************/
//initialisation
	test_case++;
    in.b0=1;
    in.b1=0;
    in.b2=0;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=0;
	
    in.R=0;
	out.Cnt=1;
	
//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==1) && (out.output==2) && out.Cnt==2 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }
    
    
/*********************test case 3***********************************/
//initialisation
	test_case++;
    in.b0=1;
    in.b1=1;
    in.b2=0;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=6;
	
    in.R=0;
	out.Cnt=2;
	
//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==3) && (out.output==5) && out.Cnt==2 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }


/*********************test case 4***********************************/
//initialisation
	test_case++;
    in.b0=0;
    in.b1=0;
    in.b2=1;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=2;
	
    in.R=0;
	out.Cnt=2;

//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==4) && (out.output==3) && out.Cnt==2 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }
    

/*********************test case 5***********************************/
//initialisation
	test_case++;
    in.b0=0;
    in.b1=2;
    in.b2=1;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=1;
	
    in.R=1;
	out.Cnt=2;

//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==8) && (out.output==2) && out.Cnt==0 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }


/*********************test case 6***********************************/
//initialisation
	test_case++;
    in.b0=1;
    in.b1=2;
    in.b2=0;
    out.BitField=0;
    
    in.upper=5;
    in.lower=2;
    in.input=1;
	out.output=5;
	
    in.R=1;
	out.Cnt=0;
	
//MUT call
    MBD();
    printf("MUT call for test case number: %d \n",test_case );

//CHECK output
    if((out.BitField==5) && (out.output==5) && out.Cnt==0 ){
        printf("test number %d passed",test_case);
    }
    else {
        printf("test number %d failed",test_case);
    }

	return 0;
}
