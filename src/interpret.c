#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;
extern hash_table_t *ht;
extern Environment *env;
#define HASH_TABLE_SIZE 1024;


void interpret(BlockStmt *stmt_lst)
{
  env = create_env(NULL);

  for (size_t i = 0; i < stmt_lst->count; i++)
  {
    execute(env, stmt_lst->stmts[i]);
  }
}
