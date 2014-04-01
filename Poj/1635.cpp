#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1510
vector<int>G[N];
int ft[N],l[N],r[N],len;
int bfs(int u,int *l){
	if(l[u]!=-1)return l[u];
	l[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
	/*	if(v<=len/2)*/l[u]+=bfs(v,l);
		}
	return l[u];
	}
void build_tree(char *a,int l[]){
		int i,j;
		int mp=0,now=0,u,v;
		ft[1]=-1;
		for(i=0;i<=len/2;i++)G[i].clear();
		for(i=0;i<len;i++){
			if(a[i]=='0'){
				u=now;
				v=++mp;
				ft[v]=u;
				G[u].push_back(v);
				now=v;
				}
			else now=ft[now];
			}	
	/*	for(i=0;i<len/2;i++){
			printf("%4d::",i);
			for(int j=0;j<G[i].size();j++)printf("%d ",G[i][j]);
			printf("\n");
			}	*/ 
		for(i=0;i<=len/2;i++)l[i]=-1;
		bfs(0,l);
		sort(l,l+len/2+1);
		}
int main(){
	char a[3010],b[3010];
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",a,b);
		len=strlen(a);
		build_tree(a,l);
		build_tree(b,r);
		int flag=1;
		for(int i=0;i<=len/2;i++)if(l[i]!=r[i])flag=0;
		if(flag)printf("same\n");
		else printf("different\n");
		}
	return 0;
	}
