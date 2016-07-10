#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

int R,C;
int h[55][55];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int vis[55][55];
bool check(int x,int y,int d){
	queue<PII>Q;
	rep(i,0,R)rep(j,0,C)vis[i][j]=0;
	Q.push(MP(x,y));
	vis[x][y]=1;
	while(!Q.empty()){
		PII qf=Q.front();Q.pop();
		rep(k,0,4){
			int xx=qf.AA+dx[k];
			int yy=qf.BB+dy[k];
			if(xx<0||xx>=R)return 0;
			if(yy<0||yy>=C)return 0;
			if(h[xx][yy]<d&&!vis[xx][yy]){
				vis[xx][yy]=1;
				Q.push(MP(xx,yy));
			}
		}
	}
	return true;
}
void solve(){
	scanf("%d%d",&R,&C);
	rep(i,0,R)rep(j,0,C)
		scanf("%d",&h[i][j]);
	int ans=0;
	rep(i,1,R-1)rep(j,1,C-1){
		int le=h[i][j],re=1000,ge=-1;
		while(re>=le){
			if(re-le<=1){
				if(check(i,j,re))ge=re;
				else ge=le;
				break;
			}
			int me=(le+re)>>1;
			if(check(i,j,me))le=me;
			else re=me;
		}
		ans+=ge-h[i][j];
	}
	printf("%d\n",ans);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}