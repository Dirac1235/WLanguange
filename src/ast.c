#include "../include/ast.h"


Token *numToken(TokenType op, long double lex)
// TODO: handle numbers and other characters
{
  Token *t = (Token *)malloc(sizeof(Token));
  t->tkn = op;
  t->f_lexeme = lex;
  return t;
}

Token *strToken(TokenType op, char *lex)
// TODO: handle numbers and other characters
{
  Token *t = (Token *)malloc(sizeof(Token));
  t->tkn = op;
  t->s_lexeme = strdup(lex);
  return t;
}

Expr *strExpr(TokenType op, char *lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = strToken(op, lex);
  return expr;
}

Expr *numExpr(TokenType op, long double lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = numToken(op, lex);
  return expr;
}

Expr *makeUnaryExpr(TokenType op, Expr *right)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_UNARY;

  Unary *u = (Unary *)malloc(sizeof(Unary));

  u->token = strToken(op, find_op(op));
  u->expr = right;

  expr->unary = u;
  return expr;
}

Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_BINARY;

  Binary *b = (Binary *)malloc(sizeof(Binary));
  b->token = strToken(op, find_op(op));
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

Stmt *makeDeclStmt(NODE_TYPE type, char *identifier, Expr *decl)
{
  
  Stmt *stmt = (Stmt *)malloc(sizeof(Stmt));
  stmt->type = STMT_DECL;
  DeclStmt *dst = (DeclStmt *)malloc(sizeof(DeclStmt));
  stmt->decl_stmt = dst;
  stmt->decl_stmt->type = type;
  stmt->decl_stmt->expr = decl;
  stmt->decl_stmt->identifier = identifier;
  return stmt;
}

Stmt *makePrintStmt(Expr *expr)
{
  Stmt *stmt = (Stmt *)malloc(sizeof(Stmt));
  stmt->type = STMT_PRINT;
  PrintStmt *pst = (PrintStmt *)malloc(sizeof(PrintStmt));
  stmt->print_stmt = pst;
  stmt->print_stmt->expr = expr;
  return stmt;
}

Stmt **addStmt(Stmt **stmt_root, size_t stmt_root_count)
{
  Stmt **tmp = realloc(stmt_root, (stmt_root_count + 1) * sizeof(Expr *));

  if (!tmp)
  {
    fprintf(stdout, "out of memory");
    exit(1);
  }
  return tmp;
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
