#include <stdio.h>

int main() {

    char s[100]; //Defienieren eines character Feldes
    double z1;   //Zahl1
    double z2;   //Zahl2
    double add;
    double sub;
    double mul;
    double div;

    printf("UE3 Taschenrechner\n");
    printf("------------------\n\n");

    printf("  Zahl1: ");
    fgets(s, 100, stdin); // stdin -> standart input -> Tastatur
    printf("\n %s\n", s);

    sscanf(s, "%lf", &z1);
    printf("z1=%f\n", z1);
    printf(" \n\n");

    printf(" Zahl2: ");
    fgets(s, 100, stdin);
    printf("\n %s\n", s);

    sscanf(s, "%lf", &z2);
    printf("z2=%f\n", z2);

    return 0;
}
