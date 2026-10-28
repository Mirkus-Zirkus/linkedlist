#include <stdio.h>
#include "ReglerHeader.h"

int main() {
    double istZustand = 18.0;
    double sollZustand = 20.0;
    double abkühlungsRate = 0.5;
    double epsilon = 1;
    __uint8_t aktuellerZustand = 1;
    __uint64_t schritte = 100;

    printf("=== Einfache Temperatur-Simulation (Ohne Regler) ===\n");
    printf("Soll-Zustand: %.1f °C\n", sollZustand);
    printf("--------------------------------------------------\n");
    printf(" Zeitschritt |  Ist-Zustand\n");
    printf("--------------------------------------------------\n");

    for (__uint64_t t = 0; t < schritte; t++) {
        aktuellerZustand = zweipunkt_regler(istZustand, sollZustand, epsilon, aktuellerZustand);

        printf("     %2d      |   %5.2f °C  |    %3s\n", t, istZustand, (aktuellerZustand == 1) ? "AN" : "AUS");

        if (aktuellerZustand == 1) {
            istZustand += abkühlungsRate;
        } else {
            istZustand -= (abkühlungsRate / 2.0);
        }
    }

    return 0;
}