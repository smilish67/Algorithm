#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <malloc.h>
#define Max 1000

int map[Max][Max], cnt;
int visited[Max][Max];
std::stack<int> idx;
std::stack<int> jdx;
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	char* tmp = (char*)malloc(sizeof(char) * (M+1));

	if (tmp == NULL) return -1;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", tmp);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = (int)*(tmp + j)-48; //sub ASCII code
		}
	}
	

	//search all node
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//only for unvisited
			if (!visited[i][j] && map[i][j] == 0)
			{
				//push current node.
				visited[i][j] = 1;
				idx.push(i);
				jdx.push(j);

				//until stack is empty
				while (!idx.empty())
				{
					//현재 스택에 있는 인덱스를 가져와서 pop하고 해당 노드에서 움직일 수 있는 곳을 조사할 수 있도록 함.
					int k = idx.top();
					int s = jdx.top();
					idx.pop();
					jdx.pop();
					if (k + 1 < N && map[k + 1][s] == 0 && !visited[k + 1][s])
					{
						visited[k + 1][s] = 1;
						idx.push(k + 1);
						jdx.push(s);
					}
					if (k - 1 >= 0 && map[k - 1][s] == 0 && !visited[k - 1][s])
					{
						visited[k - 1][s] = 1;
						idx.push(k - 1);
						jdx.push(s);
					}
					if (s + 1 < M && map[k][s+1] == 0 && !visited[k][s+1])
					{
						visited[k][s+1] = 1;
						idx.push(k);
						jdx.push(s+1);
					}
					if (s - 1 >= 0 && map[k][s-1] == 0 && !visited[k][s-1])
					{
						visited[k][s-1] = 1;
						idx.push(k);
						jdx.push(s-1);
					}
				}
				cnt++;
			}
		}
	}
	//메모리 해제
	free(tmp);
	printf("%d", cnt);
}
