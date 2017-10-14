#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{	int min = INT_MAX,max = INT_MIN;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &(arr[i]));
		if(arr[i]>max){max = arr[i];}
		if(arr[i]<min){min = arr[i];}
	}
	printf("min %d, max %d",min, max);

	return 0;
}