#include <math.h>    // Pour fmaxf et fminf (fonctions de max/min pour float)
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut �tre retir� en embarqu�)

// --- Variable d'�tat pour le mod�le de saturation ---
// Stocke la sortie de la fonction de saturation de l'�tape pr�c�dente.
// C'est l'�quivalent du bloc '1/z' dans la boucle de feedback.
static float prev_output_from_saturation = 0.0;

/**
 * @brief Applique une saturation (limitation) avec un feedback de la sortie pr�c�dente.
 *
 * La valeur � saturer est (current_input + prev_output), puis elle est limit�e
 * entre lower et upper. La sortie limit�e est ensuite renvoy�e et stock�e
 * pour la prochaine it�ration.
 *
 * @param input      L'entr�e actuelle du syst�me.
 * @param upper      La limite sup�rieure pour la saturation.
 * @param lower      La limite inf�rieure pour la saturation.
 * @return float     La valeur de sortie satur�e.
 */
float update_saturation_model(float input, float upper, float lower) {
    float output; // La sortie finale satur�e

    // --- Logique du bloc d'addition ---
    // La valeur � saturer est la somme de l'entr�e actuelle et de la sortie pr�c�dente
    // (qui vient du bloc '1/z' du feedback).
    float value_to_saturate = input + prev_output_from_saturation;

    // --- Logique de saturation (comparaisons et switches) ---
    // Cette partie est �quivalente � un bloc de saturation simple.
    // 1. Appliquer la limite sup�rieure
    if (value_to_saturate > upper) {
        output = upper;
    }
    // 2. Appliquer la limite inf�rieure
    else if (value_to_saturate < lower) {
        output = lower;
    }
    // 3. Si la valeur est entre les limites, elle n'est pas modifi�e.
    else {
        output = value_to_saturate;
    }

    // --- Mise � jour de la variable de feedback (bloc 1/z) ---
    // La sortie calcul�e de cette �tape devient la 'sortie pr�c�dente' pour la prochaine.
    prev_output_from_saturation = output;

    return output;
}

