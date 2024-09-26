%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

// Estrutura para os nós da árvore
typedef struct Nodo {
    char* tipo; // Tipo do nó 
    char* nome; // Nome da variável 
    char* tipo_variavel; // Tipo da variável 
    int linha; // Número da linha 
    struct Nodo* filho; // Primeiro filho
    struct Nodo* proximo; // Irmão
} Nodo;

Nodo* raiz = NULL;

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
    comando_condicional:
    TOKEN_SE expressao TOKEN_ENTAO comando
    ;
    {
        Nodo* novo_no = malloc(sizeof(Nodo));
        novo_no->tipo = "condicional";
        novo_no->filho = $2; // Expressão
        novo_no->proximo = $4; // Comando
        $$ = novo_no; // Atribuindo o novo nó a $$
    }
   |TOKEN_SE expressao TOKEN_ENTAO comando TOKEN_SENAO comando
    {
        Nodo* novo_no = malloc(sizeof(Nodo));
        novo_no->tipo = "condicional";
        novo_no->filho = $2; // Expressão
        novo_no->proximo = $4; // Comando
        novo_no->proximo->proximo = $6; // Comando do "senão"
        $$ = novo_no; // Atribuindo o novo nó a $$
    }
    ;

bloco_comando:
    TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO
    ;

comando_enquanto: TOKEN_ENQUANTO expressao TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO
                {
                    Nodo* novo_no = malloc(sizeof(Nodo));
                    novo_no->tipo = "enquanto";
                    novo_no->filho = $2; // Condição
                    novo_no->proximo = $4; // Comandos
                }
                ;

comando_repita: TOKEN_REPITA bloco_comando TOKEN_ATE expressao
              {
                  Nodo* novo_no = malloc(sizeof(Nodo));
                  novo_no->tipo = "repita";
                  novo_no->filho = $2; // Comando
                  novo_no->proximo = $4; // Condição
              }
              | TOKEN_REPITA comando TOKEN_ATE expressao
              {
                  Nodo* novo_no = malloc(sizeof(Nodo));
                  novo_no->tipo = "repita";
                  novo_no->filho = $2; // Comando
                  novo_no->proximo = $4; // Condição
              }
              ;

comando_leitura: TOKEN_LER TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_IDENTIFICADOR TOKEN_OPERACAO_FECHA_EXPRECAO
               {
                   Nodo* novo_no = malloc(sizeof(Nodo));
                   novo_no->tipo = "leitura";
                   novo_no->nome = strdup(yytext); 
                   $$ = novo_no; // Atribuindo o novo nó a $$
               }
               ;

comando_escrita: TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO
               {
                   Nodo* novo_no = malloc(sizeof(Nodo));
                   novo_no->tipo = "escrita";
                   novo_no->filho = $3; // Expressão
                   $$ = novo_no; // Atribuindo o novo nó a $$
               }
               ;


declaracao_variavel: tipo lista_identificadores
                   {
                       Nodo* novo_no = malloc(sizeof(Nodo));
                       novo_no->tipo = "declaracao";
                       novo_no->tipo_variavel = $1; // Tipo da variável
                       novo_no->linha = yylineno; // Linha atual
                       novo_no->filho = NULL; // Inicializar como NULL
                       
                       Nodo* ultimo = novo_no; // Para encadear identificadores
                       for (Nodo* id = $2; id; id = id->proximo) {
                           Nodo* novo_id = malloc(sizeof(Nodo));
                           novo_id->nome = strdup(id->nome);
                           novo_id->tipo_variavel = novo_no->tipo_variavel;
                           novo_id->linha = novo_no->linha;
                           ultimo->filho = novo_id; // Atribui o primeiro identificador
                           ultimo = novo_id; // Move o ponteiro para o último nó
                       }
                       $$ = novo_no; // Atribuindo o novo nó a $$
                   }
                   ;


tipo: TOKEN_INTEIRO { $$ = "inteiro"; }
    | TOKEN_REAL { $$ = "real"; }
    ;

lista_identificadores: TOKEN_IDENTIFICADOR
                     {
                         Nodo* novo_no = malloc(sizeof(Nodo));
                         novo_no->nome = strdup(yytext); // Nome da variável
                         novo_no->proximo = NULL;
                         $$ = novo_no;
                     }
                     | lista_identificadores TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES TOKEN_IDENTIFICADOR
                     {
                         Nodo* novo_no = malloc(sizeof(Nodo));
                         novo_no->nome = strdup(yytext); // Nome da variável
                         novo_no->proximo = $1; // Próximo identificador
                         $$ = novo_no;
                     }
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
    fprintf(stderr, "Erro de análise: %s na linha %d\n", s, yylineno);
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

    yyin = file;

    yyparse();

    fclose(file);

    return 0;
}