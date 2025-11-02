/****************************************************************************/
/*                        Abdelmajid Ouahki                                 */
/*               Travail encadré par Mr. M.Najoui                           */
/****************************************************************************/


#include <stdio.h>
#include <math.h>


const  unsigned char Cst = 2;
unsigned char DT = 1.0;
unsigned int output;
short BitField;
unsigned char Cnt = 0, t = 0;
short b0, b1, b2, BitField;
unsigned char R;
unsigned int upper;
unsigned int lower;
int input;
void MBD(void);


int main(int argc, char *argv[])
{
	/*------------------------ Cas de test 1. -------------------------------*/
	/* Here we are testing the first decision (sum <= upper && sum >= lower) */
	/* so the result should be (output = sum)                                */

	input = 0;
	output = 0;
	upper = 0;
	lower = 0;
	b0 = 0;
	b1 = 0;
	b2 = 0;
	R = 0;
	BitField = 0;
	
	// call  MUT
	
	MBD();
	
	// Verification.
	
	if((BitField == 0) && (output == 0) && (Cnt == 1)){
		printf("CT1 passed :)\n");
	}
	else {
		printf("CT1 failed :(\n");

	}
	
	
	/*------------------------ Cas de test 2. -------------------------------*/
	/* Here we are testing the second decision (sum > upper)                 */
	/* so the result should be (output = upper)                              */
	
	input = 2;
	output = 1;
	upper = 2;
	lower = 1;
	b0 = 1;
	b1 = 0;
	b2 = 0;
	R = 0;
	BitField = 1;
	
	// call MUT
	
	MBD();
		
	// Verification.
	
	if((BitField == 1) && (output == 2) && (Cnt == 2)){
		printf("CT2 passed :)\n");
	}
	else {
		printf("CT2 failed :(\n");

	}
	/*------------------------ Cas de test 3. -------------------------------*/
	/* Here we are testing the first decision (other value) */
	/* so the result should be (output = lower)                              */
	
	input = 0;
	output = 1;
	upper = 3;
	lower = 2;
	b0 = 1;
	b1 = 1;
	b2 = 0;
	R = 0;
	BitField = 1;
	
	// call de MUT
	
	MBD();
		
	// Verification.
	
	if((BitField == 3) && (output == 2) && (Cnt == 2)){
		printf("CT3 passed :)\n");
	}
	else {
		printf("CT3 failed :(\n");

	}
	
	/*------------------------ Cas de test 4. --------------------------------------*/
	/* Here we are testing the Timer by giving to R one as value and see the output */
	/* so the result should be (Cnt = 0), so the program gives true responses       */	
	
	input = 0;
	output = 0;
	upper = 0;
	lower = 0;
	b0 = 1;
	b1 = 1;
	b2 = 1;
	R = 1;
	BitField = 1;

	
	// call de MUT
	
	MBD();
		
	// Verification.
	
	if((BitField == 7) && (output == 0) && (Cnt == 0)){
		printf("CT4 passed :)\n");
	}
	else {
		printf("CT4 failed :(\n");

	}
	
	return 0;
}


void MBD(void){
	
	unsigned int sum;
	
	sum = output + input;
	
	if(sum <= upper && sum >= lower) output = sum;
	else if(sum > upper) output = upper;
	else output = lower;
	
	BitField = b0 + (b1 << 1) + (b2 << 2);
	
	switch(R){
	case 0: if(Cst > Cnt){
		t+=DT;
		Cnt = t;
	}
	break;
	case 1: Cnt = 0;
	break;
	}
}
