#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm> 

std::vector<int> V[1010];
std::queue<int> Q;
std::stack<int> St;

bool chA[1010], chB[1010];

int main(){
	int n,m,v;
	scanf("%d%d%d", &n,&m,&v);

	for(int i=1; i<=m; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for(int i=1; i<=n; i++) std::sort(V[i].begin(),V[i].end());
	
	St.push(v);
	while(!St.empty()){
		int t = St.top();
		St.pop();
		if(chA[t]) continue;
		chA[t] = true;
		printf("%d ", t);
		
		for(int i=V[t].size()-1; i>=0; i--){
			int k = V[t][i];
			if(chA[k]==0) St.push(k);
		}
	}
	printf("\n");
	Q.push(v);
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		if(chB[t]) continue;
		
		chB[t] = true;
		printf("%d ", t);
		for(int i = 0; i<V[t].size(); i++){
			int k = V[t][i];
			Q.push(k);
		}
	}
}
