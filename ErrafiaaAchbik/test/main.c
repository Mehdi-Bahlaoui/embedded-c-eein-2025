#include <stdio.h>
#include "Functions.h"

/* ===== Déclaration des variables globales ===== */
/* BitField */
G_Short_t b0 = 0;
G_Short_t b1 = 0;
G_Short_t b2 = 0;
G_Short_t BitField = 0;

/* Counter */
G_UChar_t R = 0;
G_UChar_t cst = 2;
G_UChar_t cnt = 0;

/* Saturator */
G_Int_t input = 0;
G_UInt_t lower = 0;
G_UInt_t upper = 0;
G_UInt_t output = 0;

/* ===== Programme principal ===== */
int main(void)
{
    /* ---------- Test de Compute_BitField ---------- */
    all();


    /* ---------- Vérification du test ---------- */
    if (BitField == 0 && cnt == 1 && output == 0)
        printf("Test valide ");
    else
        printf("Test non valide ");

    return 0;
}

