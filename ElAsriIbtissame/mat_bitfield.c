#include <stdbool.h> // Pour le type de données booléen (si les bits sont traités comme booléens)
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut être retiré en embarqué)
/**
 * @brief Calcule une valeur BitField à partir de trois entrées binaires.
 *
 * @param b0         Bit 0 (poids 1). Attendu 0 ou 1.
 * @param b1         Bit 1 (poids 2). Attendu 0 ou 1.
 * @param b2         Bit 2 (poids 4). Attendu 0 ou 1.
 * @return int       La valeur entière du BitField.
 */
int calculate_bitfield_model(bool b0, bool b1, bool b2) {
    int BitField_output; // La sortie finale du BitField

    // --- Logique de multiplication ---
    // Multiplie chaque bit par son poids correspondant.
    int term_b0 = (int)b0 * 1; // Le (int)b0 convertit true en 1, false en 0
    int term_b1 = (int)b1 * 2;
    int term_b2 = (int)b2 * 4;

    // --- Logique de sommation ---
    // Additionne les résultats des multiplications.
    BitField_output = term_b0 + term_b1 + term_b2;

    return BitField_output;
}




