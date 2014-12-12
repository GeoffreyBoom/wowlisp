#ifndef LIST_H
#define LIST_H
#include "atom.h"
#include <stdlib.h>

struct List;
typedef struct List List;

struct List{
  Atom* car;
  Atom* cdr;
};

Atom* cons(Atom* car, Atom* cdr);
Atom* cons(Atom* car, Atom* cdr){
  List* list = malloc(sizeof(List));
  list->car = car;
  list->cdr = cdr;
  Atom* atom = malloc(sizeof(List));
  *atom = (Atom) {.value = list, .type = "list"};
  return atom;
}

Atom* car(Atom* atom){
  if(strcmp(atom->type, "list") == 0){
    return ((List*)atom->value)->car;
  }
  else{
    printf("Expressions of type %s do not have a CAR", atom->type);
  }
}

Atom* cdr(Atom* atom){
  if(strcmp(atom->type, "list") == 0){
    return ((List*)atom->value)->cdr;
  }
  else{
    printf("Expressions of type %s do not have a CDR", atom->type);
  }
}

#endif
