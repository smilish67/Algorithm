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
	// ������ �Լ���  ���� ���ڰ� �Դϴ�.
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

	//ù��° ��ġ ī��Ʈ �� �湮 ����
	visit[Ypos][Xpos] = 1;
	cnt++;

	while (true)
	{
		//���� Ƚ���� �����ϰ� 4�� ���� �ڷΰ���.
		turn();
		turn_num++;
		//�� �� �ִ� ��츦 ��ȯ�Ѵ�.
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
