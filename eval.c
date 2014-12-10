#include <stdio.h>
#include <stdlib.h>

struct match;

typedef struct match match;

struct match{
  int open;
  int close;
};



#define TYPE match
#include "Array.h"
#undef TYPE

void eval(char*);
match* match_parenthesis(char*);

void eval(char* read){
  match_parenthesis(read);
}

match* match_parenthesis(char* read){
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


  printf("%i\n",numO1);
  match* matches = (match*) malloc(sizeof(match) * (numO1+1));

  if(numO > numC){
    match m = {-1,-1};
    matches[0] = m;
    printf("TOO MANY OPEN PARENTHESES\n");
  }
  else if (numO < numC){
    match m = {-1,-1};
    matches[0] = m;
    printf("TOO FEWS OPEN PARENTHESES\n");
  }
  else{
    printf("~Just the right number of parentheses~\n");
    for(x = 0; x < *(open-(sizeof(int))); x++){
      if(numC1-x > 0){
        match m =  {open[x],close[numC1-x-1]};
        matches[x] = m;
        m.open = -1;
        m.close = -1;
        matches[x+1] = m;
      }
    }
  }
  return matches;
}
