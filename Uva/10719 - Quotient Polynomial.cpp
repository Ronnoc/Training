#include<stdio.h>
int t[10010];
int a[10010];
int q[10010];
int main(){
	int k;
	int g=0;
	while(scanf("%d%*c",&k)!=EOF){
		if(g)printf("\n"); 
		int i;
		char c;
		for(i=0;;i++){
			scanf("%d%c",&t[i],&c);
			if(c=='\n')break;
			}
		int n=i;
		for(i=0;i<=n;i++)a[i]=t[n-i];
		for(i=n;i>=0;i--){
			q[i]=a[i];
			if(i)a[i-1]+=k*q[i];
			}
		printf("q(x):");
		for(i=n;i>0;i--)printf(" %d",q[i]);
		printf("\n");
		printf("r = %d\n",q[0]);
		printf("\n");
		}
	return 0;
	}
