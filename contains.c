#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int len;
  int _len;
  char *word = argv[1];
  char *_word = argv[2];
  int j = 0;
  int i = 0;
  len = strlen(argv[1]);
  _len = strlen(argv[2]);
  for (i = 0; i < len; i++){
    if(j == _len){
      printf("true\n");
      return 0;
    }
    if (word[i] == _word[j]){
      j++;
    }
    else if(word[i] != _word[j]){
      j = 0;
    }
  }
  if (i == len && j == _len){
    printf("true\n");
    return 0;
  }
  else{
    printf("false\n");
    return 0;
  }
}
