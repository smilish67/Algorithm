//greedy study first
#include <stdio.h>

int main(void)
{
	int sum = 0;
	int a = 0,b = 0,c = 0,d = 0;
	scanf("%d", &sum);
	printf("������ ��ſ��� %d���� �ʿ��ϴ� �Ͽ���.\n", sum);
	while(1)
	{
		if(sum/500) 
		{
			a = sum/500;
			sum %= 500;
		}
		
		else if(sum/100)
		{
			b = sum/100;
			sum %= 100;
		}
		
		else if(sum/10)
		{
			c = sum/10;
			sum %= 10;
		}
		
		else
		{
			d = sum;
			break;
		}
	}
	
	printf("%d %d %d %d �ʿ��մϴ� ����",a,b,c,d);
}
