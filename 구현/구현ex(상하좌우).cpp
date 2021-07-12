#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void)
{	
	int x=1,y=1;
	int N;
	char Route[110];
	scanf("%d", &N);
	rewind(stdin); 
	gets(Route);
	char *ptr = strtok(Route," ");
	while(ptr != NULL)
	{
		switch(*ptr)
		{
			case 'L':
				if(x==1) break;
				x--;
				break;
				
			case 'R':
				if(x==N) break;
				x++;
				break;
				
			case 'U':
				if(y==1) break;
				y--;
				break;
			
			case 'D':
				if(y==N) break;
				y++;
				break;
		}
		ptr = strtok(NULL, " ");
	}
	
	printf("%d %d", x,y);
}
