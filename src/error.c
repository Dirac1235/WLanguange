#include "../include/error.h"

void runtime_error(const char *fmt, va_list args)
{
  fprintf(stderr, "Runtime error: ");
  vfprintf(stderr, fmt, args);
}

void syntax_error( size_t line, size_t column_number, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  fprintf(stderr, "Syntax error: at line %zu:%zu \n", line, column_number);
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  
  va_end(args);
}

