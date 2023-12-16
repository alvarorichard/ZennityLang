#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/mpc.h"

/* Enumeração de tipos de erro possíveis */
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

/* Enumeração de tipos de lval possíveis */
enum { LVAL_NUM, LVAL_ERR };

/* Declare a struct lval */
typedef struct {
  int type;
  long num;
  int err;
} lval;

/* Cria uma lval do tipo número */
lval lval_num(long x);

/* Cria uma lval do tipo erro */
lval lval_err(int x);

/* Imprime uma lval */
void lval_print(lval v);

/* Imprime uma lval seguida de uma nova linha */
void lval_println(lval v);

/* Avalia uma operação com lvals */
lval eval_op(lval x, char* op, lval y);

/* Avalia uma expressão */
lval eval(mpc_ast_t* t);

/* Função principal para manipular a linguagem */
int eval_lang();
int error();

#ifdef __cplusplus
}
#endif

#endif /* LVAL_H */
