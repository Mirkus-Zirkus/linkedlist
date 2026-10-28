#include <stdio.h>
#include "ReglerHeader.h"

int main() {
    double istZustand = 18.0;
    double sollZustand = 20.0;
    double abkuehlungsRate = 0.5;
    double epsilon = 1;
    __uint8_t aktuellerZustand = 1;
    __uint64_t schritte = 100;

    printf("=== Einfache Temperatur-Simulation (Ohne Regler) ===\n");
    printf("Soll-Zustand: %.1f °C\n", sollZustand);
    printf("--------------------------------------------------\n");
    printf(" Zeitschritt |  Ist-Zustand\n");
    printf("--------------------------------------------------\n");

    FILE *fp = fopen("/home/mirko/Desktop/temperatur_simulation.csv", "w");
    if (fp == NULL) {
        perror("Fehler beim Öffnen der Datei");
        return 1;
    }

    for (int t = 0; t <= 20; t++) {
        aktuellerZustand = zweipunkt_regler(istZustand, sollZustand, epsilon, aktuellerZustand);

        fprintf(fp, "%d;%.2f;%.2f;%s\n", t, istZustand, sollZustand, (aktuellerZustand == 1) ? "AN" : "AUS");
        printf("Zeitschritt %2d | Ist: %5.2f °C | Status: %s\n", t, istZustand, (aktuellerZustand == 1) ? "AN" : "AUS");

        if (aktuellerZustand == 1) {
            istZustand += abkuehlungsRate;
        } else {
            istZustand -= (abkuehlungsRate / 2.0);
        }
    }
    fclose(fp);

    return 0;
}