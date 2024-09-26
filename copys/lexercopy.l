%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"  // Inclua o arquivo do parser

int yylex(); // Declaração do lexer
void yyerror(const char *s);

%}

%option noyywrap

%%

"inteiro"              { return TOKEN_INTEIRO; }
"real"                 { return TOKEN_REAL; }
"se"                   { return TOKEN_SE; }
"entao"                { return TOKEN_ENTAO; }
"senao"                { return TOKEN_SENAO; }
"mostrar"              { return TOKEN_MOSTRAR; }
"ler"                  { return TOKEN_LER; }
"enquanto"             { return TOKEN_ENQUANTO; }
"repita"               { return TOKEN_REPITA; }
"ate"                  { return TOKEN_ATE; }
"&&"                   { return TOKEN_OPERACAO_E; }
"||"                   { return TOKEN_OPERACAO_OU; }
"<"                    { return TOKEN_OPERACAO_MENOR_QUE; }
"<="                   { return TOKEN_OPERACAO_MENOR_IGUAL; }
">"                    { return TOKEN_OPERACAO_MAIOR_QUE; }
">="                   { return TOKEN_OPERACAO_MAIOR_IGUAL; }
"=="                   { return TOKEN_OPERACAO_IGUAL; }
"!="                   { return TOKEN_OPERACAO_DIFERENTE; }
"="                    { return TOKEN_OPERACAO_ATRIBUICAO; } 
"+"                    { return TOKEN_OPERACAO_SOMA; }
"-"                    { return TOKEN_OPERACAO_SUBTRACAO; }
"*"                    { return TOKEN_OPERACAO_MULTIPLICACAO; }
"/"                    { return TOKEN_OPERACAO_DIVISAO; }
";"                    { return TOKEN_OPERACAO_SEPARADOR_COMANDO; }
","                    { return TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES; }
"("                    { return TOKEN_OPERACAO_ABRE_EXPRECAO; }
")"                    { return TOKEN_OPERACAO_FECHA_EXPRECAO; }
"{"                    { return TOKEN_OPERACAO_INICIA_BLOCO_COMANDO; }
"}"                    { return TOKEN_OPERACAO_FECHA_BLOCO_COMANDO; }

\"([^"\\]|\\.)*\"      { return TOKEN_STRING; }
\'([^'\\]|\\.)*\'      { return TOKEN_CHAR; }

"/*"([^/*]|\*+[^*/])*\*+"/"   { /* Ignora o comentário de bloco */ }
"//".*                      { /* Ignora o comentário de linha */ }

[a-zA-Z_][a-zA-Z0-9_]* { return TOKEN_IDENTIFICADOR; }
[0-9]+\.[0-9]+         { return TOKEN_REAL; }
[0-9]+                 { return TOKEN_INTEIRO; }

[ \t\n]+              ; // Ignora espaços em branco
.                     { fprintf(stderr, " Caractere não reconhecido: '%c'\n", yytext[0]); } // Trata caracteres não reconhecidos

%%

int my_yywrap() {
    return 1; 
}
