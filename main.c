#include <stdio.h>
#include "y.tab.h"
// #include "y.tab.c"
#include <ctype.h>
#include <stdlib.h>

int yyparse (void);


FILE *output;
FILE *report;
extern FILE *yyin;
extern int yylineno;

//extern int result;

// int yyerror(const char*){
//     printf("Syntax error occured\n");
//     return 1;
// }


int yyerror(const char *s) {
    printf(">>Error in line: %d : %s\n", 
                yylineno, 
                s
            );

    exit(1);
    //fprintf()
    return 1;
}
// reliaze function to polinom
// struct buffer_polynom
// {
//     int coef[100];
//     char array_buffer[500];
//     int capacity = 0;
//     int flag = 0; // Priority
// }


// struct buffer_polynom
// {
//     int coef[100];
//     char array_buffer[500];
//     int capacity;
//     int flag; // Priority
// };



int main(){
    //extern int result;

    

    yyin = fopen("test.txt", "r");
    output = fopen("out.txt", "w");
    report = fopen("report.txt", "w");
    
    yyparse();
    //printf("result = %d\n", result);
    fclose(yyin);
    fclose(output);
    fclose(report);
    printf("Program completed with 1 code!\n");
}