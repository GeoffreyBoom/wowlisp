#include "../storage/list.h"
#include "print.c"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
char* read();
Expression* parse(char* read);
char* scan();
Expression* getMatches(char* read);

char* read(){
  char* read = scan();
  Expression* parsed = parse(read);
  return read;
}
/*
   parses string, returning an expression e
   where e is either:
     a list of expressions
     a variable
     an constant
*/
Expression* parse(char* read){
  Expression* expressions = cons(NULL, NULL);
  int i = 0;
  for(i = 0; read[i] != '\0';i++){
     
  }
  return expressions;
}

//returns substring including begin, excluding end
char* substr(char* str, int begin, int end){
  char* sub = malloc(sizeof(char) * (end - begin +1));
  int i = begin;
  for(;i < end; i++){
    sub[i-begin] = str[i];
  }
  sub[end] = '\0';
  return sub;
}

//parses a string and returns a list or null
//sets end to the index after the list's end
Expression* parseList(char* read, int* end){
  Expression* parse = NULL;
  int begin = 0;
  int i = 0;
  for(;read[i] != '\0';i++){
  }
}

Expression* parseVariable(char* read){
  Expression* parse = NULL;
  
}

Expression* parseString(char* read, int* end){
  Expression* parse = NULL;
  int begin = 0;
  int i = 0;
  //find initial 
  for(;read[i] != '\0'; i++){
    if(read[i] == '"'){
      begin = i;
      break;
    }
  }
  if(read[i] == '\0'){
    return NULL;
  }
  
  for(i = i+1;read[i] != '\0';i++){
    if(read[i] == '"'){
      *end = i+1;
      break;
    }
  }
  if(read[i] == '\0'){
    return NULL;
  }

  parse = malloc(sizeof(Expression));
  *parse = (Expression) {.value = substr(read,begin,*end),
                         .type = "string"};
  return parse;

}


char* scan(){
  char* buffer = malloc(sizeof(char) * 1000);
  int i = 0;
  int j = 0;
  scanf("%s",buffer);
  for(;buffer[i] != '\0';i++);
  char* read = malloc(sizeof(char) * j);
  for(;j < i;j++){
    read[j] = buffer[j];
  }
  free(buffer);
  return read;
}

#ifndef MAIN
int main(){
  char* read = "\"hello\"dont print this";
  int end = 0;
  print(parseString(read, &end));
  print(NULL);
  printf("%i",end);
}
#endif
