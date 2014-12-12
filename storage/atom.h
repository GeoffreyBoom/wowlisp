#ifndef ATOM_H
#define ATOM_H
#include <stddef.h>
#include <stdio.h>
#include "list.h"
struct Atom;
typedef struct Atom Atom;
struct Atom{
  void* value;
  char* type;
};

Atom* new_atom(void* value, char* type){
  Atom* atom = malloc(sizeof(Atom));
  (*atom) =(Atom) {value, type};
}

#endif
