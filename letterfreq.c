#include <stdio.h>
#include <ctype.h>

int main(){
  int count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  float charcount = 0.0;
  int letter[26] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
  int str,wow;
  float freq = 0.0;
  int k;
  int i;
  while((str = fgetc(stdin)) != EOF){
    if( isalpha(str) ){
      wow = tolower(str);
      charcount++;
      count[wow-97]++;
    }
  }
  for (k=0;k<26;k++){
    freq = count[k] / charcount;
    if (freq != 0){
      printf("%c %.4f\n", letter[k] , freq);
    }
  }
  return 0;
}
