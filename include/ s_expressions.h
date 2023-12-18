#ifndef S_EXPRESSIONS_H
#define S_EXPRESSIONS_H


#ifdef __cplusplus
extern "C" {
#endif

#include "../include/mpc.h"

/* Enumeração de tipos de lval possíveis */
enum { LVAL_ERR, LVAL_NUM, LVAL_SYM, LVAL_SEXPR };

/* Declare a struct lval */
typedef struct lval {
  int type;
  long num;
  /* Error and Symbol types have some string data */
  char* err;
  char* sym;
  /* Count and Pointer to a list of "lval*"; */
  int count;
  struct lval** cell;
} lval;

/* Cria um ponteiro para um novo lval do tipo número */
lval* lval_num(long x);

/* Cria um ponteiro para um novo lval do tipo erro */
lval* lval_err(char* m);

/* Cria um ponteiro para um novo lval do tipo símbolo */
lval* lval_sym(char* s);

/* Cria um ponteiro para um novo lval do tipo Sexpr */
lval* lval_sexpr(void);

/* Libera a memória alocada para um lval */
void lval_del(lval* v);

/* Adiciona um lval a outro lval */
lval* lval_add(lval* v, lval* x);

/* Remove um lval de outro lval */
lval* lval_pop(lval* v, int i);

/* Remove e libera um lval de outro lval */
lval* lval_take(lval* v, int i);

/* Imprime um lval */
void lval_print(lval* v);

/* Imprime um lval seguido de uma nova linha */
void lval_println(lval* v);

/* Avalia uma operação com lvals */
lval* builtin_op(lval* a, char* op);

/* Avalia um lval */
lval* lval_eval(lval* v);

/* Avalia um Sexpr lval */
lval* lval_eval_sexpr(lval* v);

/* Lê um número a partir de um nó mpc_ast_t */
lval* lval_read_num(mpc_ast_t* t);

/* Lê um lval a partir de um nó mpc_ast_t */
lval* lval_read(mpc_ast_t* t);

/* Função principal para manipular a linguagem */
int expression();

#ifdef __cplusplus
}
#endif

#endif /* LVAL_H */
