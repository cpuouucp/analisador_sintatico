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
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "compiler_context.h"

using namespace std;

extern int yylex();

void yyerror(const char *s) {
    contexto_compilador.reportar_erro_sintatico(s);
}

#line 87 "parser.cpp"

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

#include "tokens.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_PACKAGE = 3,              /* TOKEN_PACKAGE  */
  YYSYMBOL_TOKEN_IMPORT = 4,               /* TOKEN_IMPORT  */
  YYSYMBOL_TOKEN_ENUM = 5,                 /* TOKEN_ENUM  */
  YYSYMBOL_TOKEN_DATATYPE = 6,             /* TOKEN_DATATYPE  */
  YYSYMBOL_TOKEN_GENSET = 7,               /* TOKEN_GENSET  */
  YYSYMBOL_TOKEN_SPECIALIZES = 8,          /* TOKEN_SPECIALIZES  */
  YYSYMBOL_TOKEN_RELATION = 9,             /* TOKEN_RELATION  */
  YYSYMBOL_TOKEN_WHERE = 10,               /* TOKEN_WHERE  */
  YYSYMBOL_TOKEN_GENERAL = 11,             /* TOKEN_GENERAL  */
  YYSYMBOL_TOKEN_SPECIFICS = 12,           /* TOKEN_SPECIFICS  */
  YYSYMBOL_TOKEN_NATIVE_TYPE = 13,         /* TOKEN_NATIVE_TYPE  */
  YYSYMBOL_TOKEN_STEREOTYPE_CLASS = 14,    /* TOKEN_STEREOTYPE_CLASS  */
  YYSYMBOL_TOKEN_STEREOTYPE_RELATION = 15, /* TOKEN_STEREOTYPE_RELATION  */
  YYSYMBOL_TOKEN_META_ATTRIBUTE = 16,      /* TOKEN_META_ATTRIBUTE  */
  YYSYMBOL_TOKEN_AGGREGATION_SYMBOL = 17,  /* TOKEN_AGGREGATION_SYMBOL  */
  YYSYMBOL_TOKEN_ASSOCIATION_SYMBOL = 18,  /* TOKEN_ASSOCIATION_SYMBOL  */
  YYSYMBOL_TOKEN_COMPOSITION_SYMBOL = 19,  /* TOKEN_COMPOSITION_SYMBOL  */
  YYSYMBOL_TOKEN_RANGE = 20,               /* TOKEN_RANGE  */
  YYSYMBOL_TOKEN_NUMBER = 21,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_DISJOINT = 22,            /* TOKEN_DISJOINT  */
  YYSYMBOL_TOKEN_OVERLAPPING = 23,         /* TOKEN_OVERLAPPING  */
  YYSYMBOL_TOKEN_COMPLETE = 24,            /* TOKEN_COMPLETE  */
  YYSYMBOL_TOKEN_INCOMPLETE = 25,          /* TOKEN_INCOMPLETE  */
  YYSYMBOL_TOKEN_NEW_TYPE = 26,            /* TOKEN_NEW_TYPE  */
  YYSYMBOL_TOKEN_INSTANCE_NAME = 27,       /* TOKEN_INSTANCE_NAME  */
  YYSYMBOL_TOKEN_CLASS_NAME = 28,          /* TOKEN_CLASS_NAME  */
  YYSYMBOL_TOKEN_NAME = 29,                /* TOKEN_NAME  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_34_ = 34,                       /* '@'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_declaracao_pacote = 40,         /* declaracao_pacote  */
  YYSYMBOL_nome_pacote = 41,               /* nome_pacote  */
  YYSYMBOL_lista_elementos = 42,           /* lista_elementos  */
  YYSYMBOL_elemento = 43,                  /* elemento  */
  YYSYMBOL_regra_classe = 44,              /* regra_classe  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_lista_classes_mae = 47,         /* lista_classes_mae  */
  YYSYMBOL_corpo_classe_opt = 48,          /* corpo_classe_opt  */
  YYSYMBOL_item_classe = 49,               /* item_classe  */
  YYSYMBOL_atributo = 50,                  /* atributo  */
  YYSYMBOL_tipo_atributo = 51,             /* tipo_atributo  */
  YYSYMBOL_meta_atributos_opt = 52,        /* meta_atributos_opt  */
  YYSYMBOL_lista_meta = 53,                /* lista_meta  */
  YYSYMBOL_regra_enum = 54,                /* regra_enum  */
  YYSYMBOL_lista_instancias = 55,          /* lista_instancias  */
  YYSYMBOL_nome_instancia = 56,            /* nome_instancia  */
  YYSYMBOL_regra_datatype = 57,            /* regra_datatype  */
  YYSYMBOL_atributos_opt = 58,             /* atributos_opt  */
  YYSYMBOL_regra_genset = 59,              /* regra_genset  */
  YYSYMBOL_genset_declaracao = 60,         /* genset_declaracao  */
  YYSYMBOL_genset_restricao = 61,          /* genset_restricao  */
  YYSYMBOL_genset_completude = 62,         /* genset_completude  */
  YYSYMBOL_classes_especializadas = 63,    /* classes_especializadas  */
  YYSYMBOL_relacao_interna = 64,           /* relacao_interna  */
  YYSYMBOL_relacao_externa = 65,           /* relacao_externa  */
  YYSYMBOL_relacao_classes = 66,           /* relacao_classes  */
  YYSYMBOL_cardinalidade_opt = 67,         /* cardinalidade_opt  */
  YYSYMBOL_simbolo_relacao = 68            /* simbolo_relacao  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
       2,     2,    37,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,     2,
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    40,    46,    55,    56,    60,    61,    65,
      66,    67,    68,    69,    70,    74,    82,    81,    91,    99,
      98,   111,   112,   116,   117,   121,   122,   126,   136,   137,
     138,   139,   143,   144,   148,   149,   153,   162,   163,   167,
     168,   169,   173,   179,   185,   194,   195,   199,   203,   210,
     216,   223,   233,   234,   235,   239,   240,   241,   245,   249,
     256,   262,   272,   276,   283,   289,   299,   300,   301,   302,
     303,   304,   305,   306,   310,   311,   312
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_PACKAGE",
  "TOKEN_IMPORT", "TOKEN_ENUM", "TOKEN_DATATYPE", "TOKEN_GENSET",
  "TOKEN_SPECIALIZES", "TOKEN_RELATION", "TOKEN_WHERE", "TOKEN_GENERAL",
  "TOKEN_SPECIFICS", "TOKEN_NATIVE_TYPE", "TOKEN_STEREOTYPE_CLASS",
  "TOKEN_STEREOTYPE_RELATION", "TOKEN_META_ATTRIBUTE",
  "TOKEN_AGGREGATION_SYMBOL", "TOKEN_ASSOCIATION_SYMBOL",
  "TOKEN_COMPOSITION_SYMBOL", "TOKEN_RANGE", "TOKEN_NUMBER",
  "TOKEN_DISJOINT", "TOKEN_OVERLAPPING", "TOKEN_COMPLETE",
  "TOKEN_INCOMPLETE", "TOKEN_NEW_TYPE", "TOKEN_INSTANCE_NAME",
  "TOKEN_CLASS_NAME", "TOKEN_NAME", "'{'", "'}'", "','", "':'", "'@'",
  "'['", "']'", "'*'", "$accept", "programa", "declaracao_pacote",
  "nome_pacote", "lista_elementos", "elemento", "regra_classe", "$@1",
  "$@2", "lista_classes_mae", "corpo_classe_opt", "item_classe",
  "atributo", "tipo_atributo", "meta_atributos_opt", "lista_meta",
  "regra_enum", "lista_instancias", "nome_instancia", "regra_datatype",
  "atributos_opt", "regra_genset", "genset_declaracao", "genset_restricao",
  "genset_completude", "classes_especializadas", "relacao_interna",
  "relacao_externa", "relacao_classes", "cardinalidade_opt",
  "simbolo_relacao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      70,    64,    64,    13,  -118,  -118,  -118,  -118,  -118,  -118,
       0,   -11,    -8,    32,     2,    21,    21,    80,    83,    33,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,    66,  -118,  -118,
      74,    75,    76,    77,    78,    98,     8,  -118,  -118,  -118,
    -118,  -118,    10,   100,   101,    49,  -118,  -118,  -118,   102,
      84,    86,  -118,    87,    87,    88,    88,  -118,  -118,  -118,
      25,  -118,    53,    54,    57,    89,   106,  -118,    59,  -118,
      90,  -118,  -118,  -118,     1,     3,  -118,    49,    91,  -118,
    -118,  -118,  -118,   107,    88,  -118,    92,    37,     5,    62,
      93,    94,    95,  -118,    24,    88,    65,  -118,  -118,  -118,
     111,  -118,  -118,  -118,    23,  -118,    27,  -118,  -118,  -118,
      26,  -118,  -118,  -118,  -118,  -118,  -118,  -118,    90,    67,
    -118,    41,    90,    28,  -118,    30,  -118,    62,    99,   103,
    -118,  -118,    62,    96,   104,   105,   108,    90,  -118,   112,
    -118,    29,  -118,  -118,  -118,  -118,   109,  -118,    38,    62,
     110,  -118,  -118,  -118,    90,  -118,   114,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     8,     6,     5,     3,     4,     1,
       2,     0,     0,    57,     0,     0,     0,     0,     0,     0,
      14,     7,     9,    10,    11,    12,    47,     0,    54,    13,
       0,     0,     0,     0,     0,     0,    15,    57,    52,    53,
      55,    56,     0,     0,     0,     0,    46,    46,    46,     0,
       0,     0,    16,     0,     0,     0,     0,    39,    40,    41,
       0,    38,     0,     0,     0,     0,     0,    22,    18,    24,
      73,    62,    63,    59,     0,     0,    36,     0,     0,    42,
      45,    43,    44,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    24,    21,    17,
       0,    23,    25,    26,     0,    72,     0,    74,    75,    76,
      73,    50,    58,    51,    28,    30,    29,    31,    73,     0,
      49,     0,    73,     0,    66,     0,    71,     0,     0,    33,
      48,    20,     0,     0,     0,     0,     0,    73,    64,     0,
      27,    73,    69,    67,    68,    70,     0,    35,     0,     0,
       0,    65,    34,    32,    73,    60,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,   119,   128,  -118,  -118,  -118,  -118,  -118,  -118,
      34,  -118,   -85,  -118,  -118,  -118,  -118,  -118,    58,  -118,
      55,  -118,  -118,  -118,    85,   -55,  -118,  -118,    82,  -110,
    -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     7,    10,    21,    22,    69,    97,    68,
      87,   101,    80,   118,   140,   148,    23,    60,    61,    24,
      62,    25,    26,    27,    28,    74,   103,    29,    71,    89,
     110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     128,    75,   102,     1,     2,    11,    12,    13,   129,    90,
     137,    92,   132,     9,    14,   141,    51,    30,    31,    53,
      32,    33,    15,    16,    17,    18,   104,   146,    37,    96,
      36,   150,   154,    91,    19,    91,   102,   114,    52,    54,
     119,   105,   106,   123,   156,    17,    18,   125,    42,   133,
     115,   135,   116,   117,   152,   127,    76,    77,   149,   124,
      34,    88,    35,   126,    88,   134,    78,   136,    99,   153,
      78,   100,   131,     1,     2,   100,    57,    58,    59,   107,
     108,   109,    78,    78,    79,    81,    78,    40,    82,    85,
      41,    86,     5,     6,    43,    44,   120,    91,   130,    91,
      38,    39,    63,    64,    45,    46,    47,    48,    49,    50,
      55,    56,    66,    65,    67,    70,    73,    83,    84,    95,
      98,   111,   112,   113,    94,    88,   122,   138,   147,    20,
       8,   121,   142,   139,     0,    93,    72,   151,   155,     0,
     143,   144,   157,     0,   145
};

static const yytype_int16 yycheck[] =
{
     110,    56,    87,     3,     4,     5,     6,     7,   118,     8,
     127,     8,   122,     0,    14,   132,     8,    28,    26,     9,
      28,    29,    22,    23,    24,    25,    21,   137,     7,    84,
      28,   141,   149,    32,    34,    32,   121,    13,    30,    29,
      95,    36,    37,    20,   154,    24,    25,    20,    15,    21,
      26,    21,    28,    29,    16,    29,    31,    32,    29,    36,
      28,    35,    30,    36,    35,    37,    29,    37,    31,    31,
      29,    34,    31,     3,     4,    34,    27,    28,    29,    17,
      18,    19,    29,    29,    31,    31,    29,     7,    31,    30,
       7,    32,    28,    29,    28,    29,    31,    32,    31,    32,
      15,    16,    47,    48,    30,    30,    30,    30,    30,    11,
      10,    10,    28,    11,    28,    28,    28,    28,    12,    12,
      28,    28,    28,    28,    33,    35,    15,    28,    16,    10,
       2,    97,    36,    30,    -1,    77,    54,    28,    28,    -1,
      36,    36,    28,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    39,    40,    28,    29,    41,    41,     0,
      42,     5,     6,     7,    14,    22,    23,    24,    25,    34,
      40,    43,    44,    54,    57,    59,    60,    61,    62,    65,
      28,    26,    28,    29,    28,    30,    28,     7,    62,    62,
       7,     7,    15,    28,    29,    30,    30,    30,    30,    30,
      11,     8,    30,     9,    29,    10,    10,    27,    28,    29,
      55,    56,    58,    58,    58,    11,    28,    28,    47,    45,
      28,    66,    66,    28,    63,    63,    31,    32,    29,    31,
      50,    31,    31,    28,    12,    30,    32,    48,    35,    67,
       8,    32,     8,    56,    33,    12,    63,    46,    28,    31,
      34,    49,    50,    64,    21,    36,    37,    17,    18,    19,
      68,    28,    28,    28,    13,    26,    28,    29,    51,    63,
      31,    48,    15,    20,    36,    20,    36,    29,    67,    67,
      31,    31,    67,    21,    37,    21,    37,    68,    28,    30,
      52,    68,    36,    36,    36,    36,    67,    16,    53,    29,
      67,    28,    16,    31,    68,    28,    67,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    43,    43,    43,    43,    44,    45,    44,    44,    46,
      44,    47,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    58,    58,    59,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     2,     0,     6,     4,     0,
       8,     3,     1,     2,     0,     1,     1,     5,     1,     1,
       1,     1,     3,     0,     2,     1,     5,     3,     1,     1,
       1,     1,     5,     5,     5,     2,     0,     1,     8,     7,
       6,     6,     2,     2,     1,     2,     2,     1,     3,     1,
       6,     8,     4,     4,     5,     7,     3,     5,     5,     5,
       5,     3,     2,     0,     1,     1,     1
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
  case 2: /* programa: declaracao_pacote lista_elementos  */
#line 34 "parser.y"
    {
        cout << "\n✅ Análise sintática e construção da tabela de símbolos concluídas com sucesso!" << endl;
    }
#line 1250 "parser.cpp"
    break;

  case 3: /* declaracao_pacote: TOKEN_PACKAGE nome_pacote  */
#line 41 "parser.y"
    {
        contexto_compilador.set_contexto("pacote");
        contexto_compilador.get_tabela().registrar_pacote((yyvsp[0].sval), false);
        free((yyvsp[0].sval));
    }
#line 1260 "parser.cpp"
    break;

  case 4: /* declaracao_pacote: TOKEN_IMPORT nome_pacote  */
#line 47 "parser.y"
    {
        contexto_compilador.set_contexto("pacote");
        contexto_compilador.get_tabela().registrar_pacote((yyvsp[0].sval), true);
        free((yyvsp[0].sval));
    }
#line 1270 "parser.cpp"
    break;

  case 5: /* nome_pacote: TOKEN_NAME  */
#line 55 "parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 1276 "parser.cpp"
    break;

  case 6: /* nome_pacote: TOKEN_CLASS_NAME  */
#line 56 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1282 "parser.cpp"
    break;

  case 15: /* regra_classe: TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME  */
#line 75 "parser.y"
    {
        contexto_compilador.set_contexto("classe");
        contexto_compilador.get_tabela().iniciar_classe((yyvsp[0].sval), "Classe Ontológica (Simples)");
        contexto_compilador.get_tabela().finalizar_classe();
        free((yyvsp[0].sval));
    }
#line 1293 "parser.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 82 "parser.y"
      {
          contexto_compilador.set_contexto("classe");
          contexto_compilador.get_tabela().iniciar_classe((yyvsp[-1].sval), "Classe Ontológica (com Escopo)");
      }
#line 1302 "parser.cpp"
    break;

  case 17: /* regra_classe: TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME '{' $@1 corpo_classe_opt '}'  */
#line 87 "parser.y"
      {
          contexto_compilador.get_tabela().finalizar_classe();
          free((yyvsp[-4].sval));
      }
#line 1311 "parser.cpp"
    break;

  case 18: /* regra_classe: TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME TOKEN_SPECIALIZES lista_classes_mae  */
#line 92 "parser.y"
    {
        contexto_compilador.set_contexto("classe");
        contexto_compilador.get_tabela().iniciar_classe((yyvsp[-2].sval), "Classe Ontológica (Especializada)");
        contexto_compilador.get_tabela().finalizar_classe();
        free((yyvsp[-2].sval));
    }
#line 1322 "parser.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 99 "parser.y"
      {
          contexto_compilador.set_contexto("classe");
          contexto_compilador.get_tabela().iniciar_classe((yyvsp[-3].sval), "Classe Ontológica (Especializada com Escopo)");
      }
#line 1331 "parser.cpp"
    break;

  case 20: /* regra_classe: TOKEN_STEREOTYPE_CLASS TOKEN_CLASS_NAME TOKEN_SPECIALIZES lista_classes_mae '{' $@2 corpo_classe_opt '}'  */
#line 104 "parser.y"
      {
          contexto_compilador.get_tabela().finalizar_classe();
          free((yyvsp[-6].sval));
      }
#line 1340 "parser.cpp"
    break;

  case 21: /* lista_classes_mae: lista_classes_mae ',' TOKEN_CLASS_NAME  */
#line 111 "parser.y"
                                           { free((yyvsp[0].sval)); }
#line 1346 "parser.cpp"
    break;

  case 22: /* lista_classes_mae: TOKEN_CLASS_NAME  */
#line 112 "parser.y"
                       { free((yyvsp[0].sval)); }
#line 1352 "parser.cpp"
    break;

  case 27: /* atributo: TOKEN_NAME ':' tipo_atributo cardinalidade_opt meta_atributos_opt  */
#line 127 "parser.y"
    {
        contexto_compilador.set_contexto("atributo");
        contexto_compilador.get_tabela().registrar_atributo((yyvsp[-4].sval), "Atributo Interno");
        free((yyvsp[-4].sval));
        free((yyvsp[-2].sval));
    }
#line 1363 "parser.cpp"
    break;

  case 28: /* tipo_atributo: TOKEN_NATIVE_TYPE  */
#line 136 "parser.y"
                      { (yyval.sval) = strdup("nativo"); }
#line 1369 "parser.cpp"
    break;

  case 29: /* tipo_atributo: TOKEN_CLASS_NAME  */
#line 137 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1375 "parser.cpp"
    break;

  case 30: /* tipo_atributo: TOKEN_NEW_TYPE  */
#line 138 "parser.y"
                     { (yyval.sval) = (yyvsp[0].sval); }
#line 1381 "parser.cpp"
    break;

  case 31: /* tipo_atributo: TOKEN_NAME  */
#line 139 "parser.y"
                 { (yyval.sval) = (yyvsp[0].sval); }
#line 1387 "parser.cpp"
    break;

  case 36: /* regra_enum: TOKEN_ENUM TOKEN_CLASS_NAME '{' lista_instancias '}'  */
#line 154 "parser.y"
    {
        contexto_compilador.set_contexto("enum");
        contexto_compilador.get_tabela().registrar_enum((yyvsp[-3].sval));
        free((yyvsp[-3].sval));
    }
#line 1397 "parser.cpp"
    break;

  case 39: /* nome_instancia: TOKEN_INSTANCE_NAME  */
#line 167 "parser.y"
                        { free((yyvsp[0].sval)); }
#line 1403 "parser.cpp"
    break;

  case 40: /* nome_instancia: TOKEN_CLASS_NAME  */
#line 168 "parser.y"
                       { free((yyvsp[0].sval)); }
#line 1409 "parser.cpp"
    break;

  case 41: /* nome_instancia: TOKEN_NAME  */
#line 169 "parser.y"
                 { free((yyvsp[0].sval)); }
#line 1415 "parser.cpp"
    break;

  case 42: /* regra_datatype: TOKEN_DATATYPE TOKEN_NEW_TYPE '{' atributos_opt '}'  */
#line 174 "parser.y"
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype((yyvsp[-3].sval));
        free((yyvsp[-3].sval));
    }
#line 1425 "parser.cpp"
    break;

  case 43: /* regra_datatype: TOKEN_DATATYPE TOKEN_CLASS_NAME '{' atributos_opt '}'  */
#line 180 "parser.y"
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype((yyvsp[-3].sval));
        free((yyvsp[-3].sval));
    }
#line 1435 "parser.cpp"
    break;

  case 44: /* regra_datatype: TOKEN_DATATYPE TOKEN_NAME '{' atributos_opt '}'  */
#line 186 "parser.y"
    {
        contexto_compilador.set_contexto("datatype");
        contexto_compilador.get_tabela().registrar_datatype((yyvsp[-3].sval));
        free((yyvsp[-3].sval));
    }
#line 1445 "parser.cpp"
    break;

  case 48: /* genset_declaracao: TOKEN_GENSET TOKEN_CLASS_NAME '{' TOKEN_GENERAL TOKEN_CLASS_NAME TOKEN_SPECIFICS classes_especializadas '}'  */
#line 204 "parser.y"
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset((yyvsp[-6].sval), (yyvsp[-3].sval));
        free((yyvsp[-6].sval));
        free((yyvsp[-3].sval));
    }
#line 1456 "parser.cpp"
    break;

  case 49: /* genset_declaracao: TOKEN_GENSET '{' TOKEN_GENERAL TOKEN_CLASS_NAME TOKEN_SPECIFICS classes_especializadas '}'  */
#line 211 "parser.y"
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset("GensetBloco", (yyvsp[-3].sval));
        free((yyvsp[-3].sval));
    }
#line 1466 "parser.cpp"
    break;

  case 50: /* genset_declaracao: genset_restricao TOKEN_CLASS_NAME TOKEN_WHERE classes_especializadas TOKEN_SPECIALIZES TOKEN_CLASS_NAME  */
#line 217 "parser.y"
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset((yyvsp[-4].sval), (yyvsp[0].sval));
        free((yyvsp[-4].sval));
        free((yyvsp[0].sval));
    }
#line 1477 "parser.cpp"
    break;

  case 51: /* genset_declaracao: genset_restricao TOKEN_NAME TOKEN_WHERE classes_especializadas TOKEN_SPECIALIZES TOKEN_CLASS_NAME  */
#line 224 "parser.y"
    {
        contexto_compilador.set_contexto("genset");
        contexto_compilador.get_tabela().registrar_genset((yyvsp[-4].sval), (yyvsp[0].sval));
        free((yyvsp[-4].sval));
        free((yyvsp[0].sval));
    }
#line 1488 "parser.cpp"
    break;

  case 58: /* classes_especializadas: classes_especializadas ',' TOKEN_CLASS_NAME  */
#line 246 "parser.y"
    {
        free((yyvsp[0].sval));
    }
#line 1496 "parser.cpp"
    break;

  case 59: /* classes_especializadas: TOKEN_CLASS_NAME  */
#line 250 "parser.y"
    {
        free((yyvsp[0].sval));
    }
#line 1504 "parser.cpp"
    break;

  case 60: /* relacao_interna: '@' TOKEN_STEREOTYPE_RELATION cardinalidade_opt simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME  */
#line 257 "parser.y"
    {
        contexto_compilador.set_contexto("relacao");
        contexto_compilador.get_tabela().registrar_relacao_interna((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 1514 "parser.cpp"
    break;

  case 61: /* relacao_interna: '@' TOKEN_STEREOTYPE_RELATION cardinalidade_opt simbolo_relacao TOKEN_NAME simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME  */
#line 263 "parser.y"
    {
        contexto_compilador.set_contexto("relacao");
        contexto_compilador.get_tabela().registrar_relacao_interna((yyvsp[0].sval));
        free((yyvsp[-3].sval));
        free((yyvsp[0].sval));
    }
#line 1525 "parser.cpp"
    break;

  case 62: /* relacao_externa: '@' TOKEN_STEREOTYPE_RELATION TOKEN_RELATION relacao_classes  */
#line 273 "parser.y"
    {
        contexto_compilador.set_contexto("relacao");
    }
#line 1533 "parser.cpp"
    break;

  case 63: /* relacao_externa: '@' TOKEN_STEREOTYPE_RELATION TOKEN_NAME relacao_classes  */
#line 277 "parser.y"
    {
        contexto_compilador.set_contexto("relacao");
    }
#line 1541 "parser.cpp"
    break;

  case 64: /* relacao_classes: TOKEN_CLASS_NAME cardinalidade_opt simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME  */
#line 284 "parser.y"
    {
        contexto_compilador.get_tabela().registrar_relacao_externa((yyvsp[-4].sval), (yyvsp[0].sval));
        free((yyvsp[-4].sval));
        free((yyvsp[0].sval));
    }
#line 1551 "parser.cpp"
    break;

  case 65: /* relacao_classes: TOKEN_CLASS_NAME cardinalidade_opt simbolo_relacao TOKEN_NAME simbolo_relacao cardinalidade_opt TOKEN_CLASS_NAME  */
#line 290 "parser.y"
    {
        contexto_compilador.get_tabela().registrar_relacao_externa((yyvsp[-6].sval), (yyvsp[0].sval), (yyvsp[-3].sval));
        free((yyvsp[-6].sval));
        free((yyvsp[-3].sval));
        free((yyvsp[0].sval));
    }
#line 1562 "parser.cpp"
    break;


#line 1566 "parser.cpp"

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

#line 315 "parser.y"


int main(int argc, char** argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            contexto_compilador.processar_arquivo(argv[i]);
        }
    } else {
        contexto_compilador.processar_entrada_padrao();
    }

    contexto_compilador.get_tabela().imprimir_tabela_dispersao();
    contexto_compilador.get_tabela().imprimir_tabela_sintese();

    return 0;
}
