#include <stdio.h>
#include <ctype.h>


unsigned long charcount = 0;
unsigned long wordcount = 0;
unsigned long linecount =0;
int str;
int input = 0;
int main(){
while((str = fgetc(stdin)) != EOF){
    charcount++;
  if (str == '\n'){
    linecount++;
  }
      if (input == 1){
        if(  (str >= 65 && str <= 90) || (str >= 97 && str <= 122 ) || str == 39){
          wordcount = wordcount;
      }
      else{
        input = 0;
      }
    }
    else{
      if(  (str >= 65 && str <= 90) || (str >= 97 && str <= 122 ) || str == 39){
        input = 1;
        wordcount++;
      }
    }
  }
  printf( "%lu %lu %lu\n", charcount, wordcount , linecount );
  return 0;
}
