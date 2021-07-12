#include <stdio.h>
#include <stack>

std::stack<int> stack;
int main(){
	int N, h, tmp=0;
	scanf("%d", &N);
	
	
	for(int i=0; i<N; i++){
		scanf("%d", &h);	
		while(!stack.empty()&&stack.top()<=h) {
			stack.pop();
			tmp++;
		}
		stack.push(h); 
	}
	
	printf("%d", stack.size());
} 
