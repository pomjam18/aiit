/* 
 * File:   main.c
 * Author: jan
 *
 * Created on 3. März 2021, 8:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_num_zahlen 10

int getOp(char *txt) 
{

 if(strcmp("+", txt) == 0) {
    return 1;
  } else if(strcmp("-", txt) == 0) {
    return 2; 
  } else if(strcmp("*", txt) == 0) {
    return 3;
  }else if(strcmp("/", txt) == 0) {
    return 4;
  } else{
    return 0;
  }
}

void calc(double num1, double num2, int op, double *result) 
{
    switch(op)
    {
        case 0:
            printf("\tFehler!!!\n");
            break;
        case 1:
            *result = num1 + num2;
            break;
        case 2:
            *result = num1 - num2;
            break;
        case 3:
            *result = num1 * num2;
            break;
        case 4:
            *result = num1 / num2;
            break;
    }  
}

int getLengthOfNumber(char *text) 
{
    int rv = 0;
    int merker = 0;
    int merker2 = 0;
   
    for (int i=0; i<10; i++) {
        if((text[i] >= '0' && text[i] <= '9' && merker < 1 && merker2 < 1) || (text[i] == '-' && i==0) || text[i] == '.') 
        {
            if(text[i] == '-') 
            {
                merker++;
            } else if(text[i] == '.') 
            {
                merker2++;
            }
            rv++;

        } else
            return rv;
    }
    return rv;
}

int parseText(char *text, int length, double *result) 
{
    double num1 = 0.0; 
    double num2 = 0.0;
    int offset = 0;
    int op = 0;
    int bracket_open = 0;  
    
    if(*text=='\0') {
        return -1;
    } else {
        op = getOp(text);
    }
    
    if(*text=='(') {
        bracket_open = 1;
        offset++;
    }
    
    if(text[offset] == '(') {
      offset = offset + parseText(text+offset, length - offset, result);
      return offset;
    }
    
    if(op==0) {
      if(sscanf(text+offset, "%lf", &num1) != 1) {
        return -1;
      }
      
      offset = offset + getLengthOfNumber(text + offset);
      op = getOp((text+offset)); 
      
    } else {
      num1 = *result;
    }
    
    if(op == 0) {
      return -1;
    }
    
    ++offset;
    
    if(text[offset]=='(') {
      offset = offset + parseText(text + offset, length - offset, &num2);
    } else {
      if(sscanf(text+offset, "%lf", &num2) == 1) {
          offset = offset + getLengthOfNumber(text+offset);
       } else {
        calc(num1, num2, op, result);
        return -1;  
       }
    }
    
    if((op < 3) && (text[offset] == '*' || text[offset] == '/') && (text[offset]!= ')')) {
      offset = offset + parseText(text + offset, length - offset, &num2); 
      calc(num1, num2, op, result);
    } else {
       calc(num1, num2, op, result);
    }
    
    if(text[offset]==')') {
      if(bracket_open == 0) {
        return offset;
      }
      offset=offset+1;
      
      if(*(text-1)=='*' || *(text-1)=='/') {
        return offset;
      }
    }
    
    if(text[offset]==')') {
      return offset;
    }
    return offset + parseText(text + offset, length - offset, result);
}


int main (int argc, char** argv)
{
  double ergebnis;

  
  parseText(argv[1], strlen(argv[1]),  &ergebnis);
  printf("\tErgebnis: %.2lf\n\n", ergebnis);  
  
  return 0;
}
