#include <stdio.h>


int S[10010], p=0;

int push(int a){
	S[p] = a;
	p++;
	return a;
}

int pop(){
	if(p==0) return -1;
	else{
		int tmp = S[p-1];
		S[p-1] = 0;
		p = p-1;
		return tmp;
	}
}

int top(){
	if(p==0) return -1;
	else return S[p-1];	
}

int size(){
	return p;
}

bool empty(){
	if(size()==0) return true;
	else return false;
}

int main(){
	int N;
	int a;
	scanf("%d", &N);
	char str[1234];
	for(int i=0; i<N; i++){
		scanf("%s",str);
		if(str[0]=='t') printf("%d\n", top());
		if(str[0]=='s') printf("%d\n", size());
		if(str[0]=='e') printf("%d\n", empty());
		if(str[0]=='p'){
			if(str[1]=='u') {
				scanf("%d", &a);
				push(a);
			}
			if(str[1]=='o') printf("%d\n", pop());
		}
	} 
}
