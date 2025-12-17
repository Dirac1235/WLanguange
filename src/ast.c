#include "../include/ast.h"

Token *makeNumToken(TokenType op, long double lex)
// TODO: handle numbers and other characters
{
  Token *t = (Token *) malloc(sizeof(Token));
  t->tkn = op;
  t->f_lexeme = lex;
  return t;
}

Token *makeStrToken(TokenType op, char *lex)
// TODO: handle numbers and other characters
{
  Token *t = (Token *) malloc(sizeof(Token));
  t->tkn = op;
  t->s_lexeme = strdup(lex);
  return t;
}

Expr *makeStrTokenExpr(TokenType op, char *lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = makeStrToken(op, lex);
  return expr;
}

Expr *makeNumTokenExpr(TokenType op, long double lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = makeNumToken(op, lex);
  return expr;
}

Expr *makeUnaryExpr(TokenType op, Expr *right)
{
  Expr *expr = (Expr *) malloc(sizeof(Expr));
  expr->type = EXPR_UNARY;

  Unary *u = (Unary *) malloc(sizeof(Unary));

  u->token = makeStrToken(op, find_op(op));
  u->expr = right;

  expr->unary = u;
  return expr;
}

Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_BINARY;

  Binary *b = (Binary *)malloc(sizeof(Binary));
  b->token = makeStrToken(op, find_op(op));
  b->left = left;
  b->right = right;

  expr->binary = b;
  return expr;
}

Expr *makeGroupExpr(Expr *inner)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_GROUP;

  Group *g = (Group *)malloc(sizeof(Group));
  g->expr = inner;

  expr->group = g;
  return expr;
}

char *find_op(TokenType type)
{
  switch (type)
  {
  case TKN_OP_ADD:
    return "+";
  case TKN_OP_SUB:
    return "-";
  case TKN_OP_DIV:
    return "/";
  case TKN_OP_MUL:
    return "*";
  default:
    fprintf(stderr, "wrong token");
    return "";
  }
}