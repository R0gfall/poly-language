%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>





extern int yylex();
extern int yylineno;
extern FILE* output;
extern FILE* report;



int yyerror(const char* s);



typedef struct buffer_polynom
{
        int coef[2000];
        int capacity;
        char var; 
        int priority;
        char name_var[100];
        //int fb_sign;
        
}b_poly;


typedef struct list_var 
{
    char name[100];
    b_poly* polynom;
    struct list_var* next_list;

}list;


list* first_list_var = NULL;

int line_of_error = 0;


void init_poly(b_poly* firstP);
void set_zero_poly(b_poly* firstP);
b_poly* poly_power_poly(b_poly* firstP, b_poly* secondP);
b_poly* add_poly_to_poly(b_poly* firstP, b_poly* secondP, int sign);
b_poly* multi_poly_to_poly(b_poly* firstP, b_poly* secondP);
void output_poly(b_poly* firstP);
void output_poly_to_file(b_poly* firstP);
b_poly* full_poly_power_poly(b_poly* firstP, b_poly* secondP);

void add_new_element(char* variable, b_poly* polynom);
b_poly* search_polynom_in_list(char* variable);


%}




%union {
    int number;
    int signal;
    int pow_number;
    char value;
    struct buffer_polynom* poly;
    char variable[100];
    //struct list_var* first_list_var;
}


%token PLUS MINUS MULTI POW EQUAL OY PRINT NEXT FINISH

%token OPENC CLOSEC      // ADD ( ) !

%token <number> NUMBER
%token <value> VAR
%token <variable> VARIABLE


%type <poly> expression
%type <signal> sign
%type <poly> polynom
%type <poly> exprmonom
%type <poly> termmonom
%type <poly> monom
%type <poly> peremen


%%






main: 
    | polynom NEXT main
    | NEXT main
    {
        fprintf(report, ">>main competed!\n");   
    }
    ; 
    


polynom:
            termmonom
            {
                $$ = $1;
            }

            | PRINT termmonom
            {
                output_poly_to_file($2);
                $$ = $2;
            }

            | peremen

            {
                $$ = $1;
            }

            | PRINT peremen
            {
                output_poly_to_file($2);
                $$ = $2;
            };     
            

            
peremen:
            OY VARIABLE EQUAL termmonom
            {
                $$ = $4;
                fprintf(report, ">>peremen: OY VARIABLE EQUAL termmonom: Find new peremen!\n");
                add_new_element($2, $4);
            };

termmonom:
            termmonom sign monom
            {
                
                // if ($2 == "-")
                //     $3->coef[$3->capacity - 1] = - $3->coef[$3->capacity - 1];
                //printf("()()\n");

                $$ = add_poly_to_poly($1, $3, $2);

            }

            | sign monom
            {
                //printf("!()!(!)(!)!!()\n");
                //printf("%d\n", $1);
                $$ = $2;
                //($1 == "+") ? $$->fb_sign = 1 : $$->fb_sign = 2;
                if ($1 == 2) {
                    fprintf(report, ">>termmonom: sign monom\n");
                    //printf("--%d\n", $2->capacity);
                    $$->coef[$2->capacity - 1] = 0 - ($$->coef[$2->capacity - 1]);
                    fprintf(report, "sign coef = %d\n", $$->coef[$2->capacity - 1]);
                }
            }

            | monom
            {
                //printf("!()!(!)(!)!!()\n");
                $$ = $1;
            };



monom:

            monom MULTI exprmonom
            {
                $$ = multi_poly_to_poly($1, $3);
            }

            | monom exprmonom
            {
                //printf(">>monom: monom exprmonom created\n");
                output_poly($1);
                output_poly($2);
                $$ = multi_poly_to_poly($1, $2);
            }

            | exprmonom
            {
                fprintf(report, ">>monom: exprmonom created\n");
                output_poly($1);
                
                $$ = $1;
                //free($1);
            };


exprmonom:
            expression POW exprmonom
            {
                fprintf(report, ">>exprmonom: expression POW exprmonom!\n");
                output_poly($1);

                output_poly($3);
                //fprintf(report, "------\n");
                //printf("%d\n", $3->capacity);
                if ($3->coef[0] < 0){
                    printf("ERROR: minus power number! line: %d\n", yylineno);
                    fprintf(report, "ERROR: exprmonom: expression POW exprmonom!\n >> Отрицательная степень!");
                    exit(1);
                }

                if ($3->capacity == 1){
                    //fprintf(report, "------\n");
                    if ($1->capacity == 2){
                        set_zero_poly($$);
                        $$->capacity = $3->coef[0];
                        $$->coef[$3->coef[0]] = 1;
                        
                    }

                    // else if ($1->capacity == 1){
                    //     $$ = poly_power_poly($1, $3);
                    //     printf("<><><\n");
                    // }

                    else {
                        $$ = full_poly_power_poly($1, $3);
                        //printf("---\n");
                    }
                }

                else if ($3->capacity == 0){
                    
                    set_zero_poly($$);
                    $$->capacity = 1;
                    $$->coef[0] = 1;
                }

                else {
                    printf("ERROR: minus power number! line: %d\n", yylineno);
                    fprintf(report, "ERROR: exprmonom: expression POW exprmonom!\n >> Отрицательная степень!");
                    exit(1);
                }
            }

            | expression
            {
                output_poly($1);
                $$ = $1;
            };


expression: 

            VARIABLE {
                fprintf(report, ">>expression: VARIABLE find\n");
                if (($$ = search_polynom_in_list($1)) == NULL){
                    //printf("ERROR: Unidentified variable!\n");
                    break;
                }
            }

            | NUMBER {
                fprintf(report, ">>expression: NUMBER created\n");
                $$ = (b_poly*)malloc(sizeof(b_poly));
                init_poly($$);
                $$->capacity = 1;
                $$->coef[0] = $1;
                //printf("---%c\n", $$->var);
            }


            | VAR
            {
                fprintf(report, ">>expression: VAR created\n");
                $$ = (b_poly*)malloc(sizeof(b_poly));
                init_poly($$);
                $$->capacity = 2;
                $$->coef[1] = 1;
                $$->var = $1;

            }

            | OPENC termmonom CLOSEC
            {
                $$ = $2;
            };


sign: 
            PLUS
            {
                $$ = 1;
            }
            | MINUS
            {
                $$ = 2;
            };










%%
void init_poly(b_poly* firstP){
    firstP->capacity = 0;
    firstP->var = ' ';
    memset(firstP->coef, 0, 2000);
    //memset(firstP->name_var, NULL, 100);
    firstP->priority = 0;
}

void set_zero_poly(b_poly* firstP){
    firstP->capacity = 0;
    memset(firstP->coef, 0, 2000);
    firstP->priority = 0;
}

b_poly* poly_power_poly(b_poly* firstP, b_poly* secondP){

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    init_poly(thirdP);
    thirdP->capacity = 1;
    thirdP->coef[0] = firstP->coef[0] * secondP->coef[0];
    //free(firstP);         // ??
    //free(secondP);         // ??
    return thirdP;

}

b_poly* full_poly_power_poly(b_poly* firstP, b_poly* secondP){


    fprintf(report, ">>full_poly_power_poly function start\n");

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    init_poly(thirdP);
    thirdP->var = firstP->var;

    int power = secondP->coef[0];
    int max_capacity = 0;

    //printf("%d\n", firstP->coef[0]);

    if (firstP->coef[0] > 0){
        thirdP->coef[0] = (int)pow(firstP->coef[0], secondP->coef[0]);
        thirdP->capacity = 1;
        max_capacity = 1;
        //printf("---\n");
    }

    fprintf(report, "first step of function\n");
    output_poly(thirdP);

    // printf("%d\n", firstP->capacity);
    for (int i = 1; i <= firstP->capacity; i++){
        thirdP->coef[i * secondP->coef[0]] = (int)pow(firstP->coef[i], secondP->coef[0]);
        //printf("---\n");
        max_capacity = fmax(max_capacity, i * secondP->coef[0]);

    }
    thirdP->capacity = max_capacity;
    return thirdP;
}


b_poly* add_poly_to_poly(b_poly* firstP, b_poly* secondP, int sign){

    // sign = 1 -> +
    // sign = 2 -> -

    //printf("===coef %d\n", firstP->coef[2]);

    fprintf(report, ">>gram.y: FUNCTION add_poly_to_poly start\n");

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));

    if (firstP->var == ' '){
        firstP->var = secondP->var;
    }
    else if (secondP->var == ' '){
        secondP->var = firstP->var;
    }

    if ((firstP->var != secondP->var)){
        
        // add yyerror()

        //printf("<<>>%c\n", firstP->var);
        //printf("<<>>%c\n", secondP->var);

        printf("<<Error: gram.y: func add_p2p: different var! line: %d\n", yylineno);
        fprintf(report, "<<Error: gram.y: func add_p2p: different var!\n");
        //return -1;
        exit(1);
        
    }


    init_poly(thirdP);

    //int maximum_pow = fmax(firstP->capacity, secondP->capacity); 
    int maximum_pow = (firstP->capacity > secondP->capacity) ? firstP->capacity : secondP->capacity;
    fprintf(report, "max-pow %d\n", maximum_pow);


    //struct buffer_polynom* thirdP = (b_poly*)malloc(sizeof(b_poly));
    
    //b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));

    thirdP->capacity = maximum_pow;
    thirdP->var = firstP->var;

    //memset(thirdP->coef, 0, 2000); 

    /* printf("-=-=-=- %d\n", sign);


    printf("++++++++++\n");
    output_poly(firstP);
    output_poly(secondP);
    printf("++++++++++\n"); */

    if (sign == 1){
        //printf("PLUS\n");
        for (int i = 0; i <= maximum_pow; i++){
            thirdP->coef[i] = firstP->coef[i] + secondP->coef[i];
        }
    }


    
    else if (sign == 2){
        //printf("MINUS\n");
        for (int i = 0; i <= maximum_pow; i++){

            thirdP->coef[i] = firstP->coef[i] - secondP->coef[i];
            /* printf("><><><>%d\n", firstP->coef[i]);
            printf("><><><>%d\n", secondP->coef[i]);
            printf("><><><>%d\n", thirdP->coef[i]); */
        
        }
    }
    output_poly(thirdP);
    return thirdP;

}

b_poly* multi_poly_to_poly(b_poly* firstP, b_poly* secondP){
    
    
    if (firstP->var == ' '){
        firstP->var = secondP->var;
    }
    else if (secondP->var == ' '){
        secondP->var = firstP->var;
    }
    

    if (firstP->var != secondP->var){
        
        // add yyerror()
        printf("<<Error: gram.y: func add_p2p: different var! line: %d\n", yylineno);
        fprintf(report, "<<Error: gram.y: func add_p2p: different var!\n");
        //return -1;
        exit(1);
    }


    output_poly(firstP);
    //printf("-----\n");
    output_poly(secondP);

    //int maximum_pow = max(firstP->capacity, secondP->capacity); 

    //struct b_poly thirdP;
    
    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    //thirdP->capacity = 1;


    thirdP->var = firstP->var;
    memset(thirdP->coef, 0, 2000);



    
    for (int i = 0; i <= firstP->capacity; i++){
        for (int j = 0; j <= secondP->capacity; j++){
            
            if ((firstP->coef[i] != 0) && (secondP->coef[j] != 0)){
                int count_coef = firstP->coef[i] * secondP->coef[j];
                //printf("))%d\n", count_coef);
                int count_pow = i + j;
                
                thirdP->coef[count_pow] = count_coef;
                thirdP->capacity = count_pow + 1;

            }
        }
        
    }

    /* free(firstP);
    free(secondP); */
    return thirdP;
    

}

void output_poly(b_poly* firstP) {
    fprintf(report, ">>gram.y: FUNCTION output_poly start\n");
    
    
    /* printf("===coef[0] %d  ", firstP->coef[0]);
    printf("===coef[1] %d\n", firstP->coef[1]);
    printf("===capacity %d\n", firstP->capacity); */
    

    int first_term = 1; // Флаг для первого члена

    for (int i = firstP->capacity; i >= 0; i--) {
        int coef = firstP->coef[i];
        if (coef == 0) continue; 
        if (!first_term) {
            if (coef > 0) {
                fprintf(report, " + ");
            } else {
                fprintf(report, " - ");
                coef = -coef; 
            }
        } else {
            if (coef < 0) {
                fprintf(report, "-");
                coef = -coef;
            }
            first_term = 0;
        }

        if (i == 0) {
            fprintf(report, "%d", coef);
        } else {
            if (coef != 1 || i == 0) { 
                fprintf(report, "%d", coef);
            }
            fprintf(report, "%c", firstP->var);
            if (i > 1) {
                fprintf(report, "^%d", i);
            }
        }
    }

    if (first_term) { 
        fprintf(report, "0");
    }
    fprintf(report, "\n");
}


void output_poly_to_file(b_poly* firstP) {
    //printf(">>gram.y: FUNCTION output_poly start\n");
    
    
    /* printf("===coef[0] %d  ", firstP->coef[0]);
    printf("===coef[1] %d\n", firstP->coef[1]);
    printf("===capacity %d\n", firstP->capacity); */
    

    int first_term = 1; // Флаг для первого члена

    for (int i = firstP->capacity; i >= 0; i--) {
        int coef = firstP->coef[i];
        if (coef == 0) continue; 
        if (!first_term) {
            if (coef > 0) {
                fprintf(output, " + ");
            } else {
                fprintf(output, " - ");
                coef = -coef; 
            }
        } else {
            if (coef < 0) {
                fprintf(output, "-");
                coef = -coef;
            }
            first_term = 0;
        }

        if (i == 0) {
            fprintf(output, "%d", coef);
        } else {
            if (coef != 1 || i == 0) { 
                fprintf(output, "%d", coef);
            }
            fprintf(output, "%c", firstP->var);
            if (i > 1) {
                fprintf(output, "^%d", i);
            }
        }
    }

    if (first_term) { 
        fprintf(output, "0");
    }
    fprintf(output, "\n");
}


void add_new_element(char* variable, b_poly* polynom)
{
    list* temp = (list*)malloc(sizeof(list));
    strcpy(temp->name, variable);
    temp->polynom = polynom;
    temp->next_list = first_list_var;
    
    first_list_var = temp;
    fprintf(report, ">>function add_new_element: Create new element at list_var!\n");
}


b_poly* search_polynom_in_list(char* variable)
{
    list* temp = first_list_var;
    fprintf(report, ">>function search_polynom_in_list: Start search at list_var!\n");
    while (temp != NULL)
    {
        if (strcmp(temp->name, variable) == 0) {
            return temp->polynom;
        }
        temp = temp->next_list;
    }

    printf("ERROR: Unidentified variable! line: %d\n", yylineno);
    fprintf(report, "ERROR: Unidentified variable!\n");
    exit(1);
}
