/*
 * File:   main.c
 * Author: jan
 *
 * Created on 18. März 2021, 13:36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// #define string  "Ich kenne mich nicht gut mit ABC aus, da ich das Programm zum Thema ABC nicht selbsständig gelöst habe!" // Geht nicht, da sich die Groesse des Strings aendert und, dadurch ein "Segmentation Fault" entsteht.
 #define search "ABC"
 #define string_replace  "Strings"
 #define delete_word "nicht"



int replace(char* str_source, char* str_search, char* str_replace)
{

 int laenge_source = strlen(str_source);
 int laenge_search = strlen(str_search);
 int laenge_replace = strlen(str_replace);
 char tmp_str[laenge_source];
 int zaehler = 0;
 
 do
 {
        int fundstelle = strstr(str_source, str_search) - str_source;

        strcpy(tmp_str, &str_source[fundstelle + laenge_search]);
        strcpy(&str_source[fundstelle], str_replace);
        strncpy(&str_source[(fundstelle + laenge_replace)], tmp_str, strlen(tmp_str));

        zaehler++;
 }while(strstr(str_source, str_search) != NULL);

 str_source [(laenge_source) + ((laenge_replace - laenge_search) * zaehler)] = '\0';
}



int delete(char* str_source, char* strc_delete)
{

 int laenge_source = strlen(str_source);
 int laenge_delete = strlen(strc_delete);
 char tmp_str[laenge_source];
 int zaehler = 0;
 
  do
  {
     int fundstelle = strstr(str_source, strc_delete) - str_source;

     strcpy(tmp_str, &str_source[fundstelle + laenge_delete]);
     strncpy(&str_source[fundstelle - 1], tmp_str, strlen(tmp_str));

     zaehler++;
  }while(strstr(str_source, strc_delete) != NULL);
  
  str_source [(laenge_source) - ((laenge_delete + 1) * zaehler)] = '\0';
}



int main ()
{
    char string[] = "Ich kenne mich nicht gut mit ABC aus, da ich das Programm zum Thema ABC nicht selbsständig gelöst habe!";
    printf("%s\n\n", string);
    replace(string, search, string_replace);
    printf("%s\n\n", string);
    delete(string, delete_word);
    printf("%s", string);

    return 0;
}

