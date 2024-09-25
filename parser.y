%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void yyerror(const char *s);
int yylex();
%}

%token TOKEN_INTEIRO TOKEN_REAL TOKEN_SE TOKEN_ENTAO TOKEN_SENAO
%token TOKEN_ENQUANTO TOKEN_REPITA TOKEN_ATE TOKEN_LER TOKEN_MOSTRAR
%token TOKEN_OPERACAO_SOMA TOKEN_OPERACAO_SUBTRACAO TOKEN_OPERACAO_MULTIPLICACAO
%token TOKEN_OPERACAO_DIVISAO TOKEN_OPERACAO_E TOKEN_OPERACAO_OU
%token TOKEN_OPERACAO_MENOR_QUE TOKEN_OPERACAO_MENOR_IGUAL TOKEN_OPERACAO_MAIOR_QUE
%token TOKEN_OPERACAO_MAIOR_IGUAL TOKEN_OPERACAO_IGUAL TOKEN_OPERACAO_DIFERENTE
%token TOKEN_OPERACAO_ATRIBUICAO TOKEN_OPERACAO_SEPARADOR_COMANDO
%token TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES TOKEN_OPERACAO_ABRE_EXPRECAO
%token TOKEN_OPERACAO_FECHA_EXPRECAO TOKEN_OPERACAO_INICIA_BLOCO_COMANDO
%token TOKEN_OPERACAO_FECHA_BLOCO_COMANDO TOKEN_IDENTIFICADOR
%token TOKEN_STRING TOKEN_CHAR

// Definição da precedência dos operadores
%left TOKEN_OPERACAO_OU 
%left TOKEN_OPERACAO_E
%left TOKEN_OPERACAO_IGUAL TOKEN_OPERACAO_DIFERENTE
%left TOKEN_OPERACAO_MENOR_QUE TOKEN_OPERACAO_MENOR_IGUAL TOKEN_OPERACAO_MAIOR_QUE TOKEN_OPERACAO_MAIOR_IGUAL
%left TOKEN_OPERACAO_SOMA TOKEN_OPERACAO_SUBTRACAO
%left TOKEN_OPERACAO_MULTIPLICACAO TOKEN_OPERACAO_DIVISAO


%% 
programa: lista_de_comandos
        ;

lista_de_comandos: lista_de_comandos comando
                 | comando
                 ;

comando:
    expressao TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_condicional
    | comando_enquanto TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_repita TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_leitura TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_escrita TOKEN_OPERACAO_SEPARADOR_COMANDO
    | declaracao_variavel TOKEN_OPERACAO_SEPARADOR_COMANDO
    | bloco_comando TOKEN_OPERACAO_SEPARADOR_COMANDO
    ;

comando_condicional:
    TOKEN_SE expressao TOKEN_ENTAO comando
    |TOKEN_SE expressao TOKEN_ENTAO comando TOKEN_SENAO comando
    ;


bloco_comando:
    TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO
    ;

comando_enquanto: TOKEN_ENQUANTO expressao TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO
                ;

comando_repita: TOKEN_REPITA bloco_comando TOKEN_ATE expressao
              | TOKEN_REPITA comando TOKEN_ATE expressao
              ;

comando_leitura: TOKEN_LER TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_IDENTIFICADOR TOKEN_OPERACAO_FECHA_EXPRECAO
               ;

comando_escrita: TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO
               ;

declaracao_variavel: tipo lista_identificadores
                   ;

tipo: TOKEN_INTEIRO
    | TOKEN_REAL
    ;

lista_identificadores: TOKEN_IDENTIFICADOR
                     | lista_identificadores TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES TOKEN_IDENTIFICADOR
                     ;

expressao: expressao TOKEN_OPERACAO_SOMA expressao
         | expressao TOKEN_OPERACAO_SUBTRACAO expressao
         | expressao TOKEN_OPERACAO_MULTIPLICACAO expressao
         | expressao TOKEN_OPERACAO_DIVISAO expressao
         | expressao TOKEN_OPERACAO_E expressao
         | expressao TOKEN_OPERACAO_OU expressao
         | expressao TOKEN_OPERACAO_MENOR_QUE expressao
         | expressao TOKEN_OPERACAO_MENOR_IGUAL expressao
         | expressao TOKEN_OPERACAO_MAIOR_QUE expressao
         | expressao TOKEN_OPERACAO_MAIOR_IGUAL expressao
         | expressao TOKEN_OPERACAO_IGUAL expressao
         | expressao TOKEN_OPERACAO_DIFERENTE expressao
         | TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO
         | TOKEN_INTEIRO
         | TOKEN_REAL
         | TOKEN_IDENTIFICADOR
         | TOKEN_STRING
         | TOKEN_CHAR
         ;

%% 

void yyerror(const char *s) {
    fprintf(stderr, "Erro de análise: %s\n", s);
}
