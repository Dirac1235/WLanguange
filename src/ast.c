#include "../include/ast.h"

extern hash_table_t *ht;

Token *i_token(int lex)
{
  Token *t = (Token *)malloc(sizeof(Token));
  t->tkn = TKN_INT;
  t->i_lexeme = lex;
  return t;
}

Token *b_token(int lex)
{
  Token *t = (Token *)malloc(sizeof(Token));
  if (lex)
  {
    t->b_lexeme = true;
    t->tkn = TKN_OP_TRUE;
  }
  else
  {
    t->b_lexeme = false;
    t->tkn = TKN_OP_FALSE;
  };

  return t;
}

Token *d_token(long double lex)
{
  Token *t = (Token *)malloc(sizeof(Token));
  t->tkn = TKN_DOUBLE;
  t->f_lexeme = lex;
  return t;
}

Token *s_token(TokenType op, char *lex)
{
  Token *t = (Token *)malloc(sizeof(Token));
  t->tkn = op;
  t->s_lexeme = strdup(lex);
  return t;
}

// Expressions 

Expr *l_expr(char *lit)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  Token *t = (Token *)malloc(sizeof(Token));
  expr->token = t;
  expr->token->tkn = TKN_LITERAL;
  expr->token->literal = strdup(lit);
  return expr;
}

Expr *s_expr(char *lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = s_token(TKN_STRING, lex);
  return expr;
}

Expr *i_expr(int lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = i_token(lex);
  return expr;
}

Expr *b_expr(int lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = b_token(lex);
  return expr;
}

Expr *d_expr(long double lex)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_TOKEN;
  expr->token = d_token(lex);
  return expr;
}

Expr *makeUnaryExpr(TokenType op, Expr *right)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_UNARY;

  Unary *u = (Unary *)malloc(sizeof(Unary));
  
  u->token = s_token(op, tt_to_str(op));
  u->expr = right;

  expr->unary = u;
  return expr;
}

Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right)
{
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_BINARY;

  Binary *b = (Binary *)malloc(sizeof(Binary));
  b->token = s_token(op, tt_to_str(op));
  b->left = left;
  b->right = right;

  expr->binary = b;
  return expr;
}

Expr *makeLogicalExpr(TokenType op, Expr *left, Expr *right) {
  Expr *expr = (Expr *)malloc(sizeof(Expr));
  expr->type = EXPR_LOGICAL;

  Logical *b = (Logical *)malloc(sizeof(Logical));
  b->token = s_token(op, tt_to_str(op));
  b->left = left;
  b->right = right;

  expr->logical = b;
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

// Statements

Stmt *makeDeclStmt(NODE_TYPE type, char *identifier, Expr *decl)
{

  Stmt *stmt = (Stmt *)malloc(sizeof(Stmt));
  stmt->type = type;
  DeclStmt *dst = (DeclStmt *)malloc(sizeof(DeclStmt));
  stmt->decl_stmt = dst;
  stmt->decl_stmt->expr = decl;
  stmt->decl_stmt->identifier = identifier;
  return stmt;
}

Stmt *makeAssStmt(char *identifier, Expr *decl)
{
  Stmt *stmt = (Stmt *)malloc(sizeof(Stmt));
  stmt->type = STMT_ASS;
  DeclStmt *dst = (DeclStmt *)malloc(sizeof(DeclStmt));
  stmt->decl_stmt = dst;
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
