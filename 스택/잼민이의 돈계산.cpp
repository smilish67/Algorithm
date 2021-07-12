#include <stdio.h>
#include <stack>

std::stack<int> stack;
int main(){
	int K, in, ans=0;
	scanf("%d", &K);
	
	for(int i=0; i<K; i++){
		scanf("%d", &in);
		if(in==0) stack.pop();
		else stack.push(in);
	}
	
	while(!stack.empty()){
		ans += stack.top();
		stack.pop();
	}
	printf("%d", ans);
}
