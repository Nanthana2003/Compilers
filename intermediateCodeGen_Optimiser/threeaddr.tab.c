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
#line 1 "threeaddr.y"

	#include<bits/stdc++.h>
	typedef long long ll;
	using namespace std;
	int yylex();
	void yyerror(char *s);
	
	//for 3addr
	int tempcount=0;
	int getTemp();
	typedef struct node
	{
		string  addr, array;
		pair<string,vector<ll> > type;
		vector<ll> trueList,falseList,nextList;
		int instNum;
	}NODE;

	NODE* makeNode()
	{
		NODE *temp=new NODE();
		ostringstream ss;
		ss<<"t"<<getTemp();
		temp->addr=ss.str();
		ss.str("");
		temp->array="";
		return temp;
	}
	NODE* makeNode(string *x)
	{
		NODE *temp=new NODE();
		temp->addr=*x;
		temp->array="";
		return temp;
	}

	//for symbol table
	deque<string> s;
	deque<int> vars;
	deque<int> blocks;
	int blocknum=-1,varnum=0;
	string currType;
	map<ll,map<string,pair<pair<string,vector<ll> >,string> > > table;//blockno,varname,type,dimensions,value
	map<string,ll> width;
	ll getWidth(pair<string,vector<ll> > type);
	string to_string(ll val);
	ll to_int(string val);
	void insertID(int bno,string varname);
	void printTable();

	// for backpatch
	int instCounter=0;
	map<ll,string> instList;
	int nextInst();
	vector<ll> merge(vector<ll> a,vector<ll> b);
	void backpatch(vector<ll> list,int num);
	void displayInst();

	//for Control Flow Graph
	map<ll,vector<string> > basicBlock;
	set<ll> leaders;
	vector<vector<ll> > bbgraph;
	void genBasicBlock();
	void findLeaders();


#line 138 "threeaddr.tab.c"

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

#include "threeaddr.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEY = 3,                        /* KEY  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_OR = 5,                         /* OR  */
  YYSYMBOL_NOT = 6,                        /* NOT  */
  YYSYMBOL_RELOP = 7,                      /* RELOP  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_VAL = 9,                        /* VAL  */
  YYSYMBOL_SC = 10,                        /* SC  */
  YYSYMBOL_CM = 11,                        /* CM  */
  YYSYMBOL_PL = 12,                        /* PL  */
  YYSYMBOL_MI = 13,                        /* MI  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_POW = 16,                       /* POW  */
  YYSYMBOL_OP = 17,                        /* OP  */
  YYSYMBOL_CL = 18,                        /* CL  */
  YYSYMBOL_AO = 19,                        /* AO  */
  YYSYMBOL_AC = 20,                        /* AC  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_BO = 22,                        /* BO  */
  YYSYMBOL_BC = 23,                        /* BC  */
  YYSYMBOL_UNR = 24,                       /* UNR  */
  YYSYMBOL_TRUE = 25,                      /* TRUE  */
  YYSYMBOL_FALSE = 26,                     /* FALSE  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_ss = 31,                        /* ss  */
  YYSYMBOL_32_1 = 32,                      /* $@1  */
  YYSYMBOL_stmt = 33,                      /* stmt  */
  YYSYMBOL_if = 34,                        /* if  */
  YYSYMBOL_ifelse = 35,                    /* ifelse  */
  YYSYMBOL_while = 36,                     /* while  */
  YYSYMBOL_block = 37,                     /* block  */
  YYSYMBOL_38_2 = 38,                      /* $@2  */
  YYSYMBOL_stmt_list = 39,                 /* stmt_list  */
  YYSYMBOL_decl = 40,                      /* decl  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_id = 42,                        /* id  */
  YYSYMBOL_arr = 43,                       /* arr  */
  YYSYMBOL_d = 44,                         /* d  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_a = 46,                         /* a  */
  YYSYMBOL_l = 47,                         /* l  */
  YYSYMBOL_r = 48,                         /* r  */
  YYSYMBOL_bool = 49,                      /* bool  */
  YYSYMBOL_bb = 50,                        /* bb  */
  YYSYMBOL_m = 51,                         /* m  */
  YYSYMBOL_n = 52,                         /* n  */
  YYSYMBOL_e = 53,                         /* e  */
  YYSYMBOL_t = 54,                         /* t  */
  YYSYMBOL_f = 55,                         /* f  */
  YYSYMBOL_g = 56                          /* g  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    82,    90,    91,    92,    93,    94,    95,
      98,   103,   110,   117,   117,   137,   142,   142,   143,   143,
     155,   155,   157,   157,   159,   159,   162,   164,   165,   173,
     184,   194,   196,   202,   208,   210,   211,   212,   219,   220,
     222,   223,   225,   226,   227,   228,   230,   231,   232,   234,
     235,   237,   238,   245,   248,   249
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
  "\"end of file\"", "error", "\"invalid token\"", "KEY", "AND", "OR",
  "NOT", "RELOP", "ID", "VAL", "SC", "CM", "PL", "MI", "MUL", "DIV", "POW",
  "OP", "CL", "AO", "AC", "EQ", "BO", "BC", "UNR", "TRUE", "FALSE", "IF",
  "ELSE", "WHILE", "$accept", "ss", "$@1", "stmt", "if", "ifelse", "while",
  "block", "$@2", "stmt_list", "decl", "$@3", "id", "arr", "d", "$@4", "a",
  "l", "r", "bool", "bb", "m", "n", "e", "t", "f", "g", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -39,    19,     3,   -39,    16,    15,   -39,    34,   -39,   -39,
     -39,   -39,   -39,   -39,    72,   -39,   -39,    57,    42,   -39,
      62,    62,     3,    20,    79,     3,    62,    62,    77,    78,
      89,    70,   -39,    62,    62,    69,    35,     1,   -39,    85,
      92,    68,    81,    20,    20,   -39,   -39,    17,   -39,    61,
      20,   -39,    37,    95,    86,    98,    16,    99,    91,   -39,
      26,    62,    62,   -39,    62,    62,    62,   -39,   -39,   -39,
      36,     0,   -39,   -39,   -39,    62,    38,   -39,   -39,    42,
     -39,   -39,   -39,   -39,     1,     1,   -39,   -39,   -39,   -39,
      20,    20,     3,    68,   -39,   -39,    89,   -39,   -39,    80,
       3,   -39,   -39,   -39,   -39,     3,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    17,     1,     0,     0,    13,     0,    40,    16,
       4,     5,     6,     7,    40,     9,     8,     0,    23,    18,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    20,
      26,    52,    54,     0,     0,    45,     0,    44,    48,    50,
       0,    31,    40,     0,     0,    38,    39,     0,    34,     0,
       0,    15,     0,     0,     0,     0,     0,     0,    53,    55,
       0,     0,     0,    29,     0,     0,     0,    28,    14,    35,
       0,     0,    40,    40,    40,     0,     0,    30,    27,    23,
      21,    24,    19,    51,    42,    43,    46,    47,    49,    36,
       0,     0,     0,    37,    40,    22,    26,    33,    32,    10,
       0,    25,    41,    12,    40,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -23,   -39,   -39,   -39,   -39,   -39,    90,
     -39,   -39,    55,    39,    18,   -39,   -39,    -2,    88,   -36,
     -38,    -7,   -39,   -17,    33,    27,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    11,    12,    13,    22,    14,
      15,    30,    19,    29,    57,    96,    16,    35,    40,    47,
      48,    25,   104,    49,    37,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    24,    51,    36,    41,    69,     4,    75,    70,    52,
      41,     5,    61,    62,    76,    64,    65,    60,    83,     3,
      17,    72,    73,    17,    18,     6,    43,    71,    31,    32,
       7,    58,     8,    33,    20,    74,    21,    44,    61,    62,
      72,    73,    72,    73,    83,    45,    46,    61,    62,    61,
      62,    23,    97,    98,    89,    63,    94,    77,    93,    58,
      58,    28,    58,    58,    58,    90,    91,    92,    75,    99,
      31,    32,    -3,    61,    62,    33,    26,   103,    27,    34,
      61,    62,   106,   -53,   -53,   -53,    54,   100,    26,    20,
      17,    86,    87,    88,    84,    85,    50,   105,    17,    55,
      56,    66,    67,    17,    68,    78,    79,    80,   102,    82,
      26,    81,    42,     0,   101,    53,    59,     0,    95
};

static const yytype_int8 yycheck[] =
{
       2,     8,    25,    20,    21,    43,     3,     7,    44,    26,
      27,     8,    12,    13,    50,    14,    15,    34,    18,     0,
      22,     4,     5,    25,     8,    22,     6,    44,     8,     9,
      27,    33,    29,    13,    19,    18,    21,    17,    12,    13,
       4,     5,     4,     5,    18,    25,    26,    12,    13,    12,
      13,    17,    90,    91,    18,    20,    18,    20,    75,    61,
      62,    19,    64,    65,    66,    72,    73,    74,     7,    92,
       8,     9,     0,    12,    13,    13,    19,   100,    21,    17,
      12,    13,   105,    14,    15,    16,     9,    94,    19,    19,
      92,    64,    65,    66,    61,    62,    17,   104,   100,    21,
      11,    16,    10,   105,    23,    10,    20,     9,    28,    10,
      19,    56,    22,    -1,    96,    27,    33,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,     0,     3,     8,    22,    27,    29,    33,
      34,    35,    36,    37,    39,    40,    46,    47,     8,    42,
      19,    21,    38,    17,    51,    51,    19,    21,    19,    43,
      41,     8,     9,    13,    17,    47,    53,    54,    55,    56,
      48,    53,    39,     6,    17,    25,    26,    49,    50,    53,
      17,    33,    53,    48,     9,    21,    11,    44,    47,    56,
      53,    12,    13,    20,    14,    15,    16,    10,    23,    50,
      49,    53,     4,     5,    18,     7,    49,    20,    10,    20,
       9,    42,    10,    18,    54,    54,    55,    55,    55,    18,
      51,    51,    51,    53,    18,    43,    45,    50,    50,    33,
      51,    44,    28,    33,    52,    51,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    32,    31,    33,    33,    33,    33,    33,    33,
      34,    35,    36,    38,    37,    39,    39,    39,    41,    40,
      42,    42,    43,    43,    45,    44,    44,    46,    46,    47,
      47,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       6,    10,     7,     0,     4,     3,     1,     0,     0,     5,
       2,     4,     4,     0,     0,     4,     0,     4,     4,     4,
       4,     1,     4,     4,     1,     2,     3,     3,     1,     1,
       0,     0,     3,     3,     1,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     2
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
  case 2: /* $@1: %empty  */
#line 82 "threeaddr.y"
                {
			blocknum++;
			blocks.push_back(blocknum);
			vars.push_back(varnum);
			varnum=0;
		}
#line 1250 "threeaddr.tab.c"
    break;

  case 3: /* ss: $@1 stmt_list  */
#line 88 "threeaddr.y"
                          {}
#line 1256 "threeaddr.tab.c"
    break;

  case 4: /* stmt: if  */
#line 90 "threeaddr.y"
           {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1262 "threeaddr.tab.c"
    break;

  case 5: /* stmt: ifelse  */
#line 91 "threeaddr.y"
                        {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1268 "threeaddr.tab.c"
    break;

  case 6: /* stmt: while  */
#line 92 "threeaddr.y"
                        {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1274 "threeaddr.tab.c"
    break;

  case 7: /* stmt: block  */
#line 93 "threeaddr.y"
                         {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1280 "threeaddr.tab.c"
    break;

  case 8: /* stmt: a  */
#line 94 "threeaddr.y"
                      {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1286 "threeaddr.tab.c"
    break;

  case 9: /* stmt: decl  */
#line 95 "threeaddr.y"
                         {((yyval.node))=new NODE();((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1292 "threeaddr.tab.c"
    break;

  case 10: /* if: IF OP bool CL m stmt  */
#line 98 "threeaddr.y"
                                     {
								((yyval.node))=new NODE();
								backpatch(((yyvsp[-3].node))->trueList,((yyvsp[-1].node))->instNum);
								((yyval.node))->nextList=merge(((yyvsp[-3].node))->falseList,((yyvsp[0].node))->nextList);
							}
#line 1302 "threeaddr.tab.c"
    break;

  case 11: /* ifelse: IF OP bool CL m stmt ELSE n m stmt  */
#line 103 "threeaddr.y"
                                           {
											((yyval.node))=new NODE();
											backpatch(((yyvsp[-7].node))->trueList,((yyvsp[-5].node))->instNum);
											backpatch(((yyvsp[-7].node))->falseList,((yyvsp[-1].node))->instNum);
											((yyval.node))->nextList=merge(((yyvsp[-4].node))->nextList,((yyvsp[-2].node))->nextList);
											((yyval.node))->nextList=merge(((yyval.node))->nextList,((yyvsp[0].node))->nextList);
										}
#line 1314 "threeaddr.tab.c"
    break;

  case 12: /* while: WHILE m OP bool CL m stmt  */
#line 110 "threeaddr.y"
                                  {
									((yyval.node))=new NODE();
									backpatch(((yyvsp[-3].node))->trueList,((yyvsp[-1].node))->instNum);
									backpatch(((yyvsp[0].node))->nextList,((yyvsp[-5].node))->instNum);
									instList[nextInst()]="goto "+to_string(((yyvsp[-5].node))->instNum);
									((yyval.node))->nextList=((yyvsp[-3].node))->falseList;
								}
#line 1326 "threeaddr.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 117 "threeaddr.y"
                {
			blocknum++;
			blocks.push_back(blocknum);
			for(int i=0;i<s.size();i++)
			{
				insertID(blocknum,s[i]);
			}
			vars.push_back(varnum);
			varnum=0;
		}
#line 1341 "threeaddr.tab.c"
    break;

  case 14: /* block: BO $@2 stmt_list BC  */
#line 128 "threeaddr.y"
                {
			blocks.pop_back();
			for(int i=0;i<varnum;i++)
				s.pop_back();
			varnum=vars.back();
			vars.pop_back();	
			((yyval.node))=new NODE();
			((yyval.node))->nextList=((yyvsp[-1].node))->nextList;
		}
#line 1355 "threeaddr.tab.c"
    break;

  case 15: /* stmt_list: stmt_list m stmt  */
#line 137 "threeaddr.y"
                            {
								((yyval.node))=new NODE();
								backpatch(((yyvsp[-2].node))->nextList,((yyvsp[-1].node))->instNum);
								((yyval.node))->nextList=((yyvsp[0].node))->nextList;
							}
#line 1365 "threeaddr.tab.c"
    break;

  case 16: /* stmt_list: stmt  */
#line 142 "threeaddr.y"
                              {((yyval.node))->nextList=((yyvsp[0].node))->nextList;}
#line 1371 "threeaddr.tab.c"
    break;

  case 17: /* stmt_list: %empty  */
#line 142 "threeaddr.y"
                                                                 {}
#line 1377 "threeaddr.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 143 "threeaddr.y"
             {
				varnum++;s.push_back(*((yyvsp[-1].str))+" "+*((yyvsp[0].str)));
				insertID(blocks.back(),*((yyvsp[-1].str))+" "+*((yyvsp[0].str)));
				currType=*((yyvsp[-1].str));
			}
#line 1387 "threeaddr.tab.c"
    break;

  case 19: /* decl: KEY id $@3 d SC  */
#line 147 "threeaddr.y"
                               {((yyval.node))=new NODE();}
#line 1393 "threeaddr.tab.c"
    break;

  case 20: /* id: ID arr  */
#line 155 "threeaddr.y"
              {((yyval.str))=new string(*((yyvsp[-1].str))+*((yyvsp[0].str)));}
#line 1399 "threeaddr.tab.c"
    break;

  case 21: /* id: ID arr EQ VAL  */
#line 155 "threeaddr.y"
                                                              {((yyval.str))=new string(*((yyvsp[-3].str))+*((yyvsp[-2].str))+*((yyvsp[-1].str))+*((yyvsp[0].str)));}
#line 1405 "threeaddr.tab.c"
    break;

  case 22: /* arr: AO VAL AC arr  */
#line 157 "threeaddr.y"
                      {((yyval.str))=new string(*((yyvsp[-3].str))+*((yyvsp[-2].str))+*((yyvsp[-1].str))+*((yyvsp[0].str)));}
#line 1411 "threeaddr.tab.c"
    break;

  case 23: /* arr: %empty  */
#line 157 "threeaddr.y"
                                                                   {((yyval.str))=new string("");}
#line 1417 "threeaddr.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 159 "threeaddr.y"
         {
			varnum++;s.push_back(currType+" "+*((yyvsp[0].str)));
			insertID(blocks.back(),currType+" "+*((yyvsp[0].str)));
		}
#line 1426 "threeaddr.tab.c"
    break;

  case 26: /* d: %empty  */
#line 162 "threeaddr.y"
                      {}
#line 1432 "threeaddr.tab.c"
    break;

  case 27: /* a: l EQ r SC  */
#line 164 "threeaddr.y"
                  {instList[nextInst()]=((yyvsp[-3].node))->array+"["+((yyvsp[-3].node))->addr+"] = "+((yyvsp[-1].node))->addr;	}
#line 1438 "threeaddr.tab.c"
    break;

  case 28: /* a: ID EQ r SC  */
#line 165 "threeaddr.y"
                                {
	  					if(table[blocks.back()].find(*((yyvsp[-3].str)))==table[blocks.back()].end())
						{
							yyerror("variable not declared");
						}
	  					instList[nextInst()]=*((yyvsp[-3].str))+" = "+((yyvsp[-1].node))->addr;
	  					((yyval.node))=new NODE();
	  				}
#line 1451 "threeaddr.tab.c"
    break;

  case 29: /* l: ID AO e AC  */
#line 174 "threeaddr.y"
                                {
					((yyval.node))=makeNode();
					((yyval.node))->array=*((yyvsp[-3].str));
					if(table[blocks.back()].find(*((yyvsp[-3].str)))==table[blocks.back()].end())
					{
						yyerror("variable not declared");
					}
					((yyval.node))->type=table[blocks.back()][*((yyvsp[-3].str))].first;
					instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-1].node))->addr+" * "+to_string((int)getWidth(((yyval.node))->type));
				}
#line 1466 "threeaddr.tab.c"
    break;

  case 30: /* l: l AO e AC  */
#line 185 "threeaddr.y"
                                {
		 			NODE *myTemp=makeNode();
		 			((yyval.node))=makeNode();
		 			((yyval.node))->array=((yyvsp[-3].node))->array;
		 			((yyval.node))->type=((yyvsp[-3].node))->type;
		 			((yyval.node))->type.second.erase(((yyval.node))->type.second.begin());
		 			instList[nextInst()]=myTemp->addr + " = "+((yyvsp[-1].node))->addr +" * "+to_string((int)getWidth(((yyval.node))->type));
		 			instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-3].node))->addr+ " + " + myTemp->addr;
		 		}
#line 1480 "threeaddr.tab.c"
    break;

  case 31: /* r: e  */
#line 194 "threeaddr.y"
        {((yyval.node))=((yyvsp[0].node));}
#line 1486 "threeaddr.tab.c"
    break;

  case 32: /* bool: bool OR m bb  */
#line 196 "threeaddr.y"
                        {
					((yyval.node))=new NODE();
					backpatch(((yyvsp[-3].node))->falseList,((yyvsp[-1].node))->instNum);
					((yyval.node))->trueList=merge(((yyvsp[-3].node))->trueList,((yyvsp[0].node))->trueList);
					((yyval.node))->falseList=((yyvsp[0].node))->falseList;
				}
#line 1497 "threeaddr.tab.c"
    break;

  case 33: /* bool: bool AND m bb  */
#line 202 "threeaddr.y"
                        {
	 				((yyval.node))=new NODE();
	 				backpatch(((yyvsp[-3].node))->trueList,((yyvsp[-1].node))->instNum);
	 				((yyval.node))->trueList=((yyvsp[0].node))->trueList;
	 				((yyval.node))->falseList=merge(((yyvsp[-3].node))->falseList,((yyvsp[0].node))->falseList);
				}
#line 1508 "threeaddr.tab.c"
    break;

  case 34: /* bool: bb  */
#line 208 "threeaddr.y"
                    {((yyval.node))=new NODE();((yyval.node))->trueList=((yyvsp[0].node))->trueList;((yyval.node))->falseList=((yyvsp[0].node))->falseList;}
#line 1514 "threeaddr.tab.c"
    break;

  case 35: /* bb: NOT bb  */
#line 210 "threeaddr.y"
                 {((yyval.node))=new NODE();((yyval.node))->trueList=((yyvsp[0].node))->falseList;((yyval.node))->falseList=((yyvsp[0].node))->trueList;}
#line 1520 "threeaddr.tab.c"
    break;

  case 36: /* bb: OP bool CL  */
#line 211 "threeaddr.y"
                      {((yyval.node))=new NODE();((yyval.node))->trueList=((yyvsp[-1].node))->trueList;((yyval.node))->falseList=((yyvsp[-1].node))->falseList;}
#line 1526 "threeaddr.tab.c"
    break;

  case 37: /* bb: e RELOP e  */
#line 212 "threeaddr.y"
                        {
	    				((yyval.node))=new NODE();
	    				((yyval.node))->trueList.push_back(nextInst());
	    				instList[((yyval.node))->trueList.back()]="if "+((yyvsp[-2].node))->addr+" "+*((yyvsp[-1].str))+" "+((yyvsp[0].node))->addr+" goto";
	    				((yyval.node))->falseList.push_back(nextInst());
	    				instList[((yyval.node))->falseList.back()]="goto";
	    			}
#line 1538 "threeaddr.tab.c"
    break;

  case 38: /* bb: TRUE  */
#line 219 "threeaddr.y"
                  {((yyval.node))=new NODE();((yyval.node))->trueList.push_back(nextInst());instList[((yyval.node))->trueList.back()]="goto";}
#line 1544 "threeaddr.tab.c"
    break;

  case 39: /* bb: FALSE  */
#line 220 "threeaddr.y"
                    {((yyval.node))=new NODE();((yyval.node))->falseList.push_back(nextInst());instList[((yyval.node))->falseList.back()]="goto";}
#line 1550 "threeaddr.tab.c"
    break;

  case 40: /* m: %empty  */
#line 222 "threeaddr.y"
        {((yyval.node))=new NODE();((yyval.node))=new NODE();((yyval.node))->instNum=instCounter;}
#line 1556 "threeaddr.tab.c"
    break;

  case 41: /* n: %empty  */
#line 223 "threeaddr.y"
        {((yyval.node))=new NODE();((yyval.node))->nextList.push_back(nextInst());instList[((yyval.node))->nextList.back()]="goto";}
#line 1562 "threeaddr.tab.c"
    break;

  case 42: /* e: e PL t  */
#line 225 "threeaddr.y"
           {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-2].node))->addr+" + "+((yyvsp[0].node))->addr;}
#line 1568 "threeaddr.tab.c"
    break;

  case 43: /* e: e MI t  */
#line 226 "threeaddr.y"
                {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-2].node))->addr+" - "+((yyvsp[0].node))->addr;}
#line 1574 "threeaddr.tab.c"
    break;

  case 44: /* e: t  */
#line 227 "threeaddr.y"
            {((yyval.node))=((yyvsp[0].node));}
#line 1580 "threeaddr.tab.c"
    break;

  case 45: /* e: l  */
#line 228 "threeaddr.y"
             {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[0].node))->array+"["+((yyvsp[0].node))->addr+"]";}
#line 1586 "threeaddr.tab.c"
    break;

  case 46: /* t: t MUL f  */
#line 230 "threeaddr.y"
            {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-2].node))->addr+" * "+((yyvsp[0].node))->addr;}
#line 1592 "threeaddr.tab.c"
    break;

  case 47: /* t: t DIV f  */
#line 231 "threeaddr.y"
                 {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-2].node))->addr+" / "+((yyvsp[0].node))->addr;}
#line 1598 "threeaddr.tab.c"
    break;

  case 48: /* t: f  */
#line 232 "threeaddr.y"
            {((yyval.node))=((yyvsp[0].node));}
#line 1604 "threeaddr.tab.c"
    break;

  case 49: /* f: g POW f  */
#line 234 "threeaddr.y"
            {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[-2].node))->addr+" ^ "+((yyvsp[0].node))->addr;}
#line 1610 "threeaddr.tab.c"
    break;

  case 50: /* f: g  */
#line 235 "threeaddr.y"
           {((yyval.node))=((yyvsp[0].node));}
#line 1616 "threeaddr.tab.c"
    break;

  case 51: /* g: OP e CL  */
#line 237 "threeaddr.y"
            {((yyval.node))=((yyvsp[-1].node));}
#line 1622 "threeaddr.tab.c"
    break;

  case 52: /* g: ID  */
#line 238 "threeaddr.y"
            {
	 		if(table[blocks.back()].find(*((yyvsp[0].str)))==table[blocks.back()].end())
			{
				yyerror("variable not declared");
			}
			((yyval.node))=makeNode(((yyvsp[0].str)));
		}
#line 1634 "threeaddr.tab.c"
    break;

  case 53: /* g: l  */
#line 245 "threeaddr.y"
           {
	 		((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = "+((yyvsp[0].node))->array+"["+((yyvsp[0].node))->addr+"]";
	 	}
#line 1642 "threeaddr.tab.c"
    break;

  case 54: /* g: VAL  */
#line 248 "threeaddr.y"
              {((yyval.node))=makeNode((yyvsp[0].str));}
#line 1648 "threeaddr.tab.c"
    break;

  case 55: /* g: MI g  */
#line 249 "threeaddr.y"
                {((yyval.node))=makeNode();instList[nextInst()]=((yyval.node))->addr+" = - "+((yyvsp[0].node))->addr;}
#line 1654 "threeaddr.tab.c"
    break;


#line 1658 "threeaddr.tab.c"

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

#line 251 "threeaddr.y"

//for DAG
bool isInt(string s)
{
	bool flag=true;
	for(ll i=0;i<s.length();i++)
	{
		if(s[i]<'0' || s[i]>'9')
			flag=false;
	}
	return flag;
}
typedef struct dNode
{
	string op,name;
	vector<string> resVars;
	bool isGenerated;
	vector<struct dNode*> children;
}dagNode;

vector<vector<dagNode*> > dagBlock;
map<string,ll> dagVarCount;

dagNode* getDAGNode(string name, string op)
{
	dagNode *x=new dagNode();
	x->op=op;
	x->resVars.push_back(name+"_"+to_string((int)dagVarCount[name]));
	dagVarCount[name]++;
	x->isGenerated=false;
	return x;
}
dagNode* getDAGNode(string name)
{
	dagNode *x=new dagNode();
	if(isInt(name))
	{
		x->name=name;
	}
	else
		x->name=name+"_"+to_string((int)dagVarCount[name]);
	x->isGenerated=false;
	dagVarCount[name]++;
	return x;
}

string getVarName(dagNode *curr)
{
	if(curr->name!="")
		return curr->name;
	if(curr->resVars.size()>0)
		return curr->resVars.front();
	return "<not found>";
}
string getVarName(string var)
{
	return var.substr(0,var.rfind("_"));
}
void dfsDAG(dagNode *curr,string tab="\t")
{
	if(curr->op!="")
		cout<<tab<<"OP: "<<curr->op<<endl;
	if(curr->name!="")
		cout<<tab<<"NAME: "<<curr->name<<endl;
	if(curr->resVars.size()>0)
	{
		cout<<tab<<"ResVars: ";
		for(ll i=0;i<curr->resVars.size();i++)
		{
			cout<<curr->resVars[i]<<" ";
		}
		cout<<endl;
	}	
	for(ll i=0;i<curr->children.size();i++)
	{
		cout<<tab<<"child "<<(i+1)<<":"<<endl;
		dfsDAG(curr->children[i],tab+"\t");
	}
}
void displayDAG()
{
	cout<<"DAG:"<<endl;
	for(ll i=0;i<dagBlock.size();i++)
	{
		cout<<"Block "<<i<<":"<<endl;
		for(ll j=0;j<dagBlock[i].size();j++)
		{
			dfsDAG(dagBlock[i][j]);
			cout<<endl;
		}
	}
}
bool findDagNode(map<string,dagNode*> dagMap,dagNode *res,string op1,string op,string op2="")
{
	for(map<string,dagNode*>::iterator it=dagMap.begin();it!=dagMap.end();it++)
	{
		dagNode *curr=it->second;
		if(curr->op==op)
		{
			if(curr->children.size()==2 && op2!="")
			{
				bool one=(getVarName(curr->children[0]->name)==op1),two=(getVarName(curr->children[1]->name)==op2);
				for(int i=0;i<curr->children[0]->resVars.size();i++)
				{
					if(op1==getVarName(curr->children[0]->resVars[i]))
						one=true;
				}
				for(int i=0;i<curr->children[1]->resVars.size();i++)
				{
					if(op2==getVarName(curr->children[1]->resVars[i]))
						two=true;
				}
				if(one && two)
				{
					res=curr;
					return true;
				}
			}
			if(curr->children.size()==1)
			{
				bool one=(getVarName(curr->children[0]->name)==op1);
				for(int i=0;i<curr->children[0]->resVars.size();i++)
				{
					if(op1==getVarName(curr->children[0]->resVars[i]))
						one=true;
				}
				if(one)
				{
					res=curr;
					return true;
				}
			}
		}
	}
	return false;
}
void genDAG(ll bno)
{
	vector<string> inst=basicBlock[bno];
	map<string,dagNode*> dagMap;
	for(ll i=0;i<inst.size();i++)
	{
		istringstream ss(inst[i]);
		string temp;
		vector<string> splits;
		while(ss>>temp)
		{
			splits.push_back(temp);
		}
		if(splits.size()>0 && splits[0]=="if" || splits[0]=="goto")
			continue;
		if(splits.size()==5)
		{
			dagNode *op1,*op2,*res;
			if(findDagNode(dagMap,res,splits[2],splits[3],splits[4]))
			{
				res->resVars.push_back(splits[0]+"_"+to_string((int)dagVarCount[splits[0]]));
				dagMap[splits[0]]=res;
				continue;
			}
			if(dagMap.find(splits[2])!=dagMap.end())
				op1=dagMap[splits[2]];
			else
				op1=getDAGNode(splits[2]);
			if(dagMap.find(splits[4])!=dagMap.end())
				op2=dagMap[splits[4]];
			else
				op2=getDAGNode(splits[4]);
			res=getDAGNode(splits[0],splits[3]);
			res->children.push_back(op1);
			res->children.push_back(op2);
			for(ll j=0;j<dagBlock[bno].size();j++)
			{
				if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2)
				{
					dagBlock[bno].erase(dagBlock[bno].begin()+j);
					j--;
				}
			}
			dagBlock[bno].push_back(res);
			dagMap[splits[2]]=op1;
			dagMap[splits[4]]=op2;
			dagMap[splits[0]]=res;
		}
		else if(splits.size()==3)
		{
			dagNode *op1,*res;
			if(splits[2].find("[")!=-1)
			{
				dagNode *op2;
				ll ind=splits[2].find("[");
				string base=splits[2].substr(0,ind),offset=splits[2].substr(ind+1,splits[2].find("]")-ind-1);
				if(dagMap.find(base)!=dagMap.end())
					op1=dagMap[base];
				else
					op1=getDAGNode(base);
				if(dagMap.find(offset)!=dagMap.end())
					op2=dagMap[offset];
				else
					op2=getDAGNode(offset);
				res=getDAGNode(splits[0],"=[]");
				res->children.push_back(op1);
				res->children.push_back(op2);
				for(ll j=0;j<dagBlock[bno].size();j++)
				{
					if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2)
					{
						dagBlock[bno].erase(dagBlock[bno].begin()+j);
						j--;
					}
				}
				dagBlock[bno].push_back(res);
				dagMap[base]=op1;
				dagMap[offset]=op2;
				dagMap[splits[0]]=res;
				continue;
			}
			if(splits[0].find("[")!=-1)
			{
				dagNode *op2,*op3;
				ll ind=splits[0].find("[");
				string base=splits[0].substr(0,ind),offset=splits[0].substr(ind+1,splits[0].find("]")-ind-1);
				if(dagMap.find(base)!=dagMap.end())
					op1=dagMap[base];
				else
					op1=getDAGNode(base);
				if(dagMap.find(offset)!=dagMap.end())
					op2=dagMap[offset];
				else
					op2=getDAGNode(offset);
				if(dagMap.find(splits[2])!=dagMap.end())
					op3=dagMap[splits[2]];
				else
					op3=getDAGNode(splits[2]);
				res=getDAGNode(base,"[]=");
				res->children.push_back(op1);
				res->children.push_back(op2);
				res->children.push_back(op3);
				for(ll j=0;j<dagBlock[bno].size();j++)
				{
					if(dagBlock[bno][j]==op1 || dagBlock[bno][j]==op2 || dagBlock[bno][j]==op3)
					{
						dagBlock[bno].erase(dagBlock[bno].begin()+j);
						j--;
					}
				}
				dagBlock[bno].push_back(res);
				dagMap[base]=op1;
				dagMap[offset]=op2;
				dagMap[splits[2]]=op3;
				continue;
			}
			if(findDagNode(dagMap,res,splits[2],splits[1]))
			{
				res->resVars.push_back(splits[0]+"_"+to_string((int)dagVarCount[splits[0]]));
				dagMap[splits[0]]=res;
				continue;
			}
			if(dagMap.find(splits[2])!=dagMap.end())
			{
				op1=dagMap[splits[2]];
				op1->resVars.push_back(splits[0]+"_"+to_string((int)dagVarCount[splits[0]]));
				dagVarCount[splits[0]]++;
				dagMap[splits[0]]=op1;
			}
			else
			{
				op1=getDAGNode(splits[2]);
				op1->resVars.push_back(splits[0]+"_"+to_string((int)dagVarCount[splits[0]]));
				dagVarCount[splits[0]]++;
				dagBlock[bno].push_back(op1);
				dagMap[splits[0]]=op1;
				dagMap[splits[2]]=op1;
			}
			
		}
	}
}


void dagToThreeAddr(dagNode *curr)
{
	if(curr->isGenerated)
	{
		return;
	}
	for(ll i=0;i<curr->children.size();i++)
	{
		dagToThreeAddr(curr->children[i]);
	}
	if(curr->children.size()<2)
		return;
	if(curr->children.size()==2)
	{
		cout<<curr->resVars.front()<<" = "<<getVarName(curr->children[0])<<" "<<curr->op<<" "<<getVarName(curr->children[1])<<endl;
	}
	curr->isGenerated=true;
}
void genThreeAddr()
{
	cout<<"New Three Address:"<<endl;
	for(ll i=0;i<dagBlock.size();i++)
	{
		cout<<"Block "<<i<<": "<<endl;
		for(ll j=0;j<dagBlock[i].size();j++)
		{
			dagToThreeAddr(dagBlock[i][j]);
		}
		cout<<endl;
	}
}
void genDAG()
{
	dagBlock.resize(basicBlock.size());
	for(ll i=0;i<dagBlock.size();i++)
		genDAG(i);
}
void genFlowGraph()
{
	bbgraph.resize(basicBlock.size());
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		ll ind=-1;
		string lastStmt=it->second.back();
		if((ind=lastStmt.rfind("goto"))!=-1)
		{
			bbgraph[it->first].push_back(to_int(lastStmt.substr(ind+5)));
			if(ind!=0 && it->first!=basicBlock.size()-1)
			{
				bbgraph[it->first].push_back(it->first+1);
			}
		}
		else
		{
			if(it->first!=basicBlock.size()-1)
				bbgraph[it->first].push_back(it->first+1);
		}
	}
}
void displayFlowGraph()
{
	cout<<"Flow Graph:"<<endl;
	for(ll i=0;i<bbgraph.size();i++)
	{
		cout<<i<<": ";
		for(ll j=0;j<bbgraph[i].size();j++)
		{
			cout<<bbgraph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void findLeaders()
{
	bool flag=true;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(flag)
		{
			leaders.insert(it->first);
			int ind=it->second.rfind("goto");
			if(ind!=-1)
			{
				leaders.insert(to_int(it->second.substr(ind+5)));
				flag=true;
				continue;
			}
			flag=false;
		}
		int ind=it->second.rfind("goto");
		if(ind!=-1)
		{
			leaders.insert(to_int(it->second.substr(ind+5)));
			flag=true;
			continue;
		}
	}
}
void displayLeaders()
{
	cout<<"Leaders:"<<endl;
	for(set<ll>::iterator it=leaders.begin();it!=leaders.end();it++)
	{
		cout<<*it<<endl;
	}
}
void genBasicBlock()
{
	findLeaders();
	map<ll,ll> lineToBlock;
	ll bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		lineToBlock[it->first]=bbno;
	}
	bbno=-1;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		if(leaders.find(it->first)!=leaders.end())
		{
			bbno++;
		}
		int ind=-1;
		string bbinst=it->second;
		if((ind=it->second.rfind("goto"))!=-1)
		{
			bbinst=it->second.substr(0,ind+5) + to_string((int)lineToBlock[to_int(it->second.substr(ind+5))]);
		}
		basicBlock[bbno].push_back(bbinst);
	}
}
void displayBasicBlocks()
{
	cout<<"Basic Blocks:"<<endl;
	for(map<ll,vector<string> >::iterator it=basicBlock.begin();it!=basicBlock.end();it++)
	{
		cout<<"Block "<<it->first<<":"<<endl;
		for(ll i=0;i<it->second.size();i++)
		{
			cout<<"\t"<<it->second[i]<<endl;
		}
		cout<<endl;
	}
}
void displayInst()
{
	cout<<"Three Address Statements:"<<endl;
	for(map<ll,string>::iterator it=instList.begin();it!=instList.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
}

int getTemp()
{
	return tempcount++;
}
int nextInst()
{
	return instCounter++;
}
vector<ll> merge(vector<ll> a,vector<ll> b)
{
	a.insert(a.end(),b.begin(),b.end());
	return a;
}
void backpatch(vector<ll> list,int num)
{
	for(ll i=0;i<list.size();i++)
	{
		if(instList[list[i]].find("goto")==instList[list[i]].length()-4)
		{
			instList[list[i]]+=" "+to_string(num);
		}
	}
}
void insertID(int bno,string varname)
{
	string type,value;
	int ind=varname.find(" ");
	if(ind!=-1)
	{
		type=varname.substr(0,ind);
		varname=varname.substr(ind+1);
	}
	ind=varname.find("=");
	value="";
	if(ind!=-1)
	{
		value=varname.substr(ind+1);
		varname=varname.substr(0,ind);
	}
	ind=varname.find("[");
	vector<ll> dims;
	if(ind!=-1)
	{
		string indexes=varname.substr(ind);
		varname=varname.substr(0,ind);
		for(ll i=0;i<indexes.length();i++)
		{
			if(indexes[i]=='[' || indexes[i]==']')
				indexes[i]=' ';
		}
		istringstream in(indexes.c_str());
		int dim;
		while(in>>dim)
		{
			dims.push_back(dim);
		}
	}
	if(table[bno].find(varname)!=table[bno].end())
	{
		yyerror("variable already declared");
	}
	table[bno][varname]=make_pair(make_pair(type,dims),value);
}
ll getWidth(pair<string,vector<ll> > type)
{
	ll ans=width[type.first];
	for(ll i=1;i<type.second.size();i++)
	{
		ans=ans*type.second[i];
	}
	return ans;
}
void printTable()
{
	cout<<"Symbol Table:"<<endl;
	for(map<ll,map<string,pair<pair<string,vector<ll> >,string> > >::iterator it=table.begin();it!=table.end();it++)
	{
		cout<<"Block "<<it->first<<":"<<endl;
		for(map<string,pair<pair<string,vector<ll> >,string> >::iterator it2=it->second.begin();it2!=it->second.end();it2++)
		{
			cout<<it2->first<<" "<<it2->second.first.first<<" "<<it2->second.second;
			for(vector<ll>::iterator it3=it2->second.first.second.begin();it3!=it2->second.first.second.end();it3++)
				cout<<*it3<<' ';
			cout<<endl;
		}
		cout<<endl;
	}
}
void setWidths()
{
	width["int"]=4;
	width["float"]=4;
	width["char"]=1;
	width["double"]=8;
}
string to_string(ll val)
{
	ostringstream ss;
	ss<<val;
	return ss.str();
}
ll to_int(string val)
{
	istringstream ss(val);
	ll x;
	ss>>x;
	return x;
}
void readThreeAddress(int start=0)
{
	string inst;
	while(getline(cin,inst))
		instList[start++]=inst;
}
void yyerror(char* s)
{
	cout<<s<<endl;
	exit(0);
}
int main()
{
	setWidths();
	yyparse();
	readThreeAddress();
	printTable();
	displayInst();
	genBasicBlock();
	displayBasicBlocks();
	genFlowGraph();
	displayFlowGraph();
	//comment the following if the code has control statements
	//use only with no control flows
	
	genDAG();
	displayDAG();
	genThreeAddr();
}
