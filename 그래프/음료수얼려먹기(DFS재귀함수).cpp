#define _CRT_SECURE_NO_WARNINGS
#define M 1000
#include <stdio.h>
#include <malloc.h>

int cnt;
int map[M][M] = { 0, };
int visited[M][M] = { 0, };
void dfs(int i, int j, int n, int m);

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	char* tmp = (char*)malloc(sizeof(char) * (m+1));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp);
		for (int j = 0; j < m; j++)
		{
			map[i][j] = (int)*(tmp + j) - 48;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]==0 && map[i][j]==0)
			{
				dfs(i, j, n, m);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}

void dfs(int i, int j, int n, int m)
{
	visited[i][j] = 1;
	if (i+1< n && map[i + 1][j] == 0 && !visited[i+1][j])
	{
		dfs(i + 1, j, n, m);
	}
	if (i-1 >= 0 && map[i - 1][j] == 0 && !visited[i - 1][j])
	{
		dfs(i - 1, j, n, m);
	}
	if (j+1 < m && map[i][j + 1] == 0 && !visited[i][j+1])
	{
		dfs(i, j+1, n, m);
	}
	if (j-1 >= 0 && map[i][j - 1] == 0 && !visited[i][j - 1])
	{
		dfs(i, j-1, n, m);
	}
}
