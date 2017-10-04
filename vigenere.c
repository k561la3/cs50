#include <cs50.h>
#include <stdio.h>
#include <string.h>

char vig(char ch, int k);

int main(int argc, char *argv[])
{

	if(argc!=2){printf("%d", argc);return 1;}
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if(argv[1][i]<'A' || (argv[1][i]>'Z' && argv[1][i]< 'a') || argv[1][i]>'z'){printf("error");return 1;}
	}
	char* str = get_string();
	char key[strlen(argv[1])];
	int len_key = 0;
	for(int v = 0;v<strlen(argv[1]);v++){
		if((argv[1][v]>='A' && argv[1][v]<='Z') ){
			key[v] = argv[1][v]-'A';len_key++;
		}else if(argv[1][v]>= 'a' && argv[1][v]<='z'){
			key[v] = argv[1][v]-'a';len_key++;
		}

	}
	int offset = 0;
	for(int i = 0;i<strlen(str);i++){
		if(str[i]<'A' || (str[i]>'Z' && str[i]< 'a') || str[i]>'z'){offset++;}

		printf("%c",vig(str[i],key[(i-offset)%(len_key)]));

	}





	printf("\n");
	return 0;
}




char vig(char ch, int k){
	if(ch>='A' && ch<='Z'){return((ch+k<='Z'?ch+k:ch+k-26));}
	else if(ch>='a' && ch<='z'){return((ch+k<='z'?ch+k:ch+k-26));}
	return ch;
}
