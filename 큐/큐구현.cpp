 #include <stdio.h>
 
 int S[100010], f, l;
 
 int front(){
 	if(f==l) return -1;
 	else return S[f];
 }
 
 int pop(){
 	if(f==l) return -1;
 	else {
 		int tmp = S[f];
 		f++;
 		return tmp;
	 }
 }
 
 void push(int a){
 	S[l] = a;
 	l++;
 }
 
 bool empty(){
 	if(l==f) return true;
 	else return false;
 }
 
 int size(){
 	return l-f;
 }
 
 int back(){
 	if(l==f) return -1;
 	else return S[l-1];
 }
 
 
 int main(){
 	int N, a;
 	scanf("%d",&N);
 	char str[1234];
	for(int i=0; i<N; i++){
		scanf("%s", str);
		if(str[0]=='b') printf("%d\n", back());
		if(str[0]=='f') printf("%d\n", front());
		if(str[0]=='e') printf("%d\n", empty());
		if(str[0]=='s') printf("%d\n", size());
		if(str[0]=='p'){
			if(str[1]=='u'){
				scanf("%d", &a);
				push(a);
			}
			if(str[1]=='o')	printf("%d\n",pop());
		}
	} 
 } 
