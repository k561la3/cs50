#include <stdio.h>
char height = 0;

void pyrstage(char ht, char width){
	for (int n = 0; n < (ht + 1 - width); n++)
	{
		/* code */
		printf(' ');
	}
	for (int j = 0; j < width; j++)
	{
		/* code */
		printf('#');
	}
}



int main(void){

do{
    printf("Height: ");
    scanf("%d", &height);
    printf("%s\n", height);
}while(height >= 23 || height <= 1);

for (int i = 0; i < height; i++)
{
	/* code */
	pyrstage(height,i);
	printf('\n');

};

return 0;
}
