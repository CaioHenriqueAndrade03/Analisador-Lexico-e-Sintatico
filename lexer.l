%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"


// Estrutura para armazenar tokens
typedef struct {
    int tipo;
    char* valor;
} Token;

// Função para imprimir tokens
void print_token(int token_type, const char* value) {
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
        default: printf("TOKEN DESCONHECIDO\n");
    }
}

// Função do analisador sintático
void analisador_sintatico(Token* tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        printf("Processando Token %d: Tipo = %d, Valor = %s\n", i, tokens[i].tipo, tokens[i].valor);
    }
}
%}

%%

"inteiro"              { return TOKEN_INTEIRO; }
"real"                 { return TOKEN_REAL; }
"se"                   { return TOKEN_SE; }
"entao"                { return TOKEN_ENTAO; }
"senao"                { return TOKEN_SENAO; }
"enquanto"             { return TOKEN_ENQUANTO; }
"repita"               { return TOKEN_REPITA; }
"ate"                  { return TOKEN_ATE; }
"ler"                  { return TOKEN_LER; }
"mostrar"              { return TOKEN_MOSTRAR; }
"+"                    { return TOKEN_OPERACAO_SOMA; }
"-"                    { return TOKEN_OPERACAO_SUBTRACAO; }
"*"                    { return TOKEN_OPERACAO_MULTIPLICACAO; }
"/"                    { return TOKEN_OPERACAO_DIVISAO; }
"&&"                   { return TOKEN_OPERACAO_E; }
"||"                   { return TOKEN_OPERACAO_OU; }
"<"                    { return TOKEN_OPERACAO_MENOR_QUE; }
"<="                   { return TOKEN_OPERACAO_MENOR_IGUAL; }
">"                    { return TOKEN_OPERACAO_MAIOR_QUE; }
">="                   { return TOKEN_OPERACAO_MAIOR_IGUAL; }
"=="                   { return TOKEN_OPERACAO_IGUAL; }
"!="                   { return TOKEN_OPERACAO_DIFERENTE; }
"="                    { return TOKEN_OPERACAO_ATRIBUICAO; } 
";"                    { return TOKEN_OPERACAO_SEPARADOR_COMANDO; }
","                    { return TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES; }
"("                    { return TOKEN_OPERACAO_ABRE_EXPRECAO; }
")"                    { return TOKEN_OPERACAO_FECHA_EXPRECAO; }
"{"                    { return TOKEN_OPERACAO_INICIA_BLOCO_COMANDO; }
"}"                    { return TOKEN_OPERACAO_FECHA_BLOCO_COMANDO; }

\"([^"\\]|\\.)*\"     { return TOKEN_STRING; }
\'([^'\\]|\\.)*\'     { return TOKEN_CHAR; }

"/*"([^/*]|\*+[^*/])*\*+"/"   { /* Ignora o comentário de bloco */ }
"//".*                      { /* Ignora o comentário de linha */ }

[a-zA-Z_][a-zA-Z0-9_]* { return TOKEN_IDENTIFICADOR; }
[0-9]+\.[0-9]+         { return TOKEN_REAL; }
[0-9]+                 { return TOKEN_INTEIRO; }

[ \t\n]+              ; // Ignora espaços em branco fora de strings e caracteres

.                     ; //mostra caracteres que nao foram interpretados


%%

int yywrap() {
    return 1;  // Indica que não há mais dados para processar
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

    yyin = file; // Define o arquivo de entrada para o Flex

    int token;
    Token tokens[1000]; // Exemplo de array para armazenar tokens
    int token_count = 0;

    while ((token = yylex()) != 0) {
    if (token < 0) {
        fprintf(stderr, "Erro no lexer: caractere não reconhecido.\n");
        break; // Sai do loop em caso de erro
    }

    tokens[token_count].tipo = token;
    tokens[token_count].valor = strdup(yytext); // Copia o valor do token
    print_token(token, yytext); // Imprime o token
    token_count++;
}

if (token_count >= sizeof(tokens)/sizeof(tokens[0])) {
    fprintf(stderr, "Erro: número máximo de tokens excedido.\n");

}


    fclose(file); // Fecha o arquivo de entrada

    // Chama o analisador sintático
    analisador_sintatico(tokens, token_count);

    yyparse();

    // Liberar memória
    for (int i = 0; i < token_count; i++) {
        free(tokens[i].valor);
    }

    return 0;}
