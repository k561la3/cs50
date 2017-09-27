#include <stdio.h>

#include <stdlib.h>

#define BUFSIZE 64

int getInt(void)
{
  char buf[BUFSIZE];
  char *p;
  long int i;
  do{

  if (fgets(buf, sizeof(buf), stdin) != NULL)
  {
  	
    i = strtol(buf, &p, 10);
    
    if (buf[0] != '\n' && (*p == '\n' || *p == '\0'))
     {
     	if(i<0 || i>=24){printf("Height: ");}
     	if(i==0){exit(0);}
     }

    else {printf("Retry: ");}
    
  }  

}while(i > 23 || i < 1);
  
  return(i);
}




void pyrstage(char ht, char width){
	for (int n = 0; n < (ht + 1 - width); n++)
	{
		/* code */
		printf(" ");
	}
	for (int j = 0; j < width; j++)
	{
		/* code */
		printf("#");
	}
}




int height = 0;
int main(void){
do{
    printf("Height: ");
    height = getInt();
}while(height > 23 || height < 1);    


for (int i = 2; i < height+2; i++)
{
	/* code */
	pyrstage(height,i);
	printf("\n");

};

return 0;
}

