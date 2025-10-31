#include <math.h>    // Pour fmaxf et fminf (fonctions de max/min pour float)
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut être retiré en embarqué)

// --- Variable d'état pour le modèle de saturation ---
// Stocke la sortie de la fonction de saturation de l'étape précédente.
// C'est l'équivalent du bloc '1/z' dans la boucle de feedback.
static float prev_output_from_saturation = 0.0;

/**
 * @brief Applique une saturation (limitation) avec un feedback de la sortie précédente.
 *
 * La valeur à saturer est (current_input + prev_output), puis elle est limitée
 * entre lower et upper. La sortie limitée est ensuite renvoyée et stockée
 * pour la prochaine itération.
 *
 * @param input      L'entrée actuelle du système.
 * @param upper      La limite supérieure pour la saturation.
 * @param lower      La limite inférieure pour la saturation.
 * @return float     La valeur de sortie saturée.
 */
float update_saturation_model(float input, float upper, float lower) {
    float output; // La sortie finale saturée

    // --- Logique du bloc d'addition ---
    // La valeur à saturer est la somme de l'entrée actuelle et de la sortie précédente
    // (qui vient du bloc '1/z' du feedback).
    float value_to_saturate = input + prev_output_from_saturation;

    // --- Logique de saturation (comparaisons et switches) ---
    // Cette partie est équivalente à un bloc de saturation simple.
    // 1. Appliquer la limite supérieure
    if (value_to_saturate > upper) {
        output = upper;
    }
    // 2. Appliquer la limite inférieure
    else if (value_to_saturate < lower) {
        output = lower;
    }
    // 3. Si la valeur est entre les limites, elle n'est pas modifiée.
    else {
        output = value_to_saturate;
    }

    // --- Mise à jour de la variable de feedback (bloc 1/z) ---
    // La sortie calculée de cette étape devient la 'sortie précédente' pour la prochaine.
    prev_output_from_saturation = output;

    return output;
}

