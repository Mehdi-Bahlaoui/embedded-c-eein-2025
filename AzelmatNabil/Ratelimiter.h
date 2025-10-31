#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int32_t previous_output;
} RateLimiterState;

int32_t rateLimiter(int32_t input, int32_t upper_rate_limit, int32_t lower_rate_limit, RateLimiterState* S) {
    
    int32_t difference = input - S->previous_output;

    if (difference > upper_rate_limit) {
        difference = upper_rate_limit;
    } else if (difference < lower_rate_limit) {
        difference = lower_rate_limit;
    }

    int32_t new_output = S->previous_output + difference;

    S->previous_output = new_output;

    return new_output;
}