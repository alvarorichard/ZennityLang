#ifndef ZENNITYLANG_H
#define ZENNITYLANG_H

/* Include necessary headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <editline/readline.h>
#include "../include/mpc.h"


/* Enumeration for lval types */
enum {
    LVAL_ERR,
    LVAL_NUM,
    LVAL_SYM,
    LVAL_SEXPR,
    LVAL_QEXPR
};

/* Struct definition for lval */
typedef struct lval {
    int type;
    long num;
    char* err;
    char* sym;
    int count;
    struct lval** cell;
} lval;

/* Function declarations */
lval* lval_num(long x);
lval* lval_err(char* m);
lval* lval_sym(char* s);
lval* lval_sexpr(void);
lval* lval_qexpr(void);
void lval_del(lval* v);
lval* lval_add(lval* v, lval* x);
lval* lval_pop(lval* v, int i);
lval* lval_join(lval* x, lval* y);
lval* lval_take(lval* v, int i);
void lval_print(lval* v);
void lval_println(lval* v);
lval* lval_eval(lval* v);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);
int qexpression(void);

#endif /* ZENNITYLANG_H */
