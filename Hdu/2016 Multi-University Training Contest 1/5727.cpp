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

void update(int &tp,int w){
	if(w==-1)return;
	if(~tp)cmin(tp,w);
	else tp=w;
}
int dp[1<<17][19][3];
int g[11][11];
void solve(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0){
			printf("0\n");
			continue;
		}
		memset(g,0,sizeof g);
		rep(i,0,m){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u-1][v-1]=1;
		}
		if(n==1){
			if(m==1)
				printf("1\n");
			else printf("0\n");
			continue;
		}
		int z=n+n-1;
		rep(mask,0,1<<z)rep(j,0,z+1)rep(k,0,2)dp[mask][j][k]=-1;
		rep(j,0,n)
			dp[1<<(j+n-1)][j+n-1][g[0][j]]=0;
		int yang=(1<<(n-1))-1;
		int yin=((1<<n)-1)<<(n-1);
		rep(i,0,1<<z)rep(j,0,z)rep(k,0,2)if(~dp[i][j][k]){
			//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
			int ryang=(i^yang)&yang;
			int ryin=(i^yin)&yin;
			rep(p,0,n-1)if(ryang>>p&1)rep(q,n-1,z)if(ryin>>q&1){
				update(dp[i|(1<<p)|(1<<q)][q][k],dp[i][j][k]+(g[p+1][q-(n-1)]||g[p+1][j-(n-1)]));
			}
		}
		int ans=-1;
		//cout<<(yin|yang)<<"\n";
		rep(j,0,n)rep(k,0,2)if(~dp[yin|yang][j+n-1][k]){
			//cout<<(yin|yang)<<" "<<j<<" "<<k<<" "<<(k||g[0][j])<<"+"<<dp[yin|yang][j+n-1][k]<<"\n";
			update(ans,dp[yin|yang][j+n-1][k]+(k||g[0][j]));
		}
		printf("%d\n",ans);
	}
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}