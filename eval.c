#include <stdio.h>
#include <stdlib.h>

struct match;

typedef struct match match;

struct match{
  int open;
  int close;
};



#define TYPE match
#include "array.h"
#undef TYPE

#ifndef ARR_INT
#define ARR_INT
  #define TYPE int
  #include "array.h"
  #undef TYPE
#endif

void eval(char*);
ARRAY(match)* match_parenthesis(char*);

void eval(char* read){
  match_parenthesis(read);
}

ARRAY(match)* match_parenthesis(char* read){
  int x = 0;
  int numO = 0;
  int numC = 0;
  while(read[x] != '\0'){
    if(read[x] == '(')
      numO++;
    if(read[x] == ')')
      numC++;
    x++;
  }
  ARRAY(int)* open = narray_int(numO);
  ARRAY(int)* close = narray_int(numC);
 
  x = 0;
  
  numC = 0;
  numO = 0;

  while(read[x] != '\0'){
    if(read[x] == '(')
      *at_int(open,numO++) = x;
    if(read[x] == ')')
      *close->at(close,numC++) = x;
      //*at_int(close,numC++) = x;
    x++;
  }

  printf("i%i\n",numO);
  array_match* matches = narray_match(numO);
  if(numO > numC){
    match m = {-1,-1};
    *at_match(matches,0) = m;
    printf("TOO MANY OPEN PARENTHESES\n");
  }
  else if (numO < numC){
    match m = {-1,-1};
    *at_match(matches,0) = m;
    printf("TOO FEWS OPEN PARENTHESES\n");
  }
  else{
    printf("~Just the right number of parentheses~\n");
    for(x = 0; x < (len_int(open)); x++){
      if(numC-x > 0){
        match m = {*at_int(open,x),*at_int(close,numC-x-1)};
        *at_match(matches,x) = m;
        m.open = -1;
        m.close = -1;
        *at_match(matches,x+1) = m;
      }
    }
  }
  return matches;
}
