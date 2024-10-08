/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    TOKEN_INTEIRO = 258,           /* TOKEN_INTEIRO  */
    TOKEN_REAL = 259,              /* TOKEN_REAL  */
    TOKEN_SE = 260,                /* TOKEN_SE  */
    TOKEN_ENTAO = 261,             /* TOKEN_ENTAO  */
    TOKEN_SENAO = 262,             /* TOKEN_SENAO  */
    TOKEN_ENQUANTO = 263,          /* TOKEN_ENQUANTO  */
    TOKEN_REPITA = 264,            /* TOKEN_REPITA  */
    TOKEN_ATE = 265,               /* TOKEN_ATE  */
    TOKEN_LER = 266,               /* TOKEN_LER  */
    TOKEN_MOSTRAR = 267,           /* TOKEN_MOSTRAR  */
    TOKEN_OPERACAO_SOMA = 268,     /* TOKEN_OPERACAO_SOMA  */
    TOKEN_OPERACAO_SUBTRACAO = 269, /* TOKEN_OPERACAO_SUBTRACAO  */
    TOKEN_OPERACAO_MULTIPLICACAO = 270, /* TOKEN_OPERACAO_MULTIPLICACAO  */
    TOKEN_OPERACAO_DIVISAO = 271,  /* TOKEN_OPERACAO_DIVISAO  */
    TOKEN_OPERACAO_E = 272,        /* TOKEN_OPERACAO_E  */
    TOKEN_OPERACAO_OU = 273,       /* TOKEN_OPERACAO_OU  */
    TOKEN_OPERACAO_MENOR_QUE = 274, /* TOKEN_OPERACAO_MENOR_QUE  */
    TOKEN_OPERACAO_MENOR_IGUAL = 275, /* TOKEN_OPERACAO_MENOR_IGUAL  */
    TOKEN_OPERACAO_MAIOR_QUE = 276, /* TOKEN_OPERACAO_MAIOR_QUE  */
    TOKEN_OPERACAO_MAIOR_IGUAL = 277, /* TOKEN_OPERACAO_MAIOR_IGUAL  */
    TOKEN_OPERACAO_IGUAL = 278,    /* TOKEN_OPERACAO_IGUAL  */
    TOKEN_OPERACAO_DIFERENTE = 279, /* TOKEN_OPERACAO_DIFERENTE  */
    TOKEN_OPERACAO_ATRIBUICAO = 280, /* TOKEN_OPERACAO_ATRIBUICAO  */
    TOKEN_OPERACAO_SEPARADOR_COMANDO = 281, /* TOKEN_OPERACAO_SEPARADOR_COMANDO  */
    TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES = 282, /* TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES  */
    TOKEN_OPERACAO_ABRE_EXPRECAO = 283, /* TOKEN_OPERACAO_ABRE_EXPRECAO  */
    TOKEN_OPERACAO_FECHA_EXPRECAO = 284, /* TOKEN_OPERACAO_FECHA_EXPRECAO  */
    TOKEN_OPERACAO_INICIA_BLOCO_COMANDO = 285, /* TOKEN_OPERACAO_INICIA_BLOCO_COMANDO  */
    TOKEN_OPERACAO_FECHA_BLOCO_COMANDO = 286, /* TOKEN_OPERACAO_FECHA_BLOCO_COMANDO  */
    TOKEN_IDENTIFICADOR = 287,     /* TOKEN_IDENTIFICADOR  */
    TOKEN_STRING = 288,            /* TOKEN_STRING  */
    TOKEN_CHAR = 289               /* TOKEN_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
