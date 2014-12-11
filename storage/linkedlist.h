#include "atom.h"

struct List;
int len(List* list, int sum = 0);
Atom car(List* list);
List* cons(Atom* car, List* cdr);
typedef struct List List;
struct List{
  Atom* car;
  List* cdr;
  int (* len)(List*);
}

List* cons(Atom* car, List* cdr){
  List* list = malloc(sizeof(List));
  list->car = car;
  list->cdr = cdr;
  list->len = len;
  return list;
}


