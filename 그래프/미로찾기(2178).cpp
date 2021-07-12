#include <stdio.h>
#include <queue>
#include <vector>

char x[1010][1010];
int dist[1010][1010];

std::queue<std::pair<int,int> > Q;
std::vector<std::pair<int,int> > V[1010][1010];
int main(){
	int n,m;
	scanf("%d%d", &n,&m);
	for(int i=0; i<n; i++) scanf("%s", x[i]+1);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(x[i][j]=='0') continue;
			
			if(1<=i&&i<=n&&1<=j-1&&j-1<=m) if(x[i][j-1]=='1') V[i][j].push_back(std::make_pair<i,j-1>);
			if(1<=i&&i<=n&&1<=j+1&&j+1<=m) if(x[i][j+1]=='1') V[i][j].push_back(std::make_pair<i,j+1>);
			if(1<=i-1&&i-1<=n&&1<=j&&j<=m) if(x[i-1][j]=='1') V[i][j].push_back(std::make_pair<i-1,j>);
			if(1<=i+1&&i+1<=n&&1<=j&&j<=m) if(x[i+1][j]=='1') V[i][j].push_back(std::make_pair<i+1,j>);
		}
	}
	
	dist[1][1] = 1;
	Q.push(std::<1,1>);
	while(!Q.empty()){
		std::pair<int, int> k = Q.front();
	}
}
