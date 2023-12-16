#ifndef EVALUATION_H
#define EVALUATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/mpc.h"

/* Função para avaliar a operação */
long eval_op(long x, char* op, long y);

/* Função para avaliar a expressão */
long eval(mpc_ast_t* t);

/* Função principal de avaliação */
int evaluation();

#ifdef __cplusplus
}
#endif

#endif /* EVALUATION_H */
