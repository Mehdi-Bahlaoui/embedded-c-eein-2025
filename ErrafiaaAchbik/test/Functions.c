#define FUNCTIONS_C

#include "Functions.h"

void all(void)
{
   
   /* Compute total output: BitField = b0*1 + b1*2 + b2*4 */
   BitField = b0 + (b1<<1) + (b2<<2);




   /* Variable statique pour garder la valeur entre les appels */
   static G_UChar_t t = 0;
   
   
   switch(R){case 0: if (cst>cnt){
   							t+=1;
   							cnt=t;
   						};break;
   			case 1 : cnt=0;break;	  }






   /* 1. Si input est inférieur à la limite basse */
   if (input < (G_Int_t)lower)
   {
      output = lower;  /* Saturation basse */
   }
   /* 2. Si input est supérieur à la limite haute */
   else if (input > (G_Int_t)upper)
   {
      output = upper;  /* Saturation haute */
   }
   /* 3. Sinon, input est dans la plage acceptable */
   else
   {
      output = (G_UInt_t)input;  /* Valeur non modifiée (cast pour éviter warning) */
   }
}
/* ------------------------------ End of file ------------------------------ */
