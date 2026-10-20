#include <stdio.h>
#include <stdint.h>

void print_bits16(uint16_t val) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i == 8) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    uint16_t A = 0;
    uint16_t B = 0;
    int wahl = 0;

    do {
        printf("\n----------------------------------------\n");
        printf("A  Hex: %04X\n", A);
        printf("Bits: ");
        print_bits16(A);
        printf("B  Hex: %04X\n", B);
        printf("Bits: ");
        print_bits16(B);
        printf("----------------------------------------\n");

        printf("1  A eingeben (Hex)\n");
        printf("2  B eingeben (Hex)\n");
        printf("3  A = A + B\n");
        printf("4  A UND B\n");
        printf("5  A OR B\n");
        printf("6  A XOR B\n");
        printf("0  Ende\n");
        printf("Deine Wahl: ");

        if (scanf("%d", &wahl) != 1) {
            printf("Fehler: Bitte eine gültige Zahl eingeben!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (wahl) {
            case 1:
                printf("Neue Hexzahl für A eingeben: ");
                if (scanf("%hx", &A) != 1) {
                    printf("Ungültige Hexadezimalzahl!\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                printf("Neue Hexzahl für B eingeben: ");
                if (scanf("%hx", &B) != 1) {
                    printf("Ungültige Hexadezimalzahl!\n");
                    while (getchar() != '\n');
                }
                break;

            case 3:
                A = A + B;
                break;

            case 4:
                A = A & B;
                break;

            case 5:
                A = A || B;
                break;

            case 6:
                A = A ^ B;
                break;

            case 0:
                printf("Programm wird beendet.\n");
                break;

            default:
                printf("Falscher Menüpunkt! Bitte einen gültigen Menüpunkt wählen.\n");

        }

    } while (wahl != 0);

    return 0;
}
