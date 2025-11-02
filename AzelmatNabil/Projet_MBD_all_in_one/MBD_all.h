#ifndef MBD_ALL_H
#define MBD_ALL_H

typedef struct {
    short b0;
    short b1;
    short b2;
    unsigned int upper;
    unsigned int lower;
    unsigned int input;
    unsigned char R;
} IN;

typedef struct {
    short BitField;
    unsigned int output;
    unsigned char Cnt;
} OUT;

extern IN in;
extern OUT out;

void MBD(void);

#endif /* MBD_ALL_H */
