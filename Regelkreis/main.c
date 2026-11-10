#include <stdio.h>
#include "ReglerHeader.h"

int main() {
    double istZustand = 18.0;
    double sollZustand = 20.0;
    double heizLeistung = 0.75;    // Erwärmung pro Schritt bei 100 % Stellgröße
    double abkuehlungsRate = 0.25; // Wärmeverlust pro Schritt

    double epsilon = 1.0;
    int aktuellerZustand = 1;

    PIDRegler pid;
    pid_init(&pid, 0.5, 0.1, 0.1, 1.0, 0.0, 1.0); /* Kp, Ki, Kd, dt, min, max */

    int auswahl = 0;
    printf("Welchen Regler moechtest du verwenden?\n");
    printf("  1 = Zweipunkt-Regler\n");
    printf("  2 = PID-Regler\n");
    printf("Auswahl: ");
    if (scanf("%d", &auswahl) != 1 || (auswahl != 1 && auswahl != 2)) {
        fprintf(stderr, "Ungueltige Auswahl.\n");
        return 1;
    }

    const char *reglerName = (auswahl == 1) ? "Zweipunkt-Regler" : "PID-Regler";

    printf("\n=== Temperatur-Simulation (%s) ===\n", reglerName);
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
        double stellgroesse;

        if (auswahl == 1) {
            aktuellerZustand = zweipunkt_regler(istZustand, sollZustand, epsilon, aktuellerZustand);
            stellgroesse = (aktuellerZustand == 1) ? 1.0 : 0.0;
        } else {
            stellgroesse = pid_berechne(&pid, istZustand, sollZustand);
        }

        fprintf(fp, "%d;%.2f;%.2f;%.2f\n", t, istZustand, sollZustand, stellgroesse);
        printf("Zeitschritt %2d | Ist: %5.2f °C | Stellgröße: %4.0f %%\n",
               t, istZustand, stellgroesse * 100.0);

        istZustand += stellgroesse * heizLeistung - abkuehlungsRate;
    }
    fclose(fp);

    return 0;
}