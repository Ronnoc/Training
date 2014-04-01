#include<stdio.h>
const int maxn=20000+10;
int ft[maxn],d[maxn];
int dis(int a,int b){
	int z;
	if(a-b>0)z=a-b;
	else z=b-a;
	return z%1000;
	}
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i,d[i]=0;
	}
int find(int x){
	if(ft[x]!=x){
		int root=find(ft[x]);
		d[x]+=d[ ft[x] ];
		return ft[x]=root;
		}
	return x;
	}
int main(){
	char c,s[1000];
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		scanf("%d%*c",&n);
		in_ft(n);
		while(scanf("%s",s)!=EOF&&s[0]!='O'){
			if(s[0]=='I'){
				scanf("%d%d",&x,&y);
				ft[x]=y;
				d[x]=dis(x,y);
				}
			else {
				scanf("%d",&x);
				find(x);
				printf("%d\n",d[x]);
				}
			}
		}
	return 0;
	}
