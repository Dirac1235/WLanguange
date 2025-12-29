#include "../build/parser.tab.h"
#include "../include/global.h"

int yyparse();
extern Stmt **stmt_root;
extern size_t stmt_root_count;

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
    interpret(stmt_root, stmt_root_count);
  }
  else
  {
    printf("Parsing failed.\n");
  }

  return 0;
}