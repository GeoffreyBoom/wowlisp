#ifndef PRINT_H
#define PRINT_H
void print(Expression* express);

void print(Expression* express){

  if(express == NULL){
    printf("\nprinting null\n");
    printf("()");
  }
  else if(strcmp(express->type, "string")==0){
    printf("\nprinting string\n");
    printf("%s", (((char*)(express->value))));
  }
  else if(strcmp(express->type, "int")==0){
    printf("\nprinting int\n");
    printf("%i", (*(int*)(express->value)));
  }
  else if(strcmp(express->type, "list") == 0){
    printf("(");
    if(express != NULL){
      print(car(express));
    }
    if(cdr(express) == NULL){
      printf("()");
    }
    else{
      print(cdr(express));
    }
    printf(")");
  }

}
#endif
