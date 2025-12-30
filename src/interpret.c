#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;      
extern hash_table_t *ht;
#define HASH_TABLE_SIZE 1024;

Object *evaluate(hash_table_t *ht, Expr *expr)
{
  if (expr->type == EXPR_BINARY)
  {
    Object *left = evaluate(ht, expr->binary->left);
    Object *right = evaluate(ht, expr->binary->right);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        if (left->type == TYPE_INT && right->type == TYPE_INT)
        {
          Object *obj = makeObj(left->type);
          int val = left->data.i + right->data.i;
          obj->data.i = val;
          return obj;
        }
        else if (left->type == TYPE_DOUBLE || right->type == TYPE_DOUBLE)
        {
          Object *obj = makeObj(TYPE_DOUBLE);
          double val;
          if (left->type == TYPE_INT)
            val = left->data.i;
          else
            val = left->data.d;
          if (right->type == TYPE_INT)
            val += right->data.i;
          else
            val += right->data.d;
          obj->data.d = val;
          return obj;
        }
      }
      else if (left->type == TYPE_STR && right->type == TYPE_INT)
      {
        fprintf(stderr, "TypeError: Unsupported Operand '+' on types str and int");
        exit(1);
      }
      else if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && right->type == TYPE_STR)
      {
        fprintf(stderr, "TypeError: Unsupported Operand '+' on types int and str");
        exit(1);
      }
      else
      {
        char *val = concat(left->data.s, right->data.s);
        Object *obj = makeObj(left->type);
        obj->data.s = val;
        return obj;
      }
    case TKN_OP_SUB:
      if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        if (left->type == TYPE_INT && right->type == TYPE_INT)
        {
          Object *obj = makeObj(left->type);
          int val = left->data.i - right->data.i;
          obj->data.i = val;
          return obj;
        }
        else if (left->type == TYPE_DOUBLE || right->type == TYPE_DOUBLE)
        {
          Object *obj = makeObj(TYPE_DOUBLE);
          double val;
          if (left->type == TYPE_INT)
            val = left->data.i;
          else
            val = left->data.d;
          if (right->type == TYPE_INT)
            val -= right->data.i;
          else
            val -= right->data.d;
          obj->data.d = val;
          return obj;
        }
      }
      else if (left->type == TYPE_STR && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '-' on types str and int");
      }
      else if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && right->type == TYPE_STR)
      {
        fprintf(stderr, "TypeError: Unsupported Operand '-' on types int and str");
      }
      else
      {
        fprintf(stderr, "TypeError: Unsupported Operand '-' on types str and str");
      }
    case TKN_OP_DIV:
      if (right->data.i == 0)
      {
        fprintf(stderr, "DivisionByZeroError: Division by zero is undefined at line: %zu \n", line_number);
        exit(1);
      }
      if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {

        if (left->type == TYPE_INT && right->type == TYPE_INT)
        {
          Object *obj = makeObj(left->type);
          int val = left->data.d / right->data.d;
          obj->data.i = val;
          return obj;
        }
        else if (left->type == TYPE_DOUBLE || right->type == TYPE_DOUBLE)
        {
          Object *obj = makeObj(TYPE_DOUBLE);
          double val;
          if (left->type == TYPE_INT)
            val = left->data.i;
          else
            val = left->data.d;
          if (right->type == TYPE_INT)
            val /= right->data.i;
          else
            val += right->data.d;
          obj->data.d = val;
          return obj;
        }
      }
      else if (left->type == TYPE_STR && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '/' on types str and int");
        exit(1);
      }
      else if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && right->type == TYPE_STR)
      {
        fprintf(stderr, "TypeError: Unsupported Operand '/' on types int and str");
        exit(1);
      }
      else
      {
        fprintf(stderr, "TypeError: Unsupported Operand '/' on types str and str");
        exit(1);
      }
    case TKN_OP_MUL:
      if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        if (left->type == TYPE_INT && right->type == TYPE_INT)
        {
          Object *obj = makeObj(left->type);

          int val = left->data.d + right->data.d;
          obj->data.i = val;
          return obj;
        }
        else if (left->type == TYPE_DOUBLE || right->type == TYPE_DOUBLE)
        {
          Object *obj = makeObj(TYPE_DOUBLE);
          double val;
          if (left->type == TYPE_INT)
            val = left->data.i;
          else
            val = left->data.d;
          if (right->type == TYPE_INT)
            val *= right->data.i;
          else
            val *= right->data.d;
          obj->data.d = val;
          return obj;
        }
      }
      else if ((left->type == TYPE_INT || left->type == TYPE_STR)  && (right->type == TYPE_STR || right->type == TYPE_INT))
      {
        Object *obj = makeObj(TYPE_STR);
        if (left->type == TYPE_STR)
          obj->data.s =  mul_str(left->data.s, right->data.i);
        else
          obj->data.s =  mul_str(right->data.s, left->data.i);
        return obj;
    
      }
      else
      {
        fprintf(stderr, "TypeError: Unsupported Operand '*' on types str and str \n");
        exit(1);
      }
    case TKN_OP_MOD:
      if ((left->type == TYPE_INT) && (right->type == TYPE_INT))
      {
        Object *obj = makeObj(left->type);
        int val = left->data.i % right->data.i;
        obj->data.i = val;
        return obj;
      }
      else if (left->type == TYPE_DOUBLE && right->type == TYPE_DOUBLE)
      {
        fprintf(stderr, "TypeError: Unsupported Operand '%%' on types double and dobule");
        exit(1);
      }
      else if (left->type == TYPE_STR && (right->type == TYPE_INT || right->type == TYPE_DOUBLE))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '%%' on types str and int");
        exit(1);
      }
      else if ((left->type == TYPE_INT || left->type == TYPE_DOUBLE) && right->type == TYPE_STR)
      {
        // TODO: add mulitplication of strings

        fprintf(stderr, "TypeError: Unsupported Operand '%%' on types int and str");
        exit(1);
      }
      else
      {
        fprintf(stderr, "TypeError: Unsupported Operand '%%' on types str and str");
        exit(1);
      }
    default:
      fprintf(stderr, "SyntaxError: Wrong Operator at line: %zu got: %s\n", line_number, expr->binary->token->s_lexeme);
      exit(1);
    }
  }
  else if (expr->type == EXPR_UNARY)
  {
    Object *val = evaluate(ht, expr->unary->expr);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      return val;
    case TKN_OP_SUB:
      if (val->type == TYPE_INT || val->type == TYPE_DOUBLE)
      {
        if (val->type == TYPE_INT)
          val->data.i *= -1;
        else
          val->data.i *= -1;
      }
      else
      {
        fprintf(stderr, "TypeError: Unsupported Operand '-' on types str");
        exit(1);
      }
    case TKN_OP_DIV:
    case TKN_OP_MUL:
    default:
      fprintf(stderr, "TypeError: Unsupported Operand %s  on types str\n", tt_to_str(expr->binary->token->tkn));
      exit(1);
    }
  }
  else if (expr->type == EXPR_GROUP)
  {
    return evaluate(ht, expr->group->expr);
  }
  else if (expr->type == EXPR_TOKEN)
  {
    if (expr->token->tkn == TKN_INT)
    {

      Object *obj = makeObj(TYPE_INT);
      obj->data.i = expr->token->i_lexeme;
      return obj;
    }
    else if (expr->token->tkn == TKN_DOUBLE)
    {
      Object *obj = makeObj(TYPE_DOUBLE);
      obj->data.d = expr->token->f_lexeme;
      return obj;
    }
    else if (expr->token->tkn == TKN_STRING)
    {
      Object *obj = makeObj(TYPE_STR);
      obj->data.s = expr->token->s_lexeme;
      return obj;
    }

    else if (expr->token->tkn == TKN_LITERAL)
    {
      Object *value = hash_table_get(ht, expr->token->literal);
      if (!value)
      {
        fprintf(stderr, "RuntimeError: undefined variable '%s'\n",
                expr->token->literal);
        exit(1);
      }

      return value;
    }
  }
  fprintf(stderr, "SyntaxError: Wrong Operator at line: %zu got: %s\n", line_number, tt_to_str(expr->token->tkn));
  exit(1);
}

void execute(Stmt *stmt)
{
  if (stmt->type == STMT_PRINT)
  {
    Object *obj = evaluate(ht, stmt->print_stmt->expr);
    switch (obj->type)
    {
    case TYPE_INT:
      printf("%d\n", obj->data.i);
      break;
    case TYPE_DOUBLE:
      printf("%f\n", obj->data.d);
      break;
    case TYPE_STR:
      printf("%s\n", obj->data.s);
      break;
    default:
      fprintf(stderr, "Error while printing");
      exit(1);
    }
  }
  else if (stmt->type == STMT_DECL)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(ht, stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
  }
  else if (stmt->type == STMT_ASS)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *value = hash_table_get(ht, identifier);
    if (!value)
    {
      fprintf(stderr, "Runtime error: undefined variable '%s'\n", identifier);
      exit(1);
    }
    Object *eval_res = evaluate(ht, stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
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
