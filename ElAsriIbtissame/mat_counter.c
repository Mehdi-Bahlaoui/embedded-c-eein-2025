#include <stdlib.h>
#include <stdbool.h> // Pour le type de donn�es bool�en
#include <stdio.h>   // Pour des fonctions d'impression d'exemple (peut �tre retir� en embarqu�)

// --- Variables d'�tat pour le mod�le de compteur ---
// La variable 't' interne du bloc de compteur/int�grateur.
// 'static' assure que sa valeur persiste entre les appels de la fonction.
static float t_internal_state = 0.0;
// La sortie du bloc 't = E ? t : DT : t' de l'�tape pr�c�dente,
// n�cessaire pour le feedback via le bloc '1/z'.
static float t_prev_output_for_feedback = 0.0;

/**
 * @brief Met � jour la logique du compteur.
 *
 * @param R          Signal de reset (bool�en). Si vrai, le compteur est remis � z�ro.
 * @param Cst        Constante de seuil pour le compteur.
 * @param DT         Pas d'incr�mentation du compteur.
 * @return float     La valeur actuelle du compteur (Cnt).
 */
float update_counter_model(bool R, float Cst, float DT) {
    float Cnt; // La sortie finale du compteur

    // --- Logique du bloc de Reset (g�r� par R) ---
    if (R) {
        // Si le signal R est actif, le compteur est remis � z�ro.
        t_internal_state = 0.0;
    } else {
        // --- Logique du bloc interne 't = E ? t : DT : t' ---
        // Le bloc prend la valeur de la sortie pr�c�dente (via 1/z) comme entr�e.
        float current_t_input = t_prev_output_for_feedback;

        // Condition 'E' pour l'incr�mentation: (t <= Cst)
        // Si la valeur actuelle est inf�rieure ou �gale au seuil, on l'incr�mente.
        if (current_t_input <= Cst) {
            t_internal_state = current_t_input + DT;
        } else {
            // Si la valeur d�passe le seuil, le diagramme montre un '0' entrant dans un switch
            // si la condition 't > Cst' est vraie. Cela peut signifier un reset ou un maintien.
            // Une interpr�tation courante pour un compteur discret est de le "bloquer" � Cst
            // ou de le remettre � z�ro s'il d�passe. Ici, je choisis le reset simple
            // si l'�tat actuel a d�j� d�pass� le Cst.
            if (t_internal_state > Cst) {
                 t_internal_state = 0.0; // Remise � z�ro si le seuil est d�pass�
            }
            // Sinon, il ne devrait pas s'incr�menter si d�j� � Cst (ou bloqu�).
            // Le diagramme est un peu ambigu sur le comportement exact apr�s d�passement sans reset R.
            // Pour l'instant, si non R et t > Cst, on le met � 0.
        }
    }

    // Mettre � jour la variable de feedback pour la prochaine it�ration.
    // La sortie du bloc interne 't = E ? ...' (qui est maintenant t_internal_state)
    // est celle qui sera utilis�e par le '1/z' � l'�tape suivante.
    t_prev_output_for_feedback = t_internal_state;

    // La sortie Cnt est la valeur actuelle de t_internal_state.
    Cnt = t_internal_state;

    return Cnt;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	return 0;
}
