#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include "ast.h"

typedef struct Token Token;
typedef struct Expr Expr;

typedef enum
{
    ERR_NOTE,
    ERR_WARNING,
    ERR_ERROR,
    ERR_FATAL
} ErrorLevel;

typedef enum
{
    ERR_SYNTAX,
    ERR_TYPE,
    ERR_RUNTIME,
    ERR_INTERNAL
} ErrorCategory;


/* Report error at a token */
void error_at_token(
    ErrorLevel level,
    ErrorCategory category,
    Token *token,
    const char *fmt,
    ...);

/* Same but underline full token */
void error_at_token_range(
    ErrorLevel level,
    ErrorCategory category,
    Token *token,
    unsigned length,
    const char *fmt,
    ...);

/* Useful when error is tied to AST node */
void error_at_expr(ErrorLevel level, ErrorCategory category,  Expr *expr, const char *fmt, ...);

/* Used by Bison's yyerror */
void syntax_error( size_t line, size_t column_number, const char *fmt, ...);
/* Unexpected token error */
void error_unexpected_token( Token *token, const char *expected);

void runtime_error(const char *fmt, va_list args);

#endif /* ERROR_H */
