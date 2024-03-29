#ifndef LIST_H
#define LIST_H
#include "expression.h"
#include <stdlib.h>
#include <stddef.h>

struct List;
typedef struct List List;

struct List{
  Expression* car;
  Expression* cdr;
};

Expression* cons(Expression* car, Expression* cdr);
Expression* cons(Expression* car, Expression* cdr){
  List* list = malloc(sizeof(List));
  list->car = car;
  list->cdr = cdr;
  Expression* express = malloc(sizeof(Expression));
  *express = (Expression) {.value = list, .type = "list"};
  return express;
}



Expression* car(Expression* express){
  if(strcmp(express->type, "list") == 0){
    return ((List*)express->value)->car;
  }
  else{
    printf("Expressions of type %s do not have a CAR\n", express->type);
    return NULL;
  }
}

Expression* cdr(Expression* express){
  if(strcmp(express->type, "list") == 0){
    return ((List*)express->value)->cdr;
  }
  else{
    printf("Expressions of type %s do not have a CDR\n", express->type);
    return NULL;
  }
}

#endif
