//Poj 1502
#include <vector>
#include <queue>
#include<stdio.h>
using namespace std;
#define N 501
int INF = (int)1e9;
struct edge{
   int to;
   int w;
}tp;
vector<edge> G[N]; //vector实现邻接表 
int d[N];
bool final[N];          //记录顶点是否在队列中，SPFA算法可以入队列多次 
int cnt[N],n;             //记录顶点入队列次数 
bool SPFA(int s)
{
     queue<int>Q;
     int i,j;
     for(i=1;i<=n;++i)d[i]=INF;
     for(i=1;i<=n;i++)final[i]=0;
     for(i=1;i<=n;i++)cnt[i]=0;
     d[s]=0;                   //源点的距离为0 
     final[s] = 1;          
     cnt[s]++;                 //源点的入队列次数增加 
     Q.push(s);
     while(!Q.empty()){
         int u=Q.front();Q.pop();
         final[u]=0;
         for(i=0;i<G[u].size();++i){
             int to = G[u][i].to;
             if(d[u]<INF && d[to]>d[u]+ G[u][i].w){                           
                  d[to] = d[u]+ G[u][i].w;
                  if(!final[to]){
                      final[to] = 1;
                      cnt[to]++;
                      if(cnt[to]>=n)return 1;   //当一个点入队的次数>=n时就证明出现了负环。
                      Q.push(to);
                  }                  
             }
         }
     }
     return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,w,i,j,s,e,t;
		scanf("%d%d%d",&n,&m,&w);
		for(i=1;i<=n;i++)G[i].clear();
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&s,&e,&t);
			tp.to=e;tp.w=t;G[s].push_back(tp);
			tp.to=s;tp.w=t;G[e].push_back(tp);
			}
		for(i=1;i<=w;i++){
			scanf("%d%d%d",&s,&e,&t);
			tp.to=e;tp.w=-t;G[s].push_back(tp);
			}		
		int flag=0;
	//	for(i=1;i<=n;i++)flag=flag||SPFA(i);
		if(SPFA(1))printf("YES\n");
		else printf("NO\n");
		}
	return 0;
	}
