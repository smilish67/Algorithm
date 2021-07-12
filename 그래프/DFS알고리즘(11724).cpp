#include <stdio.h>
#include <stack>

std::stack<int> stack;
int A[1010][1010];
bool checked[1010];

int main(){
	int N, M, cnt =0;
	scanf("%d%d", &N,&M);
	for(int i=1; i<=M; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		A[a][b] = 1;
		A[b][a] = 1;
	}
	
	for(int i =1; i<=N; i++){
		if(!checked[i]){
			cnt++;
			stack.push(i);
			while(!stack.empty()){
				int t = stack.top();
				stack.pop();
				if(checked[t]) continue;
				checked[t] = true;
				
				for(int i=1; i<=N; i++){
					if(A[t][i]==1) stack.push(i);
				}
			}
		}
	}
	printf("%d", cnt);
}
