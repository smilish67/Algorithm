#include <stdio.h>
#include <stack>

int N, cmd, sum, a;

std::stack<int> score;
std::stack<int> time;
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &cmd);
		if(cmd==1){
			int s,t;
			scanf("%d%d",&s,&t);
			score.push(s);
			time.push(t-1);
		}
		else if(cmd==0&&time.empty()){
			continue;
		}
		else {
			a = time.top()-1;
			time.pop();
			time.push(a);
		}
		if(time.top()==0){
			sum+=score.top();
			time.pop();
			score.pop();
		}
 	}
 	printf("%d", sum);
}
