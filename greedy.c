#include <stdio.h>
#include <cs50.h>

#define BUFSIZE 64




int count = 0;
float height = 0;
int main(void){
do{
    printf("O hai! How much change is owed?\n");
    height = get_float();
}while(height < 0.000000);    


while(height>0.000){
  if(height>=0.249){count++; height-=0.25;}
  else if(height>=0.099){count++; height-=0.1;}
  else if(height>=0.049){count++; height-=0.05;}
  else if(height>=0.009){count++; height-=0.01;}
  else {break;}
}
printf("%d\n", count);
return 0;
}

