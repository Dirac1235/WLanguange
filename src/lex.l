%{
  #include<stdio.h>
  #include "../build/parser.tab.h"
  
  extern YYSTYPE yylval;
  extern size_t line_number;
  extern size_t column_number;

%}


%%
"num"                             column_number += 3; return NUM;
"str"                             column_number += 3; return STR;
"bool"                            column_number += 4; return BOOL;
"print"                           column_number += 5; return PRINT;

[0-9]+                            yylval.fl_val=atoi(yytext); column_number += strlen(yytext); return NUMBER;
[a-zA-Z_][a-zA-Z0-9_]*            yylval.str_val=strdup(yytext); column_number += strlen(yytext); return IDENTIFIER;
"\""([^"\\]|\\.)*"\""             yylval.str_val=strdup(yytext); column_number += strlen(yytext); return STRING;


"\+"                              column_number++; return PLUS;
"\%"                              column_number++; return MOD;
"\-"                              column_number++; return SUBTRACT;
"\*"                              column_number++; return MULTIPLY;
"\/"                              column_number++; return DIVIDE;
"\("                              column_number++; return LEFT_PAREN;
"\)"                              column_number++; return RIGHT_PAREN;
"="                               column_number++; return EQUAL;

[ \t]+                             ; /* ignore whitespace */
\n+                              line_number++; column_number = 0; return NEWLINE;

%%

