%{
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

%}

%debug

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
%left TOKEN_OPERACAO_MENOR_QUE TOKEN_OPERACAO_MENOR_IGUAL TOKEN_OPERACAO_MAIOR_QUE
%left TOKEN_OPERACAO_MAIOR_IGUAL
%left TOKEN_OPERACAO_SOMA TOKEN_OPERACAO_SUBTRACAO
%left TOKEN_OPERACAO_MULTIPLICACAO TOKEN_OPERACAO_DIVISAO

%% 

programa: lista_de_comandos {
    raiz = $1;
}
;

lista_de_comandos:
    comando {
        $$ = $1;
    }
    | lista_de_comandos comando {
        No *ultimo = $1;
        while (ultimo->irmao != NULL) {
            ultimo = ultimo->irmao;
        }
        ultimo->irmao = $2;
        $$ = $1;
    }
;

comando:
    expressao TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_enquanto TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_repita TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_leitura TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_escrita TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | declaracao_variavel TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | bloco_comando TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_condicional TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
    | comando_atribuir TOKEN_OPERACAO_SEPARADOR_COMANDO {
        $$ = $1;
    }
;

comando_atribuir:
    TOKEN_IDENTIFICADOR TOKEN_OPERACAO_ATRIBUICAO expressao {
        $$ = criar_no(NO_ATRIBUICAO, strdup("Atribuição")); 
        $$->filhos[0] = criar_no(NO_IDENTIFICADOR, strdup(yytext)); 
        $$->filhos[1] = $3; 
        $$->num_filhos = 2; // Define o número correto de filhos
    }



comando_condicional:
    TOKEN_SE expressao TOKEN_ENTAO lista_de_comandos {
        $$ = criar_no(NO_CONDICIONAL,strdup("Comando condicional"));
        $$->filhos[0] = $2; // Expressão
        $$->filhos[1] = $4; // Lista de comandos
        $$->num_filhos = 2; // Ajuste para o número correto
    }
    | TOKEN_SE expressao TOKEN_ENTAO lista_de_comandos TOKEN_SENAO lista_de_comandos {
        $$ = criar_no(NO_CONDICIONAL, strdup("Comando condicional SENAO"));
        $$->filhos[0] = $2; // Expressão
        $$->filhos[1] = $4; // Lista de comandos
        $$->filhos[2] = $6; // Lista de comandos do SENA
        $$->num_filhos = 3; // Ajuste para o número correto
    }
    ;


bloco_comando:
    TOKEN_OPERACAO_INICIA_BLOCO_COMANDO lista_de_comandos TOKEN_OPERACAO_FECHA_BLOCO_COMANDO {
        $$ = $2;
    }
;

comando_enquanto: 
    TOKEN_ENQUANTO TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO TOKEN_OPERACAO_INICIA_BLOCO_COMANDO bloco_comando TOKEN_OPERACAO_FECHA_BLOCO_COMANDO {
        $$ = criar_no(NO_LOOP, strdup("Enquanto")); // Ajuste no tipo, se necessário
        $$->filhos[0] = $3; // Expressão
        $$->filhos[1] = $6; // Bloco de comandos
        $$->num_filhos = 2; // Define o número correto de filhos
    };


comando_repita: 
    TOKEN_REPITA bloco_comando TOKEN_ATE expressao {
        $$ = criar_no(NO_LOOP, strdup("Repita ate")); // Ajuste no tipo, se necessário
        $$->filhos[0] = $1; // Bloco
        $$->filhos[1] = $4; // Expressão
        $$->num_filhos = 2; // Define o número correto de filhos
    }
    | TOKEN_REPITA comando TOKEN_ATE expressao {
        $$ = criar_no(NO_LOOP, strdup("Repita ate")); // Ajuste no tipo, se necessário
        $$->filhos[0] = $2; // Comando
        $$->filhos[1] = $4; // Expressão
        $$->num_filhos = 2; // Define o número correto de filhos
    }

;

comando_leitura: 
    TOKEN_LER TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_IDENTIFICADOR TOKEN_OPERACAO_FECHA_EXPRECAO {
        $$ = criar_no(NO_LEITURA, strdup("Leitura"));
        $$->filhos[0] = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        $$->num_filhos = 1; // Define o número correto de filhos
    }

;

comando_escrita: 
    TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO expressao TOKEN_OPERACAO_FECHA_EXPRECAO {
        $$ = criar_no(NO_ESCRITA, strdup("Escrita"));
        $$->filhos[0] = $3; // Expressão
        $$->num_filhos = 1; // Define o número correto de filhos
    }
    |TOKEN_MOSTRAR TOKEN_OPERACAO_ABRE_EXPRECAO TOKEN_STRING TOKEN_OPERACAO_FECHA_EXPRECAO {
        $$ = criar_no(NO_ESCRITA, strdup("Escrita"));
        $$->filhos[0] = $3; // Expressão
        $$->num_filhos = 1; // Define o número correto de filhos
    }

;

declaracao_variavel:
    tipo lista_identificadores {
        $$ = criar_no(NO_DECLARACAO_VARIAVEL, strdup("Declaração de Variáveis"));
        $$->filhos[0] = $1; // Tipo
        $$->filhos[1] = $2; // Lista de identificadores
        $$->num_filhos = 2; // Define o número correto de filhos
    }

;


tipo: 
    TOKEN_INTEIRO {
        $$ = criar_no(NO_TIPO, strdup("inteiro"));
    }
    | TOKEN_REAL {
        $$ = criar_no(NO_TIPO, strdup("real"));
    }
;


lista_identificadores: 
    TOKEN_IDENTIFICADOR {
        $$ = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        $$->irmao = NULL; // Inicializa o irmão como NULL
        $$->num_filhos = 0; // Não tem filhos
    }
    | lista_identificadores TOKEN_OPERACAO_SEPARADO_IDENTIFICADORES TOKEN_IDENTIFICADOR {
        No *novo_id = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        $$ = $1; // Mantém o primeiro nó
        
        // Conecta o novo identificador como irmão do último nó
        No *ultimo = $$;
        while (ultimo->irmao != NULL) {
            ultimo = ultimo->irmao;
        }
        ultimo->irmao = novo_id; // Adiciona o novo identificador como irmão
    }

;





expressao: 
    TOKEN_IDENTIFICADOR {
        $$ = criar_no(NO_IDENTIFICADOR, strdup(yytext));
        $$->num_filhos = 0; // Sem filhos
    }
    | TOKEN_INTEIRO {
        $$ = criar_no(NO_INTEIRO, strdup(yytext));
        $$->num_filhos = 0; // Sem filhos
    }
    | expressao_operacao_soma {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_subtracao {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_multiplicacao {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_divisao {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_e {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_ou {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_maior_que {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_menor_que {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_maior_igual {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_menor_igual {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_igual {
        $$ = $1; // A operação já define a estrutura correta
    }
    | expressao_operacao_diferente {
        $$ = $1; // A operação já define a estrutura correta
    }
;

expressao_operacao_soma:
    expressao TOKEN_OPERACAO_SOMA expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("+"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_subtracao:
    expressao TOKEN_OPERACAO_SUBTRACAO expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("-"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_multiplicacao:
    expressao TOKEN_OPERACAO_MULTIPLICACAO expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("*"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_divisao:
    expressao TOKEN_OPERACAO_DIVISAO expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("/"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_e:
    expressao TOKEN_OPERACAO_E expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("&&")); // Usando "&&" para E lógico
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_ou:
    expressao TOKEN_OPERACAO_OU expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("||")); // Usando "||" para OU lógico
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_maior_que:
    expressao TOKEN_OPERACAO_MAIOR_QUE expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup(">"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_menor_que:
    expressao TOKEN_OPERACAO_MENOR_QUE expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("<"));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_maior_igual:
    expressao TOKEN_OPERACAO_MAIOR_IGUAL expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup(">="));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_menor_igual:
    expressao TOKEN_OPERACAO_MENOR_IGUAL expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("<="));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_igual:
    expressao TOKEN_OPERACAO_IGUAL expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("=="));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;

expressao_operacao_diferente:
    expressao TOKEN_OPERACAO_DIFERENTE expressao {
        $$ = criar_no(NO_EXPRESSAO, strdup("!="));
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
        $$->num_filhos = 2; // Define o número correto de filhos
    }
;


%% 

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
