#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>
#include <stdbool.h>

/* Forward declarations to avoid heavy includes */
typedef struct Token Token;
typedef struct Expr  Expr;

/* =========================
   Error severity & category
   ========================= */

typedef enum {
    ERR_NOTE,
    ERR_WARNING,
    ERR_ERROR,
    ERR_FATAL
} ErrorLevel;

typedef enum {
    ERR_SYNTAX,
    ERR_TYPE,
    ERR_RUNTIME,
    ERR_INTERNAL
} ErrorCategory;

/* =========================
   Global error state
   ========================= */

/* Returns true if any error has been reported */
bool error_had_error(void);

/* Returns true if a fatal error occurred */
bool error_had_fatal(void);

/* Reset error state (useful for REPLs) */
void error_reset(void);

/* =========================
   Core reporting API
   ========================= */

/* Base diagnostic (all others call into this) */
void error_report(
    ErrorLevel level,
    ErrorCategory category,
    const char *filename,
    unsigned line,
    unsigned column,
    unsigned length,           /* token length or 1 */
    const char *fmt,
    ...
);

/* va_list version */
void error_reportv(
    ErrorLevel level,
    ErrorCategory category,
    const char *filename,
    unsigned line,
    unsigned column,
    unsigned length,
    const char *fmt,
    va_list args
);

/* =========================
   Token-based helpers
   ========================= */

/* Report error at a token */
void error_at_token(
    ErrorLevel level,
    ErrorCategory category,
    const Token *token,
    const char *fmt,
    ...
);

/* Same but underline full token */
void error_at_token_range(
    ErrorLevel level,
    ErrorCategory category,
    const Token *token,
    unsigned length,
    const char *fmt,
    ...
);

/* =========================
   Expression-based helpers
   ========================= */

/* Useful when error is tied to AST node */
void error_at_expr(
    ErrorLevel level,
    ErrorCategory category,
    const Expr *expr,
    const char *fmt,
    ...
);

/* =========================
   Parser / lexer helpers
   ========================= */

/* Used by Bison's yyerror */
void error_syntax(
    unsigned line,
    unsigned column,
    const char *fmt,
    ...
);

/* Unexpected token error */
void error_unexpected_token(
    const Token *token,
    const char *expected
);

/* =========================
   Runtime errors
   ========================= */

/* Runtime error tied to token */
void runtime_error(
    const Token *token,
    const char *fmt,
    ...
);

/* Abort immediately (internal compiler bug) */
void internal_error(
    const char *fmt,
    ...
);

/* =========================
   Source management hooks
   ========================= */

/* Set source file name */
void error_set_filename(const char *filename);

/* Provide access to source lines (for caret printing) */
void error_set_source(
    const char **lines,
    unsigned line_count
);

/* =========================
   Diagnostics formatting
   ========================= */

/* Enable/disable ANSI colors */
void error_enable_color(bool enabled);

/* =========================
   Termination
   ========================= */

/* Exit if fatal errors occurred */
void error_exit_if_needed(void);

#endif /* ERROR_H */
