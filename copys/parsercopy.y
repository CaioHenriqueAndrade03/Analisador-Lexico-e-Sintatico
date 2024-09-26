%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"  // Inclua o arquivo do lexer

int yylex(); // Declaração do lexer
void yyerror(const char *s);

extern FILE *yyin; // Declara yyin
%}

%left TOKEN_OPERACAO_SOMA TOKEN_OPERACAO_SUBTRACAO
%left TOKEN_OPERACAO_MULTIPLICACAO TOKEN_OPERACAO_DIVISAO
%left TOKEN_OPERACAO_MAIOR_QUE TOKEN_OPERACAO_MAIOR_IGUAL TOKEN_OPERACAO_MENOR_QUE TOKEN_OPERACAO_MENOR_IGUAL
%left TOKEN_OPERACAO_E TOKEN_OPERACAO_OU
%left TOKEN_OPERACAO_IGUAL TOKEN_OPERACAO_DIFERENTE

%token TOKEN_INTEIRO
%token TOKEN_REAL
%token TOKEN_SE
%token TOKEN_ENTAO
%token TOKEN_SENAO
%token TOKEN_MOSTRAR
%token TOKEN_LER
%token TOKEN_ENQUANTO
%token TOKEN_REPITA
%token TOKEN_ATE
%token TOKEN_OPERACAO_E
%token TOKEN_OPERACAO_OU
%token TOKEN_OPERACAO_MENOR_QUE
%token TOKEN_OPERACAO_MENOR_IGUAL
%token TOKEN_OPERACAO_MAIOR_QUE
%token TOKEN_OPERACAO_MAIOR_IGUAL
%token TOKEN_OPERACAO_IGUAL
%token TOKEN_OPERACAO_DIFERENTE
%token TOKEN_OPERACAO_ATRIBUICAO
%token TOKEN_OPERACAO_SOMA
%token TOKEN_OPERACAO_SUBTRACAO
%token TOKEN_OPERACAO_MULTIPLICACAO
%token TOKEN_OPERACAO_DIVISAO
%token TOKEN_OPERACAO_SEPARADOR_COMANDO
%token TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES
%token TOKEN_OPERACAO_ABRE_EXPRECAO
%token TOKEN_OPERACAO_FECHA_EXPRECAO
%token TOKEN_OPERACAO_INICIA_BLOCO_COMANDO
%token TOKEN_OPERACAO_FECHA_BLOCO_COMANDO
%token TOKEN_IDENTIFICADOR
%token TOKEN_STRING
%token TOKEN_CHAR

%%

programa: lista_de_comandos
        ;

lista_de_comandos: lista_de_comandos comando
                 | comando
                 ;

comando:
    expressao TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_enquanto TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_repita TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_leitura TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_escrita TOKEN_OPERACAO_SEPARADOR_COMANDO
    | declaracao_variavel TOKEN_OPERACAO_SEPARADOR_COMANDO
    | bloco_comando TOKEN_OPERACAO_SEPARADOR_COMANDO
    | comando_condicional TOKEN_OPERACAO_SEPARADOR_COMANDO
    ;

comando_condicional:
    TOKEN_SE expressao TOKEN_ENTAO comando
    | TOKEN_SE expressao TOKEN_ENTAO comando TOKEN_SENAO comando
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

// Função de erro
void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Não foi possível abrir o arquivo de entrada");
        return 1;
    }

    yyin = file; // Redireciona a entrada do lexer para o arquivo

    yyparse(); // Chama o parser

    fclose(file);
    return 0;
}
