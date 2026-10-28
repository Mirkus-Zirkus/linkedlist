
#include "ReglerHeader.h"

int zweipunkt_regler(double istZustand, double sollZustand, double epsilon, int aktuellerZustand) {
    if (istZustand < (sollZustand - epsilon)) {
        return 1; // AN
    }
    else if (istZustand > (sollZustand + epsilon)) {
        return 0; // Aus
    }
    return aktuellerZustand;
}