#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define N 500000
#define INF (int)1e9
struct edge{
	int to,w;
	int nxt;
	}E[N];
int n,head[N],num_edge;
void Ini_edge(){
	num_edge=0;
	memset(head,-1,sizeof(head));
	}
void Add_edge(int u,int v,int w){
	E[num_edge].to=v;
	E[num_edge].w=w;
	E[num_edge].nxt=head[u];
	head[u]=num_edge;
	num_edge++; 
	}
bool inqueue[N];
int d[N];
int cnt[N];
int Q[N],ql,qr;
bool SPFA(int src){
	int i,j;
	for(i=0;i<=n;i++)inqueue[i]=0;
	for(i=0;i<=n;i++)d[i]=INF;
	for(i=0;i<=n;i++)cnt[i]=0;
	ql=0;qr=0;
	Q[++qr]=src;
	inqueue[src]=1;
	d[src]=0;
	cnt[src]++;
	while(ql!=qr){
		int u=Q[++ql];
		ql%=N;
		inqueue[u]=0;
		for(i=head[u];i!=-1;i=E[i].nxt){
			int to=E[i].to;
			if(d[u]!=INF&&d[u]+E[i].w<d[to]){
				d[to]=d[u]+E[i].w;
				if(!inqueue[to]){
					inqueue[to]=1;
					Q[++qr]=to;
					qr%=N;
					cnt[to]++;
					if(cnt[to]>=n)return 1;
					}
				}
			}
		}
	return 0;
	}
int main(){
	int m,i,x,y,z;
	while(scanf("%d",&m)!=EOF){
		n=0;
		Ini_edge();
		while(m--){
			scanf("%d%d%d",&x,&y,&z);
			x++;y++;
			Add_edge(y,x-1,-z);
			n=max(n,max(y,x-1));
			}
		for(i=0;i<=n;i++){
			Add_edge(i+1,i,0);
			Add_edge(i,i+1,1);
			}
		SPFA(n);
		printf("%d\n",-d[0]);
		}
	return 0;
	}
