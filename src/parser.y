%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/ast.h"

extern Expr **expr_root;
extern size_t expr_root_count;

extern size_t line_number;
extern size_t column_number;

extern int yylex(void);
void yyerror(char *s) {
  fprintf(stdout, "%s",s);
};

%}


%union {
  struct Expr *expr_val;
  char* str_val;
  long double fl_val;
}


%token <fl_val> NUMBER 
%token <str_val> STRING

%token NEWLINE
%token PLUS SUBTRACT MULTIPLY DIVIDE MOD
%token LEFT_PAREN RIGHT_PAREN

%start start

%left PLUS SUBTRACT
%left MULTIPLY DIVIDE

%type <expr_val> start
%type <expr_val> expr
%type <expr_val> expr_lst

%%

start : expr_lst                         {  }        
      |                                  {  }                           
      ;
expr_lst : expr NEWLINE expr_lst
      {
            Expr **tmp = realloc(
            expr_root,
            (expr_root_count + 1) * sizeof(Expr *)
            );

            if (!tmp) {
                yyerror("out of memory");
                exit(1);
            }

            expr_root = tmp;
            expr_root[expr_root_count++] = $1;
      }
     | expr
            {
                  expr_root = malloc(sizeof(Expr *));
                  if (!expr_root) {
                    yyerror("out of memory");
                    exit(1);
                  }

                  expr_root[0] = $1;
                  expr_root_count = 1;
            }
    
    |  {}
      ;

expr  : NUMBER                              { $$ = makeNumTokenExpr(TKN_NUMBER, $1);   }
      | STRING                              { $$ = makeStrTokenExpr(TKN_STRING, $1);  }       
      | LEFT_PAREN expr RIGHT_PAREN         { $$ = makeGroupExpr($2);                  }
      | expr DIVIDE expr                    { 
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
      | expr MULTIPLY expr                  { 

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
      | expr PLUS expr                      { 
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
      | expr SUBTRACT expr                  { 
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
      | expr MOD expr                       { 
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




