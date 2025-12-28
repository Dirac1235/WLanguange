%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/ast.h"
#include "../include/token.h"

extern Stmt **stmt_root;
extern size_t stmt_root_count;

extern size_t line_number;
extern size_t column_number;

extern int yylex(void);

void yyerror(char *s) {
  fprintf(stdout, "%s",s);
};

%}


%union {
    struct Expr *expr_val;
    struct Stmt *stmt_val;
    char* str_val;
    long double fl_val;
}


%token <fl_val> NUMBER 
%token <str_val> STRING IDENTIFIER
%token  STR BOOL EQUAL NUM

%token NEWLINE
%token PLUS SUBTRACT MULTIPLY DIVIDE MOD LEFT_PAREN RIGHT_PAREN
%token PRINT
%token LEFT_PAREN RIGHT_PAREN

%start start

%left PLUS SUBTRACT
%left MULTIPLY DIVIDE

%type <expr_val> expr
%type <stmt_val> num_decl str_decl bool_decl


%%
start
    : program        
    ;    

program
    : /* empty */
    | program line
    ;

line
    : declaration NEWLINE
    | stmt NEWLINE
    ;

declaration
    : num_decl                         
    | str_decl                         
    | bool_decl                                            
    ;

stmt
    : printstmt
    ;

printstmt
    : PRINT LEFT_PAREN expr RIGHT_PAREN
    {
        Stmt *print = makePrintStmt($3);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = print;
    }
    ;

num_decl
    : NUM IDENTIFIER EQUAL expr        
    {
        Stmt *num_d = makeDeclStmt(STMT_NUM, $2, $4);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = num_d;
    } 
    ;

str_decl
    : STR IDENTIFIER EQUAL expr        
    {
        Stmt *str_d = makeDeclStmt(STMT_STR, $2, $4);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = str_d;
    }
    ;

bool_decl
    : BOOL IDENTIFIER EQUAL expr       
    {
        Stmt *bool_d = makeDeclStmt(STMT_BOOL, $2, $4);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = bool_d;
    }
    ;

expr  
    : NUMBER                              { $$ = numExpr(TKN_NUMBER, $1); }
    | STRING                              { $$ = strExpr(TKN_STRING, $1); }       
    | IDENTIFIER                          { $$ = strExpr(TKN_LITERAL, $1); }       
    | LEFT_PAREN expr RIGHT_PAREN         { $$ = makeGroupExpr($2);       }
    | expr DIVIDE expr                    
    { 
        if ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_NUMBER)
            $$ = makeBinaryExpr(TKN_OP_DIV, $1, $3);
        else if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_NUMBER) || ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_STRING) ) {
            fprintf(
            stderr,
                "incompatible types '%s' and '%s' at line %zu\n",
                ($1->token->tkn == TKN_STRING ? "string" : "int"),
                ($3->token->tkn == TKN_STRING ? "string" : "int"),
                  line_number
                  );

            }

            
    }
    | expr MULTIPLY expr                  
    { 

        if ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_NUMBER)
            $$ = makeBinaryExpr(TKN_OP_MUL, $1, $3);
        else if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_NUMBER) || ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_STRING) ) {
            fprintf(
                stderr,
                "incompatible types '%s' and '%s' at line %zu\n",
                ($1->token->tkn == TKN_STRING ? "string" : "int"),
                ($3->token->tkn == TKN_STRING ? "string" : "int"),
                line_number
            );

        }
        $$ = makeBinaryExpr(TKN_OP_MUL, $1, $3); 
    }
    | expr PLUS expr                      
    { 
        if ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_NUMBER)
            $$ = makeBinaryExpr(TKN_OP_ADD, $1, $3);
        else if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_NUMBER) || ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_STRING) ) {
            fprintf(
                stderr,
                "incompatible types '%s' and '%s' at line %zu\n",
                ($1->token->tkn == TKN_STRING ? "string" : "int"),
                ($3->token->tkn == TKN_STRING ? "string" : "int"),
                line_number
            );

        }
        $$ = makeBinaryExpr(TKN_OP_ADD, $1, $3); 
    }
    | expr SUBTRACT expr                  
    { 
        if ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_NUMBER)
            $$ = makeBinaryExpr(TKN_OP_SUB, $1, $3);
        else if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_NUMBER) || ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_STRING) ) {
            fprintf(
                stderr,
                    "incompatible types '%s' and '%s' at line %zu\n",
                    ($1->token->tkn == TKN_STRING ? "string" : "int"),
                    ($3->token->tkn == TKN_STRING ? "string" : "int"),
                    line_number
                );

            }
            $$ = makeBinaryExpr(TKN_OP_SUB, $1, $3); 
    }
    | expr MOD expr                       
    { 
            if ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_NUMBER)
                  $$ = makeBinaryExpr(TKN_OP_MOD, $1, $3);
            else if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_NUMBER) || ($1->token->tkn == TKN_NUMBER && $3->token->tkn == TKN_STRING) ) {
                fprintf(
                    stderr,
                    "incompatible types '%s' and '%s' at line %zu\n",
                    ($1->token->tkn == TKN_STRING ? "string" : "int"),
                    ($3->token->tkn == TKN_STRING ? "string" : "int"),
                    line_number
                );

            }
            $$ = makeBinaryExpr(TKN_OP_MOD, $1, $3); 
    }
    ;
  

%%




