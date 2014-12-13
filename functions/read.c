#include "../storage/list.h"
#include "print.c"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
char* read();
char* scan();
Expression* parse(char* read, int* end);
Expression* parseInt(char* read, int* end);
Expression* parseList(char* read, int* end);
Expression* parseNil(char* read, int* end);
Expression* parseVariable(char* read, int* end);
Expression* parseString(char* read, int* end);
char* substr(char* str, int begin, int end);

char* read(){
  char* read = scan();
  int* end = 0;
  Expression* parsed = parse(read,end);
  return read;
}
/*
   parses string, returning an expression e
   where e is either:
     a list of expressions
     a variable
     an constant
*/
Expression* parse(char* read,int* end){
  Expression* car = NULL;
  if(car = parseList(read, end)){ 
  }
  else if(car = parseInt(read, end)){
  }
  else if(car = parseNil(read, end)){
  }
  else if(car = parseString(read, end)){
  }
  else if(car = parseVariable(read, end)){
  }
  return car;
}

//parses a string and returns a list or null
//sets end to the index after the list's end
Expression* parseList(char* read, int* end){
  Expression* parse = NULL;
  int begin = 0;
  int i = 0;
  for(;read[i] != '\0';i++){
    if(read[i] == '('){
      begin = i;
      break;
    }
    else if(read[i] != ' '){
      return NULL;
    }
  }
  if(read[i] == '\0'){
    return NULL;
  }
  Expression* car = NULL; 

}

Expression* parseInt(char* read, int* end){
  Expression* parse = NULL;
  return parse;
}

Expression* parseNil(char* read, int* end){
  Expression* parse = NULL;
  return parse;
}

Expression* parseVariable(char* read, int* end){
  Expression* parse = NULL;
  return parse;
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
    else if(read[i] != ' '){
      return NULL;
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

#ifndef MAIN
int main(){
  char* read = "e\"hello\"dont print this";
  int end = 0;
  print(parseString(read, &end));
  print(NULL);
  printf("\n");
}
#endif
