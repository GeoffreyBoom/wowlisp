#ifndef ATOM_H
#define ATOM_H
#include <stddef.h>
#include <stdio.h>
struct Atom{
  void* value;
  char* type;
  void (*print)(Atom* atom);
};
typedef struct Atom Atom;
void print_atom(Atom* atom){
  if(atom == NULL){
    printf("()");
  }
  if(atom->type == "string"){
    printf("%s", ((*(char**)(atom->value))));
  }
  if(atom->type == "int"){
    printf("%i", (*(int*)(atom->value)));
  }
}
#endif
