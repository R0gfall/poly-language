/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gram.y"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>





extern int yylex();
extern int yylineno;
extern FILE* output;
extern FILE* report;



int yyerror(const char* s);



typedef struct buffer_polynom
{
        int coef[2000];
        int capacity;
        char var; 
        int priority;
        char name_var[100];
        //int fb_sign;
        
}b_poly;


typedef struct list_var 
{
    char name[100];
    b_poly* polynom;
    struct list_var* next_list;

}list;


list* first_list_var = NULL;

int line_of_error = 0;


void init_poly(b_poly* firstP);
void set_zero_poly(b_poly* firstP);
b_poly* poly_power_poly(b_poly* firstP, b_poly* secondP);
b_poly* add_poly_to_poly(b_poly* firstP, b_poly* secondP, int sign);
b_poly* multi_poly_to_poly(b_poly* firstP, b_poly* secondP);
void output_poly(b_poly* firstP);
void output_poly_to_file(b_poly* firstP);
b_poly* full_poly_power_poly(b_poly* firstP, b_poly* secondP);

void add_new_element(char* variable, b_poly* polynom);
b_poly* search_polynom_in_list(char* variable);



#line 133 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULTI = 260,                   /* MULTI  */
    POW = 261,                     /* POW  */
    EQUAL = 262,                   /* EQUAL  */
    OY = 263,                      /* OY  */
    PRINT = 264,                   /* PRINT  */
    NEXT = 265,                    /* NEXT  */
    OPENC = 266,                   /* OPENC  */
    CLOSEC = 267,                  /* CLOSEC  */
    NUMBER = 268,                  /* NUMBER  */
    VAR = 269,                     /* VAR  */
    VARIABLE = 270                 /* VARIABLE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PLUS 258
#define MINUS 259
#define MULTI 260
#define POW 261
#define EQUAL 262
#define OY 263
#define PRINT 264
#define NEXT 265
#define OPENC 266
#define CLOSEC 267
#define NUMBER 268
#define VAR 269
#define VARIABLE 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "gram.y"

    int number;
    int signal;
    int pow_number;
    char value;
    struct buffer_polynom* poly;
    char variable[100];
    //struct list_var* first_list_var;

#line 226 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULTI = 5,                      /* MULTI  */
  YYSYMBOL_POW = 6,                        /* POW  */
  YYSYMBOL_EQUAL = 7,                      /* EQUAL  */
  YYSYMBOL_OY = 8,                         /* OY  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_NEXT = 10,                      /* NEXT  */
  YYSYMBOL_OPENC = 11,                     /* OPENC  */
  YYSYMBOL_CLOSEC = 12,                    /* CLOSEC  */
  YYSYMBOL_NUMBER = 13,                    /* NUMBER  */
  YYSYMBOL_VAR = 14,                       /* VAR  */
  YYSYMBOL_VARIABLE = 15,                  /* VARIABLE  */
  YYSYMBOL_YYACCEPT = 16,                  /* $accept  */
  YYSYMBOL_main = 17,                      /* main  */
  YYSYMBOL_polynom = 18,                   /* polynom  */
  YYSYMBOL_peremen = 19,                   /* peremen  */
  YYSYMBOL_termmonom = 20,                 /* termmonom  */
  YYSYMBOL_monom = 21,                     /* monom  */
  YYSYMBOL_exprmonom = 22,                 /* exprmonom  */
  YYSYMBOL_expression = 23,                /* expression  */
  YYSYMBOL_sign = 24                       /* sign  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   68

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  23
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  37

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   103,   104,   113,   118,   124,   130,   139,
     147,   158,   170,   180,   185,   193,   204,   252,   261,   269,
     279,   290,   297,   301
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULTI", "POW", "EQUAL", "OY", "PRINT", "NEXT", "OPENC", "CLOSEC",
  "NUMBER", "VAR", "VARIABLE", "$accept", "main", "polynom", "peremen",
  "termmonom", "monom", "exprmonom", "expression", "sign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-13)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      24,   -13,   -13,    -8,    37,    24,    43,   -13,   -13,   -13,
      16,    10,   -13,     9,    48,   -13,     3,    53,    14,   -13,
       9,   -13,     2,   -13,    24,    53,    53,   -13,    53,    48,
      43,   -13,   -13,    48,   -13,   -13,     9
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    22,    23,     0,     0,     2,     0,    19,    20,    18,
       0,     0,     7,     5,    12,    15,    17,     0,     0,     8,
       6,     4,     0,     1,     2,     0,     0,    14,     0,    11,
       0,    21,     3,    10,    13,    16,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,    -1,   -13,    21,    -4,    -6,   -11,   -13,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    25,    22,    27,    21,     1,     2,    18,    25,    28,
      25,    29,     1,     2,    31,    34,    23,    35,    27,    33,
      24,    30,    27,    32,    25,    19,    36,     1,     2,     0,
       0,     0,     3,     4,     5,     6,     0,     7,     8,     9,
       1,     2,     0,     0,     0,     3,     1,     2,     6,     0,
       7,     8,     9,    26,     6,     0,     7,     8,     9,     6,
       0,     7,     8,     9,     6,     0,     7,     8,     9
};

static const yytype_int8 yycheck[] =
{
       4,    13,     6,    14,     5,     3,     4,    15,    20,     6,
      22,    17,     3,     4,    12,    26,     0,    28,    29,    25,
      10,     7,    33,    24,    36,     4,    30,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    -1,    13,    14,    15,
       3,     4,    -1,    -1,    -1,     8,     3,     4,    11,    -1,
      13,    14,    15,     5,    11,    -1,    13,    14,    15,    11,
      -1,    13,    14,    15,    11,    -1,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,     9,    10,    11,    13,    14,    15,
      17,    18,    19,    20,    21,    22,    23,    24,    15,    19,
      20,    17,    20,     0,    10,    24,     5,    22,     6,    21,
       7,    12,    17,    21,    22,    22,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    16,    17,    17,    17,    18,    18,    18,    18,    19,
      20,    20,    20,    21,    21,    21,    22,    22,    23,    23,
      23,    23,    24,    24
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     2,     1,     2,     4,
       3,     2,     1,     3,     2,     1,     3,     1,     1,     1,
       1,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* main: NEXT main  */
#line 105 "gram.y"
    {
        fprintf(report, ">>main competed!\n");   
    }
#line 1248 "y.tab.c"
    break;

  case 5: /* polynom: termmonom  */
#line 114 "gram.y"
            {
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1256 "y.tab.c"
    break;

  case 6: /* polynom: PRINT termmonom  */
#line 119 "gram.y"
            {
                output_poly_to_file((yyvsp[0].poly));
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1265 "y.tab.c"
    break;

  case 7: /* polynom: peremen  */
#line 126 "gram.y"
            {
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1273 "y.tab.c"
    break;

  case 8: /* polynom: PRINT peremen  */
#line 131 "gram.y"
            {
                output_poly_to_file((yyvsp[0].poly));
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1282 "y.tab.c"
    break;

  case 9: /* peremen: OY VARIABLE EQUAL termmonom  */
#line 140 "gram.y"
            {
                (yyval.poly) = (yyvsp[0].poly);
                fprintf(report, ">>peremen: OY VARIABLE EQUAL termmonom: Find new peremen!\n");
                add_new_element((yyvsp[-2].variable), (yyvsp[0].poly));
            }
#line 1292 "y.tab.c"
    break;

  case 10: /* termmonom: termmonom sign monom  */
#line 148 "gram.y"
            {
                printf("%d\n", (yyvsp[-1].signal));
                // if ($2 == "-")
                //     $3->coef[$3->capacity - 1] = - $3->coef[$3->capacity - 1];
                //printf("()()\n");

                (yyval.poly) = add_poly_to_poly((yyvsp[-2].poly), (yyvsp[0].poly), (yyvsp[-1].signal));

            }
#line 1306 "y.tab.c"
    break;

  case 11: /* termmonom: sign monom  */
#line 159 "gram.y"
            {
                //printf("!()!(!)(!)!!()\n");
                (yyval.poly) = (yyvsp[0].poly);
                //($1 == "+") ? $$->fb_sign = 1 : $$->fb_sign = 2;
                if ((yyvsp[-1].signal) == 2) {
                    fprintf(report, ">>termmonom: sign monom\n");
                    (yyval.poly)->coef[(yyvsp[0].poly)->capacity] = 0 - ((yyval.poly)->coef[(yyvsp[0].poly)->capacity]);
                    fprintf(report, "sign coef = %d\n", (yyval.poly)->coef[(yyvsp[0].poly)->capacity]);
                }
            }
#line 1321 "y.tab.c"
    break;

  case 12: /* termmonom: monom  */
#line 171 "gram.y"
            {
                //printf("!()!(!)(!)!!()\n");
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1330 "y.tab.c"
    break;

  case 13: /* monom: monom MULTI exprmonom  */
#line 181 "gram.y"
            {
                (yyval.poly) = multi_poly_to_poly((yyvsp[-2].poly), (yyvsp[0].poly));
            }
#line 1338 "y.tab.c"
    break;

  case 14: /* monom: monom exprmonom  */
#line 186 "gram.y"
            {
                //printf(">>monom: monom exprmonom created\n");
                output_poly((yyvsp[-1].poly));
                output_poly((yyvsp[0].poly));
                (yyval.poly) = multi_poly_to_poly((yyvsp[-1].poly), (yyvsp[0].poly));
            }
#line 1349 "y.tab.c"
    break;

  case 15: /* monom: exprmonom  */
#line 194 "gram.y"
            {
                fprintf(report, ">>monom: exprmonom created\n");
                output_poly((yyvsp[0].poly));
                
                (yyval.poly) = (yyvsp[0].poly);
                //free($1);
            }
#line 1361 "y.tab.c"
    break;

  case 16: /* exprmonom: expression POW exprmonom  */
#line 205 "gram.y"
            {
                fprintf(report, ">>exprmonom: expression POW exprmonom!\n");
                output_poly((yyvsp[-2].poly));

                output_poly((yyvsp[0].poly));
                //fprintf(report, "------\n");
                //printf("%d\n", $3->capacity);
                if ((yyvsp[0].poly)->coef[0] < 0){
                    printf("ERROR: minus power number! line: %d\n", yylineno);
                    fprintf(report, "ERROR: exprmonom: expression POW exprmonom!\n >> Отрицательная степень!");
                    exit(1);
                }

                if ((yyvsp[0].poly)->capacity == 1){
                    //fprintf(report, "------\n");
                    if ((yyvsp[-2].poly)->capacity == 2){
                        set_zero_poly((yyval.poly));
                        (yyval.poly)->capacity = (yyvsp[0].poly)->coef[0];
                        (yyval.poly)->coef[(yyvsp[0].poly)->coef[0]] = 1;
                        
                    }

                    // else if ($1->capacity == 1){
                    //     $$ = poly_power_poly($1, $3);
                    //     printf("<><><\n");
                    // }

                    else {
                        (yyval.poly) = full_poly_power_poly((yyvsp[-2].poly), (yyvsp[0].poly));
                        //printf("---\n");
                    }
                }

                else if ((yyvsp[0].poly)->capacity == 0){
                    
                    set_zero_poly((yyval.poly));
                    (yyval.poly)->capacity = 1;
                    (yyval.poly)->coef[0] = 1;
                }

                else {
                    printf("ERROR: minus power number! line: %d\n", yylineno);
                    fprintf(report, "ERROR: exprmonom: expression POW exprmonom!\n >> Отрицательная степень!");
                    exit(1);
                }
            }
#line 1412 "y.tab.c"
    break;

  case 17: /* exprmonom: expression  */
#line 253 "gram.y"
            {
                output_poly((yyvsp[0].poly));
                (yyval.poly) = (yyvsp[0].poly);
            }
#line 1421 "y.tab.c"
    break;

  case 18: /* expression: VARIABLE  */
#line 261 "gram.y"
                     {
                fprintf(report, ">>expression: VARIABLE find\n");
                if (((yyval.poly) = search_polynom_in_list((yyvsp[0].variable))) == NULL){
                    //printf("ERROR: Unidentified variable!\n");
                    break;
                }
            }
#line 1433 "y.tab.c"
    break;

  case 19: /* expression: NUMBER  */
#line 269 "gram.y"
                     {
                fprintf(report, ">>expression: NUMBER created\n");
                (yyval.poly) = (b_poly*)malloc(sizeof(b_poly));
                init_poly((yyval.poly));
                (yyval.poly)->capacity = 1;
                (yyval.poly)->coef[0] = (yyvsp[0].number);
                //printf("---%c\n", $$->var);
            }
#line 1446 "y.tab.c"
    break;

  case 20: /* expression: VAR  */
#line 280 "gram.y"
            {
                fprintf(report, ">>expression: VAR created\n");
                (yyval.poly) = (b_poly*)malloc(sizeof(b_poly));
                init_poly((yyval.poly));
                (yyval.poly)->capacity = 2;
                (yyval.poly)->coef[1] = 1;
                (yyval.poly)->var = (yyvsp[0].value);

            }
#line 1460 "y.tab.c"
    break;

  case 21: /* expression: OPENC termmonom CLOSEC  */
#line 291 "gram.y"
            {
                (yyval.poly) = (yyvsp[-1].poly);
            }
#line 1468 "y.tab.c"
    break;

  case 22: /* sign: PLUS  */
#line 298 "gram.y"
            {
                (yyval.signal) = 1;
            }
#line 1476 "y.tab.c"
    break;

  case 23: /* sign: MINUS  */
#line 302 "gram.y"
            {
                (yyval.signal) = 2;
            }
#line 1484 "y.tab.c"
    break;


#line 1488 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 315 "gram.y"

void init_poly(b_poly* firstP){
    firstP->capacity = 0;
    firstP->var = ' ';
    memset(firstP->coef, 0, 2000);
    //memset(firstP->name_var, NULL, 100);
    firstP->priority = 0;
}

void set_zero_poly(b_poly* firstP){
    firstP->capacity = 0;
    memset(firstP->coef, 0, 2000);
    firstP->priority = 0;
}

b_poly* poly_power_poly(b_poly* firstP, b_poly* secondP){

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    init_poly(thirdP);
    thirdP->capacity = 1;
    thirdP->coef[0] = firstP->coef[0] * secondP->coef[0];
    //free(firstP);         // ??
    //free(secondP);         // ??
    return thirdP;

}

b_poly* full_poly_power_poly(b_poly* firstP, b_poly* secondP){


    fprintf(report, ">>full_poly_power_poly function start\n");

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    init_poly(thirdP);
    thirdP->var = firstP->var;

    int power = secondP->coef[0];
    int max_capacity = 0;

    //printf("%d\n", firstP->coef[0]);

    if (firstP->coef[0] > 0){
        thirdP->coef[0] = (int)pow(firstP->coef[0], secondP->coef[0]);
        thirdP->capacity = 1;
        max_capacity = 1;
        //printf("---\n");
    }

    fprintf(report, "first step of function\n");
    output_poly(thirdP);

    // printf("%d\n", firstP->capacity);
    for (int i = 1; i <= firstP->capacity; i++){
        thirdP->coef[i * secondP->coef[0]] = (int)pow(firstP->coef[i], secondP->coef[0]);
        //printf("---\n");
        max_capacity = fmax(max_capacity, i * secondP->coef[0]);

    }
    thirdP->capacity = max_capacity;
    return thirdP;
}


b_poly* add_poly_to_poly(b_poly* firstP, b_poly* secondP, int sign){

    // sign = 1 -> +
    // sign = 2 -> -

    //printf("===coef %d\n", firstP->coef[2]);

    fprintf(report, ">>gram.y: FUNCTION add_poly_to_poly start\n");

    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));

    if (firstP->var == ' '){
        firstP->var = secondP->var;
    }
    else if (secondP->var == ' '){
        secondP->var = firstP->var;
    }

    if ((firstP->var != secondP->var)){
        
        // add yyerror()

        //printf("<<>>%c\n", firstP->var);
        //printf("<<>>%c\n", secondP->var);

        printf("<<Error: gram.y: func add_p2p: different var! line: %d\n", yylineno);
        fprintf(report, "<<Error: gram.y: func add_p2p: different var!\n");
        //return -1;
        exit(1);
        
    }


    init_poly(thirdP);

    //int maximum_pow = fmax(firstP->capacity, secondP->capacity); 
    int maximum_pow = (firstP->capacity > secondP->capacity) ? firstP->capacity : secondP->capacity;
    fprintf(report, "max-pow %d\n", maximum_pow);


    //struct buffer_polynom* thirdP = (b_poly*)malloc(sizeof(b_poly));
    
    //b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));

    thirdP->capacity = maximum_pow;
    thirdP->var = firstP->var;

    //memset(thirdP->coef, 0, 2000); 

    /* printf("-=-=-=- %d\n", sign);


    printf("++++++++++\n");
    output_poly(firstP);
    output_poly(secondP);
    printf("++++++++++\n"); */

    if (sign == 1){
        //printf("PLUS\n");
        for (int i = 0; i <= maximum_pow; i++){
            thirdP->coef[i] = firstP->coef[i] + secondP->coef[i];
        }
    }


    
    else if (sign == 2){
        //printf("MINUS\n");
        for (int i = 0; i <= maximum_pow; i++){

            thirdP->coef[i] = firstP->coef[i] - secondP->coef[i];
            /* printf("><><><>%d\n", firstP->coef[i]);
            printf("><><><>%d\n", secondP->coef[i]);
            printf("><><><>%d\n", thirdP->coef[i]); */
        
        }
    }
    output_poly(thirdP);
    return thirdP;

}

b_poly* multi_poly_to_poly(b_poly* firstP, b_poly* secondP){
    
    
    if (firstP->var == ' '){
        firstP->var = secondP->var;
    }
    else if (secondP->var == ' '){
        secondP->var = firstP->var;
    }
    

    if (firstP->var != secondP->var){
        
        // add yyerror()
        printf("<<Error: gram.y: func add_p2p: different var! line: %d\n", yylineno);
        fprintf(report, "<<Error: gram.y: func add_p2p: different var!\n");
        //return -1;
        exit(1);
    }


    output_poly(firstP);
    //printf("-----\n");
    output_poly(secondP);

    //int maximum_pow = max(firstP->capacity, secondP->capacity); 

    //struct b_poly thirdP;
    
    b_poly* thirdP = (b_poly*)malloc(sizeof(b_poly));
    //thirdP->capacity = 1;


    thirdP->var = firstP->var;
    memset(thirdP->coef, 0, 2000);



    
    for (int i = 0; i <= firstP->capacity; i++){
        for (int j = 0; j <= secondP->capacity; j++){
            
            if ((firstP->coef[i] != 0) && (secondP->coef[j] != 0)){
                int count_coef = firstP->coef[i] * secondP->coef[j];
                printf("))%d\n", count_coef);
                int count_pow = i + j;
                
                thirdP->coef[count_pow] = count_coef;
                thirdP->capacity = count_pow + 1;

            }
        }
        
    }

    /* free(firstP);
    free(secondP); */
    return thirdP;
    

}

void output_poly(b_poly* firstP) {
    fprintf(report, ">>gram.y: FUNCTION output_poly start\n");
    
    
    /* printf("===coef[0] %d  ", firstP->coef[0]);
    printf("===coef[1] %d\n", firstP->coef[1]);
    printf("===capacity %d\n", firstP->capacity); */
    

    int first_term = 1; // Флаг для первого члена

    for (int i = firstP->capacity; i >= 0; i--) {
        int coef = firstP->coef[i];
        if (coef == 0) continue; 
        if (!first_term) {
            if (coef > 0) {
                fprintf(report, " + ");
            } else {
                fprintf(report, " - ");
                coef = -coef; 
            }
        } else {
            if (coef < 0) {
                fprintf(report, "-");
                coef = -coef;
            }
            first_term = 0;
        }

        if (i == 0) {
            fprintf(report, "%d", coef);
        } else {
            if (coef != 1 || i == 0) { 
                fprintf(report, "%d", coef);
            }
            fprintf(report, "%c", firstP->var);
            if (i > 1) {
                fprintf(report, "^%d", i);
            }
        }
    }

    if (first_term) { 
        fprintf(report, "0");
    }
    fprintf(report, "\n");
}


void output_poly_to_file(b_poly* firstP) {
    //printf(">>gram.y: FUNCTION output_poly start\n");
    
    
    /* printf("===coef[0] %d  ", firstP->coef[0]);
    printf("===coef[1] %d\n", firstP->coef[1]);
    printf("===capacity %d\n", firstP->capacity); */
    

    int first_term = 1; // Флаг для первого члена

    for (int i = firstP->capacity; i >= 0; i--) {
        int coef = firstP->coef[i];
        if (coef == 0) continue; 
        if (!first_term) {
            if (coef > 0) {
                fprintf(output, " + ");
            } else {
                fprintf(output, " - ");
                coef = -coef; 
            }
        } else {
            if (coef < 0) {
                fprintf(output, "-");
                coef = -coef;
            }
            first_term = 0;
        }

        if (i == 0) {
            fprintf(output, "%d", coef);
        } else {
            if (coef != 1 || i == 0) { 
                fprintf(output, "%d", coef);
            }
            fprintf(output, "%c", firstP->var);
            if (i > 1) {
                fprintf(output, "^%d", i);
            }
        }
    }

    if (first_term) { 
        fprintf(output, "0");
    }
    fprintf(output, "\n");
}


void add_new_element(char* variable, b_poly* polynom)
{
    list* temp = (list*)malloc(sizeof(list));
    strcpy(temp->name, variable);
    temp->polynom = polynom;
    temp->next_list = first_list_var;
    
    first_list_var = temp;
    fprintf(report, ">>function add_new_element: Create new element at list_var!\n");
}


b_poly* search_polynom_in_list(char* variable)
{
    list* temp = first_list_var;
    fprintf(report, ">>function search_polynom_in_list: Start search at list_var!\n");
    while (temp != NULL)
    {
        if (strcmp(temp->name, variable) == 0) {
            return temp->polynom;
        }
        temp = temp->next_list;
    }

    printf("ERROR: Unidentified variable! line: %d\n", yylineno);
    fprintf(report, "ERROR: Unidentified variable!\n");
    exit(1);
}
