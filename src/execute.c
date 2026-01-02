#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;
extern hash_table_t *ht;

/**
 * execute - executes statements
 * @stmt: the statement to be executed
 *
 */
void execute(Stmt *stmt)
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
  else if (stmt->type == STMT_BLOCK) {
    executeBlock(stmt);
  }
  else if (stmt->type == STMT_STR)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
  }
  else if (stmt->type == STMT_INT)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
  }
  else if (stmt->type == STMT_DOUBLE)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
  }
  else if (stmt->type == STMT_BOOL)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *eval_res = is_true(evaluate(stmt->decl_stmt->expr));
    hash_table_set(ht, identifier, eval_res);
  }
  else if (stmt->type == STMT_ASS)
  {
    char *identifier = stmt->decl_stmt->identifier;
    Object *value = hash_table_get(ht, identifier);
    if (!value)
    {
      fprintf(stderr, "Runtime error: undefined variable '%s' at: %zu\n", identifier, line_number);
      exit(1);
    }
    Object *eval_res = evaluate(stmt->decl_stmt->expr);
    hash_table_set(ht, identifier, eval_res);
  }
}

void executeBlock(Stmt *b_stmt)
{
  hash_table_t *prev = ht;
  ht = hash_table_create(1024);
  for (size_t i = 0; i < b_stmt->block_stmt->count; i++)
  {
    execute(b_stmt->block_stmt->stmts[i]);
  }
  hash_table_delete(ht);
  ht = prev;
  
}
