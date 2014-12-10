#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#include "Array.h"
#undef TYPE

#define TYPE float
#include "Array.h"
#undef TYPE

#include "eval.c"
#include "read.c"
#include "print.c"

int main(){
  while(1){
    eval(read());
  }
  return 0;
}
