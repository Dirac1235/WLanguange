#ifndef AST_H_
#define AST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>
#include "token.h"
#include "hash_table.h"
#include "helper.h"

typedef struct Expr Expr;
typedef struct Stmt Stmt;

typedef struct Token
{
  TokenType tkn;
  int i_lexeme;
  double f_lexeme;
  char *s_lexeme;
  bool b_lexeme;
  char *literal;
} Token;

typedef struct Binary
{
  Token *token;
  Expr *left;
  Expr *right;
} Binary;

typedef struct Logical
{
  Token *token;
  Expr *left;
  Expr *right;
} Logical;

typedef struct Unary
{
  Token *token;
  Expr *expr;
} Unary;

typedef struct Group
{
  NODE_TYPE type;
  Expr *expr;
} Group;

typedef struct Expr
{
  NODE_TYPE type;
  union
  {
    Binary *binary;
    Logical *logical;
    Unary *unary;
    Group *group;
    Token *token;
  };
} Expr;

typedef struct
{
  Expr *expr;
} PrintStmt;

typedef struct
{
  char *identifier;
  Expr *expr;
} DeclStmt;



typedef struct BlockStmt
{
  Stmt **stmts;
  size_t count;
  size_t capacity;
} BlockStmt;

typedef struct IfStmt
{
  Expr *expr;
  Stmt *ifs;
  Stmt *els;
} IfStmt;

typedef struct Stmt
{
  NODE_TYPE type;
  union
  {
    PrintStmt *print_stmt;
    DeclStmt *decl_stmt;
    BlockStmt *block_stmt;
    IfStmt *if_stmt;
  };
} Stmt;

BlockStmt *stmt_root;
size_t line_number;
size_t column_number;
hash_table_t *ht;
Environment *env;

Token *i_token(int lex);
Token *b_token(int lex);
Token *d_token(long double lex);
Token *s_token(TokenType op, char *lex);

Expr *s_expr(char *lex);
Expr *i_expr(int lex);
Expr *d_expr(long double lex);
Expr *l_expr(char *lit);
Expr *b_expr(int lex);

Expr *makeUnaryExpr(TokenType op, Expr *right);
Expr *makeBinaryExpr(TokenType op, Expr *left, Expr *right);
Expr *makeLogicalExpr(TokenType op, Expr *left, Expr *right);
Expr *makeGroupExpr(Expr *inner);
Stmt *makeDeclStmt(NODE_TYPE type, char *identifier, Expr *decl);
Stmt *makePrintStmt(Expr *expr);
Stmt *makeAssStmt(char *identifier, Expr *decl);
Stmt *makeBlockStmt(BlockStmt *bs);
Stmt *makeIfStmt(Expr *expr, Stmt *ifs, Stmt *els);

void printAst(Expr **expr_lst, size_t expr_root_count);
void interpret(BlockStmt *stmt_lst);

void add_to_block(BlockStmt *bs, Stmt *stmt);
BlockStmt *make_block_stmt();

Object *evaluate(Expr *expr);
void execute(Environment *env, Stmt *stmt);
void executeBlock(BlockStmt *b_stmt);

#endif