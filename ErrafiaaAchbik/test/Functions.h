#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef unsigned char G_UChar_t;
typedef unsigned int G_UInt_t;
typedef int G_Int_t;
typedef short G_Short_t;

/* ==================== Variables pour BitField ==================== */

extern G_Short_t b0;
extern G_Short_t b1;
extern G_Short_t b2;
extern G_Short_t BitField;

/* ==================== Variables pour Counter ==================== */

extern G_UChar_t R;
extern G_UChar_t cst;
extern G_UChar_t cnt;

/* ==================== Variables pour Saturator ==================== */

extern G_Int_t input;
extern G_UInt_t lower;
extern G_UInt_t upper;
extern G_UInt_t output;


extern void all(void);


#endif /* FUNCTIONS_H */
