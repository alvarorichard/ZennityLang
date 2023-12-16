#ifndef PARSING_H
#define PARSING_H

#ifdef __cplusplus
extern "C" {
#endif

/* Funções para readline e add_history */
char* readline(char* prompt);
void add_history(char* unused);

/* Declarar tipos de dados para os parsers */
typedef struct mpc_parser_t mpc_parser_t;
typedef struct mpc_err_t mpc_err_t;

/* Funções para os parsers */
mpc_parser_t* mpc_new(const char* name);
int mpca_lang(int flags, const char* language, ...);
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
void mpc_ast_print(void* v);
void mpc_ast_delete(void* v);

/* Função principal do parser */
int parser();

#ifdef __cplusplus
}
#endif

#endif /* PARSER_H */
