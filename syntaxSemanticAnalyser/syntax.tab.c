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
#line 1 "syntax.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<signal.h>
// #define YYDEBUG 1
#include "syntax.tab.h"
// #include "lex.yy.c"

void insert_type();
void add(char);
int search(char *, char *);
void check_declaration(char *, char *);
int check_types(char *, char *);
char *get_type(char *, char *);
void check_returnval(char *, char *);
void check_returnval_void();

char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
extern int yylineno;
extern char typeval[32];
int count = 0;
int q;
char type[10], functype[10];
int sem_errors=0;
int label=0;
char scopedetail[20] = {'m', 'a', 'i', 'n'};
char mainval[20] = {'m', 'a', 'i', 'n'};
char buff[100];
char errors[10][100];

 struct dataType {
        char * id_name;
        char * data_type;
        char * type;
		char * scope;
        int line_no;
	} symbol_table[40];



struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);
    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };

#line 124 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ADD = 4,                        /* ADD  */
  YYSYMBOL_DIV = 5,                        /* DIV  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_OTHER = 9,                      /* OTHER  */
  YYSYMBOL_EQL = 10,                       /* EQL  */
  YYSYMBOL_EOL = 11,                       /* EOL  */
  YYSYMBOL_DATA = 12,                      /* DATA  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 17,                    /* ELSEIF  */
  YYSYMBOL_NEWLINE = 18,                   /* NEWLINE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_DELIM = 20,                     /* DELIM  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GTE = 27,                       /* GTE  */
  YYSYMBOL_LTE = 28,                       /* LTE  */
  YYSYMBOL_EE = 29,                        /* EE  */
  YYSYMBOL_NE = 30,                        /* NE  */
  YYSYMBOL_SPC = 31,                       /* SPC  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_entry = 34,                     /* entry  */
  YYSYMBOL_start = 35,                     /* start  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_functionstatement = 37,         /* functionstatement  */
  YYSYMBOL_38_1 = 38,                      /* $@1  */
  YYSYMBOL_returnstatement = 39,           /* returnstatement  */
  YYSYMBOL_funcdec = 40,                   /* funcdec  */
  YYSYMBOL_declist = 41,                   /* declist  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_nextdec = 43,                   /* nextdec  */
  YYSYMBOL_ifelsestatement = 44,           /* ifelsestatement  */
  YYSYMBOL_ifclause = 45,                  /* ifclause  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_elseifstatement = 47,           /* elseifstatement  */
  YYSYMBOL_elseifclause = 48,              /* elseifclause  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_identifier = 50,                /* identifier  */
  YYSYMBOL_elseclause = 51,                /* elseclause  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_whilestatement = 53,            /* whilestatement  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_56_7 = 56,                      /* $@7  */
  YYSYMBOL_declaration = 57,               /* declaration  */
  YYSYMBOL_varlist = 58,                   /* varlist  */
  YYSYMBOL_newvar = 59,                    /* newvar  */
  YYSYMBOL_datatype = 60,                  /* datatype  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_single = 62,                    /* single  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_singledec = 64,                 /* singledec  */
  YYSYMBOL_exp = 65,                       /* exp  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_compexp = 67,                   /* compexp  */
  YYSYMBOL_factor = 68,                    /* factor  */
  YYSYMBOL_69_10 = 69                      /* $@10  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    75,    76,    80,    81,    82,    83,    84,
      87,    87,    90,    91,    94,    95,    99,    99,   102,   103,
     107,   111,   111,   116,   117,   121,   121,   124,   127,   128,
     128,   132,   132,   136,   136,   140,   144,   147,   148,   152,
     152,   156,   156,   159,   160,   164,   165,   207,   248,   249,
     288,   329,   330,   331,   332,   333,   334,   337,   337,   338
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ADD", "DIV",
  "MUL", "SUB", "ID", "OTHER", "EQL", "EOL", "DATA", "WHILE", "FOR", "IF",
  "ELSE", "ELSEIF", "NEWLINE", "COMMA", "DELIM", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "GT", "LT", "GTE", "LTE", "EE", "NE", "SPC",
  "RETURN", "$accept", "entry", "start", "statement", "functionstatement",
  "$@1", "returnstatement", "funcdec", "declist", "$@2", "nextdec",
  "ifelsestatement", "ifclause", "$@3", "elseifstatement", "elseifclause",
  "$@4", "identifier", "elseclause", "$@5", "whilestatement", "$@6",
  "expression", "$@7", "declaration", "varlist", "newvar", "datatype",
  "$@8", "single", "$@9", "singledec", "exp", "term", "compexp", "factor",
  "$@10", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-11)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,   -51,   -51,   -51,   -51,     6,   -23,    -3,   -51,   -51,
      25,   -51,   -51,   -51,   -51,    13,   -51,    -4,     4,   -51,
     -51,   -51,   -51,   -51,   -51,    25,   -51,    23,    27,    42,
      35,    16,    16,    32,    36,   -51,    16,    37,    46,   -51,
      13,   -51,   -51,   -51,     9,    39,    38,   -51,    40,    -3,
      16,     7,    47,    16,   -51,   -51,   -51,   -51,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    41,    43,
      44,    45,   -51,    48,   -51,    13,    19,    39,    39,    19,
      19,    19,    19,    19,    19,   -51,   -51,    -3,    -3,   -51,
      49,    50,   -51,    52,    53,    -3,    -3,    55,   -51,   -51,
      54,    29,    47,   -51,   -51,    13,    56,   -51,    58,   -51,
     -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    27,    39,    31,    21,     0,     0,     4,     9,     8,
      28,    33,     7,     5,     6,     0,    40,     0,     0,     1,
       2,     3,    29,    25,    20,    28,    23,     0,    41,     0,
      37,     0,     0,     0,     0,    24,     0,     0,    43,    35,
       0,    36,    57,    59,     0,    45,     0,    48,     0,     4,
       0,     0,    14,     0,    42,    41,    38,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,    15,     0,    44,    46,    47,    53,
      54,    55,    56,    51,    52,    50,    49,     4,     4,    30,
       0,     0,    16,     0,     0,     4,     4,    18,    32,    22,
       0,    12,     0,    17,    26,     0,     0,    19,     0,    11,
      13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    -6,   -51,   -51,   -51,   -51,   -51,   -39,   -51,
     -51,   -51,   -51,   -51,    59,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,    31,   -51,   -50,   -51,   -51,
     -51,   -51,   -33,   -12,   -28,   -16,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    37,   106,    73,    74,    97,
     103,     9,    10,    18,    24,    25,    34,    43,    26,    33,
      12,    17,    13,    27,    14,    29,    41,    15,    16,    30,
      38,    54,    44,    45,    46,    47,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    21,    75,    51,    48,     1,    19,    11,    20,     2,
       3,    58,     4,    58,    59,    28,    59,    31,    72,    42,
      76,     1,    71,    58,     1,    32,    59,    79,    80,    81,
      82,    83,    84,    36,    60,    61,    62,    63,    64,    65,
      55,    22,    23,    70,    66,    67,    77,    78,   -10,    11,
      85,    86,    75,    39,    40,    49,    53,    50,    52,     2,
      68,   105,    69,   107,    87,     0,    88,    90,    89,   110,
      91,    56,    95,    96,   102,    92,    98,    99,   104,     0,
     109,    93,    94,     0,    35,     0,     0,    11,    11,   100,
     101,     0,     0,     0,     0,    11,    11,     0,     0,     0,
       0,     0,     0,     0,     0,   108
};

static const yytype_int8 yycheck[] =
{
       0,     7,    52,    36,    32,     8,     0,     7,    31,    12,
      13,     4,    15,     4,     7,    15,     7,    21,    11,     3,
      53,     8,    50,     4,     8,    21,     7,    60,    61,    62,
      63,    64,    65,    10,    25,    26,    27,    28,    29,    30,
      40,    16,    17,    49,     5,     6,    58,    59,    21,    49,
      66,    67,   102,    11,    19,    23,    10,    21,    21,    12,
      22,    32,    22,   102,    23,    -1,    23,    22,    24,    11,
      22,    40,    23,    23,    19,    75,    24,    24,    24,    -1,
      24,    87,    88,    -1,    25,    -1,    -1,    87,    88,    95,
      96,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    12,    13,    15,    34,    35,    36,    37,    44,
      45,    50,    53,    55,    57,    60,    61,    54,    46,     0,
      31,    35,    16,    17,    47,    48,    51,    56,    50,    58,
      62,    21,    21,    52,    49,    47,    10,    38,    63,    11,
      19,    59,     3,    50,    65,    66,    67,    68,    67,    23,
      21,    65,    21,    10,    64,    50,    58,    69,     4,     7,
      25,    26,    27,    28,    29,    30,     5,     6,    22,    22,
      35,    67,    11,    40,    41,    60,    65,    66,    66,    65,
      65,    65,    65,    65,    65,    68,    68,    23,    23,    24,
      22,    22,    50,    35,    35,    23,    23,    42,    24,    24,
      35,    35,    19,    43,    24,    32,    39,    41,    50,    24,
      11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      38,    37,    39,    39,    40,    40,    42,    41,    43,    43,
      44,    46,    45,    47,    47,    49,    48,    50,    51,    52,
      51,    54,    53,    56,    55,    57,    58,    59,    59,    61,
      60,    63,    62,    64,    64,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    69,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       0,    10,     0,     3,     0,     1,     0,     4,     0,     2,
       2,     0,     8,     1,     2,     0,     8,     1,     0,     0,
       5,     0,     8,     0,     5,     3,     2,     0,     2,     0,
       2,     0,     3,     0,     2,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     2,     1
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
  case 2: /* entry: start SPC  */
#line 70 "syntax.y"
            {head = ((yyvsp[-1].nd_obj)).nd; ((yyval.nd_obj)).nd = ((yyvsp[-1].nd_obj)).nd; printeverything(); }
#line 1252 "syntax.tab.c"
    break;

  case 3: /* start: statement start  */
#line 75 "syntax.y"
                  {((yyval.nd_obj)).nd = mknode(((yyvsp[-1].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "start");}
#line 1258 "syntax.tab.c"
    break;

  case 4: /* start: %empty  */
#line 76 "syntax.y"
   {((yyval.nd_obj)).nd = NULL;}
#line 1264 "syntax.tab.c"
    break;

  case 5: /* statement: expression  */
#line 80 "syntax.y"
            {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1270 "syntax.tab.c"
    break;

  case 6: /* statement: declaration  */
#line 81 "syntax.y"
               {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1276 "syntax.tab.c"
    break;

  case 7: /* statement: whilestatement  */
#line 82 "syntax.y"
                  {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1282 "syntax.tab.c"
    break;

  case 8: /* statement: ifelsestatement  */
#line 83 "syntax.y"
                   {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1288 "syntax.tab.c"
    break;

  case 9: /* statement: functionstatement  */
#line 84 "syntax.y"
                     {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1294 "syntax.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 87 "syntax.y"
                     {add('F'); strcpy(scopedetail, ((yyvsp[0].nd_obj)).name); strcpy(((yyvsp[0].nd_obj)).type, type); strcpy(functype, ((yyvsp[-1].nd_obj)).name); }
#line 1300 "syntax.tab.c"
    break;

  case 11: /* functionstatement: datatype identifier $@1 LPAREN funcdec RPAREN LBRACE start returnstatement RBRACE  */
#line 87 "syntax.y"
                                                                                                                                                                                  {((yyval.nd_obj)).nd = mknode(mknode(((yyvsp[-9].nd_obj)).nd, ((yyvsp[-5].nd_obj)).nd, "func-dec"), mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "statements"), ((yyvsp[-8].nd_obj)).name); strcpy(scopedetail, mainval); }
#line 1306 "syntax.tab.c"
    break;

  case 12: /* returnstatement: %empty  */
#line 90 "syntax.y"
                 {check_returnval_void(); ((yyval.nd_obj)).nd = mknode(NULL, NULL, "void");}
#line 1312 "syntax.tab.c"
    break;

  case 13: /* returnstatement: RETURN identifier EOL  */
#line 91 "syntax.y"
                         {check_returnval(((yyvsp[-1].nd_obj)).type, ((yyvsp[-1].nd_obj)).name); ((yyval.nd_obj)).nd = mknode(NULL, NULL, ((yyvsp[-1].nd_obj)).name); }
#line 1318 "syntax.tab.c"
    break;

  case 14: /* funcdec: %empty  */
#line 94 "syntax.y"
         {((yyval.nd_obj)).nd = mknode(NULL, NULL, "empty-dec");}
#line 1324 "syntax.tab.c"
    break;

  case 15: /* funcdec: declist  */
#line 95 "syntax.y"
           {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd; }
#line 1330 "syntax.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 99 "syntax.y"
                     {add('V'); strcpy(((yyvsp[0].nd_obj)).type, type); }
#line 1336 "syntax.tab.c"
    break;

  case 17: /* declist: datatype identifier $@2 nextdec  */
#line 99 "syntax.y"
                                                                   {((yyval.nd_obj)).nd = mknode(mknode(((yyvsp[-3].nd_obj)).nd, ((yyvsp[-2].nd_obj)).nd, "dec"), ((yyvsp[0].nd_obj)).nd, ",");}
#line 1342 "syntax.tab.c"
    break;

  case 18: /* nextdec: %empty  */
#line 102 "syntax.y"
         {((yyval.nd_obj)).nd = mknode(NULL, NULL, "end"); }
#line 1348 "syntax.tab.c"
    break;

  case 19: /* nextdec: COMMA declist  */
#line 103 "syntax.y"
                 {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd; }
#line 1354 "syntax.tab.c"
    break;

  case 20: /* ifelsestatement: ifclause elseifstatement  */
#line 107 "syntax.y"
                          {((yyval.nd_obj)).nd = mknode(((yyvsp[-1].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "if-else-elseif");}
#line 1360 "syntax.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 111 "syntax.y"
    {add('K');}
#line 1366 "syntax.tab.c"
    break;

  case 22: /* ifclause: IF $@3 LPAREN compexp RPAREN LBRACE start RBRACE  */
#line 111 "syntax.y"
                                                          {((yyval.nd_obj)).nd = mknode(((yyvsp[-4].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "if");}
#line 1372 "syntax.tab.c"
    break;

  case 23: /* elseifstatement: elseclause  */
#line 116 "syntax.y"
            {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1378 "syntax.tab.c"
    break;

  case 24: /* elseifstatement: elseifclause elseifstatement  */
#line 117 "syntax.y"
                                {((yyval.nd_obj)).nd = mknode(((yyvsp[-1].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "else-if-statement");}
#line 1384 "syntax.tab.c"
    break;

  case 25: /* $@4: %empty  */
#line 121 "syntax.y"
        {add('K');}
#line 1390 "syntax.tab.c"
    break;

  case 26: /* elseifclause: ELSEIF $@4 LPAREN compexp RPAREN LBRACE start RBRACE  */
#line 121 "syntax.y"
                                                              {((yyval.nd_obj)).nd = mknode(((yyvsp[-4].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "else-if");}
#line 1396 "syntax.tab.c"
    break;

  case 27: /* identifier: ID  */
#line 124 "syntax.y"
               {((yyval.nd_obj)).nd = mknode(NULL, NULL, ((yyvsp[0].nd_obj)).name);  strcpy(((yyval.nd_obj)).type, get_type(((yyvsp[0].nd_obj)).name, scopedetail)); }
#line 1402 "syntax.tab.c"
    break;

  case 28: /* elseclause: %empty  */
#line 127 "syntax.y"
            {((yyval.nd_obj)).nd = NULL;}
#line 1408 "syntax.tab.c"
    break;

  case 29: /* $@5: %empty  */
#line 128 "syntax.y"
        {add('K');}
#line 1414 "syntax.tab.c"
    break;

  case 30: /* elseclause: ELSE $@5 LBRACE start RBRACE  */
#line 128 "syntax.y"
                                        {((yyval.nd_obj)).nd = ((yyvsp[-1].nd_obj)).nd;}
#line 1420 "syntax.tab.c"
    break;

  case 31: /* $@6: %empty  */
#line 132 "syntax.y"
       {add('K');}
#line 1426 "syntax.tab.c"
    break;

  case 32: /* whilestatement: WHILE $@6 LPAREN compexp RPAREN LBRACE start RBRACE  */
#line 132 "syntax.y"
                                                             {((yyval.nd_obj)).nd = mknode(((yyvsp[-4].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "while");}
#line 1432 "syntax.tab.c"
    break;

  case 33: /* $@7: %empty  */
#line 136 "syntax.y"
            {check_declaration(typeval, scopedetail);}
#line 1438 "syntax.tab.c"
    break;

  case 34: /* expression: identifier $@7 EQL exp EOL  */
#line 136 "syntax.y"
                                                                   {((yyval.nd_obj)).nd = mknode(((yyvsp[-4].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "=");}
#line 1444 "syntax.tab.c"
    break;

  case 35: /* declaration: datatype varlist EOL  */
#line 140 "syntax.y"
                      {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[-1].nd_obj)).nd, "declaration");}
#line 1450 "syntax.tab.c"
    break;

  case 36: /* varlist: single newvar  */
#line 144 "syntax.y"
               {((yyval.nd_obj)).nd = mknode(((yyvsp[-1].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, ",");}
#line 1456 "syntax.tab.c"
    break;

  case 37: /* newvar: %empty  */
#line 147 "syntax.y"
        {((yyval.nd_obj)).nd = NULL;}
#line 1462 "syntax.tab.c"
    break;

  case 38: /* newvar: COMMA varlist  */
#line 148 "syntax.y"
                 {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1468 "syntax.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 152 "syntax.y"
               {insert_type();}
#line 1474 "syntax.tab.c"
    break;

  case 40: /* datatype: DATA $@8  */
#line 152 "syntax.y"
                                {((yyval.nd_obj)).nd = mknode(NULL, NULL, ((yyvsp[-1].nd_obj)).name);}
#line 1480 "syntax.tab.c"
    break;

  case 41: /* $@9: %empty  */
#line 156 "syntax.y"
            {add('V');  strcpy(((yyvsp[0].nd_obj)).type, type); }
#line 1486 "syntax.tab.c"
    break;

  case 42: /* single: identifier $@9 singledec  */
#line 156 "syntax.y"
                                                             {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "=");}
#line 1492 "syntax.tab.c"
    break;

  case 43: /* singledec: %empty  */
#line 159 "syntax.y"
           {((yyval.nd_obj)).nd = NULL;}
#line 1498 "syntax.tab.c"
    break;

  case 44: /* singledec: EQL exp  */
#line 160 "syntax.y"
           {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1504 "syntax.tab.c"
    break;

  case 45: /* exp: term  */
#line 164 "syntax.y"
          {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1510 "syntax.tab.c"
    break;

  case 46: /* exp: exp ADD term  */
#line 165 "syntax.y"
                {
  if(!strcmp(((yyvsp[-2].nd_obj)).type, ((yyvsp[0].nd_obj)).type)) {
		// printf("%s\n", ($1).type);
		((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "+"); 
	}
	else {
		if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "float")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "+");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "+");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "+");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "char") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "+");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "+");
		}
		else {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "+");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } 
 }
#line 1557 "syntax.tab.c"
    break;

  case 47: /* exp: exp SUB term  */
#line 207 "syntax.y"
                {if(!strcmp(((yyvsp[-2].nd_obj)).type, ((yyvsp[0].nd_obj)).type)) {
		((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "-"); 
	}
	else {
		if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "float")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "-");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "-");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "-");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "char") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "-");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "-");
		}
		else {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "-");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
#line 1601 "syntax.tab.c"
    break;

  case 48: /* term: factor  */
#line 248 "syntax.y"
             {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd;}
#line 1607 "syntax.tab.c"
    break;

  case 49: /* term: term MUL factor  */
#line 249 "syntax.y"
                   {if(!strcmp(((yyvsp[-2].nd_obj)).type, ((yyvsp[0].nd_obj)).type)) {
		((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "*"); 
	}
	else {
		if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "float")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "*");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "*");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "*");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "char") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "*");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "*");
		}
		else {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "*");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
#line 1651 "syntax.tab.c"
    break;

  case 50: /* term: term DIV factor  */
#line 288 "syntax.y"
                   {if(!strcmp(((yyvsp[-2].nd_obj)).type, ((yyvsp[0].nd_obj)).type)) {
		((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "/"); 
	}
	else {
		if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "float")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "/");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "inttofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "/");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "int") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "/");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "char") && !strcmp(((yyvsp[0].nd_obj)).type, "int")) {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartoint");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "/");
		}
		else if(!strcmp(((yyvsp[-2].nd_obj)).type, "float") && !strcmp(((yyvsp[0].nd_obj)).type, "char")) {
			struct node *temp = mknode(NULL, ((yyvsp[0].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[-2].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, temp, "/");
		}
		else {
			struct node *temp = mknode(NULL, ((yyvsp[-2].nd_obj)).nd, "chartofloat");
			sprintf(((yyval.nd_obj)).type, ((yyvsp[0].nd_obj)).type);
			((yyval.nd_obj)).nd = mknode(temp, ((yyvsp[0].nd_obj)).nd, "/");
		}
  
  
  
  // ($$).nd = mknode(($1).nd, ($3).nd, "+");
  } }
#line 1695 "syntax.tab.c"
    break;

  case 51: /* compexp: exp EE exp  */
#line 329 "syntax.y"
                    {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "==");}
#line 1701 "syntax.tab.c"
    break;

  case 52: /* compexp: exp NE exp  */
#line 330 "syntax.y"
               {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "!=");}
#line 1707 "syntax.tab.c"
    break;

  case 53: /* compexp: exp GT exp  */
#line 331 "syntax.y"
               {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, ">");}
#line 1713 "syntax.tab.c"
    break;

  case 54: /* compexp: exp LT exp  */
#line 332 "syntax.y"
               {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "<");}
#line 1719 "syntax.tab.c"
    break;

  case 55: /* compexp: exp GTE exp  */
#line 333 "syntax.y"
                {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, ">=");}
#line 1725 "syntax.tab.c"
    break;

  case 56: /* compexp: exp LTE exp  */
#line 334 "syntax.y"
                {((yyval.nd_obj)).nd = mknode(((yyvsp[-2].nd_obj)).nd, ((yyvsp[0].nd_obj)).nd, "<=");}
#line 1731 "syntax.tab.c"
    break;

  case 57: /* $@10: %empty  */
#line 337 "syntax.y"
            { add('C');}
#line 1737 "syntax.tab.c"
    break;

  case 58: /* factor: NUM $@10  */
#line 337 "syntax.y"
                         {((yyval.nd_obj)).nd = mknode(NULL, NULL, ((yyvsp[-1].nd_obj)).name);}
#line 1743 "syntax.tab.c"
    break;

  case 59: /* factor: identifier  */
#line 338 "syntax.y"
              {((yyval.nd_obj)).nd = ((yyvsp[0].nd_obj)).nd; check_declaration(typeval, scopedetail); }
#line 1749 "syntax.tab.c"
    break;


#line 1753 "syntax.tab.c"

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

#line 345 "syntax.y"


int p = -1;

void sigint_handler(int sig_no)
{
  signal(SIGINT, sigint_handler);
    printf("CTRL-C pressed\n");
    // struct sigaction old_action;
    if(p!=-2) printBT(head);
    // sigaction(SIGINT, &old_action, NULL);
    kill(0, SIGINT);
}


int main(int argc, char **argv)
{
  // int p = -1;
  // yydebug = 1;
  p = yyparse();
  // struct sigaction action, old_action;
    // memset(&action, 0, sizeof(action));
    // action.sa_handler = &sigint_handler;
    // sigaction(SIGINT, &action, &old_action);
  // if(p) printf("Parsing is successful\n");
  // while(1){}
  // signal(SIGINT, sigint_handler);
  
  
  return 0;

}

yyerror(char *s)
{
  
  p = -2;
  printf("Error : %s at line number %d\n", s, yylineno);
}

void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("├──"); } 
		else { printf("└──"); }
        printf("%s",ptr->token);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);    
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void insert_type() {
  // printf("%s\n", typeval);
	strcpy(type, typeval);
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return 6;
}

char *get_type(char *var, char *scopeval){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var) && !strcmp(symbol_table[i].scope, scopeval)) {
			return symbol_table[i].data_type;
		}
	}
	return "h";
}

void add(char c) {
  // printf("here\n");
	if(c == 'V'){
		for(int i=0; i<10; i++){
      // printf("%s\n", typeval);
      // printf("here\n");
			if(!strcmp(reserved[i], strdup(typeval))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", yylineno+1, typeval);
				sem_errors++;
				return;
			}
		}
	}
//   printf("here\n");
    q=search(typeval, scopedetail);
    // printf("here\n");
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Variable");
			symbol_table[count].scope = strdup(scopedetail);
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(typeval);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=yylineno;
			symbol_table[count].type=strdup("Function");
			symbol_table[count].scope = strdup(scopedetail);
			count++;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", yylineno+1, typeval);
		sem_errors++;
    }
}

int search(char *type, char *scopeval) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0 && symbol_table[i].scope && strcmp(symbol_table[i].scope, scopeval) == 0) {
			return -1;
			break;
		}
	}
	return 0;
}

void printeverything(){
  printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t%s\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].scope);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printBT(head);
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
  if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
}

void check_declaration(char *c, char* s) {
    q = search(c, s);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", yylineno+1, c);
		sem_errors++;
    }
}

void check_returnval(char *c, char* n){
	if(strcmp(c, functype) == 0){
		return ;
	}
	else{
		sprintf(errors[sem_errors], "Line %d: Variable \"%s\" wrong return type!\n", yylineno+1, n);
		sem_errors++;

		return ;
	}

}

void check_returnval_void(){
	if(strcmp("void", functype)!=0){
		sprintf(errors[sem_errors], "Line %d: It is not a void function!\n", yylineno+1);
		sem_errors++;

	}
}
