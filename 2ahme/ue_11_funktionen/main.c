#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getInputIntegerValue(char text[])
{
    int rv;
    int n;
    char s[100];

    do{
       printf("%s", text);
        fgets(s, 100, stdin);
        n = sscanf(s, "%d", &rv);

    } while (n != 1);

    return rv;
}

double getInputDoubleValue(char text[])
{
    double rv;
    int n;
    char s[100];

    do{
        printf("%s", text);
        fgets(s, 100, stdin);
        n = sscanf(s, "%lf", &rv);

    } while (n != 1);

    return rv;
}

int getSelectedMenu()
{
    int rv;

    do{
        printf("===============\n  1...Wuerfel\n  2...Quader\n  3...Kugel\n  4...Programm beenden\n");
       rv = getInputIntegerValue("Auswahl (1-4)");

    } while(rv < 1 || rv > 4);

    return rv;
}

void calcCube()
{
    double laenge;
    double volumen;
    double oberflaeche;

    printf("\n  Würfel:");

    do{
       laenge = getInputDoubleValue("Laenge: ");
    
    } while (laenge < 0);

    volumen = laenge * laenge * laenge;
    oberflaeche = 6 * laenge * laenge;

    printf("Volumen: %.2lf\n", volumen);
    printf("Oberflaeche: %.2lf\n", oberflaeche);
}

void calcCuboid()
{
    double laenge;
    double breite;
    double hoehe;
    double volumen;
    double oberflaeche;

    do{
       laenge = getInputDoubleValue("Laenge: ");
    
    } while (laenge < 0);

    do{
       breite = getInputDoubleValue("Breite: ");
    
    } while (breite < 0);

    do{
       hoehe = getInputDoubleValue("Hoehe: ");
    
    } while (hoehe < 0);

    volumen = laenge * breite * hoehe;
    oberflaeche = 2 * laenge * breite + 2 * laenge * hoehe + 2 * breite * hoehe;

    printf("Volumen: %.2lf\n", volumen);
    printf("Oberflaeche: %.2lf\n", oberflaeche);
}

void calcSphere()
{
    double durchmesser;
    double oberflaeche;
    double volumen;

    do{
       durchmesser = getInputDoubleValue("Durchmesser: ");
    
    } while (durchmesser < 0);

    oberflaeche = 4 * M_PI * ((durchmesser / 2) * (durchmesser / 2));
    volumen = (4 / 3) * M_PI * ((durchmesser / 2) * (durchmesser / 2) * (durchmesser/2));

    printf("Volumen: %.2lf\n", volumen);
    printf("Oberflaeche: %.2lf\n", oberflaeche);
}

int main()
{
    int auswahl = getSelectedMenu();

    switch(auswahl) {

     case 1: calcCube(); break;
     case 2: calcCuboid(); break;
     case 3: calcSphere(); break;
     case 4: return 0;

    }
}