#ifndef LIST_H
#define LIST_H
#include "atom.h"
#include <stdlib.h>
struct List;
typedef struct List List;


Atom car(List* list);
List* cons(Atom* car, List* cdr);
struct List{
  Atom* car;
  List* cdr;
};

List* cons(Atom* car, List* cdr){
  List* list = malloc(sizeof(List));
  list->car = car;
  list->cdr = cdr;
  return list;
}
#endif