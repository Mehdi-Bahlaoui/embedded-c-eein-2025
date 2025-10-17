#include <stdlib.h>
#include <stdbool.h> // Pour le type de données booléen
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut être retiré en embarqué)

// --- Variables d'état pour le modèle de compteur ---
// La variable 't' interne du bloc de compteur/intégrateur.
// 'static' assure que sa valeur persiste entre les appels de la fonction.
static float t_internal_state = 0.0;
// La sortie du bloc 't = E ? t : DT : t' de l'étape précédente,
// nécessaire pour le feedback via le bloc '1/z'.
static float t_prev_output_for_feedback = 0.0;

/**
 * @brief Met à jour la logique du compteur.
 *
 * @param R          Signal de reset (booléen). Si vrai, le compteur est remis à zéro.
 * @param Cst        Constante de seuil pour le compteur.
 * @param DT         Pas d'incrémentation du compteur.
 * @return float     La valeur actuelle du compteur (Cnt).
 */
float update_counter_model(bool R, float Cst, float DT) {
    float Cnt; // La sortie finale du compteur

    // --- Logique du bloc de Reset (géré par R) ---
    if (R) {
        // Si le signal R est actif, le compteur est remis à zéro.
        t_internal_state = 0.0;
    } else {
        // --- Logique du bloc interne 't = E ? t : DT : t' ---
        // Le bloc prend la valeur de la sortie précédente (via 1/z) comme entrée.
        float current_t_input = t_prev_output_for_feedback;

        // Condition 'E' pour l'incrémentation: (t <= Cst)
        // Si la valeur actuelle est inférieure ou égale au seuil, on l'incrémente.
        if (current_t_input <= Cst) {
            t_internal_state = current_t_input + DT;
        } else {
            // Si la valeur dépasse le seuil, le diagramme montre un '0' entrant dans un switch
            // si la condition 't > Cst' est vraie. Cela peut signifier un reset ou un maintien.
            // Une interprétation courante pour un compteur discret est de le "bloquer" à Cst
            // ou de le remettre à zéro s'il dépasse. Ici, je choisis le reset simple
            // si l'état actuel a déjà dépassé le Cst.
            if (t_internal_state > Cst) {
                 t_internal_state = 0.0; // Remise à zéro si le seuil est dépassé
            }
            // Sinon, il ne devrait pas s'incrémenter si déjà à Cst (ou bloqué).
            // Le diagramme est un peu ambigu sur le comportement exact après dépassement sans reset R.
            // Pour l'instant, si non R et t > Cst, on le met à 0.
        }
    }

    // Mettre à jour la variable de feedback pour la prochaine itération.
    // La sortie du bloc interne 't = E ? ...' (qui est maintenant t_internal_state)
    // est celle qui sera utilisée par le '1/z' à l'étape suivante.
    t_prev_output_for_feedback = t_internal_state;

    // La sortie Cnt est la valeur actuelle de t_internal_state.
    Cnt = t_internal_state;

    return Cnt;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
