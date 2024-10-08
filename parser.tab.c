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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

extern FILE *yyin; // Declaração externa para yyin
extern char *yytext; // Declaração externa para yytext

void yyerror(const char *s);
int yylex();

#define YYSTYPE No*

typedef enum {
    NO_DECLARACAO_VARIAVEL,
    NO_ATRIBUICAO,
    NO_CONDICIONAL,
    NO_ESCRITA,
    NO_LEITURA,
    NO_EXPRESSAO,
    NO_TIPO,
    NO_IDENTIFICADOR,
    NO_STRING,
    NO_CHAR,
    NO_INTEIRO,
    NO_REAL,
    NO_BLOCO_COMANDO,
    NO_FUNCIONAMENTO,  
    NO_LOOP,
    NO_PARAMETRO,    
    NO_ERRO,    
} TipoNo;

typedef struct No {
    TipoNo tipo;
    char *valor;
    struct No *filhos[3];
    struct No *irmao;
    int num_filhos;
} No;

No* criar_no(TipoNo tipo, char *valor) {
    No *no = (No *)malloc(sizeof(No));
    no->tipo = tipo;
    no->valor = valor ? strdup(valor) : NULL;
    no->num_filhos = 0;
    for (int i = 0; i < 3; i++) no->filhos[i] = NULL;
    no->irmao = NULL;
    return no;
}

void imprimir_arvore(No *no, int nivel) {
    if (no == NULL) return;

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }

    // Usar um switch ou um array para mapear tipos a strings
    const char *tipo_str;
    switch (no->tipo) {
        case NO_DECLARACAO_VARIAVEL: tipo_str = "Declaração de Variável"; break;
        case NO_ATRIBUICAO: tipo_str = "Atribuição"; break;
        case NO_CONDICIONAL: tipo_str = "Condicional"; break;
        case NO_ESCRITA: tipo_str = "Escrita"; break;
        case NO_LEITURA: tipo_str = "Leitura"; break;
        case NO_EXPRESSAO: tipo_str = "Expressão"; break;
        case NO_TIPO: tipo_str = "Tipo"; break;
        case NO_IDENTIFICADOR: tipo_str = "Identificador"; break;
        case NO_STRING: tipo_str = "String"; break;
        case NO_CHAR: tipo_str = "Char"; break;
        case NO_INTEIRO: tipo_str = "Inteiro"; break;
        case NO_REAL: tipo_str = "Real"; break;
        case NO_BLOCO_COMANDO: tipo_str = "Bloco de Comando"; break;
        case NO_FUNCIONAMENTO: tipo_str = "Funcionamento"; break;
        case NO_LOOP: tipo_str = "Loop"; break;
        case NO_PARAMETRO: tipo_str = "Parâmetro"; break;
        case NO_ERRO: tipo_str = "Erro"; break;
        default: tipo_str = "Desconhecido"; break;
    }

    printf("%s: %s\n", tipo_str, no->valor ? no->valor : "NULL");

    for (int i = 0; i < no->num_filhos; i++) {
        imprimir_arvore(no->filhos[i], nivel + 1);
    }

    imprimir_arvore(no->irmao, nivel);
}




static No *raiz = NULL;


#line 169 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INTEIRO = 3,              /* TOKEN_INTEIRO  */
  YYSYMBOL_TOKEN_REAL = 4,                 /* TOKEN_REAL  */
  YYSYMBOL_TOKEN_SE = 5,                   /* TOKEN_SE  */
  YYSYMBOL_TOKEN_ENTAO = 6,                /* TOKEN_ENTAO  */
  YYSYMBOL_TOKEN_SENAO = 7,                /* TOKEN_SENAO  */
  YYSYMBOL_TOKEN_ENQUANTO = 8,             /* TOKEN_ENQUANTO  */
  YYSYMBOL_TOKEN_REPITA = 9,               /* TOKEN_REPITA  */
  YYSYMBOL_TOKEN_ATE = 10,                 /* TOKEN_ATE  */
  YYSYMBOL_TOKEN_LER = 11,                 /* TOKEN_LER  */
  YYSYMBOL_TOKEN_MOSTRAR = 12,             /* TOKEN_MOSTRAR  */
  YYSYMBOL_TOKEN_OPERACAO_SOMA = 13,       /* TOKEN_OPERACAO_SOMA  */
  YYSYMBOL_TOKEN_OPERACAO_SUBTRACAO = 14,  /* TOKEN_OPERACAO_SUBTRACAO  */
  YYSYMBOL_TOKEN_OPERACAO_MULTIPLICACAO = 15, /* TOKEN_OPERACAO_MULTIPLICACAO  */
  YYSYMBOL_TOKEN_OPERACAO_DIVISAO = 16,    /* TOKEN_OPERACAO_DIVISAO  */
  YYSYMBOL_TOKEN_OPERACAO_E = 17,          /* TOKEN_OPERACAO_E  */
  YYSYMBOL_TOKEN_OPERACAO_OU = 18,         /* TOKEN_OPERACAO_OU  */
  YYSYMBOL_TOKEN_OPERACAO_MENOR_QUE = 19,  /* TOKEN_OPERACAO_MENOR_QUE  */
  YYSYMBOL_TOKEN_OPERACAO_MENOR_IGUAL = 20, /* TOKEN_OPERACAO_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_OPERACAO_MAIOR_QUE = 21,  /* TOKEN_OPERACAO_MAIOR_QUE  */
  YYSYMBOL_TOKEN_OPERACAO_MAIOR_IGUAL = 22, /* TOKEN_OPERACAO_MAIOR_IGUAL  */
  YYSYMBOL_TOKEN_OPERACAO_IGUAL = 23,      /* TOKEN_OPERACAO_IGUAL  */
  YYSYMBOL_TOKEN_OPERACAO_DIFERENTE = 24,  /* TOKEN_OPERACAO_DIFERENTE  */
  YYSYMBOL_TOKEN_OPERACAO_ATRIBUICAO = 25, /* TOKEN_OPERACAO_ATRIBUICAO  */
  YYSYMBOL_TOKEN_OPERACAO_SEPARADOR_COMANDO = 26, /* TOKEN_OPERACAO_SEPARADOR_COMANDO  */
  YYSYMBOL_TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES = 27, /* TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES  */
  YYSYMBOL_TOKEN_OPERACAO_ABRE_EXPRECAO = 28, /* TOKEN_OPERACAO_ABRE_EXPRECAO  */
  YYSYMBOL_TOKEN_OPERACAO_FECHA_EXPRECAO = 29, /* TOKEN_OPERACAO_FECHA_EXPRECAO  */
  YYSYMBOL_TOKEN_OPERACAO_INICIA_BLOCO_COMANDO = 30, /* TOKEN_OPERACAO_INICIA_BLOCO_COMANDO  */
  YYSYMBOL_TOKEN_OPERACAO_FECHA_BLOCO_COMANDO = 31, /* TOKEN_OPERACAO_FECHA_BLOCO_COMANDO  */
  YYSYMBOL_TOKEN_IDENTIFICADOR = 32,       /* TOKEN_IDENTIFICADOR  */
  YYSYMBOL_TOKEN_STRING = 33,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 34,                /* TOKEN_CHAR  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_lista_de_comandos = 37,         /* lista_de_comandos  */
  YYSYMBOL_comando = 38,                   /* comando  */
  YYSYMBOL_comando_atribuir = 39,          /* comando_atribuir  */
  YYSYMBOL_comando_condicional = 40,       /* comando_condicional  */
  YYSYMBOL_bloco_comando = 41,             /* bloco_comando  */
  YYSYMBOL_comando_enquanto = 42,          /* comando_enquanto  */
  YYSYMBOL_comando_repita = 43,            /* comando_repita  */
  YYSYMBOL_comando_leitura = 44,           /* comando_leitura  */
  YYSYMBOL_comando_escrita = 45,           /* comando_escrita  */
  YYSYMBOL_declaracao_variavel = 46,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 47,                      /* tipo  */
  YYSYMBOL_lista_identificadores = 48,     /* lista_identificadores  */
  YYSYMBOL_expressao = 49,                 /* expressao  */
  YYSYMBOL_expressao_operacao_soma = 50,   /* expressao_operacao_soma  */
  YYSYMBOL_expressao_operacao_subtracao = 51, /* expressao_operacao_subtracao  */
  YYSYMBOL_expressao_operacao_multiplicacao = 52, /* expressao_operacao_multiplicacao  */
  YYSYMBOL_expressao_operacao_divisao = 53, /* expressao_operacao_divisao  */
  YYSYMBOL_expressao_operacao_e = 54,      /* expressao_operacao_e  */
  YYSYMBOL_expressao_operacao_ou = 55,     /* expressao_operacao_ou  */
  YYSYMBOL_expressao_operacao_maior_que = 56, /* expressao_operacao_maior_que  */
  YYSYMBOL_expressao_operacao_menor_que = 57, /* expressao_operacao_menor_que  */
  YYSYMBOL_expressao_operacao_maior_igual = 58, /* expressao_operacao_maior_igual  */
  YYSYMBOL_expressao_operacao_menor_igual = 59, /* expressao_operacao_menor_igual  */
  YYSYMBOL_expressao_operacao_igual = 60,  /* expressao_operacao_igual  */
  YYSYMBOL_expressao_operacao_diferente = 61 /* expressao_operacao_diferente  */
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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   129,   132,   143,   146,   149,   152,   155,
     158,   161,   164,   167,   173,   183,   189,   200,   206,   215,
     221,   231,   240,   245,   254,   265,   268,   275,   280,   299,
     303,   307,   310,   313,   316,   319,   322,   325,   328,   331,
     334,   337,   340,   346,   355,   364,   373,   382,   391,   400,
     409,   418,   427,   436,   445
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
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INTEIRO",
  "TOKEN_REAL", "TOKEN_SE", "TOKEN_ENTAO", "TOKEN_SENAO", "TOKEN_ENQUANTO",
  "TOKEN_REPITA", "TOKEN_ATE", "TOKEN_LER", "TOKEN_MOSTRAR",
  "TOKEN_OPERACAO_SOMA", "TOKEN_OPERACAO_SUBTRACAO",
  "TOKEN_OPERACAO_MULTIPLICACAO", "TOKEN_OPERACAO_DIVISAO",
  "TOKEN_OPERACAO_E", "TOKEN_OPERACAO_OU", "TOKEN_OPERACAO_MENOR_QUE",
  "TOKEN_OPERACAO_MENOR_IGUAL", "TOKEN_OPERACAO_MAIOR_QUE",
  "TOKEN_OPERACAO_MAIOR_IGUAL", "TOKEN_OPERACAO_IGUAL",
  "TOKEN_OPERACAO_DIFERENTE", "TOKEN_OPERACAO_ATRIBUICAO",
  "TOKEN_OPERACAO_SEPARADOR_COMANDO",
  "TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES",
  "TOKEN_OPERACAO_ABRE_EXPRECAO", "TOKEN_OPERACAO_FECHA_EXPRECAO",
  "TOKEN_OPERACAO_INICIA_BLOCO_COMANDO",
  "TOKEN_OPERACAO_FECHA_BLOCO_COMANDO", "TOKEN_IDENTIFICADOR",
  "TOKEN_STRING", "TOKEN_CHAR", "$accept", "programa", "lista_de_comandos",
  "comando", "comando_atribuir", "comando_condicional", "bloco_comando",
  "comando_enquanto", "comando_repita", "comando_leitura",
  "comando_escrita", "declaracao_variavel", "tipo",
  "lista_identificadores", "expressao", "expressao_operacao_soma",
  "expressao_operacao_subtracao", "expressao_operacao_multiplicacao",
  "expressao_operacao_divisao", "expressao_operacao_e",
  "expressao_operacao_ou", "expressao_operacao_maior_que",
  "expressao_operacao_menor_que", "expressao_operacao_maior_igual",
  "expressao_operacao_menor_igual", "expressao_operacao_igual",
  "expressao_operacao_diferente", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,   -27,   -28,     8,   -14,    73,    -4,    -1,    73,    18,
      47,    73,   -28,    13,    22,    24,    30,    31,    36,    57,
      60,    62,   139,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,    93,     8,    82,
      -6,    63,     0,     4,     8,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,    69,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,   -28,
      73,   105,     8,     8,    71,    72,   122,   -28,   153,    70,
      26,    26,   -28,   -28,   177,   165,    15,    15,    15,    75,
      39,    39,    14,    74,   153,   153,   -28,   -28,   -28,   -28,
      73,   100,    73,   101,   -28
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    30,    26,     0,     0,     0,     0,     0,     0,    29,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    30,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     4,    13,    12,    11,
       6,     7,     8,     9,    10,    27,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,    17,    14,     0,
      43,    44,    45,    46,    47,    48,    50,    52,    49,    51,
      53,    54,    15,     0,    20,    19,    21,    23,    22,    28,
       0,     0,    16,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    -7,    -5,   -28,   -28,    -3,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,     7,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    56,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    43,    40,    35,    73,   -25,    46,     1,     2,     3,
      37,    35,     4,     5,    38,     6,     7,     1,     2,     3,
      49,   100,     4,     5,    41,     6,     7,    42,    57,    58,
      59,    60,    36,    75,     8,    77,     9,    66,    46,    47,
      36,    59,    60,    44,     8,    71,     9,    45,    48,    76,
      49,    78,    57,    58,    59,    60,    50,    51,    63,    64,
      65,    66,    52,    92,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     1,     2,     3,    94,
      95,     4,     5,    53,     6,     7,    54,    46,    57,    58,
      59,    60,    72,   102,    55,    74,    79,    46,   103,    70,
      96,    97,    99,     8,   101,     9,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       8,     0,   104,     0,    93,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     0,
       0,    98,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    57,    58,
      59,    60,    61,     0,    63,    64,    65,    66,    67,    68,
      57,    58,    59,    60,     0,     0,    63,    64,    65,    66,
      67,    68
};

static const yytype_int8 yycheck[] =
{
       5,     8,     5,     3,    10,    32,    11,     3,     4,     5,
       3,     3,     8,     9,    28,    11,    12,     3,     4,     5,
      26,     7,     8,     9,    28,    11,    12,    28,    13,    14,
      15,    16,    32,    33,    30,    31,    32,    22,    43,    26,
      32,    15,    16,    25,    30,    38,    32,     0,    26,    42,
      26,    44,    13,    14,    15,    16,    26,    26,    19,    20,
      21,    22,    26,    70,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     3,     4,     5,    72,
      73,     8,     9,    26,    11,    12,    26,    92,    13,    14,
      15,    16,    10,   100,    32,    32,    27,   102,   101,     6,
      29,    29,    32,    30,    30,    32,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      30,    -1,    31,    -1,    29,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     8,     9,    11,    12,    30,    32,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     3,    32,    49,    28,    38,
      41,    28,    28,    37,    25,     0,    38,    26,    26,    26,
      26,    26,    26,    26,    26,    32,    48,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    26,
       6,    49,    10,    10,    32,    33,    49,    31,    49,    27,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    37,    29,    49,    49,    29,    29,    29,    32,
       7,    30,    37,    41,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    39,    40,    40,    41,    42,    43,
      43,    44,    45,    45,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     6,     3,     7,     4,
       4,     4,     4,     4,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
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
  case 2: /* programa: lista_de_comandos  */
#line 123 "parser.y"
                            {
    raiz = yyvsp[0];
}
#line 1320 "parser.tab.c"
    break;

  case 3: /* lista_de_comandos: comando  */
#line 129 "parser.y"
            {
        yyval = yyvsp[0];
    }
#line 1328 "parser.tab.c"
    break;

  case 4: /* lista_de_comandos: lista_de_comandos comando  */
#line 132 "parser.y"
                                {
        No *ultimo = yyvsp[-1];
        while (ultimo->irmao != NULL) {
            ultimo = ultimo->irmao;
        }
        ultimo->irmao = yyvsp[0];
        yyval = yyvsp[-1];
    }
#line 1341 "parser.tab.c"
    break;

  case 5: /* comando: expressao TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 143 "parser.y"
                                               {
        yyval = yyvsp[-1];
    }
#line 1349 "parser.tab.c"
    break;

  case 6: /* comando: comando_enquanto TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 146 "parser.y"
                                                        {
        yyval = yyvsp[-1];
    }
#line 1357 "parser.tab.c"
    break;

  case 7: /* comando: comando_repita TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 149 "parser.y"
                                                      {
        yyval = yyvsp[-1];
    }
#line 1365 "parser.tab.c"
    break;

  case 8: /* comando: comando_leitura TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 152 "parser.y"
                                                       {
        yyval = yyvsp[-1];
    }
#line 1373 "parser.tab.c"
    break;

  case 9: /* comando: comando_escrita TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 155 "parser.y"
                                                       {
        yyval = yyvsp[-1];
    }
#line 1381 "parser.tab.c"
    break;

  case 10: /* comando: declaracao_variavel TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 158 "parser.y"
                                                           {
        yyval = yyvsp[-1];
    }
#line 1389 "parser.tab.c"
    break;

  case 11: /* comando: bloco_comando TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 161 "parser.y"
                                                     {
        yyval = yyvsp[-1];
    }
#line 1397 "parser.tab.c"
    break;

  case 12: /* comando: comando_condicional TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 164 "parser.y"
                                                           {
        yyval = yyvsp[-1];
    }
#line 1405 "parser.tab.c"
    break;

  case 13: /* comando: comando_atribuir TOKEN_OPERACAO_SEPARADOR_COMANDO  */
#line 167 "parser.y"
                                                        {
        yyval = yyvsp[-1];
    }
#line 1413 "parser.tab.c"
    break;

  case 14: /* comando_atribuir: TOKEN_IDENTIFICADOR TOKEN_OPERACAO_ATRIBUICAO expressao  */
#line 173 "parser.y"
                                                            {
        yyval = criar_no(NO_ATRIBUICAO, strdup("Atribuição")); 
        yyval->filhos[0] = criar_no(NO_IDENTIFICADOR, strdup(yytext)); 
        yyval->filhos[1] = yyvsp[0]; 
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1424 "parser.tab.c"
    break;

  case 15: /* comando_condicional: TOKEN_SE expressao TOKEN_ENTAO lista_de_comandos  */
#line 183 "parser.y"
                                                     {
        yyval = criar_no(NO_CONDICIONAL,strdup("Comando condicional"));
        yyval->filhos[0] = yyvsp[-2]; // Expressão
        yyval->filhos[1] = yyvsp[0]; // Lista de comandos
        yyval->num_filhos = 2; // Ajuste para o número correto
    }
#line 1435 "parser.tab.c"
    break;

  case 16: /* comando_condicional: TOKEN_SE expressao TOKEN_ENTAO lista_de_comandos TOKEN_SENAO lista_de_comandos  */
#line 189 "parser.y"
                                                                                     {
        yyval = criar_no(NO_CONDICIONAL, strdup("Comando condicional SENAO"));
        yyval->filhos[0] = yyvsp[-4]; // Expressão
        yyval->filhos[1] = yyvsp[-2]; // Lista de comandos
        yyval->filhos[2] = yyvsp[0]; // Lista de comandos do SENA
        yyval->num_filhos = 3; // Ajuste para o número correto
    }
#line 1447 "parser.tab.c"
    break;

  case 17: /* bloco_comando: TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO  */
#line 200 "parser.y"
                                                                                             {
        yyval = yyvsp[-1];
    }
#line 1455 "parser.tab.c"
    break;

  case 18: /* comando_enquanto: TOKEN_ENQUANTO TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO TOKEN_OPERACAO_INICIA_BLOCO_COMANDO bloco_comando TOKEN_OPERACAO_FECHA_BLOCO_COMANDO  */
#line 206 "parser.y"
                                                                                                                                                                             {
        yyval = criar_no(NO_LOOP, strdup("Enquanto")); // Ajuste no tipo, se necessário
        yyval->filhos[0] = yyvsp[-4]; // Expressão
        yyval->filhos[1] = yyvsp[-1]; // Bloco de comandos
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1466 "parser.tab.c"
    break;

  case 19: /* comando_repita: TOKEN_REPITA bloco_comando TOKEN_ATE expressao  */
#line 215 "parser.y"
                                                   {
        yyval = criar_no(NO_LOOP, strdup("Repita ate")); // Ajuste no tipo, se necessário
        yyval->filhos[0] = yyvsp[-3]; // Bloco
        yyval->filhos[1] = yyvsp[0]; // Expressão
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1477 "parser.tab.c"
    break;

  case 20: /* comando_repita: TOKEN_REPITA comando TOKEN_ATE expressao  */
#line 221 "parser.y"
                                               {
        yyval = criar_no(NO_LOOP, strdup("Repita ate")); // Ajuste no tipo, se necessário
        yyval->filhos[0] = yyvsp[-2]; // Comando
        yyval->filhos[1] = yyvsp[0]; // Expressão
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1488 "parser.tab.c"
    break;

  case 21: /* comando_leitura: TOKEN_LER TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_IDENTIFICADOR TOKEN_OPERACAO_FECHA_EXPRECAO  */
#line 231 "parser.y"
                                                                                             {
        yyval = criar_no(NO_LEITURA, strdup("Leitura"));
        yyval->filhos[0] = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        yyval->num_filhos = 1; // Define o número correto de filhos
    }
#line 1498 "parser.tab.c"
    break;

  case 22: /* comando_escrita: TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO  */
#line 240 "parser.y"
                                                                                       {
        yyval = criar_no(NO_ESCRITA, strdup("Escrita"));
        yyval->filhos[0] = yyvsp[-1]; // Expressão
        yyval->num_filhos = 1; // Define o número correto de filhos
    }
#line 1508 "parser.tab.c"
    break;

  case 23: /* comando_escrita: TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_STRING TOKEN_OPERACAO_FECHA_EXPRECAO  */
#line 245 "parser.y"
                                                                                           {
        yyval = criar_no(NO_ESCRITA, strdup("Escrita"));
        yyval->filhos[0] = yyvsp[-1]; // Expressão
        yyval->num_filhos = 1; // Define o número correto de filhos
    }
#line 1518 "parser.tab.c"
    break;

  case 24: /* declaracao_variavel: tipo lista_identificadores  */
#line 254 "parser.y"
                               {
        yyval = criar_no(NO_DECLARACAO_VARIAVEL, strdup("Declaração de Variáveis"));
        yyval->filhos[0] = yyvsp[-1]; // Tipo
        yyval->filhos[1] = yyvsp[0]; // Lista de identificadores
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1529 "parser.tab.c"
    break;

  case 25: /* tipo: TOKEN_INTEIRO  */
#line 265 "parser.y"
                  {
        yyval = criar_no(NO_TIPO, strdup("inteiro"));
    }
#line 1537 "parser.tab.c"
    break;

  case 26: /* tipo: TOKEN_REAL  */
#line 268 "parser.y"
                 {
        yyval = criar_no(NO_TIPO, strdup("real"));
    }
#line 1545 "parser.tab.c"
    break;

  case 27: /* lista_identificadores: TOKEN_IDENTIFICADOR  */
#line 275 "parser.y"
                        {
        yyval = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        yyval->irmao = NULL; // Inicializa o irmão como NULL
        yyval->num_filhos = 0; // Não tem filhos
    }
#line 1555 "parser.tab.c"
    break;

  case 28: /* lista_identificadores: lista_identificadores TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES TOKEN_IDENTIFICADOR  */
#line 280 "parser.y"
                                                                                        {
        No *novo_id = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        yyval = yyvsp[-2]; // Mantém o primeiro nó
        
        // Conecta o novo identificador como irmão do último nó
        No *ultimo = yyval;
        while (ultimo->irmao != NULL) {
            ultimo = ultimo->irmao;
        }
        ultimo->irmao = novo_id; // Adiciona o novo identificador como irmão
    }
#line 1571 "parser.tab.c"
    break;

  case 29: /* expressao: TOKEN_IDENTIFICADOR  */
#line 299 "parser.y"
                        {
        yyval = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        yyval->num_filhos = 0; // Sem filhos
    }
#line 1580 "parser.tab.c"
    break;

  case 30: /* expressao: TOKEN_INTEIRO  */
#line 303 "parser.y"
                    {
        yyval = criar_no(NO_INTEIRO, strdup(yytext));
        yyval->num_filhos = 0; // Sem filhos
    }
#line 1589 "parser.tab.c"
    break;

  case 31: /* expressao: expressao_operacao_soma  */
#line 307 "parser.y"
                              {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1597 "parser.tab.c"
    break;

  case 32: /* expressao: expressao_operacao_subtracao  */
#line 310 "parser.y"
                                   {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1605 "parser.tab.c"
    break;

  case 33: /* expressao: expressao_operacao_multiplicacao  */
#line 313 "parser.y"
                                       {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1613 "parser.tab.c"
    break;

  case 34: /* expressao: expressao_operacao_divisao  */
#line 316 "parser.y"
                                 {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1621 "parser.tab.c"
    break;

  case 35: /* expressao: expressao_operacao_e  */
#line 319 "parser.y"
                           {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1629 "parser.tab.c"
    break;

  case 36: /* expressao: expressao_operacao_ou  */
#line 322 "parser.y"
                            {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1637 "parser.tab.c"
    break;

  case 37: /* expressao: expressao_operacao_maior_que  */
#line 325 "parser.y"
                                   {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1645 "parser.tab.c"
    break;

  case 38: /* expressao: expressao_operacao_menor_que  */
#line 328 "parser.y"
                                   {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1653 "parser.tab.c"
    break;

  case 39: /* expressao: expressao_operacao_maior_igual  */
#line 331 "parser.y"
                                     {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1661 "parser.tab.c"
    break;

  case 40: /* expressao: expressao_operacao_menor_igual  */
#line 334 "parser.y"
                                     {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1669 "parser.tab.c"
    break;

  case 41: /* expressao: expressao_operacao_igual  */
#line 337 "parser.y"
                               {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1677 "parser.tab.c"
    break;

  case 42: /* expressao: expressao_operacao_diferente  */
#line 340 "parser.y"
                                   {
        yyval = yyvsp[0]; // A operação já define a estrutura correta
    }
#line 1685 "parser.tab.c"
    break;

  case 43: /* expressao_operacao_soma: expressao TOKEN_OPERACAO_SOMA expressao  */
#line 346 "parser.y"
                                            {
        yyval = criar_no(NO_EXPRESSAO, strdup("+"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1696 "parser.tab.c"
    break;

  case 44: /* expressao_operacao_subtracao: expressao TOKEN_OPERACAO_SUBTRACAO expressao  */
#line 355 "parser.y"
                                                 {
        yyval = criar_no(NO_EXPRESSAO, strdup("-"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1707 "parser.tab.c"
    break;

  case 45: /* expressao_operacao_multiplicacao: expressao TOKEN_OPERACAO_MULTIPLICACAO expressao  */
#line 364 "parser.y"
                                                     {
        yyval = criar_no(NO_EXPRESSAO, strdup("*"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1718 "parser.tab.c"
    break;

  case 46: /* expressao_operacao_divisao: expressao TOKEN_OPERACAO_DIVISAO expressao  */
#line 373 "parser.y"
                                               {
        yyval = criar_no(NO_EXPRESSAO, strdup("/"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1729 "parser.tab.c"
    break;

  case 47: /* expressao_operacao_e: expressao TOKEN_OPERACAO_E expressao  */
#line 382 "parser.y"
                                         {
        yyval = criar_no(NO_EXPRESSAO, strdup("&&")); // Usando "&&" para E lógico
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1740 "parser.tab.c"
    break;

  case 48: /* expressao_operacao_ou: expressao TOKEN_OPERACAO_OU expressao  */
#line 391 "parser.y"
                                          {
        yyval = criar_no(NO_EXPRESSAO, strdup("||")); // Usando "||" para OU lógico
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1751 "parser.tab.c"
    break;

  case 49: /* expressao_operacao_maior_que: expressao TOKEN_OPERACAO_MAIOR_QUE expressao  */
#line 400 "parser.y"
                                                 {
        yyval = criar_no(NO_EXPRESSAO, strdup(">"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1762 "parser.tab.c"
    break;

  case 50: /* expressao_operacao_menor_que: expressao TOKEN_OPERACAO_MENOR_QUE expressao  */
#line 409 "parser.y"
                                                 {
        yyval = criar_no(NO_EXPRESSAO, strdup("<"));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1773 "parser.tab.c"
    break;

  case 51: /* expressao_operacao_maior_igual: expressao TOKEN_OPERACAO_MAIOR_IGUAL expressao  */
#line 418 "parser.y"
                                                   {
        yyval = criar_no(NO_EXPRESSAO, strdup(">="));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1784 "parser.tab.c"
    break;

  case 52: /* expressao_operacao_menor_igual: expressao TOKEN_OPERACAO_MENOR_IGUAL expressao  */
#line 427 "parser.y"
                                                   {
        yyval = criar_no(NO_EXPRESSAO, strdup("<="));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1795 "parser.tab.c"
    break;

  case 53: /* expressao_operacao_igual: expressao TOKEN_OPERACAO_IGUAL expressao  */
#line 436 "parser.y"
                                             {
        yyval = criar_no(NO_EXPRESSAO, strdup("=="));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1806 "parser.tab.c"
    break;

  case 54: /* expressao_operacao_diferente: expressao TOKEN_OPERACAO_DIFERENTE expressao  */
#line 445 "parser.y"
                                                 {
        yyval = criar_no(NO_EXPRESSAO, strdup("!="));
        yyval->filhos[0] = yyvsp[-2];
        yyval->filhos[1] = yyvsp[0];
        yyval->num_filhos = 2; // Define o número correto de filhos
    }
#line 1817 "parser.tab.c"
    break;


#line 1821 "parser.tab.c"

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

#line 454 "parser.y"
 

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Não foi possível abrir o arquivo");
            return EXIT_FAILURE;
        }
    }
    
    yyparse();
    imprimir_arvore(raiz, 0);
    return EXIT_SUCCESS;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}
