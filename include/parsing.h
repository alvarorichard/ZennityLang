#ifndef PARSING_H
#define PARSING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/mpc.h"


/* Funções para readline e add_history */
char* readline(char* prompt);
void add_history(char* unused);

/* Declarar tipos de dados para os parsers */
typedef struct mpc_parser_t mpc_parser_t;
struct mpc_err_t; // Fix: Remove 'typedef' keyword

/* Funções para os parsers */
mpc_parser_t* mpc_new(const char* name);
mpc_err_t* mpc_lang(int flags, const char* language, ...); // Fix: Renamed function
int mpc_parse(const char* filename, const char* input, mpc_parser_t* p, mpc_result_t* r);
void mpc_cleanup(int num, ...);

/* Estruturas para os resultados dos parsers */
typedef struct {
    char* error;
    void* output;
    void* ast;
    char* filename;
    int failure;
    int pos;
    int expected_num;
    char* expected;
} mpc_result_t;

/* Função para imprimir o AST */
void mpc_ast_print(mpc_ast_t* a);
//void mpc_ast_delete(void* v);
void mpc_ast_delete(mpc_ast_t* a);


/* Função principal do parser */
int parser();

#ifdef __cplusplus
}
#endif

#endif /* PARSER_H */
