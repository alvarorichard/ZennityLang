#ifndef STRINGS_H
#define STRINGS_H

#include "../include/mpc.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Parser Declarations */
extern mpc_parser_t* Number;
extern mpc_parser_t* Symbol;
extern mpc_parser_t* String;
extern mpc_parser_t* Comment;
extern mpc_parser_t* Sexpr;
extern mpc_parser_t* Qexpr;
extern mpc_parser_t* Expr;
extern mpc_parser_t* Lispy;

/* Forward Declarations */
struct lval;
struct lenv;
typedef struct lval lval;
typedef struct lenv lenv;
typedef lval*(*lbuiltin)(lenv*, lval*);

/* Lisp Value Enum */
enum { LVAL_ERR, LVAL_NUM, LVAL_SYM, LVAL_STR, LVAL_FUN, LVAL_SEXPR, LVAL_QEXPR };

/* Lisp Value Struct */
struct lval {
  int type;
  long num;
  char* err;
  char* sym;
  char* str;
  lbuiltin builtin;
  lenv* env;
  lval* formals;
  lval* body;
  int count;
  lval** cell;
};

/* Function Prototypes */
char* ltype_name(int t);
void lenv_add_builtin(lenv* e, char* name, lbuiltin func);
void lenv_add_builtins(lenv* e);
lenv* lenv_new(void);
void lenv_del(lenv* e);
lenv* lenv_copy(lenv* e);
lval* lenv_get(lenv* e, lval* k);
void lenv_put(lenv* e, lval* k, lval* v);
void lenv_def(lenv* e, lval* k, lval* v);

lval* lval_num(long x);
lval* lval_err(char* fmt, ...);
lval* lval_sym(char* s);
lval* lval_str(char* s);
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
void lval_println(lval* v);
int lval_eq(lval* x, lval* y);

lval* lval_eval(lenv* e, lval* v);
lval* lval_call(lenv* e, lval* f, lval* a);
lval* lval_eval_sexpr(lenv* e, lval* v);

lval* lval_read_num(mpc_ast_t* t);
lval* lval_read_str(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);
int strings();

/* Readline Function Prototypes */
#ifdef _WIN32
char* readline(char* prompt);
void add_history(char* unused);
#endif

#endif /* LVAL_H */
