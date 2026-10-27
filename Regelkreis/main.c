#include <stdio.h>
#include "ReglerHeader.h"

int main() {
    double istZustand = 22.0;
    double sollZustand = 20.0;
    double abkühlungsRate = 0.5;
    double epsilon = 1;
    int aktuellerZustand = 1;

    printf("=== Einfache Temperatur-Simulation (Ohne Regler) ===\n");
    printf("Soll-Zustand: %.1f °C\n", sollZustand);
    printf("--------------------------------------------------\n");
    printf(" Zeitschritt |  Ist-Zustand\n");
    printf("--------------------------------------------------\n");

    for (int t = 0; t < 10; t++) {
        printf("     %2d      |   %5.2f °C\n", t, istZustand);
        if (zweipunktregler(istZustand, sollZustand, epsilon, aktuellerZustand)==1) {

        }
    }

    return 0;
}