#include <stdio.h>

void DFS(int (*node)[5], int visited[], int idx);

int main(void)
{
	int node[5][5] = {0, };
	int visited[5] = {0, };
	//4!까지 간선 가능. 
	for(int i =0; i<5; i++)
	{
		int a,b;
		scanf("%d%d", &a,&b);
		node[a][b] = 1;
		node[b][a] = 1;
	}
	
	DFS(node, visited, 1);
}

void DFS(int (*node)[5], int visited[], int idx)
{
	visited[idx] = 1;
	printf("현재노드: %d\n", idx);
	for(int i=0; i<5; i++)
	{
		if(node[idx][i]==1&&!visited[i])
		{
			DFS(node, visited, i);
		}
	}
}
