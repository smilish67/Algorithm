#include <stdio.h>
#include <stack>

int h[500010];
int lastidx;

std::stack<int> St;
int main(){
	int N, cnt=0;
	int sum = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		cnt = 0;
		scanf("%d",&h[i]);
		while(!St.empty()&&St.top()<h[i]){
			St.pop();
			cnt++;
			sum += cnt;
		}
		while(!St.empty()&&St.top()>h[i]){
			
		}
		St.push(h[i]);
	}
	printf("%d", sum);
}
