#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define MAX_WINDOW_SIZE 100

#define MDATA_MAX_SIZE 1000

 

double getSinusWithNoise(double f[], int length, double length_period, double amplitude, double offset, double amplitude_noise)
{
    double f[length];
    double x = 0;

    double summe = 0;


    for(int i=0; i <length ; i++)

        f[i] = amplitude * sin(2*M_PI/length_period * i) + offset + (rand() % 100) * amplitude_noise/100;

    return 0;

}


double removeOffset(double f[], int length)

{
    double summe = 0;
    double offset = 0;

    for(int i=0; i < length; ++i)

        summe += f[i];

        offset = summe/length;

    for(int i=0; i < length; ++i)

    {

        f[i] -= offset;

    }
        
    return offset;

}

void calcMovingAveraging(double f[], int length)
{
    double f[999];
    double f1[999];
    double summe = 0;
    int n = 10;
    int j = 0;
    
    for(int i=0; i < 1000; i++) {
        
        f[i] = sin(((2 * M_PI) / 100) * i);
    }
    
    for(int i < 1000; i++) {
        
        for(j <= n; j++){
            
           f1[i] = f1[i] + f[j];
        }
        
        j++;
        n++;
    
    }
}

int main()
{
    double mdata[MDATA_MAX_SIZE];

    double offset = 0.0;


    getSinusWithNoise(mdata, MDATA_MAX_SIZE, 100, 2.0, 1.0, 0.0);

    offset = removeOffset(mdata, MDATA_MAX_SIZE);

  
    if (offset == 1.0)

               printf("HuHu\n");

    else

               printf("Offset-Differenz %3.2f\n", 1.0 - offset);

    calcMovingAveraging;

    return 0;
}
