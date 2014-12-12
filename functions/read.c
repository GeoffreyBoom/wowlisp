#include <stddef.h>
#include <stdio.h>
#include "../storage/list.h"
char* read();
Expression* parse(char* read);
char* scan();
Expression* getMatches(char* read);

char* read(){
  char* read = scan();
  Expression* parsed = parse(read);
  return read;
}

Expression* parse(char* read){
  Expression* paren = cons(NULL, NULL);
  int i = 0;
  for(i = 0; read[i] != '\0';i++){
  }
  return paren;
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
