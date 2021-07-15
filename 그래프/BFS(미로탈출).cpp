#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <queue>
#define Max 200

int map[Max][Max];
int visited[Max][Max];
int dist[Max][Max];

std::queue<int> idx;
std::queue<int> jdx;
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	char* tmp = (char*)malloc(sizeof(char) * (M + 1));
	if (tmp == NULL) return -1;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", tmp);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = (int)*(tmp + j)-48;
		}
	}

	//push start node
	idx.push(0);
	jdx.push(0);
	visited[0][0] = 1;
	dist[0][0] = 1;
	while (!idx.empty())
	{
		int y = idx.front();
		int x = jdx.front();
		idx.pop();
		jdx.pop();
		if (x+1<M && map[y][x + 1] == 1 && !visited[y][x + 1])
		{
			dist[y][x + 1] = dist[y][x] + 1;
			if (x + 1 == M - 1 && y == N) goto shit;
			visited[y][x + 1] = 1;
			idx.push(y);
			jdx.push(x+1);
			
		}
		if (x-1 >= 0 && map[y][x - 1] == 1 && !visited[y][x - 1])
		{
			dist[y][x - 1] = dist[y][x] + 1;
			if (x - 1 == M - 1 && y == N) goto shit;
			visited[y][x - 1] = 1;
			idx.push(y);
			jdx.push(x - 1);
		}
		if (y+1 < N && map[y+1][x] == 1 && !visited[y+1][x])
		{
			dist[y+1][x] = dist[y][x] + 1;
			if (x == M - 1 && y +1  == N) goto shit;
			visited[y+1][x] = 1;
			idx.push(y+1);
			jdx.push(x);
		}
		if (y-1 >= 0 && map[y-1][x] == 1 && !visited[y-1][x])
		{
			dist[y - 1][x] = dist[y][x] + 1;
			if (x == M - 1 && y-1 == N) goto shit;
			visited[y-1][x] = 1;
			idx.push(y-1);
			jdx.push(x);
		}
	}
shit:
	printf("%d", dist[N-1][M-1]);
	free(tmp);
}
