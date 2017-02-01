//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
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

const int MXN = 100005;
char mp[55][55];
int dp[55][8];
int play(int mask,char x){
	if(islower(x))return mask|1;
	if(isdigit(x))return mask|2;
	if(x=='*')return mask|4;
	if(x=='&')return mask|4;
	if(x=='#')return mask|4;
	return mask;
}
void update(int &x,int y){
	if(x==-1)x=y;
	else cmin(x,y);
}
void solve(){
	int n,m;
	while(cin>>n>>m){
		rep(i,0,n)scanf("%s",mp[i]);
		memset(dp,-1,sizeof dp);
		dp[0][0]=0;
		rep(i,0,n){
			rep(mask,0,8)if(~dp[i][mask]){
				rep(j,0,m){
					int jd=(m-j)%m;
					int next=play(mask,mp[i][jd]);
					update(dp[i+1][next],dp[i][mask]+j);
				}
				rep(j,0,m){
					int jd=j%m;
					int next=play(mask,mp[i][jd]);
					update(dp[i+1][next],dp[i][mask]+j);
				}
			}
			//rep(mask,0,8)cout<<dp[i][mask]<<" ";cout<<"\n";
		}
		cout<<dp[n][7]<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}