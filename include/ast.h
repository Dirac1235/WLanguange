#ifndef AST_H
#define AST_H


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>

typedef enum
{
  TKN_LITERAL,
  TKN_STRING,
  TKN_NUMBER,
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
  EXPR_TOKEN
} TYPE_EXPR;

typedef struct Expr Expr;

typedef struct Token
{
  TokenType tkn;
  long double f_lexeme;
  char *s_lexeme;
  char *literal;
} Token;

typedef struct Binary
{
  TYPE_EXPR type;
  Token *token;
  Expr *left;
  Expr *right;
} Binary;

typedef struct Unary
{
  TYPE_EXPR type;
  Token *token;
  Expr *expr;
} Unary;

typedef struct Group
{
  TYPE_EXPR type;
  Expr *expr;
} Group;

typedef struct Expr
{
  TYPE_EXPR type;
  union
  {
    Binary *binary;
    Unary *unary;
    Group *group;
    Token *token;
  };
} Expr;

char *find_op(TokenType type);
Expr **expr_root;
size_t expr_root_count;
size_t line_number;
size_t column_number;

Token *makeNumToken(TokenType op, long double lex);
Token *makeStrToken(TokenType op, char *lex);
Expr *makeStrTokenExpr(TokenType op, char *lex);
Expr *makeNumTokenExpr(TokenType op, long double lex);
Expr *makeUnaryExpr(TokenType op, Expr *right);
Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right);
Expr *makeGroupExpr(Expr *inner);

void printAst(Expr **expr_lst, size_t expr_root_count);
void interpret(Expr **expr, size_t expr_root_count);

#endif