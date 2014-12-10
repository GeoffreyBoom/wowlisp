#include <stdio.h>
#include <stdlib.h>
struct match{
  int open;
  int close;
};




struct IntArray{
  int* arr;
  int size;
};
typedef struct match match;
typedef struct IntArray IntArray;

IntArray* _IntArray(int size){
  IntArray* tmp = (IntArray*) malloc(sizeof(IntArray));
  int* a = malloc(sizeof(int)*size);
  tmp = ( IntArray *) {.arr = a, .size = size};
  return tmp;
}

void ~IntArray(IntArray* arr){
  free(arr.arr);
  free(arr)
}
int len(IntArray arr){
  return arr.size;
}
int at(IntArray arr, int index){
  return arr.arr[index];
}


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
  printf("hello\n");
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
  printf("hello\n");
  return matches;
}

char* read(){
  char* buffer = malloc(sizeof(char) * 100);
  scanf("%s",buffer);
  return buffer;
}

void print(match* matches){
  int i = 0;
  for(i = 0; matches[i].open != -1 ;i++){
    printf("begin:%i,match:%i\n",matches[i].open,matches[i].close);
  }
}

int main(){

  int* a = malloc(sizeof(int)*4);
  a = (int[]) {1,2,3,4};
  IntArray* openarr = malloc(sizeof(IntArray));
  openarr = (IntArray*) {.arr = a, .size = 4};

  int i = 0;  
  for(i = 0; i < openarr.size;i++){
    printf("%i\n",at(openarr,i));
  }
  print(eval(read()));
}
