#include 
char* read();
List* parse(char* read);
char* scan();
List* getMatches(char* read);

char* read(){
  char* read = scan();
}

List* parse(char* read){
  List* paren = cons("nil", NULL);
  int i = 0;
  for(int i = 0; string[i] != '\0';i++){
    if(string[i] == '('){
      
    }
  }
}

char* scan(){
  char* buffer = malloc(sizeof(char) * 1000);
  int i = 0;
  int j = 0;
  scanf("%s",buffer);
  for(;buffer[i] != '\0';i++);
  char* read = malloc(sizeof(char) * j);
  for(;j < i;j++){
    read[j] = buffer[j];
  }
  free(buffer);
  return read;
}

List* getMatches(char* read){
  int i = 0;
}
