#include <stdio.h>
#include "Functions.h"

/* ===== Déclaration des variables globales ===== */
/* BitField */
G_Short_t b0 = 1;
G_Short_t b1 = 1;
G_Short_t b2 = 1;
G_Short_t BitField = 0;

/* Counter */
G_UChar_t R = 1;
G_UChar_t cst = 2;
G_UChar_t cnt = 4;

/* Saturator */
G_Int_t input = 200;
G_UInt_t lower = 20;
G_UInt_t upper = 100;
G_UInt_t output = 0;

/* ===== Programme principal ===== */
int main(void)
{
    /* ---------- Test de Compute_BitField ---------- */
    all();


    /* ---------- Vérification du test ---------- */
    if (BitField == 7 && cnt == 0 && output == 100)
        printf("Test valide ");
    else
        printf("Test non valide ");

    return 0;
}

