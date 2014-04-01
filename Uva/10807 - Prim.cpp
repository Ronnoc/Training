#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 30
struct edge{
	int p,q,w;
	bool operator < (const edge& b)const {
		return w<b.w;
		}
	};
std::vector<edge>L;
int ft[MAX];
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i;
	}
int find(int x){
	int t=x,temp;
	while(ft[x]!=x)x=ft[x];
	while(t!=x){
		temp=ft[t];
		ft[t]=x;
		t=temp;
		}
	return x;
	}
void merge(int root1,int root2){
	int fr1=find(root1);
	int fr2=find(root2);
	ft[fr1]=fr2;
	}
int res=(int)1e9;
int cho[MAX];
bool ok[MAX];
int n,m;
int min(int a,int b){
	if(a>b)return b;return a;
	}
int max(int a,int b){
	if(a<b)return b;return a;
	}
int is_tree(){
	int i;
	in_ft(n);
	for(i=1;i<n;i++){
		int t=cho[i];
		int p=L[t].p;
		int q=L[t].q;
		if(find(p)!=find(q))merge(p,q);
		else return 0;
		}
	for(i=2;i<=n;i++)if(find(i)!=find(1))return 0;
	return 1;
	}
void DFS(int t){
	int i;
	if(t==n){
		int flag=is_tree();
		if(!flag)return;
	//	for(i=1;i<n;i++)printf("%d ",cho[i]);printf("\n");
		for(i=0;i<m;i++)ok[i]=0;
		for(i=1;i<n;i++)ok[ cho[i] ]=1;
		in_ft(n);
		int ha=0;
		for(i=cho[1]+1;i<m;i++){
			if(ok[i])continue;
			int p,q;
			p=L[i].p;
			q=L[i].q;
			if(find(p)!=find(q))merge(p,q),ha+=L[i].w;
			}
		find(1);
		for(i=2;i<=n;i++)if(find(i)!=ft[1])return;
		for(i=1;i<n;i++)ha+=L[ cho[i] ].w;
		res=min(res,ha);
		}
	else {
		i=max(cho[t-1]+1,t-1);
		for(;i<=m-n+t-2;i++){
			cho[t]=i;
			DFS(t+1);
			}
		}
	}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		in_ft(n);L.clear();res=(int)1e9;
		scanf("%d",&m);
		int i,p,q,w;
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&p,&q,&w);
			L.push_back( (edge){p,q,w} );
			}
		std::sort(L.begin(),L.end());
		cho[1]=0;
		DFS(2);
		if(res==(int)1e9)printf("No way!\n");
		else printf("%d\n",res);
		}
	return 0;
	}
