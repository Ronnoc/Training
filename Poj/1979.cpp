#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char map[25][25];
int vis[25][25];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		swap(n,m);
		if(!n&&!m)break;
		memset(vis,0,sizeof(vis));
		int i,j,x,y;
		for(i=0;i<n;i++)scanf("%s",map[i]);
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(map[i][j]=='@')x=i,y=j;
		stack<pair<int,int> >S;
		S.push(make_pair(x,y));
		int res=0;
		while(!S.empty()){
			x=S.top().first;
			y=S.top().second;
			S.pop();
			if(vis[x][y])continue;
			vis[x][y]=1;
			res++;
//			printf("%d %d\n",x,y);
			for(i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<0||xx>=n)continue;
				if(yy<0||yy>=m)continue;
				if(vis[xx][yy])continue;
				if(map[xx][yy]!='.')continue;
				S.push(make_pair(xx,yy));
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
