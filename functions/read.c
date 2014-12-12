#include <stddef.h>
#include <stdio.h>
#include "../storage/list.h"
char* read();
Atom* parse(char* read);
char* scan();
Atom* getMatches(char* read);

char* read(){
  char* read = scan();
  Atom* parsed = parse(read);
  return read;
}

Atom* parse(char* read){
  Atom* paren = cons(NULL, NULL);
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
