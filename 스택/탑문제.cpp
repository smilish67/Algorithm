#include <stdio.h>
#include <stack>

std::stack<int> stack;
std::stack<int> idx;
int h[500010];
int ans[500010];

int main(){
	int N;
	scanf("%d", &N);
	int lastidx = 0;
	
	for(int i=0; i<N; i++){
		scanf("%d", &h[i]);
		while(!stack.empty()&&stack.top()<h[i]){
			stack.pop();
			idx.pop();
		}
		stack.push(h[i]);
		if(stack.size()==1) {
			ans[i] = 0;
			idx.push(i+1);
			continue;
		} else {
			lastidx = idx.top();
			idx.push(i+1);
		}
		ans[i] = lastidx;
	}
	
	for(int i=0; i<N; i++)
		printf("%d ", ans[i]);
} 
