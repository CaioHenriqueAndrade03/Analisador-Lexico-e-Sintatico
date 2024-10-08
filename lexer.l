%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

// Função para imprimir tokens
void print_token(int token_type, const char* value) {
    printf("Token lido: ");
    switch (token_type) {
        case TOKEN_INTEIRO: printf("TOKEN_INTEIRO: %s\n", value); break;
        case TOKEN_REAL: printf("TOKEN_REAL: %s\n", value); break;
        case TOKEN_SE: printf("TOKEN_SE: %s\n", value); break;
        case TOKEN_ENTAO: printf("TOKEN_ENTAO: %s\n", value); break;
        case TOKEN_SENAO: printf("TOKEN_SENAO: %s\n", value); break;
        case TOKEN_ENQUANTO: printf("TOKEN_ENQUANTO: %s\n", value); break;
        case TOKEN_REPITA: printf("TOKEN_REPITA: %s\n", value); break;
        case TOKEN_ATE: printf("TOKEN_ATE: %s\n", value); break;
        case TOKEN_LER: printf("TOKEN_LER: %s\n", value); break;
        case TOKEN_MOSTRAR: printf("TOKEN_MOSTRAR: %s\n", value); break;
        case TOKEN_OPERACAO_SOMA: printf("TOKEN_OPERACAO_SOMA: %s\n", value); break;
        case TOKEN_OPERACAO_SUBTRACAO: printf("TOKEN_OPERACAO_SUBTRACAO: %s\n", value); break;
        case TOKEN_OPERACAO_MULTIPLICACAO: printf("TOKEN_OPERACAO_MULTIPLICACAO: %s\n", value); break;
        case TOKEN_OPERACAO_DIVISAO: printf("TOKEN_OPERACAO_DIVISAO: %s\n", value); break;
        case TOKEN_OPERACAO_E: printf("TOKEN_OPERACAO_E: %s\n", value); break;
        case TOKEN_OPERACAO_OU: printf("TOKEN_OPERACAO_OU: %s\n", value); break;
        case TOKEN_OPERACAO_MENOR_QUE: printf("TOKEN_OPERACAO_MENOR_QUE: %s\n", value); break;
        case TOKEN_OPERACAO_MENOR_IGUAL: printf("TOKEN_OPERACAO_MENOR_IGUAL: %s\n", value); break;
        case TOKEN_OPERACAO_MAIOR_QUE: printf("TOKEN_OPERACAO_MAIOR_QUE: %s\n", value); break;
        case TOKEN_OPERACAO_MAIOR_IGUAL: printf("TOKEN_OPERACAO_MAIOR_IGUAL: %s\n", value); break;
        case TOKEN_OPERACAO_IGUAL: printf("TOKEN_OPERACAO_IGUAL: %s\n", value); break;
        case TOKEN_OPERACAO_DIFERENTE: printf("TOKEN_OPERACAO_DIFERENTE: %s\n", value); break;
        case TOKEN_OPERACAO_ATRIBUICAO: printf("TOKEN_OPERACAO_ATRIBUICAO: %s\n", value); break;
        case TOKEN_OPERACAO_SEPARADOR_COMANDO: printf("TOKEN_OPERACAO_SEPARADOR_COMANDO: %s\n", value); break;
        case TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES: printf("TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES: %s\n", value); break;
        case TOKEN_OPERACAO_ABRE_EXPRECAO: printf("TOKEN_OPERACAO_ABRE_EXPRECAO: %s\n", value); break;
        case TOKEN_OPERACAO_FECHA_EXPRECAO: printf("TOKEN_OPERACAO_FECHA_EXPRECAO: %s\n", value); break;
        case TOKEN_OPERACAO_INICIA_BLOCO_COMANDO: printf("TOKEN_OPERACAO_INICIA_BLOCO_COMANDO: %s\n", value); break;
        case TOKEN_OPERACAO_FECHA_BLOCO_COMANDO: printf("TOKEN_OPERACAO_FECHA_BLOCO_COMANDO: %s\n", value); break;
        case TOKEN_IDENTIFICADOR: printf("TOKEN_IDENTIFICADOR: %s\n", value); break;
        case TOKEN_STRING: printf("TOKEN_STRING: %s\n", value); break;
        case TOKEN_CHAR: printf("TOKEN_CHAR: %s\n", value); break;
        default: printf("TOKEN DESCONHECIDO: %s\n", value);
    }
}
%}

%%

"inteiro"              { print_token(TOKEN_INTEIRO, yytext); return TOKEN_INTEIRO; }
"real"                 { print_token(TOKEN_REAL, yytext); return TOKEN_REAL; }
"se"                   { print_token(TOKEN_SE, yytext); return TOKEN_SE; }
"entao"                { print_token(TOKEN_ENTAO, yytext); return TOKEN_ENTAO; }
"senao"                { print_token(TOKEN_SENAO, yytext); return TOKEN_SENAO; }
"enquanto"             { print_token(TOKEN_ENQUANTO, yytext); return TOKEN_ENQUANTO; }
"repita"               { print_token(TOKEN_REPITA, yytext); return TOKEN_REPITA; }
"ate"                  { print_token(TOKEN_ATE, yytext); return TOKEN_ATE; }
"ler"                  { print_token(TOKEN_LER, yytext); return TOKEN_LER; }
"mostrar"              { print_token(TOKEN_MOSTRAR, yytext); return TOKEN_MOSTRAR; }
"+"                    { print_token(TOKEN_OPERACAO_SOMA, yytext); return TOKEN_OPERACAO_SOMA; }
"-"                    { print_token(TOKEN_OPERACAO_SUBTRACAO, yytext); return TOKEN_OPERACAO_SUBTRACAO; }
"*"                    { print_token(TOKEN_OPERACAO_MULTIPLICACAO, yytext); return TOKEN_OPERACAO_MULTIPLICACAO; }
"/"                    { print_token(TOKEN_OPERACAO_DIVISAO, yytext); return TOKEN_OPERACAO_DIVISAO; }
"&&"                   { print_token(TOKEN_OPERACAO_E, yytext); return TOKEN_OPERACAO_E; }
"||"                   { print_token(TOKEN_OPERACAO_OU, yytext); return TOKEN_OPERACAO_OU; }
"<"                    { print_token(TOKEN_OPERACAO_MENOR_QUE, yytext); return TOKEN_OPERACAO_MENOR_QUE; }
"<="                   { print_token(TOKEN_OPERACAO_MENOR_IGUAL, yytext); return TOKEN_OPERACAO_MENOR_IGUAL; }
">"                    { print_token(TOKEN_OPERACAO_MAIOR_QUE, yytext); return TOKEN_OPERACAO_MAIOR_QUE; }
">="                   { print_token(TOKEN_OPERACAO_MAIOR_IGUAL, yytext); return TOKEN_OPERACAO_MAIOR_IGUAL; }
"=="                   { print_token(TOKEN_OPERACAO_IGUAL, yytext); return TOKEN_OPERACAO_IGUAL; }
"!="                   { print_token(TOKEN_OPERACAO_DIFERENTE, yytext); return TOKEN_OPERACAO_DIFERENTE; }
"="                    { print_token(TOKEN_OPERACAO_ATRIBUICAO, yytext); return TOKEN_OPERACAO_ATRIBUICAO; } 
";"                    { print_token(TOKEN_OPERACAO_SEPARADOR_COMANDO, yytext); return TOKEN_OPERACAO_SEPARADOR_COMANDO; }
","                    { print_token(TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES, yytext); return TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES; }
"("                    { print_token(TOKEN_OPERACAO_ABRE_EXPRECAO, yytext); return TOKEN_OPERACAO_ABRE_EXPRECAO; }
")"                    { print_token(TOKEN_OPERACAO_FECHA_EXPRECAO, yytext); return TOKEN_OPERACAO_FECHA_EXPRECAO; }
"{"                    { print_token(TOKEN_OPERACAO_INICIA_BLOCO_COMANDO, yytext); return TOKEN_OPERACAO_INICIA_BLOCO_COMANDO; }
"}"                    { print_token(TOKEN_OPERACAO_FECHA_BLOCO_COMANDO, yytext); return TOKEN_OPERACAO_FECHA_BLOCO_COMANDO; }
"\n"                    { printf("Nova linha detectada\n"); }
<<EOF>>					{printf("FIM DO ARQUIVO\n"); return 0;}
\"([^"\\]|\\.)*\"     { print_token(TOKEN_STRING, yytext); return TOKEN_STRING; }
\'([^'\\]|\\.)*\'     { print_token(TOKEN_CHAR, yytext); return TOKEN_CHAR; }

"/*"([^/*]|\*+[^*/])*\*+"/"   { /* Ignora o comentário de bloco */ }
"//".*                      { /* Ignora o comentário de linha */ }

[a-zA-Z_][a-zA-Z0-9_]* { print_token(TOKEN_IDENTIFICADOR, yytext); return TOKEN_IDENTIFICADOR; }
[0-9]+\.[0-9]+         { print_token(TOKEN_REAL, yytext); return TOKEN_REAL; }
[0-9]+                 { print_token(TOKEN_INTEIRO, yytext); return TOKEN_INTEIRO; }

[ \t\n]+              ; // Ignora espaços em branco
\r                     ; // Ignora o retorno de carro

.                     { printf("Caractere desconhecido: '%s' (ASCII: %d)\n", yytext, yytext[0]); }

%%

int yywrap() {
    return 1; 
}

