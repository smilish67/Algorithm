#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 50
int Xpos, Ypos, dir, cnt, dx, dy;
int maze[max][max], visit[max][max];

enum direction {
	north,
	east,
	south,
	west
};

void turn(), move(int v);
bool cango();

int main(void)
{
	// 움직임 함수에  대한 인자값 입니다.
	int back = 1, front = 0;
	int n, m, turn_num = 0;
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &Xpos, &Ypos, &dir);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}

	//첫번째 위치 카운트 및 방문 설정
	visit[Ypos][Xpos] = 1;
	cnt++;

	while (true)
	{
		//도는 횟수가 증가하고 4번 돌면 뒤로가기.
		turn();
		turn_num++;
		//갈 수 있는 경우를 반환한다.
		if (cango())
		{
			move(front);
			cnt++;
			visit[Ypos][Xpos] = 1;
			turn_num = 0;
		}

		if (turn_num == 4)
		{
			move(back);
			if (maze[Ypos][Xpos] == 1)
			{
				goto shit;
			}
			turn_num = 0;
		}
			
	}
shit:
	printf("%d", cnt);
}

void turn()
{
	switch (dir)
	{
	case north:
		dir = west;
		dx = -1;
		dy = 0;
		break;
	case east:
		dir = north;
		dx = 0;
		dy = -1;
		break;
	case south:
		dir = east;
		dx = 1;
		dy = 0;
		break;
	case west:
		dir = south;
		dx = 0;
		dy = 1;
		break;
	}
}

bool cango()
{
	bool flag = true;
	if (visit[Ypos + dy][Xpos + dx] || maze[Ypos + dy][Xpos + dx])
	{
		flag = false;
	}

	return flag;
}

void move(int v)
{
	switch (v)
	{
	case 0:
		Xpos += dx;
		Ypos += dy;
		break;
	case 1:
		Xpos -= dx;
		Ypos -= dy;
		break;
	}
}
