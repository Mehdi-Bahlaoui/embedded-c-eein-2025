#include <stdbool.h>

double Counter(bool R, double Cst, double DT) {
    static double t_prev = 0.0; // Memory (1/z block)
    double t_next;

    if (R) {
        t_next = 0.0; // Reset
    } else if (Cst > 1.0) {
        t_next = t_prev + DT; // Increment
    } else {
        t_next = t_prev; // Hold
    }

    t_prev = t_next; // Update state
    return t_next;   // Output = Cnt
}
