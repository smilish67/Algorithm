#include <stdio.h>
#include <time.h>
int cnt, Xpos, Ypos,px,py;
enum direction {
		north,
		east,
		south,
		west
};
enum direction dir; 

void changedir(), setpxpy(), back();

int main(void)
{

	int n,m;
	scanf("%d%d", &n,&m);
	int maze[n][m];
	int visit[n][m];
	scanf("%d%d%d", &Xpos, &Ypos, &dir);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d",&maze[i][j]);
			visit[i][j] = 0;
		}
	}
	visit[Ypos][Xpos] = 1;
	cnt++;
	setpxpy();

	while(1)
	{
		if(!visit[Ypos+py][Xpos+px]&&maze[Ypos+py][Xpos+px]==0)
		{
			visit[Ypos+py][Xpos+px] =1;
			Xpos += px;
			Ypos += py;
			changedir();
			cnt++;
			printf("움직이기 (%d, %d)\n", Xpos, Ypos);
		}
		else if((visit[Ypos+1][Xpos]||maze[Ypos+1][Xpos])&&(visit[Ypos-1][Xpos]||maze[Ypos-1][Xpos])&&(visit[Ypos][Xpos+1]||maze[Ypos][Xpos+1])&&(visit[Ypos][Xpos-1]||maze[Ypos][Xpos-1]))
		{
			printf("%d 현재방향",dir); 
			back();
			printf("뒤로(%d, %d)\n", Xpos, Ypos);
			if(maze[Xpos][Ypos]==1) goto shit;
		}
		else if(((visit[Ypos+py][Xpos+px])&&maze[Ypos+py][Xpos+px]==0)||maze[Ypos+py][Xpos+px])
		{
			printf("돌기\n");
			changedir();
		}
	}
	shit:
	printf("%d", end-start);
}

void changedir()
{
	switch(dir)
	{
		case north:
			dir = west;
			break;
		
		case west:
			dir = south;
			break;
		
		case south:
			dir = east;
			break;
		
		case east:
			dir = north;
			break;
	}
	setpxpy();
}

void setpxpy()
{
	switch(dir)
	{
		case north:
			px = -1;
			py = 0;
			break;
		
		case west:
			px = 0;
			py = 1;
			break;
		
		case south:
			px = 1;
			py = 0;
			break;
		
		case east:
			px = 0;
			py = -1;
			break;
	}
}

void back()
{
	switch(dir)
	{
		case north:
			Ypos +=1;
			break;
		
		case west:
			Xpos +=1;
			break;
		
		case south:
			Ypos -=1;
			break;
		
		case east:
			Xpos -=1;
			break;
	}
}
