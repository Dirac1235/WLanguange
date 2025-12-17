#include "../build/parser.tab.h"
#include "../include/ast.h"

int yyparse();
extern Expr **expr_root;
extern size_t expr_root_count;

int yywrap()
{
  return 1;
}

int main()
{
  int status = yyparse();
  if (status == 0)
  {
    printf("Parsing successful!\n");
    /* Retrieve the final output from the global variable */
    interpret(expr_root, expr_root_count);
  }
  else
  {
    printf("Parsing failed.\n");
  }

  return 0;
}