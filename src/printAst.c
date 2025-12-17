#include "ast.h"

void printA(Expr *expr)
{
  if (expr->type == EXPR_BINARY)
  {
    printf("%s ", expr->binary->token->s_lexeme);
    printA(expr->binary->left);
    printA(expr->binary->right);
  }
  else if (expr->type == EXPR_UNARY)
  {
    printf("%s", expr->unary->token->s_lexeme);
    printA(expr->unary->expr);
  }
  else if (expr->type == EXPR_GROUP)
  {
    printf("(");
    printA(expr->group->expr);
    printf(")");
  }
  else if (expr->type == EXPR_TOKEN)
  {
    if (expr->token->tkn == TKN_NUMBER)
      printf("%Lf ", expr->token->f_lexeme);
    else
      printf("%s ", expr->token->s_lexeme);
  }
  return;
}
void printAst(Expr **expr_lst, size_t count) {
  int i = 0;
  for (; i < count; ++i) {
    printA(expr_lst[i]);
  }
}


// int main()
// {

//   Expr *five = makeTokenExpr("5");
//   Expr *three = makeTokenExpr("3");
//   Expr *ten = makeTokenExpr("10");
//   Expr *add = makeBinaryExpr("+", five, three);
//   Expr *mul = makeBinaryExpr("*", add, ten);
//   Expr *grouped = makeGroupExpr(mul);
//   Expr *unary = makeUnaryExpr("-", grouped);

//   // Print AST
//   printAst(unary);

//   return 0;
// }
