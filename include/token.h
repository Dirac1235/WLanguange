#ifndef TOKEN_H_
#define TOKEN_H_

typedef enum
{
  TKN_LITERAL,
  TKN_STRING,
  TKN_NUMBER,
  TKN_INT,
  TKN_DOUBLE,
  TKN_OP_ADD,
  TKN_OP_SUB,
  TKN_OP_MUL,
  TKN_OP_DIV,
  TKN_OP_MOD
   
} TokenType;

typedef enum
{
  EXPR_BINARY,
  EXPR_UNARY,
  EXPR_GROUP,
  EXPR_TOKEN,
  STMT_PRINT,
  STMT_DECL,
  STMT_INT,
  STMT_DOUBLE,
  STMT_STR,
  STMT_BOOL,
  STMT_ASS,
  STMT_IFELSE
} NODE_TYPE;

typedef enum {
  TYPE_INT,
  TYPE_DOUBLE,
  TYPE_STR,
} ObjectType;

typedef struct {
    ObjectType type;
    union {
        int i;
        double d;
        char *s;
    } data;
} Object;

#endif