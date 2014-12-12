#include <stdio.h>
#include <stdlib.h>
#include "functions/eval.c"
#include "functions/read.c"
#include "functions/print.c"

int main(){
  while(1){
    eval(read());
  }
  return 0;
}
