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
    return 10;
  } else if(strcmp("-", txt) == 0) {
    return 20; 
  } else if(strcmp("*", txt) == 0) {
    return 30;
  }else if(strcmp("/", txt) == 0) {
    return 40;
  } else{
    return 100;
  }
}

void calc(double num1, double num2, int op, double *result) 
{
    switch(op)
    {
        case 100:
            printf("\tFehler!!!\n");
            break;
        case 10:
            *result = num1 + num2;
            break;
        case 20:
            *result = num1 - num2;
            break;
        case 30:
            *result = num1 * num2;
            break;
        case 40:
            *result = num1 / num2;
            break;
    }  
}

int getLengthOfNumber(char *text) 
{
    int rv = 0;
    double test = 0.0;
   
    for (int i=0; i<10; i++) {
        if((sscanf(text, "%lf", &test)) == 1) 
        {
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
  double result;
  //int rv;
  
  int rv = parseText(*argv, argc, &result);
  printf("\tErgebnis: %.2lf \nRv: %d\n", result, rv);
  //rv = getOp('+');
  
  return 0;
}
