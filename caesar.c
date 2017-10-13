#include <cs50.h>
#include <stdio.h>
#include <string.h>

char caesar(char ch, int k);

int main(int argc, char *argv[])
{

	if(argc!=2){printf("%d", argc);return 1;}
	int k = atoi(argv[1])%26;
	char* str = GetString();
	for(int i = 0;i<strlen(str);i++){
		printf("%c",caesar(str[i],k));
	}




	printf("\n");
	return 0;
}




char caesar(char ch, int k){
	if(ch>='A' && ch<='Z'){return((ch+k<='Z'?ch+k:ch+k-26));}
	else if(ch>='a' && ch<='z'){return((ch+k<='z'?ch+k:ch+k-26));}	
	return ch;
}
