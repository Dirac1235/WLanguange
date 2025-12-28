#ifndef AST_H
#define AST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>
#include "token.h"

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

Token *numToken(TokenType op, long double lex);
Token *strToken(TokenType op, char *lex);
Expr *strExpr(TokenType op, char *lex);
Expr *numExpr(TokenType op, long double lex);
Expr *makeUnaryExpr(TokenType op, Expr *right);
Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right);
Expr *makeGroupExpr(Expr *inner);

void printAst(Expr **expr_lst, size_t expr_root_count);
void interpret(Expr **expr, size_t expr_root_count);

#endif