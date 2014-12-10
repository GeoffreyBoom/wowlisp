void print(match* matches){
  int i = 0;
  for(i = 0; matches[i].open != -1 ;i++){
    printf("begin:%i,match:%i\n",matches[i].open,matches[i].close);
  }
}


