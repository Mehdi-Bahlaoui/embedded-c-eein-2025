#include <stdbool.h>

int BitField(bool b0, bool b1, bool b2) {
    int bitfield = (b0 ? 1 : 0)
                 + (b1 ? 2 : 0)
                 + (b2 ? 4 : 0);
    return bitfield;
}
