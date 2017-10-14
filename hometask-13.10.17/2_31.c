#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("number square cube\n");
    for (int i = 1; i <= 10; ++i){       
         printf("%d    %*d %*d\n", i, 4-(i*i<10) ,i*i, 7 - (i*i*i<100)+(i==3),i*i*i);
    }
return 0;
}