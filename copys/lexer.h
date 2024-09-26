// tokens.h
#define TOKENS_H


typedef struct {
    int tipo;
    char* valor;
} Token;

void print_token(int token_type, const char* value);

