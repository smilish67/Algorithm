#include <stdio.h>
#include <limits.h> 

int main(void)
{
	int m,n;
	scanf("%d%d",&m,&n);
	
	int maze[n][m];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	
	int min[n], big = INT_MIN;
	for(int i=0; i<n; i++)
	{
		min[i] = maze[i][0];
		for(int j=0; j<m; j++)
		{
			if(min[i]>maze[i][j])
				min[i] = maze[i][j];
		}
		if(big<min[i])
			big = min[i];
	}
	
	printf("%d", big);
}
