#include "../include/mpc.h"
#include "../include/doge_code.h"

int doge(){

mpc_parser_t* Adjective= mpc_or(4, 
    mpc_sym("uau"), mpc_sym("muitos"),
    mpc_sym("tão"),  mpc_sym("tal")
);

/* Construir um analisador 'Substantivo' para reconhecer coisas */
mpc_parser_t* Noun = mpc_or(5,
    mpc_sym("lisp"), mpc_sym("linguagem"),
    mpc_sym("livro"), mpc_sym("construir"), 
    mpc_sym("c")
);
  
  mpc_parser_t* Phrase = mpc_and(2, mpcf_strfold, 
    Adjective, Noun, free);
    mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

    mpc_delete(Doge);

    return 0;



}