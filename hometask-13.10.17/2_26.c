//226 task
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i,j;
	printf("enter 2 ints:\n");
	scanf("%d", &i);
	scanf("%d", &j);
	if(i%j==0){
		printf("%d кратно %d\n",i,j);
	}else{
		printf("%d не кратно %d\n",i,j);
	}

	return 0;
}