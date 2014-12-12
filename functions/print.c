void print(Expression* express);

void print(Expression* express){
  if(express == NULL){
    printf("()");
  }
  if(strcmp(express->type, "string")){
    printf("%s", ((*(char**)(express->value))));
  }
  if(strcmp(express->type, "int")){
    printf("%i", (*(int*)(express->value)));
  }
  if(strcmp(express->type, "list") == 0){
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
