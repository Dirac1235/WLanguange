#include "../include/ast.h"
#include "../include/hash_table.h"
#include "../include/helper.h"

extern size_t line_number;
extern size_t column_number;
extern hash_table_t *ht;
#define HASH_TABLE_SIZE 1024;

long double evaluate(hash_table_t *ht, Expr *expr)
{
  if (expr->type == EXPR_BINARY)
  {
    long double left = evaluate(ht, expr->binary->left);
    long double right = evaluate(ht, expr->binary->right);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      return left + right;
    case TKN_OP_SUB:
      return left - right;
    case TKN_OP_DIV:
      if (right == 0)
      {
        fprintf(stderr, "Division by zero is undefined at line: %zu \n", line_number);
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
    long double val = evaluate(ht, expr->unary->expr);
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
    return evaluate(ht, expr->group->expr);
  }
  else if (expr->type == EXPR_TOKEN)
  {
    if (expr->token->tkn == TKN_NUMBER)
      return expr->token->f_lexeme;
    else if (expr->token->tkn == TKN_LITERAL)
    {
      char *value = hash_table_get(ht, expr->token->s_lexeme);
      if (!value)
      {
        fprintf(stderr, "Runtime error: undefined variable '%s'\n",
                expr->token->literal);
        exit(1);
      }
      long double num = strtold(value, NULL);

      return num;
    }
    else
      return expr->token->f_lexeme;
  }
  fprintf(stderr, "Wrong Operator \n");
  exit(68);
}

void execute(Stmt *stmt)
{
  if (stmt->type == STMT_PRINT)
  {
    printf("%LF \n", evaluate(ht, stmt->print_stmt->expr));
  }
  else if (stmt->type == STMT_DECL)
  {
    char *identifier = stmt->decl_stmt->identifier;
    long double eval_res = evaluate(ht, stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, itoa(eval_res));
  }
}

void interpret(Stmt **stmt_lst, size_t count)
{
  ht = hash_table_create(1024);
  for (size_t i = 0; i < count; i++)
  {
    execute(stmt_lst[i]);
  }
}

char *itoa(long double val)
{
  char *char_array = (char *)malloc(sizeof(char) * 50);
  snprintf(char_array, sizeof(char_array), "%Lf", val);
  return char_array;
}
