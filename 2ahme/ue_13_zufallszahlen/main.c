
 #include <stdlib.h>
 #include <time.h>

int intRandom (int min, int max) {
    int rv;
    // ....
     return rv;
 }
 
 int main () {
     
     srand(time(NULL));
     
     // meist 2147483647 (=2^31-1), bei Windows manchmal auch 32767
     printf("Zufallszahlen 0 .. %d\n", RAND_MAX);
     
     // rand() -> liefert Zufalls-Ganzzahl im Bereich 0 .. RAND_MAX
     printf("1:");
     for (int i = 0; i < 5; i++) {
         printf("  %d", rand());
     }
     printf("\n");
     
     // 0 .. RANDMAX -> 0 .. 100
     // Modulo Operator %, 104 / 101 = 1, 104 % 101 = 3
     printf("2:");
     for (int i = 0; i < 5; i++) {
         printf("  %d", rand() % 101 );
     }
     printf("\n");
     
     // 0 .. RANDMAX -> 1 .. 6 (Wuerfel)
     // rand() % 6 -> 0 .. 5 -> +1 -> 1 .. 6
     printf("3:");
     for (int i = 0; i < 20; i++) {
         printf("  %d", rand() % 6 + 1 );
     }
     printf("\n");
     
     // -1000 .. + 1000 -> 0 .. 2000 -> % 2001
     printf("4:");
     for (int i = 0; i < 5; i++) {
         printf("  %d", rand() % 2001 - 1000 );
     }
     printf("\n");
     
     // ---------------------------------------------------
     
     // 0.0 ... 1.0
     printf("5:");
     for (int i = 0; i < 6; i++) {
         printf("  %f", 1.0 * rand() / RAND_MAX );
     }
     printf("\n");
     
     // -100.0 ... +100.0 -> + 100 -> 0.0 ... +200.0 -> / 200 -> 0 .. 1.0
     printf("6:");
     for (int i = 0; i < 100; i++) {
         printf("  %f\n", 200.0 * rand() / RAND_MAX - 100.0 );
     }
     printf("\n");
     
    return 0;
 }