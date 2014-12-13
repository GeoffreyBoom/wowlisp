#ifndef PRINT_H
#define PRINT_H
void print(Expression* express);

void print(Expression* express){

  if(express == NULL){
    //printf("\nprinting null\n");
    printf("NULL. THIS SHOULDN'T HAPPEN");
  }
  else if(strcmp(express->type, "nil")==0){
    printf("()");
  }
  else if(strcmp(express->type, "string")==0){
    //printf("\nprinting string\n");
    printf("%s ", (((char*)(express->value))));
  }
  else if(strcmp(express->type, "int")==0){
    //printf("\nprinting int\n");
    printf("%i ", (*(int*)(express->value)));
  }
  else if(strcmp(express->type, "list") == 0){
    printf("\nprinting list\n");
    printf("( ");
    while(strcmp(cdr(express)->type,"list") == 0){
      print(car(express));
      express = cdr(express);
    }
    if(strcmp(cdr(express)->type, "nil") == 0){
      print(car(express));
    }
    else{
      print(car(express));
      printf(". ");
      print(cdr(express));
    }

    printf(")");
  }

}
#endif
