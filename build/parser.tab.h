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
     COMMA = 263,
     NUM = 264,
     BTRUE = 265,
     BFALSE = 266,
     INUMBER = 267,
     DNUMBER = 268,
     STRING = 269,
     IDENTIFIER = 270,
     PLUS = 271,
     SUBTRACT = 272,
     MULTIPLY = 273,
     DIVIDE = 274,
     MOD = 275,
     BANG = 276,
     BANGEQUAL = 277,
     EQUALEQUAL = 278,
     GREATER = 279,
     LESS = 280,
     GREATEREQUAL = 281,
     LESSEQUAL = 282,
     AND = 283,
     OR = 284,
     PRINT = 285,
     IF = 286,
     WHILE = 287,
     FUN = 288,
     ELSE = 289,
     LEFT_PAREN = 290,
     RIGHT_PAREN = 291,
     NEWLINE = 292,
     LEFT_CURLY = 293,
     RIGHT_CURLY = 294,
     IFX = 295
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define STR 260
#define BOOL 261
#define EQUAL 262
#define COMMA 263
#define NUM 264
#define BTRUE 265
#define BFALSE 266
#define INUMBER 267
#define DNUMBER 268
#define STRING 269
#define IDENTIFIER 270
#define PLUS 271
#define SUBTRACT 272
#define MULTIPLY 273
#define DIVIDE 274
#define MOD 275
#define BANG 276
#define BANGEQUAL 277
#define EQUALEQUAL 278
#define GREATER 279
#define LESS 280
#define GREATEREQUAL 281
#define LESSEQUAL 282
#define AND 283
#define OR 284
#define PRINT 285
#define IF 286
#define WHILE 287
#define FUN 288
#define ELSE 289
#define LEFT_PAREN 290
#define RIGHT_PAREN 291
#define NEWLINE 292
#define LEFT_CURLY 293
#define RIGHT_CURLY 294
#define IFX 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "src/parser.y"
{
    struct Expr* expr_val;
    struct Expr** expr_lst;
    struct Stmt* stmt_val;
    struct BlockStmt *block_stmt;
    
    char* s_val;
    int i_val;
    int b_val;
    double d_val;
}
/* Line 1529 of yacc.c.  */
#line 141 "build/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

