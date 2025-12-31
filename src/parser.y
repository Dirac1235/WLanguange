%{
#include "../include/global.h"

extern Stmt **stmt_root;
extern size_t stmt_root_count;

extern size_t line_number;
extern size_t column_number;

extern int yylex(void);

void yyerror(char *s) {
  fprintf(stdout, "%s\n",s);
};

%}


%union {
    struct Expr *expr_val;
    struct Stmt *stmt_val;
    char* str_val;
    int i_val;
    int b_val;
    double d_val;
}


%token  INT DOUBLE
%token  STR BOOL EQUAL NUM 
%token <b_val> BTRUE BFALSE


%token <i_val> INUMBER
%token <d_val> DNUMBER
%token <str_val> STRING IDENTIFIER

%token PLUS SUBTRACT MULTIPLY DIVIDE MOD BANG 
%token BANGEQUAL EQUALEQUAL GREATER LESS GREATEREQUAL LESSEQUAL 
%token AND OR
%token PRINT
%token LEFT_PAREN RIGHT_PAREN NEWLINE

%start start

%left PLUS SUBTRACT
%left MULTIPLY DIVIDE

%type <expr_val> expr
%type <stmt_val> int_decl double_decl str_decl bool_decl


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
    | declaration
    | stmt
    ;

declaration
    : int_decl                         
    | double_decl                         
    | str_decl                         
    | bool_decl                                            
    ;

stmt
    : printstmt
    | assignment
    ;

printstmt
    : PRINT LEFT_PAREN expr RIGHT_PAREN
    {
        Stmt *print = makePrintStmt($3);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = print;
    }
    ;

assignment
    : IDENTIFIER EQUAL expr 
    {
        Stmt *ass_stmt = makeAssStmt($1, $3);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = ass_stmt;

    }
    ;

int_decl
    : INT IDENTIFIER EQUAL expr        
    {
        Stmt *num_d = makeDeclStmt(STMT_INT, $2, $4);
        stmt_root = addStmt(stmt_root, stmt_root_count);
        stmt_root[stmt_root_count++] = num_d;
    } 
    ;
double_decl
    : DOUBLE IDENTIFIER EQUAL expr        
    {
        Stmt *num_d = makeDeclStmt(STMT_DOUBLE, $2, $4);
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
    : INUMBER                             { $$ = i_expr($1);        }
    | DNUMBER                             { $$ = d_expr($1);        }
    | BFALSE                              { $$ = b_expr($1);        }
    | BTRUE                               { $$ = b_expr($1);        }
    | STRING                              { $$ = s_expr($1);        }       
    | IDENTIFIER                          { $$ = l_expr($1);        }       
    | LEFT_PAREN expr RIGHT_PAREN         { $$ = makeGroupExpr($2); }
    | SUBTRACT expr
    {
        $$ = makeUnaryExpr(TKN_OP_SUB, $2);
    } 
    | PLUS expr
    {
        $$ = makeUnaryExpr(TKN_OP_ADD, $2);

    }           
    | expr DIVIDE expr                    
    { 
        if (($1->token->tkn == TKN_STRING && ($3->token->tkn ==TKN_INT || $3->token->tkn == TKN_DOUBLE)) || ( ($1->token->tkn ==TKN_INT || $1->token->tkn == TKN_DOUBLE) && $3->token->tkn == TKN_STRING) ) {
            fprintf(
            stderr,
                "Unsupported Operation '/' on types '%s' and '%s' at line %zu\n",
                tt_to_str($1->token->tkn), 
                tt_to_str($3->token->tkn),
                  line_number
                  );
            exit(1);
            }
        $$ = makeBinaryExpr(TKN_OP_DIV, $1, $3);
        
    }
    | expr MULTIPLY expr                  
    { 
        if (($1->token->tkn == TKN_STRING && $3->token->tkn == TKN_DOUBLE) || ( $1->token->tkn == TKN_DOUBLE && $3->token->tkn == TKN_STRING) ) {
            fprintf(
            stderr,
                "Unsupported Operation '*' on types '%s' and '%s' at line %zu\n",
                tt_to_str($1->token->tkn), 
                tt_to_str($3->token->tkn),
                  line_number
            );
            exit(1);
        }
         $$ = makeBinaryExpr(TKN_OP_MUL, $1, $3);


    }
    | expr PLUS expr                      
    {    
        if (($1->token->tkn == TKN_STRING && ($3->token->tkn ==TKN_INT || $3->token->tkn == TKN_DOUBLE)) || ( ($1->token->tkn ==TKN_INT || $1->token->tkn == TKN_DOUBLE) && $3->token->tkn == TKN_STRING) ) {
            fprintf(
            stderr,
                "Unsupported Operation '+' on types '%s' and '%s' at line %zu\n",
                tt_to_str($1->token->tkn), 
                tt_to_str($3->token->tkn),
                  line_number
            );
            exit(1);
        }
        $$ = makeBinaryExpr(TKN_OP_ADD, $1, $3);

    }
    | expr SUBTRACT expr                  
    { 
        if (($1->token->tkn == TKN_STRING && ($3->token->tkn ==TKN_INT || $3->token->tkn == TKN_DOUBLE)) || ( ($1->token->tkn ==TKN_INT || $1->token->tkn == TKN_DOUBLE) && $3->token->tkn == TKN_STRING) ) {
            fprintf(
            stderr,
                "Unsupported Operation '-' on types '%s' and '%s' at line %zu\n",
                tt_to_str($1->token->tkn), 
                tt_to_str($3->token->tkn),
                  line_number
            );
            exit(1);
        }
        $$ = makeBinaryExpr(TKN_OP_SUB, $1, $3);

    }
    | expr MOD expr                       
    { 
        if ($1->token->tkn == TKN_INT && $3->token->tkn == TKN_INT)
            $$ = makeBinaryExpr(TKN_OP_MOD, $1, $3);
        else {
            fprintf(
            stderr,
                "Unsupported Operation '+' on types '%s' and '%s' at line %zu\n",
                tt_to_str($1->token->tkn), 
                tt_to_str($3->token->tkn),
                line_number
            );
            exit(1);
            
        }

    }
    | expr BANGEQUAL expr
    {       
        $$ = makeBinaryExpr(TKN_OP_BANGEQUAL, $1, $3);
    }
    | expr EQUALEQUAL expr
    { 
        $$ = makeBinaryExpr(TKN_OP_EQUALEQUAL, $1, $3);
    }
    | expr GREATEREQUAL expr
    { 
        $$ = makeBinaryExpr(TKN_OP_GREATEREQUAL, $1, $3);
    }
    | expr LESSEQUAL expr
    { 
        $$ = makeBinaryExpr(TKN_OP_LESSEQUAL, $1, $3);
    }
    | expr LESS expr
    { 
        $$ = makeBinaryExpr(TKN_OP_LESS, $1, $3);
    }
    | expr GREATER expr
    { 
        $$ = makeBinaryExpr(TKN_OP_GREATER, $1, $3);
    }
    | expr OR expr
    {
        $$ = makeLogicalExpr(TKN_OP_OR, $1, $3);
    }
    | expr AND expr
    {
        $$ = makeLogicalExpr(TKN_OP_AND, $1, $3);
    }
    ;

%%




