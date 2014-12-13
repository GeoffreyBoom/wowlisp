#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
struct Expression;
typedef struct Expression Expression;
struct Expression{
  void* value;
  char* type;
};

Expression* Express(void* value, char* type){
  Expression* express = malloc(sizeof(Expression));
  *express= (Expression) {.value = value, .type = type};
};

Expression* NIL(){
  Expression* express = malloc(sizeof(Expression));
  *express = (Expression) {.value = NULL, .type = "nil"};
  return express; 
}

const char* inttype = "int";
const char* listtype = "list";
const char* stringtype = "string";
const char* variabletype = "variable";
const char* niltype = "nil";
#endif
