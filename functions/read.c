#include "../storage/list.h"
#include "../storage/expression.h"
#include "print.c"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
Expression* read();
char* scan();
Expression* parse(char* read, int* end);
Expression* parseInt(char* read, int* end);
Expression* parseList(char* read, int* end);
Expression* parseNil(char* read, int* end);
Expression* parseVariable(char* read, int* end);
Expression* parseString(char* read, int* end);
char* substr(char* str, int begin, int end);

#ifndef MAIN
int main(){
  int e = 0;
  Expression* in = parse("1",&e);
  in = (cons(in, in));
  print(in);
  while(1){
    print(read());
  }

 /*  
  char* r = "\"hello\"dont print this";
  r = " 1000 ";
  int end = 0;
  print(parseInt(r, &end));

  printf("\n");
  end = 0;
  r = "(\"hello\"  \"world\")";
  print(parse(r, &end));
  printf("\n");

  r = "()";
  print(parse(r, &end));

  printf("\n");
  */
}
#endif

Expression* read(){
  char* r = scan();
  printf("scanned input: %s\n", r);
  int end = 0;
  Expression* e = parse(r,&end);
  return e;
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
    printf("parsed list");
  }
  else if(car = parseInt(read, end)){
    printf("parsed int");
  }
  else if(car = parseNil(read, end)){
    printf("parsed nil");
  }
  else if(car = parseString(read, end)){
    printf("parsed string");
  }
  else if(car = parseVariable(read, end)){
    printf("parsed variable");
  }
  return car;
}

//parses a string and returns a list or null
//sets end to the index after the list's end
Expression* parseList(char* read, int* end){
  Expression* parsed = NULL;
  int begin = 0;
  int i = 0;
  //find parenthesis
  for(;read[i] != '\0';i++){
    if(read[i] == '('){
      begin = i;
      break;
    }
    else if(read[i] != ' '){
      return NULL;
    }
  }
  i = i+1;
  int devider = i;
  //make a list of expressions.
  Expression* expression;
  Expression* list = NIL();
  //while there are more expressions to be parsed
  //parse them and add them to the array. 
  while(expression = parse(substr(read,devider,strlen(read)), &i)){
    devider += i;
    list = cons(expression, list);
    //print(list);
  }

  i = devider;
  //if parenthesis is unmatched, quit the service, and find a good retirement home.
  if(read[i] == '\0'){
    return NULL;
  }

  for(;read[i] != '\0';i++){
    if(read[i] == ')'){
      *end = i+1;
      break;
    }
    else if(read[i] != ' '){
      return NULL;
    }
  }
  Expression* rlist = NIL(); 
  if(!strcmp(list->type,"nil") == 0){
    while(strcmp(cdr(list)->type, "nil") != 0){
      rlist = cons(car(list), rlist);
      list = cdr(list);
    }
    rlist = cons(car(list), rlist);
  }
  return rlist;
}

Expression* parseInt(char* read, int* end){
  Expression* parse = NULL;
  int i = 0;
  int begin = 0;
  for(;read != '\0';i++){
    if(isdigit(read[i])){
      begin = i;
      break;
    }
    else if(read[i] != ' '){
      return NULL;
    }
  }
  for(;read != '\0'; i++){
    if(!isdigit(read[i])){
      printf("%c\n", read[i]);
      break;
    }
  }
  if(read[i] == ' ' || read[i] == '\0' || read[i] == ')'){
    *end = i;
  }
  else{
    return NULL;
  }
  parse = malloc(sizeof(Expression));
  int* value = malloc(sizeof(int));
  *value = atoi(substr(read,begin,*end));
  *parse = (Expression) {.value = value, .type = "int"};
  
  return parse;
}

Expression* parseNil(char* read, int* end){
  Expression* parse = NULL;
  return parse;
}

Expression* parseVariable(char* read, int* end){
  Expression* parse = NULL;
  int i = 0;
  if(!isalpha(read[i])){
    return NULL;
  }
  
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
  char* string = malloc(sizeof(char));
  while(!newline(buffer)){
    int i = 0;
    scanf("%s",buffer);
    printf("%s\n", buffer);
    i = strlen(buffer);
    string = strncat(string, buffer, i);
    string = strncat(string, " ", 1);
  }
  string = substr(string, 0, strlen(string)-2);
  return string;
}

int newline(char* buffer){
  int i = 0;
  while(buffer[i++] != '\0'){
    if(buffer[i] == '.'){
      return 1;
    }
  }
  return 0;
}

//returns substring including begin, excluding end
char* substr(char* str, int begin, int end){
  char* sub = malloc(sizeof(char) * (end - begin +1));
  int i = begin;
  for(;i < end; i++){
    sub[i-begin] = str[i];
  }
  sub[end] = '\0';
  //printf("substring:%s\n",sub);
  return sub;
}


