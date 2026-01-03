#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;
extern Environment *env;

/**
 * evaluate - evaluates expessions
 * @expr: the expression to be evaluated
 *
 * RETURN: the evaluated object
 */
Object *evaluate(Expr *expr)
{
  if (expr->type == EXPR_BINARY)
  {
    Object *left = evaluate(expr->binary->left);
    Object *right = evaluate(expr->binary->right);
    switch (expr->binary->token->tkn)
    {
    case TKN_OP_ADD:
      if (is_number(left) && is_number(right))
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
      else if (is_number(left) && right->type == TYPE_STR)
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
      if (is_number(left) && is_number(right))
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
      else if (is_str(left) && is_number(right))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '-' on types str and int");
      }
      else if (is_number(left) && right->type == TYPE_STR)
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
      if (is_number(left) && is_number(right))
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
      else if (is_str(left) && is_number(right))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '/' on types str and int");
        exit(1);
      }
      else if (is_number(left) && right->type == TYPE_STR)
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
      if (is_number(left) && is_number(right))
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
      else if ((left->type == TYPE_INT || left->type == TYPE_STR) && (right->type == TYPE_STR || right->type == TYPE_INT))
      {
        Object *obj = makeObj(TYPE_STR);
        if (left->type == TYPE_STR)
          obj->data.s = mul_str(left->data.s, right->data.i);
        else
          obj->data.s = mul_str(right->data.s, left->data.i);
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
      else if (left->type == TYPE_STR && is_number(right))
      {
        fprintf(stderr, "TypeError: Unsupported Operand '%%' on types str and int");
        exit(1);
      }
      else if (is_number(left) && right->type == TYPE_STR)
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
    case TKN_OP_BANG_EQUAL:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l != r);
        return obj;
      }
      if (left->type == TYPE_STR && right->type == TYPE_STR)
      {
        obj->data.b = (strcmp(left->data.s, right->data.s) != 0);
        return obj;
      }
      if (left->type == TYPE_BOOL && right->type == TYPE_BOOL)
      {
        obj->data.b = (left->data.b != right->data.b);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '!=' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }
    case TKN_OP_EQUALEQUAL:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l == r);
        return obj;
      }

      if (is_str(left) && is_str(right))
      {
        obj->data.b = (strcmp(left->data.s, right->data.s) == 0);
        return obj;
      }

      if (left->type == TYPE_BOOL && right->type == TYPE_BOOL)
      {
        obj->data.b = (left->data.b == right->data.b);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '==' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }
    case TKN_OP_GREATER:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l > r);
        return obj;
      }
      else if (is_str(left) && is_str(right))
      {
        obj->data.b = strcmp(left->data.s, right->data.s);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '>' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }
    case TKN_OP_LESS:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l < r);
        return obj;
      }
      else if (is_str(left) && is_str(right))
      {
        obj->data.b = strcmp(left->data.s, right->data.s);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '<' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }
    case TKN_OP_GREATEREQUAL:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l >= r);
        return obj;
      }
      else if (is_str(left) && is_str(right))
      {
        obj->data.b = strcmp(left->data.s, right->data.s);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '>=' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }
    case TKN_OP_LESSEQUAL:
    {
      Object *obj = makeObj(TYPE_BOOL);

      if (is_number(left) && is_number(right))
      {
        double l = (left->type == TYPE_INT) ? left->data.i : left->data.d;
        double r = (right->type == TYPE_INT) ? right->data.i : right->data.d;
        obj->data.b = (l <= r);
        return obj;
      }
      else if (is_str(left) && is_str(right))
      {
        obj->data.b = strcmp(left->data.s, right->data.s);
        return obj;
      }

      fprintf(stderr,
              "TypeError: unsupported operand '<=' for types %s and %s\n",
              ot_to_str(left->type),
              ot_to_str(right->type));
      exit(1);
    }

    default:
      fprintf(stderr, "SyntaxError: Wrong Operator at line: %zu got: %s\n", line_number, expr->binary->token->s_lexeme);
      exit(1);
    }
  }
  else if (expr->type == EXPR_LOGICAL)
  {
    Object *val = evaluate(expr->logical->left);
    bool l = is_truthy(val);
    if (expr->logical->token->tkn == TKN_OP_OR)
    {
      if (l)
        return val;
    }
    else if (expr->logical->token->tkn == TKN_OP_AND)
    {
      if (!l)
        return val;
    }
    return evaluate(expr->logical->right);
  }

  else if (expr->type == EXPR_UNARY)
  {
    Object *val = evaluate(expr->unary->expr);
    switch (expr->unary->token->tkn)
    {
    case TKN_OP_ADD:
      return val;
    case TKN_OP_SUB:
      if (is_number(val))
      {
        if (val->type == TYPE_INT)
          val->data.i *= -1;
        else
          val->data.d *= -1;
        return val;
      }

    case TKN_OP_DIV:
    case TKN_OP_MUL:
    default:
      fprintf(stderr, "TypeError: Unsupported Operand %s  on  %s\n", tt_to_str(expr->binary->token->tkn), ot_to_str(val->type));
      exit(1);
    }
  }
  else if (expr->type == EXPR_GROUP)
  {
    return evaluate(expr->group->expr);
  }
  else if (expr->type == EXPR_TOKEN)
  {
    if (expr->token->tkn == TKN_INT)
    {
      Object *obj = makeObj(TYPE_INT);
      obj->data.i = expr->token->i_lexeme;
      return obj;
    }
    else if (expr->token->tkn == TKN_OP_TRUE)
    {
      Object *obj = makeObj(TYPE_BOOL);
      obj->data.b = expr->token->b_lexeme;
      return obj;
    }
    else if (expr->token->tkn == TKN_OP_FALSE)
    {
      Object *obj = makeObj(TYPE_BOOL);
      obj->data.b = expr->token->b_lexeme;
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
      Object *value = env_get(env, expr->token->literal);
      
      if (!value)
      {
        fprintf(stderr, "RuntimeError: undefined variable '%s' at %zu\n",
                expr->token->literal, line_number);
        exit(1);
      }

      return value;
    }
  }
  fprintf(stderr, "SyntaxError: Wrong Operator at line: %zu got: %s\n", line_number, tt_to_str(expr->token->tkn));
  exit(1);
}
