#include "../include/ast.h"

extern size_t line_number;
extern size_t column_number;

long double interpretA(Expr *expr)
{
  if (expr->type == EXPR_BINARY)
  {
    long double left = interpretA(expr->binary->left);
    long double right = interpretA(expr->binary->right);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      return left + right;
    case TKN_OP_SUB:
      return left - right;
    case TKN_OP_DIV:
      if (right == 0)
      {
        fprintf(stderr, "Division by zero is undefined at line: %zu \n ", line_number );
        exit(69);
      }
      return left / right;
    case TKN_OP_MUL:
      return left * right;
    default:
      fprintf(stderr, "Wrong Operator at line: %zu where: %s\n", line_number, expr->binary->token->s_lexeme);
      exit(68);
    }
  }
  else if (expr->type == EXPR_UNARY)
  {
    long double val = interpretA(expr->unary->expr);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      return val;
    case TKN_OP_SUB:
      return -val;
    case TKN_OP_DIV:
    case TKN_OP_MUL:
    default:
      fprintf(stderr, "Wrong Operator \n");
      exit(68);
    }
  }
  else if (expr->type == EXPR_GROUP)
  {
    return interpretA(expr->group->expr);
  }
  else if (expr->type == EXPR_TOKEN)
  {
    if (expr->token->tkn == TKN_NUMBER)
      return expr->token->f_lexeme;
    else
      return expr->token->f_lexeme;
  }
  fprintf(stderr, "Wrong Operator \n");
  exit(68);
  
}

void interpret(Expr **expr_lst, size_t count)
{
    for (size_t i = count; i-- > 0; ) {
        printf("%Lf\n", interpretA(expr_lst[i]));
    }
}

