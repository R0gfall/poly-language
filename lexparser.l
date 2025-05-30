%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

extern FILE* report;
int yyerror(const char* s);

%}
%option noyywrap
%option yylineno



%%



[#].*           ;

[0-9]+      {   yylval.number = atoi(yytext);
                fprintf(report, "lex: number: %d\n", yylval.number); return NUMBER;}


[a-z]       {   char f_symbol = yytext[0];
                yylval.value = f_symbol;
                //yylval.temp.pow = strlen(yytext);
                fprintf(report, "lex: val: %s\n", yytext); return VAR;}


[A-Z]+      {   //char f_ variable[100];
                strcpy(yylval.variable, yytext);
                return VARIABLE;}

"+"         {fprintf(report, "lex: : PLUS\n"); return PLUS;}
"-"         {fprintf(report, "lex: : MINUS\n"); return MINUS;}
"*"         return MULTI;
"^"         return POW;
"("         return OPENC;
")"         return CLOSEC;
"="         return EQUAL;
">>"        return PRINT;       
[ ]*             ;
[\t]+              ;

\n          return NEXT;
\0        	   ;
.           { yyerror("Incorrect symbol!"); } 


%%

/*
typedef struct buffer_polynom
{
        int coef[2000];
        //char array_buffer[500];
        int capacity;
        char var; 
        int priority;
        int fb_sign;
}b_poly; */

/* %union {
    int number;
    char signal;
    int pow_number;
    char value;
    struct buffer_polynom* poly;
} */


/* 
[a-z]+      {
                char f_symbol = yytext[0];
                for (int i = 1; i < strlen(yytext); i++){
                    if (yytext[i] != f_symbol){
                        printf("Error lexparser.l: different symbols!\n");
                        return -1;
                        // add yyerror()
                    }
                }
                yylval.value = f_symbol;
                //yylval.temp.pow = strlen(yytext);
                printf("lex: val: %s\n", yytext); return VAR;} */