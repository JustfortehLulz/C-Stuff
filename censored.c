#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  char input[128];
  int str;
  int a = 0;
  int b = 1;
  while((str = getchar()) != EOF)
  {
    while( isalnum(str) != 0 )
    { 
      input[a] = str;
      str = getchar();
      a++;
    }
  while(b<argc)
    {
    if(strcmp(input,argv[b]) == 0)
      {
        strcpy(input, "CENSORED");
      }
      b++;
    }
    printf("%s",input);
    printf("%c",str);
    memset(input, '\0' , sizeof(input));
    b = 1;
    a = 0;
  }
  return 0;
}
