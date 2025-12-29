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
     INUMBER = 264,
     DNUMBER = 265,
     STRING = 266,
     IDENTIFIER = 267,
     NEWLINE = 268,
     PLUS = 269,
     SUBTRACT = 270,
     MULTIPLY = 271,
     DIVIDE = 272,
     MOD = 273,
     PRINT = 274,
     LEFT_PAREN = 275,
     RIGHT_PAREN = 276
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define STR 260
#define BOOL 261
#define EQUAL 262
#define NUM 263
#define INUMBER 264
#define DNUMBER 265
#define STRING 266
#define IDENTIFIER 267
#define NEWLINE 268
#define PLUS 269
#define SUBTRACT 270
#define MULTIPLY 271
#define DIVIDE 272
#define MOD 273
#define PRINT 274
#define LEFT_PAREN 275
#define RIGHT_PAREN 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "src/parser.y"
{
    struct Expr *expr_val;
    struct Stmt *stmt_val;
    char* str_val;
    int i_val;
    double d_val;
}
/* Line 1529 of yacc.c.  */
#line 99 "build/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

