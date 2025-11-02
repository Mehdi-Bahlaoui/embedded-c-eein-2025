typedef struct OUTPORT
{
    short BitField;
    unsigned int output;
    unsigned char Cnt;
} OUT;


typedef struct INPORT
{
    short b0,b1,b2;
    unsigned int upper,lower;
    int input;
    unsigned char R;
} IN;


extern void MBD(void);

extern OUT out ;
extern IN in;


void MBD(void){

    int DT=1;
    const int cst=2;
    static int t;
//block1

    out.BitField = in.b0+(in.b1<<1)+(in.b2<<2);

//block2
    switch(in.R)
	{
        case 0: if (cst>out.Cnt){
           			t+=DT;
            		out.Cnt=t;
        		};break;
        case 1: out.Cnt = 0;break;
    }

//block3
    out.output += in.input;

    if ((!(in.upper >= out.output)) || (!(out.output >= in.lower))) {
        if (out.output >= in.lower) {
        out.output = in.upper;
        } 
        else {
            out.output = in.lower;
        }
    }
}


