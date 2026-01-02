/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     DOUBLE = 259,
     STR = 260,
     BOOL = 261,
     EQUAL = 262,
     NUM = 263,
     BTRUE = 264,
     BFALSE = 265,
     INUMBER = 266,
     DNUMBER = 267,
     STRING = 268,
     IDENTIFIER = 269,
     PLUS = 270,
     SUBTRACT = 271,
     MULTIPLY = 272,
     DIVIDE = 273,
     MOD = 274,
     BANG = 275,
     BANGEQUAL = 276,
     EQUALEQUAL = 277,
     GREATER = 278,
     LESS = 279,
     GREATEREQUAL = 280,
     LESSEQUAL = 281,
     AND = 282,
     OR = 283,
     PRINT = 284,
     IF = 285,
     WHILE = 286,
     FUN = 287,
     LEFT_PAREN = 288,
     RIGHT_PAREN = 289,
     NEWLINE = 290,
     LEFT_CURLY = 291,
     RIGHT_CURLY = 292
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define STR 260
#define BOOL 261
#define EQUAL 262
#define NUM 263
#define BTRUE 264
#define BFALSE 265
#define INUMBER 266
#define DNUMBER 267
#define STRING 268
#define IDENTIFIER 269
#define PLUS 270
#define SUBTRACT 271
#define MULTIPLY 272
#define DIVIDE 273
#define MOD 274
#define BANG 275
#define BANGEQUAL 276
#define EQUALEQUAL 277
#define GREATER 278
#define LESS 279
#define GREATEREQUAL 280
#define LESSEQUAL 281
#define AND 282
#define OR 283
#define PRINT 284
#define IF 285
#define WHILE 286
#define FUN 287
#define LEFT_PAREN 288
#define RIGHT_PAREN 289
#define NEWLINE 290
#define LEFT_CURLY 291
#define RIGHT_CURLY 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "src/parser.y"
{
    struct Expr *expr_val;
    struct Stmt *stmt_val;
    struct BlockStmt *block_stmt;

    char* s_val;
    int i_val;
    int b_val;
    double d_val;
}
/* Line 1529 of yacc.c.  */
#line 134 "build/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

