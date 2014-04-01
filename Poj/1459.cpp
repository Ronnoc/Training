#include<stdio.h>
#include<algorithm>
#include<queue>
#define INF (int)1e9
#define N 510
#define FOR(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int G[N][N];
int ft[N];
bool visit[N];
int n,np,nc,m;
int res;
bool EK(int src,int des){
	queue<int>Q;while(!Q.empty())Q.pop();
	int i;
	FOR(i,0,n+1)visit[i]=0;
	Q.push(src);visit[src]=0;
	while(!Q.empty()){
		int tp=Q.front();Q.pop();
		FOR(i,0,n+1){
			if(!visit[i]&&G[tp][i]){
				ft[i]=tp;
				Q.push(i);
				visit[i]=1;
				if(i==des)return 1;
				}
			}
		}
	return 0;
	}
void FF(int src,int des){
	res=0;
	while(1){
		if(!EK(src,des))break;
		int run=INF,tp=des;
		while(tp!=src){
			run=min(run,G[ft[tp]][tp]);
			tp=ft[tp];
			}
		tp=des;
		while(tp!=src){
			G[ft[tp]][tp]-=run;
			G[tp][ft[tp]]+=run;
			tp=ft[tp];
			}
		res+=run;
		}
	}
int main(){
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
		int i,j,x,y,c;
		char s[1010];
		FOR(i,0,n+1)FOR(j,0,n+1)G[i][j]=0;
		FOR(i,1,m){
			scanf("%s",s);
			sscanf(s,"(%d,%d)%d",&x,&y,&c);
			x++;y++;
			G[x][y]+=c;
			}
		FOR(i,1,np){
			scanf("%s",s);
			sscanf(s,"(%d)%d",&y,&c);
			y++;
			G[0][y]+=c;
			}
		FOR(i,1,nc){
			scanf("%s",s);
			sscanf(s,"(%d)%d",&x,&c);
			x++;
			G[x][n+1]+=c;
			}
		FF(0,n+1);
		printf("%d\n",res);
		}
	return 0;
	}
