#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Xpos, Ypos, cnt = 8;
int move(int x, int y);

int main(void)
{
	enum Xposs{
		a=1,b,c,d,e,f,g,h
	};
	char command[2];
	scanf("%s", &command);
	Ypos = atoi(command+1);
	
	switch(*command)
	{
		case 'a':
			Xpos = a;
			break;
		case 'b':
			Xpos = b;
			break;
		case 'c':
			Xpos = c;
			break;
		case 'd':
			Xpos = d;
			break;
		case 'e':
			Xpos = e;
			break;
		case 'f':
			Xpos = f;
			break;
		case 'g':
			Xpos = g;
			break;
		case 'h':
			Xpos = h;
			break;
	}
	move(2,1);
	move(2,-1);
	move(1,2);
	move(1,-2);
	move(-2,1);
	move(-2,-1);
	move(-1,2);
	move(-1,-2);
	
	printf("%d", cnt);
}

int move(int x, int y)
{
	if((x+Xpos)>8||(x+Xpos)<1||(y+Ypos)>8||(y+Ypos)<1)
		cnt--;
}

