#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;
extern Environment *env;

/**
 * execute - executes statements
 * @stmt: the statement to be executed
 *
 */
void execute(Environment *env, Stmt *stmt)
{

  if (stmt->type == STMT_PRINT)
  {
    Object *obj = evaluate(stmt->print_stmt->expr);
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
    case TYPE_BOOL:
      if (obj->data.b)
      {
        printf("true\n");
      }
      else
      {
        printf("false\n");
      }
      break;
    default:
      fprintf(stderr, "Error while printing");
      exit(1);
    }
  }

  else if (stmt->type == STMT_BLOCK)
  {
    executeBlock(stmt->block_stmt);
  }

  else if (stmt->type == STMT_IFELSE)
  {
    bool isTrue = is_truthy(evaluate(stmt->if_stmt->condition));
    if (isTrue)
    {
      executeBlock(stmt->if_stmt->if_body->block_stmt);
    }
    else
    {
      if(stmt->if_stmt->else_body)
      executeBlock(stmt->if_stmt->else_body->block_stmt);
    }
  }

  else if (stmt->type == STMT_WHILE)
  {
    while (is_truthy(evaluate(stmt->while_stmt->condition))) {
      executeBlock(stmt->while_stmt->body->block_stmt);
    }
  }

  else if (stmt->type == STMT_STR)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(env->table, identifier, eval_res);
  }

  else if (stmt->type == STMT_INT)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(env->table, identifier, eval_res);
  }

  else if (stmt->type == STMT_DOUBLE)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(env->table, identifier, eval_res);
  }

  else if (stmt->type == STMT_BOOL)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = is_true(evaluate(stmt->decl_stmt->expr));
    hash_table_set(env->table, identifier, eval_res);
  }

  else if (stmt->type == STMT_ASS)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *value = env_get(env, identifier);

    if (!value)
    {
      fprintf(stderr, "RuntimeError: undefined variable '%s' at: %zu\n", identifier, line_number);
      exit(1);
    }
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    env_assign(env, identifier, eval_res);
  }
}

void executeBlock(BlockStmt *b_stmt)
{
  Environment *next = create_env(env);
  env = next;
  for (size_t i = 0; i < b_stmt->count; i++)
  {
    execute(env, b_stmt->stmts[i]);
  }
  env = next->parent;
  // free_env(next);
}
