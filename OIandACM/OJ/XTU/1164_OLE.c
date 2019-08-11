#include <stdio.h>
#include <string.h>

int main()
{
	char s[233], i;
	while(~scanf("%s", s)){
		for(i = 0; i < strlen(s); i += 4)
			switch(s[i]){
				case '1':
					if(s[i + 1] == '2')
						printf("1");
					else
						printf("0");
					break;
				case '0':
					printf("4");
					break;
				case '8':
					printf("8");
					break;
				case '5':
					printf("3");
					break;
				case '9':
					printf("2");
					break;
				case '2':
					printf("4");
					break;
			}
		printf("\n");
	}
	return 0;
}