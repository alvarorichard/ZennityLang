#include <stdio.h>
#include <stdlib.h>


#include <editline/readline.h>

// se vc usa arch linux ou macOS , remova a linha abaixo com a biblioteca editline/history.h

//#include <editline/history.h>

int main(int argc, char** argv) {


  puts("ZennityLang 0.0.0.0.1");
  puts("Pressione Ctrl+c para Sair\n");

  while (1) {

    char* input = readline("ZennityLang> ");

    add_history(input);

    printf("Não é você %s\n", input);


    free(input);

  }

  return 0;
}
