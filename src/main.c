#include "../build/parser.tab.h"
#include "../include/global.h"

int yyparse();
extern BlockStmt *stmt_root;

extern FILE *yyin;

int yywrap()
{
  return 1;
}

int main(int argc, char *argv[])
{
  FILE *fp = input_accept(argc, argv);
  yyin = fp;
  int status = yyparse();

  if (status == 0)
  {
    interpret(stmt_root);
  }
  else
  {
    printf("Parsing failed.\n");
  }

  return 0;
}