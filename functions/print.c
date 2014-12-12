void print_atom(Atom* atom);
void print_list(List* list);

void print_atom(Atom* atom){
  if(atom == NULL){
    printf("()");
  }
  if(atom->type == "string"){
    printf("%s", ((*(char**)(atom->value))));
  }
  if(atom->type == "int"){
    printf("%i", (*(int*)(atom->value)));
  }
  if(atom->type== "list"){
    print_list((List*)(atom->value));
  }
}
void print_list(List* list){
  if(list == NULL){
    printf("()");
  }
  else{
    print_atom(list->car);
  }
  if(list->cdr == NULL){
    printf("()");
  }
  else{
    print_list(list->cdr);
  }
}
