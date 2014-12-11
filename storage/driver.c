#include "list.h"
#include "atom.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
  Atom* atom = malloc(sizeof(Atom));
  char* value = malloc(sizeof(char)*4);
  value = "hell";
  char** value2 = &value;
  *atom = (Atom) {.value = value2, "string"};
  List* lst = cons(atom, NULL);
  printf("%s\n",(*(char**)(lst->car->value)));
  print_atom(atom);
}
