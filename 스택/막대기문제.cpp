#include <stdio.h>

int h[100010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &h[i]);
	int ans = 0;
	
	for(int i=0; i<n; i++){
		int visible = 1;
		for(int j=i+1; j<n; j++){
			if(h[j]>=h[i])
				visible = 0;
		}
		if(visible==1) ans++;
	}
	printf("%d", ans);
}

//배열활용 
