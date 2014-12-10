#include <stdio.h>
#include <stdlib.h>

struct match{
  int open;
  int close;
};

typedef struct match match;

#define TYPE match
#include "Array.h"
#undef TYPE

match* eval(char* read){
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

  int* open = (int*) malloc(sizeof(int) * (numO + 1));
  int* close = (int*) malloc(sizeof(int) * (numC + 1));
  
  open[0] = numO;
  close[0] = numC;
 
  open = open+(sizeof(int));
  close = close+(sizeof(int));

  x = 0;

  int numO1 = 0;
  int numC1 = 0;

  while(read[x] != '\0'){
    if(read[x] == '(')
      open[numO1++] = x;
    if(read[x] == ')')
      close[numC1++] = x;
    x++;
  }

  match* matches = (match*) malloc(sizeof(match) * (numO1+1));
  for(x = 0; x < *(open-(sizeof(int))); x++){
    if(numC1-x > 0){
      match m =  {open[x],close[numC1-x-1]};
      matches[x] = m;
      m.open = -1;
      m.close = -1;
      matches[x+1] = m;
    }
    else{
      printf("Parentheses don't match!\n");
    }
  }
  return matches;
}
