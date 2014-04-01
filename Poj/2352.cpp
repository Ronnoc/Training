#include<stdio.h>
int LB(int x){return x&(-x);}
#define N 32001
int tree[32010]; 
void add(int w,int d){
	for(;w<=N;w+=LB(w))tree[w]+=d;
	} 
int get_sum(int w){
	int res=0;
	for(;w>0;w-=LB(w))res+=tree[w];
	return res;
	}
int star[15010];
int main(){
	int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=32000+1;i++)tree[i]=0;
		for(i=0;i<n;i++)star[i]=0;
		for(i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x++;
			star[ get_sum(x) ]++;
			add(x,1);
			}
		for(i=0;i<n;i++)printf("%d\n",star[i]);
	return 0;
	}
