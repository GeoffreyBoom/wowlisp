#define CONC(x, y) x ## _ ## y
#define LEN(T) CONC(len,T)
#define ARRAY(T) CONC(array, T)
#define NEW(T) CONC(narray, T)
#define DELETE(T) CONC(darray, T)
#define AT(T) CONC(at, T)
#include <stdlib.h>



//struct for an array of ambiguous type. 
struct ARRAY(TYPE){
  TYPE* arr;
  int size;
};

//making it so you can use array_TYPE instead of struct array_TYPE
typedef struct ARRAY(TYPE) ARRAY(TYPE);

ARRAY(TYPE)* NEW(TYPE)(int size){
  ARRAY(TYPE)* array = malloc(sizeof(ARRAY(TYPE)));
  TYPE* a = malloc(sizeof(TYPE) * size);
  *array = (ARRAY(TYPE)) {.arr = a, .size = size};
  return array;
}

TYPE* AT(TYPE) (ARRAY(TYPE)* arr, int index){
  return &arr->arr[index];
}

int LEN(TYPE)(ARRAY(TYPE)* arr){
  return arr->size;
}

void DELETE(TYPE)(ARRAY(TYPE)* arr){
  free(arr->arr);
  free(arr);
}
