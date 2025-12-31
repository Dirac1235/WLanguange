#include "../include/global.h"

extern size_t line_number;
extern size_t column_number;
extern hash_table_t *ht;
#define HASH_TABLE_SIZE 1024;



void interpret(Stmt **stmt_lst, size_t count)
{
  ht = hash_table_create(1024);
  for (size_t i = 0; i < count; i++)
  {
    execute(stmt_lst[i]);
  }
}
