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


int yyerror(const char *s) {
    printf(">>Error in line: %d : %s\n", 
                yylineno, 
                s
            );

    exit(1);
    //fprintf()
    return 1;
}

void add_slash_to_file() {
    FILE* input = fopen("test.txt", "a+");
    fseek(input, -1, SEEK_END); 
    char last_char = fgetc(input);
    if (last_char != '\n') {
        fputc('\n', input); 
    }
    fseek(input, 0, SEEK_SET);
    fclose(input);
}


int main(){


    add_slash_to_file();

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