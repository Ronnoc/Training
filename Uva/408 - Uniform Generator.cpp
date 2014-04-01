#include<stdio.h>
int gcd(int x,int y){
	if(x<y)return gcd(y,x);
	if(y==0)return x;
	return gcd(y,x%y);                                                                     
	}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		printf("%10d%10d    ",n,m);
		if(gcd(n,m)==1)printf("Good Choice\n");
		else printf("Bad Choice\n");
		printf("\n"); 
		}
	return 0;
	}
