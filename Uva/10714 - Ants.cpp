#include<stdio.h>
#include<algorithm>
int a[100010];
int max(int a,int b){
	if(a>b)return a;
	return b;
	}
int min(int a,int b){
	if(a>b)return b;
	return a;
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int i,n,L;
		scanf("%d%d",&L,&n);
		int resa=0,resb=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			resa=max( resa,max(a[i],L-a[i]) );
			resb=max( resb,min(a[i],L-a[i]) );
			}
		printf("%d %d\n",resb,resa);
		}
	return 0;
	}
