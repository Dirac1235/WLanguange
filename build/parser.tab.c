/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

#include "../include/global.h"

extern BlockStmt *stmt_root;
extern Expr** arg_lst;
extern size_t arg_count;

size_t _count = 0;

extern size_t line_number;
extern size_t column_number;

extern int yylex(void);

void yyerror(char *s) {
    fprintf(stderr, "%s \n", s);
};



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 208 "build/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "build/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      44,    50,    58,    65,    74,    78,    84,    91,    95,   100,
     103,   108,   111,   116,   119,   124,   125,   127,   129,   133,
     135,   138,   141,   145,   149,   153,   157,   161,   165,   169,
     173,   177,   181,   185,   189,   193,   195,   197,   199,   201,
     203,   205,   209
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    -1,    43,    44,    -1,    37,
      -1,    45,    37,    -1,    46,    37,    -1,    45,    -1,    46,
      -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,    47,
      -1,    48,    -1,    50,    -1,    49,    -1,    51,    -1,    30,
      35,    58,    36,    -1,    31,    35,    58,    36,    46,    -1,
      31,    35,    58,    36,    46,    34,    46,    -1,    31,    35,
      58,    36,    37,    46,    -1,    31,    35,    58,    36,    37,
      46,    34,    46,    -1,    38,    43,    39,    -1,    32,    35,
      58,    36,    46,    -1,    32,    35,    58,    36,    37,    46,
      -1,    15,     7,    58,    -1,     3,    15,     7,    58,    -1,
       3,    15,    -1,     4,    15,     7,    58,    -1,     4,    15,
      -1,     5,    15,     7,    58,    -1,     5,    15,    -1,     6,
      15,     7,    58,    -1,    -1,    57,    -1,    59,    -1,    57,
       8,    59,    -1,    59,    -1,    17,    58,    -1,    16,    58,
      -1,    58,    19,    58,    -1,    58,    18,    58,    -1,    58,
      16,    58,    -1,    58,    17,    58,    -1,    58,    20,    58,
      -1,    58,    22,    58,    -1,    58,    23,    58,    -1,    58,
      26,    58,    -1,    58,    27,    58,    -1,    58,    25,    58,
      -1,    58,    24,    58,    -1,    58,    29,    58,    -1,    58,
      28,    58,    -1,    12,    -1,    13,    -1,    11,    -1,    10,
      -1,    14,    -1,    15,    -1,    35,    58,    36,    -1,    15,
      35,    56,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    74,    78,    88,    89,    90,    91,    92,
      96,    97,    98,    99,   103,   104,   105,   106,   107,   111,
     119,   123,   127,   131,   139,   146,   150,   157,   165,   170,
     177,   183,   192,   197,   206,   213,   214,   218,   222,   229,
     230,   234,   239,   248,   259,   269,   278,   289,   293,   297,
     301,   305,   309,   313,   317,   324,   325,   326,   327,   328,
     329,   330,   331
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "STR", "BOOL", "EQUAL",
  "COMMA", "NUM", "BTRUE", "BFALSE", "INUMBER", "DNUMBER", "STRING",
  "IDENTIFIER", "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", "MOD", "BANG",
  "BANGEQUAL", "EQUALEQUAL", "GREATER", "LESS", "GREATEREQUAL",
  "LESSEQUAL", "AND", "OR", "PRINT", "IF", "WHILE", "FUN", "ELSE",
  "LEFT_PAREN", "RIGHT_PAREN", "NEWLINE", "LEFT_CURLY", "RIGHT_CURLY",
  "IFX", "$accept", "start", "program", "line", "declaration", "stmt",
  "print_stmt", "if_stmt", "block", "while_stmt", "assignment", "int_decl",
  "double_decl", "str_decl", "bool_decl", "args_opt", "args", "expr",
  "primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    46,    46,    46,    46,    46,    47,
      48,    48,    48,    48,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     7,     6,     8,     3,     5,     6,     3,     4,     2,
       4,     2,     4,     2,     4,     0,     1,     1,     3,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     3,     4,     8,     9,    14,    15,    17,
      16,    18,    10,    11,    12,    13,    29,    31,    33,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     0,
       0,    58,    57,    55,    56,    59,    60,     0,     0,     0,
      27,    39,     0,     0,     0,    24,    28,    30,    32,    34,
      35,    41,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    36,    37,    61,    44,    45,    43,    42,    46,    47,
      48,    52,    51,    49,    50,    54,    53,     0,    20,     0,
      25,    62,     0,    22,     0,    26,    38,     0,    21,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    80,    81,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
     -57,     3,    47,   -57,   -10,    -5,    -4,    -3,     6,   -21,
     -20,   -16,   -57,   -57,   -57,   -13,   -12,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,    19,    20,    21,    22,
      59,    59,    59,    59,    17,   -57,   -57,    59,    59,    59,
      59,   -57,   -57,   -57,   -57,   -57,    23,    59,    59,    59,
     171,   -57,   111,   126,   141,   -57,   171,   171,   171,   171,
      87,   183,   183,   156,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,   -57,    74,    77,
      -6,    49,   -57,   -57,   183,   183,   193,   193,   171,   171,
     171,   171,   171,   171,   171,   171,   171,    88,    25,    88,
     -57,   -57,    87,    26,    88,   -57,   -57,    88,   -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,    18,   -57,   -57,   -11,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -31,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    53,    54,     3,    82,    26,    56,    57,    58,    59,
      27,    28,    29,    30,    31,    32,    61,    62,    63,    33,
       4,     5,     6,     7,    35,    36,    37,    38,    39,    40,
     101,    34,     8,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   106,     9,    10,    11,
       4,     5,     6,     7,    12,    13,    55,   102,    60,   104,
     107,     0,     8,     0,     0,     0,     0,    98,   100,    41,
      42,    43,    44,    45,    46,    47,    48,     9,    10,    11,
       0,     0,     0,     0,    12,    13,   103,     0,   105,     8,
       0,     0,     8,   108,    49,     0,   109,    41,    42,    43,
      44,    45,    46,     8,     9,    10,    11,     9,    10,    11,
       0,    97,    13,     0,    99,    13,     0,     0,     9,    10,
      11,     0,    49,     0,     0,     0,    13,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    64,    65,    66,    67,    68,    77,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    64,    65,    66,
      67,    68,    78,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    64,    65,    66,    67,    68,    79,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    64,    65,    66,
      67,    68,    83,    69,    70,    71,    72,    73,    74,    75,
      76,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76
};

static const yytype_int8 yycheck[] =
{
      31,    32,    33,     0,    60,    15,    37,    38,    39,    40,
      15,    15,    15,     7,    35,    35,    47,    48,    49,    35,
       3,     4,     5,     6,    37,    37,     7,     7,     7,     7,
      36,    13,    15,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   102,    30,    31,    32,
       3,     4,     5,     6,    37,    38,    39,     8,    35,    34,
      34,    -1,    15,    -1,    -1,    -1,    -1,    78,    79,    10,
      11,    12,    13,    14,    15,    16,    17,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    97,    -1,    99,    15,
      -1,    -1,    15,   104,    35,    -1,   107,    10,    11,    12,
      13,    14,    15,    15,    30,    31,    32,    30,    31,    32,
      -1,    37,    38,    -1,    37,    38,    -1,    -1,    30,    31,
      32,    -1,    35,    -1,    -1,    -1,    38,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    16,    17,    18,    19,    20,    36,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    16,    17,    18,
      19,    20,    36,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    16,    17,    18,    19,    20,    36,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    16,    17,    18,
      19,    20,    36,    22,    23,    24,    25,    26,    27,    28,
      29,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,     3,     4,     5,     6,    15,    30,
      31,    32,    37,    38,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    15,    15,    15,    15,
       7,    35,    35,    35,    43,    37,    37,     7,     7,     7,
       7,    10,    11,    12,    13,    14,    15,    16,    17,    35,
      58,    59,    58,    58,    58,    39,    58,    58,    58,    58,
      35,    58,    58,    58,    16,    17,    18,    19,    20,    22,
      23,    24,    25,    26,    27,    28,    29,    36,    36,    36,
      56,    57,    59,    36,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    37,    46,    37,
      46,    36,     8,    46,    34,    46,    59,    34,    46,    46
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 66 "src/parser.y"
    { 
        (yyval.block_stmt) = (yyvsp[(1) - (1)].block_stmt); 
        stmt_root = (yyvsp[(1) - (1)].block_stmt);
    ;}
    break;

  case 3:
#line 74 "src/parser.y"
    {
        (yyval.block_stmt) = make_block_stmt();
        _count = 0; 
    ;}
    break;

  case 4:
#line 79 "src/parser.y"
    {
        if ((yyvsp[(2) - (2)].stmt_val) != NULL) {
            add_to_block((yyvsp[(1) - (2)].block_stmt), (yyvsp[(2) - (2)].stmt_val));
        } 
        (yyval.block_stmt) = (yyvsp[(1) - (2)].block_stmt);
    ;}
    break;

  case 5:
#line 88 "src/parser.y"
    { (yyval.stmt_val) = NULL ;}
    break;

  case 6:
#line 89 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (2)].stmt_val);  ;}
    break;

  case 7:
#line 90 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (2)].stmt_val);  ;}
    break;

  case 8:
#line 91 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 9:
#line 92 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 10:
#line 96 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val); ;}
    break;

  case 11:
#line 97 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val); ;}
    break;

  case 12:
#line 98 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val); ;}
    break;

  case 13:
#line 99 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val); ;}
    break;

  case 14:
#line 103 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 15:
#line 104 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 16:
#line 105 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 17:
#line 106 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 18:
#line 107 "src/parser.y"
    { (yyval.stmt_val) = (yyvsp[(1) - (1)].stmt_val);  ;}
    break;

  case 19:
#line 112 "src/parser.y"
    {
        Stmt *print = makePrintStmt((yyvsp[(3) - (4)].expr_val));
        (yyval.stmt_val) = print;
    ;}
    break;

  case 20:
#line 120 "src/parser.y"
    { 
        (yyval.stmt_val) = makeIfStmt((yyvsp[(3) - (5)].expr_val), (yyvsp[(5) - (5)].stmt_val), NULL); 
    ;}
    break;

  case 21:
#line 124 "src/parser.y"
    { 
        (yyval.stmt_val) = makeIfStmt((yyvsp[(3) - (7)].expr_val), (yyvsp[(5) - (7)].stmt_val), (yyvsp[(7) - (7)].stmt_val)); 
    ;}
    break;

  case 22:
#line 128 "src/parser.y"
    { 
        (yyval.stmt_val) = makeIfStmt((yyvsp[(3) - (6)].expr_val), (yyvsp[(6) - (6)].stmt_val), NULL); 
    ;}
    break;

  case 23:
#line 132 "src/parser.y"
    { 
        (yyval.stmt_val) = makeIfStmt((yyvsp[(3) - (8)].expr_val), (yyvsp[(6) - (8)].stmt_val), (yyvsp[(8) - (8)].stmt_val)); 
    ;}
    break;

  case 24:
#line 140 "src/parser.y"
    {
        (yyval.stmt_val) = makeBlockStmt((yyvsp[(2) - (3)].block_stmt));
    ;}
    break;

  case 25:
#line 147 "src/parser.y"
    {
        (yyval.stmt_val) = makeWhileStmt((yyvsp[(3) - (5)].expr_val), (yyvsp[(5) - (5)].stmt_val));
    ;}
    break;

  case 26:
#line 151 "src/parser.y"
    {
        (yyval.stmt_val) = makeWhileStmt((yyvsp[(3) - (6)].expr_val), (yyvsp[(6) - (6)].stmt_val));
    ;}
    break;

  case 27:
#line 158 "src/parser.y"
    {
        Stmt *ass_stmt = makeAssStmt((yyvsp[(1) - (3)].s_val), (yyvsp[(3) - (3)].expr_val));
        (yyval.stmt_val) = ass_stmt;
    ;}
    break;

  case 28:
#line 166 "src/parser.y"
    {
        Stmt *num_d = makeDeclStmt(STMT_INT, (yyvsp[(2) - (4)].s_val), (yyvsp[(4) - (4)].expr_val));
        (yyval.stmt_val) = num_d;
    ;}
    break;

  case 29:
#line 171 "src/parser.y"
    {
        Stmt *num_d = makeDeclStmt(STMT_INT, (yyvsp[(2) - (2)].s_val), 0);
        (yyval.stmt_val) = num_d;
    ;}
    break;

  case 30:
#line 178 "src/parser.y"
    {
        Stmt *num_d = makeDeclStmt(STMT_DOUBLE, (yyvsp[(2) - (4)].s_val), (yyvsp[(4) - (4)].expr_val));
        (yyval.stmt_val) = num_d;

    ;}
    break;

  case 31:
#line 184 "src/parser.y"
    {
        Stmt *num_d = makeDeclStmt(STMT_DOUBLE, (yyvsp[(2) - (2)].s_val), 0);
        (yyval.stmt_val) = num_d;

    ;}
    break;

  case 32:
#line 193 "src/parser.y"
    {
        Stmt *str_d = makeDeclStmt(STMT_STR, (yyvsp[(2) - (4)].s_val), (yyvsp[(4) - (4)].expr_val));
        (yyval.stmt_val) = str_d;
    ;}
    break;

  case 33:
#line 198 "src/parser.y"
    {
        Stmt *str_d = makeDeclStmt(STMT_STR, (yyvsp[(2) - (2)].s_val), NULL);
        (yyval.stmt_val) = str_d;
    ;}
    break;

  case 34:
#line 207 "src/parser.y"
    {
        Stmt *bool_d = makeDeclStmt(STMT_BOOL, (yyvsp[(2) - (4)].s_val), (yyvsp[(4) - (4)].expr_val));
        (yyval.stmt_val) = bool_d;
    ;}
    break;

  case 35:
#line 213 "src/parser.y"
    { (yyval.expr_lst) = NULL; ;}
    break;

  case 36:
#line 214 "src/parser.y"
    { (yyval.expr_lst) = (yyvsp[(1) - (1)].expr_lst);   ;}
    break;

  case 37:
#line 219 "src/parser.y"
    { 
        (yyval.expr_lst) = add_to_args(arg_lst, (yyvsp[(1) - (1)].expr_val), &arg_count);
    ;}
    break;

  case 38:
#line 223 "src/parser.y"
    {
        (yyval.expr_lst) = add_to_args(arg_lst, (yyvsp[(3) - (3)].expr_val), &arg_count);
    ;}
    break;

  case 39:
#line 229 "src/parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val) ;}
    break;

  case 40:
#line 231 "src/parser.y"
    {
        (yyval.expr_val) = makeUnaryExpr(TKN_OP_SUB, (yyvsp[(2) - (2)].expr_val));
    ;}
    break;

  case 41:
#line 235 "src/parser.y"
    {
        (yyval.expr_val) = makeUnaryExpr(TKN_OP_ADD, (yyvsp[(2) - (2)].expr_val));

    ;}
    break;

  case 42:
#line 240 "src/parser.y"
    { 
        if (((yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_STRING && ((yyvsp[(3) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_DOUBLE)) || ( ((yyvsp[(1) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_DOUBLE) && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_STRING) ) {
            syntax_error(line_number, column_number,"Unsupported operaition: / on type %s and %s ", tt_to_str((yyvsp[(1) - (3)].expr_val)->token->tkn), tt_to_str((yyvsp[(3) - (3)].expr_val)->token->tkn));
            exit(1);
            }
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_DIV, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
        
    ;}
    break;

  case 43:
#line 249 "src/parser.y"
    { 
        if (((yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_STRING && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_DOUBLE) || ( (yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_DOUBLE && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_STRING) ) {
            syntax_error(line_number, column_number,"Unsupported operaition: '*' on type %s and %s ", tt_to_str((yyvsp[(1) - (3)].expr_val)->token->tkn), tt_to_str((yyvsp[(3) - (3)].expr_val)->token->tkn));

            exit(1);
        }
         (yyval.expr_val) = makeBinaryExpr(TKN_OP_MUL, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));


    ;}
    break;

  case 44:
#line 260 "src/parser.y"
    {    
        if (((yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_STRING && ((yyvsp[(3) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_DOUBLE)) || ( ((yyvsp[(1) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_DOUBLE) && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_STRING) ) {
           syntax_error(line_number, column_number, "Unsupportd operation: '+' on type %s and %s", tt_to_str((yyvsp[(1) - (3)].expr_val)->token->tkn), tt_to_str((yyvsp[(3) - (3)].expr_val)->token->tkn));

            exit(1);
        }
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_ADD, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));

    ;}
    break;

  case 45:
#line 270 "src/parser.y"
    { 
        if (((yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_STRING && ((yyvsp[(3) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_DOUBLE)) || ( ((yyvsp[(1) - (3)].expr_val)->token->tkn ==TKN_INT || (yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_DOUBLE) && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_STRING) ) {
            syntax_error(line_number, column_number, "Unsupportd operation: '-' on type %s and %s", tt_to_str((yyvsp[(1) - (3)].expr_val)->token->tkn), tt_to_str((yyvsp[(3) - (3)].expr_val)->token->tkn));
            exit(1);
        }
        (yyval.expr_val)  = makeBinaryExpr(TKN_OP_SUB, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));

    ;}
    break;

  case 46:
#line 279 "src/parser.y"
    { 
        if ((yyvsp[(1) - (3)].expr_val)->token->tkn == TKN_INT && (yyvsp[(3) - (3)].expr_val)->token->tkn == TKN_INT)
            (yyval.expr_val) = makeBinaryExpr(TKN_OP_MOD, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
        else {
            syntax_error(line_number, column_number, "Unsupportd operation: '%%' on type %s and %s", tt_to_str((yyvsp[(1) - (3)].expr_val)->token->tkn), tt_to_str((yyvsp[(3) - (3)].expr_val)->token->tkn));
            exit(1);
            
        }

    ;}
    break;

  case 47:
#line 290 "src/parser.y"
    {       
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_BANG_EQUAL, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 48:
#line 294 "src/parser.y"
    { 
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_EQUALEQUAL, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 49:
#line 298 "src/parser.y"
    { 
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_GREATEREQUAL, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 50:
#line 302 "src/parser.y"
    { 
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_LESSEQUAL, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 51:
#line 306 "src/parser.y"
    { 
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_LESS, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 52:
#line 310 "src/parser.y"
    { 
        (yyval.expr_val) = makeBinaryExpr(TKN_OP_GREATER, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 53:
#line 314 "src/parser.y"
    {
        (yyval.expr_val) = makeLogicalExpr(TKN_OP_OR, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 54:
#line 318 "src/parser.y"
    {
        (yyval.expr_val) = makeLogicalExpr(TKN_OP_AND, (yyvsp[(1) - (3)].expr_val), (yyvsp[(3) - (3)].expr_val));
    ;}
    break;

  case 55:
#line 324 "src/parser.y"
    { (yyval.expr_val) = i_expr((yyvsp[(1) - (1)].i_val));          ;}
    break;

  case 56:
#line 325 "src/parser.y"
    { (yyval.expr_val) = d_expr((yyvsp[(1) - (1)].d_val));          ;}
    break;

  case 57:
#line 326 "src/parser.y"
    { (yyval.expr_val) = b_expr((yyvsp[(1) - (1)].b_val));          ;}
    break;

  case 58:
#line 327 "src/parser.y"
    { (yyval.expr_val) = b_expr((yyvsp[(1) - (1)].b_val));          ;}
    break;

  case 59:
#line 328 "src/parser.y"
    { (yyval.expr_val) = s_expr((yyvsp[(1) - (1)].s_val));          ;}
    break;

  case 60:
#line 329 "src/parser.y"
    { (yyval.expr_val) = l_expr((yyvsp[(1) - (1)].s_val));          ;}
    break;

  case 61:
#line 330 "src/parser.y"
    { (yyval.expr_val) = makeGroupExpr((yyvsp[(2) - (3)].expr_val));   ;}
    break;

  case 62:
#line 331 "src/parser.y"
    { (yyval.expr_val) = makeCall((yyvsp[(1) - (4)].s_val), (yyvsp[(3) - (4)].expr_lst));    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1961 "build/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 333 "src/parser.y"


