#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
int dp[1005][1005][4];
int ok[1005][1005][4];
char s[1005][1005];
set<char>L,R,U,D;
int main(){
	int i,j,k,_T;
	int n,m;
	L.insert('+');
	R.insert('+');
	U.insert('+');
	D.insert('+');
	
	L.insert('-');
	R.insert('-');
	
	U.insert('|');
	D.insert('|');

	L.insert('<');
	R.insert('>');
	U.insert('^');
	D.insert('v');

	R.insert('L');
	U.insert('L');
	D.insert('L');

	L.insert('R');
	U.insert('R');
	D.insert('R');

	L.insert('U');
	R.insert('U');
	D.insert('U');

	L.insert('D');
	R.insert('D');
	U.insert('D');
	int dx[]={0,1,0,-1};
	int dy[]={-1,0,1,0};
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		int sx,sy;
		int tx,ty;
		scanf("%d%d",&sx,&sy);
		scanf("%d%d",&tx,&ty);
		sx--,sy--,tx--,ty--;
		memset(ok,0,sizeof ok);
		memset(dp,-1,sizeof dp);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(L.count(s[i][j]))ok[i][j][0]=1;
				if(D.count(s[i][j]))ok[i][j][1]=1;
				if(R.count(s[i][j]))ok[i][j][2]=1;
				if(U.count(s[i][j]))ok[i][j][3]=1;
			}
		}
		queue<pair<PII,int> >Q;
		Q.push(MP(MP(sx,sy),0));
		dp[sx][sy][0]=0;
		while(!Q.empty()){
			PII tp=Q.front().AA;
			int x=tp.AA,y=tp.BB;
			int g=Q.front().BB;
			Q.pop();
			//cout<<x<<" "<<y<<" "<<g<<" "<<dp[x][y][g]<<"\n";
			for(k=0;k<4;k++)if(ok[x][y][(k+g)&3]){
				int xx=x+dx[k],yy=y+dy[k];
				if(xx<0||xx>=n)continue;
				if(yy<0||yy>=m)continue;
				if(!ok[xx][yy][((k^2)+g)&3])continue;
				if(~dp[xx][yy][g])continue;
				dp[xx][yy][g]=dp[x][y][g]+1;
				Q.push(MP(MP(xx,yy),g));
			}
			if(-1==dp[x][y][(g+1)&3]){
				dp[x][y][(g+1)&3]=dp[x][y][g]+1;
				Q.push(MP(MP(x,y),(g+1)&3));
			}
		}
		int ans=-1;
		for(i=0;i<4;i++)if(~dp[tx][ty][i]){
			if(~ans)cmin(ans,dp[tx][ty][i]);
			else ans=dp[tx][ty][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}