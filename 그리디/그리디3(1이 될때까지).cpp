#include <stdio.h>

int main(void)
{
	int N, K, cnt = 0;
	scanf("%d%d", &N,&K);
	
	while(N!=1)
	{
		while(N%K!=0)
		{
			N -= 1;
			cnt++;
			if(N==1) goto shit;
		}
		
		while(N%K==0)
		{
			N /= K;
			cnt++;
			if(N==1) goto shit;
		}
	}

	shit:
	
	printf("%d", cnt);
}

