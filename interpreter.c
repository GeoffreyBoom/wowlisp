#include <stdio.h>
#include <stdlib.h>

#ifndef ARR_INT
#define ARR_INT
  #define TYPE int
  #include "array.h"
  #undef TYPE
#endif
#include "eval.c"
#include "read.c"
#include "print.c"

int main(){
  while(1){
    eval(read());
  }
  return 0;
}
