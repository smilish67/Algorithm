#include <stdio.h>
#include <stack>
#include <vector>
bool check[110];


std::vector<int> V[110];
std::stack<int> St;
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++){
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	
	St.push(1);
	while(!St.empty()){
		int t = St.top();
		St.pop();
		if(check[t]) continue;
		ans++;
		check[t] = true;
		
		for(int i=0; i<V[t].size(); i++){
			int k= V[t][i];
			if(!check[k]) St.push(k);
		}
	}
	printf("%d", ans-1);
}
