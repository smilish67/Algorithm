#include <stdio.h>
#include <stack>
#include <string.h>

char str[60];
std::stack<int> St;
int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		bool leftover= false;
		scanf("%s", str);
		int s = strlen(str);
		for(int i=0; i<s; i++){
			if(str[i]=='(') St.push(1);
			else if(str[i]==')'){
				if(St.empty()){
					leftover = true;
					break;
				}
				else St.pop();
			} 
		}
		if(St.empty()&&!leftover) printf("YES\n");
		else {
			printf("NO\n");
			while(!St.empty()) St.pop();
		}
	}
}

