#include <stdbool.h> // Pour le type de donn�es bool�en (si les bits sont trait�s comme bool�ens)
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut �tre retir� en embarqu�)
/**
 * @brief Calcule une valeur BitField � partir de trois entr�es binaires.
 *
 * @param b0         Bit 0 (poids 1). Attendu 0 ou 1.
 * @param b1         Bit 1 (poids 2). Attendu 0 ou 1.
 * @param b2         Bit 2 (poids 4). Attendu 0 ou 1.
 * @return int       La valeur enti�re du BitField.
 */
int calculate_bitfield_model(bool b0, bool b1, bool b2) {
    int BitField_output; // La sortie finale du BitField

    // --- Logique de multiplication ---
    // Multiplie chaque bit par son poids correspondant.
    int term_b0 = (int)b0 * 1; // Le (int)b0 convertit true en 1, false en 0
    int term_b1 = (int)b1 * 2;
    int term_b2 = (int)b2 * 4;

    // --- Logique de sommation ---
    // Additionne les r�sultats des multiplications.
    BitField_output = term_b0 + term_b1 + term_b2;

    return BitField_output;
}




