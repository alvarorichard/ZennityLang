#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../include/mpc.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef _WIN32
char* readline(char* prompt);
void add_history(char* unused);
#else
#include <editline/readline.h>
//#include <editline/history.h>
#endif

/* Forward Declarations */
struct lval;
struct lenv;
typedef struct lval lval;
typedef struct lenv lenv;

/* Function Pointer Type for Builtin Functions */
typedef lval* (*lbuiltin)(lenv*, lval*);

/* Lisp Value Struct */
struct lval {
  int type;
  long num;
  char* err;
  char* sym;
  lbuiltin builtin;
  lenv* env;
  lval* formals;
  lval* body;
  int count;
  lval** cell;
};

/* Lisp Environment */
struct lenv {
  lenv* par;
  int count;
  char** syms;
  lval** vals;
};

/* Function Declarations */
lval* lval_num(long x);
lval* lval_err(char* fmt, ...);
lval* lval_sym(char* s);
lval* lval_builtin(lbuiltin func);
lval* lval_lambda(lval* formals, lval* body);
lval* lval_sexpr(void);
lval* lval_qexpr(void);
void lval_del(lval* v);
lval* lval_copy(lval* v);
lval* lval_add(lval* v, lval* x);
lval* lval_join(lval* x, lval* y);
lval* lval_pop(lval* v, int i);
lval* lval_take(lval* v, int i);
void lval_print(lval* v);
void lval_print_expr(lval* v, char open, char close);
void lval_println(lval* v);
char* ltype_name(int t);

lenv* lenv_new(void);
void lenv_del(lenv* e);
lenv* lenv_copy(lenv* e);
lval* lenv_get(lenv* e, lval* k);
void lenv_put(lenv* e, lval* k, lval* v);
void lenv_def(lenv* e, lval* k, lval* v);
void lenv_add_builtin(lenv* e, char* name, lbuiltin func);
void lenv_add_builtins(lenv* e);

lval* lval_eval(lenv* e, lval* v);
lval* lval_eval_sexpr(lenv* e, lval* v);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);

int func(int argc, char** argv);

#endif /* LISP_H */
