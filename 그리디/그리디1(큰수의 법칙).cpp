#include <stdio.h>
#include <stdlib.h>

int second, first;
int main(void)
{
	int N, M, K, ans=0;
	scanf("%d%d%d", &N,&M,&K);
	int* a = (int*)malloc(N*sizeof(int));
	for(int i=0; i<N; i++)
	{
		scanf("%d", a+i);
	}
	
	int idx=0;
	for(int i=0; i<N; i++)
		if(first<=a[i])
		{
			first = a[i];
			idx = i;
		}
	
	for(int i=0; i<N; i++)
	{
		if(i!=idx){
			if(second<=a[i]) second = a[i];
		}
	}

//	for(int i=1; i<=M; i++) 
//	{
//		if(i%(K+1)==0) ans += second;
//		else ans += first;
//	}

	int sum;
	if(M%(K+1)==0)	
		ans = (M/(K+1))*(K*first+second);
	else
	{
		ans = (M/(K+1))*(K*first+second);
		ans +=  (M%(K+1))*first;
	}
	
	printf("%d", ans);
	free(a);
}


