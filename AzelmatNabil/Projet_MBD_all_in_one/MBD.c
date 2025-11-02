#include "MBD_all.h"

void MBD(void) {

    const unsigned char Cst = 2;
    unsigned char prev_Cnt_val = out.Cnt;
    unsigned char next_Cnt;

    if (in.R == 1) {
        next_Cnt = 0;
    } else {
        if (Cst > prev_Cnt_val) {
            next_Cnt = prev_Cnt_val + 1;
        } else {
            next_Cnt = prev_Cnt_val;
        }
    }
    
    out.BitField = (in.b0 * 1) + (in.b1 * 2) + (in.b2 * 4); //  le decalage (somme ponderée) est remplaçé par la multipication par poids
 
    unsigned int prev_output_val = out.output;
    int sum; 

    sum = in.input + (int)prev_output_val; 

    if (sum > (int)in.upper) { 
        out.output = in.upper;
    } else if (sum < (int)in.lower) {
        out.output = in.lower;
    } else {
        out.output = (unsigned int)sum; 
    }
    
    out.Cnt = next_Cnt;
}
