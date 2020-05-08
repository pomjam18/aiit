
#include <stdio.h>
#include <stdlib.h>


int wandleDreieckInStern(double rab, double rac, double rbc, double *pra, double *prb, double *prc) {
  
  double pruefe = rac + rab + rbc;
    
  if (pra != NULL && prb != NULL && prc != NULL && pruefe > 0 && rac >0 && rab > 0 && rbc > 0) {
 
      *pra = (rac * rab) / pruefe;
      *prb = (rab * rbc) / pruefe;
      *prc = (rac * rbc) / pruefe;
      
      return 0;
  
  }else {
      
      return 1;
  } 
}

int wandleSternInDreieck(double ra, double rb, double rc, double *prab, double *prac, double *prbc) {

  if (prac != NULL && prab != NULL && prbc != NULL && rb > 0 && rc > 0 && ra > 0) {
     
     *prac = ((ra * rb) + (rb * rc) + (rc * ra)) / rb;
     *prab = ((ra * rb) + (rb + rc) + (rc * ra)) / rc;
     *prbc = ((ra * rb) + (rb * rc) + (rc * ra)) / ra;
     
     return 0;
     
  }else {
    
     return 1;
  }

}

int main ()
{
  int rv;
  double ra, rb, rc;
  double rab, rac, rbc;
  double raT, rbT, rcT;
  
  // Test 1: wandleDreieckInStern
  
  rab = 1;
  while (rab <= 2) {  
  	rac =2 ,rbc =3;
  	rv = wandleDreieckInStern(rab, rac, rbc, &ra, &rb, &rc);
  
  	raT = (rac * rab) / (rac + rab + rbc);
  	rbT = (rab * rbc) / (rac + rab + rbc);
  	rcT = (rac * rbc) / (rac + rab + rbc);
  
  	const double eps = 1E-10;
  	if (abs (ra - raT ) <= eps) {
  		printf("ra OK ");
  	} else {
  		printf("Fehler ra");
  	}
  
   	if (abs (rb - rbT) <= eps) {
  		printf("rb OK ");
  	} else {
  		printf("Fehler rb");
  	}
  
  	if (abs (rc - rcT) <= eps) {
  		printf("rc OK ");
  	} else {
  		printf("Fehler rc");
  	}
  
  	if (rv != 0) {
    	printf("Test 1: Fehler rv = %d\n", rv);
  	} else {
    
    	printf("rab=%lf, rac=%lf, rbc=%lf -> ra=%lf, rb=%lf, rc=%lf\n",
           rab, rac, rbc, ra, rb, rc);
  	}
  	rab++;
  }
  return 0;
}

