#include <cs50.h>
#include <stdio.h>
#include <string.h>


char cap(char ch);


int main ()
{
  char* str = GetString();
    printf("%c",cap(str[0]));
    for(int i = 0; i<strlen(str); i++){
    	if(str[i] == '\x20' && i+1<strlen(str) && str[i+1] != '\x20') printf("%c", cap(str[i+1]));
    }
    
    
    
    
    
    
    
    printf("\n");    
  



  return 0;
}


char cap(char ch){
	if(ch>='A' && ch <='Z')return ch;
    else if(ch>='a' && ch <='z')return ch-32;
    return '\x20';    
}
