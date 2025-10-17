double LimitWithHysteresis(double input, double lower, double upper) {
    static double prev_output = 0.0; // Memory block

    double output = input;

    if (input > upper)
        output = upper;
    else if (input < lower)
        output = lower;

    prev_output = output;
    return output;
}
