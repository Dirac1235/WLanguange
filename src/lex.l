%{
  #include<stdio.h>
  #include "../build/parser.tab.h"
  
  extern YYSTYPE yylval;
  extern size_t line_number;
  extern size_t column_number;

%}


%%
"int"                             column_number += 3; return INT;
"double"                          column_number += 6; return DOUBLE;
"str"                             column_number += 3; return STR;
"bool"                            column_number += 4; return BOOL;
"print"                           column_number += 5; return PRINT;

[0-9]+                            yylval.i_val=atoi(yytext);             column_number += yyleng; return INUMBER;
[0-9]+\.[0-9]+                    yylval.d_val=strtod(yytext, NULL);    column_number += yyleng; return DNUMBER;
[a-zA-Z_][a-zA-Z0-9_]*            yylval.str_val=strdup(yytext);         column_number += yyleng; return IDENTIFIER;
"\""([^"\\]|\\.)*"\""             {
                                    yylval.str_val=strndup(yytext + 1, strlen(yytext) - 2);         
                                    column_number += yyleng; return STRING;
                                  }


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

