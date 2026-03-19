%{
  #include<stdio.h>
  #include "../build/parser.tab.h"
  
  extern YYSTYPE yylval;
  extern size_t line_number;
  extern size_t column_number;

%}


%%
"int"                             column_number += yyleng; return INT;
"double"                          column_number += yyleng; return DOUBLE;
"str"                             column_number += yyleng; return STR;
"bool"                            column_number += yyleng; return BOOL;
"print"                           column_number += yyleng; return PRINT;
"true"                            column_number += yyleng; yylval.b_val = atoi(yytext); return BTRUE;
"false"                           column_number += yyleng; yylval.b_val = atoi(yytext); return BFALSE;
"or"                              column_number += yyleng; return OR;
"and"                             column_number += yyleng; return AND;

"if"                              column_number += yyleng; return IF;
"else"                            column_number += yyleng; return ELSE;
"while"                           column_number += yyleng; return WHILE;
"fun"                             column_number += yyleng; return FUN;



[0-9]+                            column_number += yyleng; yylval.i_val = atoi(yytext);  printf("%s\n", yytext);        return INUMBER;
[0-9]+\.[0-9]+                    column_number += yyleng; yylval.d_val = strtod(yytext, NULL); printf("%s", yytext);  return DNUMBER;
[a-zA-Z_][a-zA-Z0-9_]*            column_number += yyleng; yylval.s_val = strdup(yytext);   printf("%s \n", yytext);     return IDENTIFIER;
"\""([^"\\]|\\.)*"\""             {
                                    yylval.s_val=strndup(yytext + 1, strlen(yytext) - 2);         
                                    column_number += yyleng; return STRING;
                                  }


"\+"                              column_number += yyleng; return PLUS;
"\%"                              column_number += yyleng; return MOD;
"\-"                              column_number += yyleng; return SUBTRACT;
"\*"                              column_number += yyleng; return MULTIPLY;
"\/"                              column_number += yyleng; return DIVIDE;
"\("                              column_number += yyleng; printf("%s\n", yytext); return LEFT_PAREN;
"\)"                              column_number += yyleng; return RIGHT_PAREN;
"\{"                              column_number += yyleng; return LEFT_CURLY;
"\}"                              column_number += yyleng; return RIGHT_CURLY;

"=="                              column_number += yyleng; return EQUALEQUAL;
"!="                              column_number += yyleng; return BANGEQUAL;
">="                              column_number += yyleng; return GREATEREQUAL;
"<="                              column_number += yyleng; return LESSEQUAL;
"="                               column_number += yyleng; return EQUAL;
"!"                               column_number += yyleng; return BANG;
">"                               column_number += yyleng; return GREATER;
"<"                               column_number += yyleng; return LESS;
","                               column_number += yyleng; printf("%s\n", yytext); return COMMA;




[ ;\t]+                             ; /* ignore whitespace */
\n+                              line_number++; column_number = 0; return NEWLINE;

%%

