#include<stdio.h>
int isp[1000010];
int p[90000];
int main(){
	int i,j;
	isp[1]=0;
	for(i=2;i<=1000000;i++)isp[i]=-1;
	for(i=2;i<=1000000;i++){
		if(isp[i]==-1){
			isp[i]=1;
			for(j=2;j*i<=1000000;j++)isp[i*j]=0;
			}
		}
	int q=0;
	for(i=1;i<=1000000;i++)if(isp[i])p[++q]=i; 
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=1;i<=q;i++)if(isp[n-p[i]])break;
		printf("%d = %d + %d\n",n,p[i],n-p[i]);
		}
	return 0;
	}
