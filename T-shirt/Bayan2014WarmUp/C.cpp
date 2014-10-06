#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;

char s[1005][1005];
int n,m;
int vis[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int x,int y,int clr){
	if(x<0||x>=n)return;
	if(y<0||y>=m)return;
	if(vis[x][y])return;
	if(s[x][y]=='.')return;
	vis[x][y]=clr;
	for(int e=0;e<4;e++)
		bfs(x+dx[e],y+dy[e],clr);
}
int isnotX(int x,int y){
	if(x<0||x>=n)return 1;
	if(y<0||y>=m)return 1;
	return s[x][y]!='X';
}
int pre[1005][1005];
int st[1005][1005];
int aim[1005][1005];
bool can(int dx,int dy,int sx,int sy){
//	cout<<dx<<","<<dy<<" "<<sx<<","<<sy<<endl;
	if(dx<=0||dy<=0)return 0;
	memset(st,0,sizeof st);
	PII p=MP(sx,sy);
	PII q=MP(sx+dx-1,sy+dy-1);
	if(q.AA>=n||q.BB>=m)return 0;
	int i,j;
	for(i=sx;i<sx+dx;i++)for(j=sy;j<sy+dy;j++)
		st[i][j]=1;
	while(1){
//		for(i=0;i<n;i++,cout<<endl)
//			for(j=0;j<m;j++)cout<<st[i][j];
//		cout<<endl;
		if(!isnotX(p.AA,q.BB+1)){
			for(i=p.AA;i<=q.AA;i++)
				st[i][q.BB+1]=1;
			q.BB++,p.BB++;
		}
		else if(!isnotX(q.AA+1,p.BB)){
			for(i=p.BB;i<=q.BB;i++)
				st[q.AA+1][i]=1;
			q.AA++,p.AA++;
		}
		else break;
	}
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(aim[i][j]!=st[i][j])return 0;
	return 1;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++)scanf("%s",s[i]);
		memset(vis,0,sizeof vis);
		memset(aim,0,sizeof aim);
		int nclr=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++)aim[i][j]=s[i][j]=='X';
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(aim[i][j]&&!vis[i][j])
			bfs(i,j,++nclr);
		if(nclr>1||nclr==0){
			printf("-1\n");
			continue;
		}
		memset(pre,0,sizeof pre);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)pre[i][j]=pre[i][j-1]+1-isnotX(i-1,j-1);
		for(j=1;j<=m;j++)for(i=1;i<=n;i++)pre[i][j]+=pre[i-1][j];
		vector<PII>L;
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			if(!isnotX(i,j)&&isnotX(i-1,j)&&isnotX(i,j-1))
				L.PB(MP(i,j));
		}
		if(L.SZ>1||L.empty()){
			printf("-1\n");
			continue;
		}
		int sx=L[0].AA+1,sy=L[0].BB+1;
		int tot=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(!isnotX(i,j))tot++;
		int isSquare=0;
		for(i=sx;i<=n;i++)for(j=sy;j<=m;j++){
			int sum=pre[i][j]+pre[sx-1][sy-1]-pre[i][sy-1]-pre[sx-1][j];
			if(sum==tot&&sum==(i-sx+1)*(j-sy+1)&&!isSquare){
				isSquare=1;
				printf("%d\n",min(i-sx+1,j-sy+1));
			}
		}
		if(isSquare)continue;
		int leftdown=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(!isnotX(i,j))
			if(isnotX(i+1,j)&&isnotX(i,j-1))leftdown++;
		vector<PII>ans;
		if(leftdown>1){
			int dx=0,dy=0;
			while(sx-1+dx<=n&&!isnotX(sx-1+dx,sy-1+dy))dx++;
			while(sy-1+dy<=m&& isnotX(sx-1+dx,sy-1+dy))dy++;
			int len=0;
			while(!isnotX(sx-1,sy-1+len))len++;
			dy=len-dy;
			if(can(dx,dy,sx-1,sy-1))
				ans.PB(MP(dx,dy));
		}
		int rightup=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++)if(!isnotX(i,j))
			if(isnotX(i-1,j)&&isnotX(i,j+1))rightup++;
		if(rightup>1){
			int dx=0,dy=0;
			while(sy-1+dy<=m&&!isnotX(sx-1+dx,sy-1+dy))dy++;
			while(sx-1+dx<=n&& isnotX(sx-1+dx,sy-1+dy))dx++;
			int len=0;
			while(!isnotX(sx-1+len,sy-1))len++;
			dx=len-dx;
			if(can(dx,dy,sx-1,sy-1))
				ans.PB(MP(dx,dy));
		}
		int S=MOD;
		for(i=0;i<ans.SZ;i++)
			cmin(S,ans[i].AA*ans[i].BB);
		if(S==MOD)printf("-1\n");
		else printf("%d\n",S);
	}
	return 0;
}
/*
3 3
XX.
XXX
X.X
3 3
XX.
X.X
.XX
3 5
XXXX.
..XX.
..XXX
*/
