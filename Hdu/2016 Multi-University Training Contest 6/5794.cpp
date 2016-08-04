#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
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
const LL MOD = 110119;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
LL dp[105][105];
LL yna[105][105];
LL fact[MOD+5];	//预处理n! mod p 的表 O(min(n,p))
LL inv[MOD+5];
// n!=a*p^e return a%p
LL modFact (LL n, LL p, LL &e) {
	e = 0;
	if (!n) return 1;
	LL res = modFact (n / p, p, e);
	e += n / p;
	if (n / p % 2)
		return res * (p - fact[n % p]) % p;
	return res * fact[n % p] % p;
}
LL comb(LL n,LL m){
	LL e1,e2,e3;
	LL a1=modFact(n,MOD,e1);
	LL a2=modFact(m,MOD,e2);
	LL a3=modFact(n-m,MOD,e3);
	if(e1>e2+e3)return 0;
	return a1*inv[a2]%MOD*inv[a3]%MOD;
}
LL any(pair<LL,PLL>A,pair<LL,PLL>B){
	if(A.AA>=B.AA)return A==B;
	if((B.AA-A.AA)%3)return 0;
	LL dx=B.BB.AA-A.BB.AA;
	LL dy=B.BB.BB-A.BB.BB;
	LL ab=(dx+dy)/3;
	if(dx<ab||dy<ab)return 0;
	LL a=dx-ab,b=dy-ab;
	return comb(a+b,a);	
}
void solve(){
	LL n,m;
	int r;
	int CA=0;
	while(cin>>n>>m>>r){
		++CA;
		vector<pair<LL,PLL> >L;
		L.PB(MP(2LL,MP(1LL,1LL)));
		L.PB(MP(n+m,MP(n,m)));
		int fail=0;
		rep(i,0,r){
			LL x,y;
			cin>>x>>y;
			L.PB(MP(x+y,MP(x,y)));
			fail|=x==n&&y==m;
		}
		printf("Case #%d: ",CA);
		if(fail){
			printf("0\n");
			continue;
		}
		sort(all(L));
		L.erase(unique(all(L)),L.ED);
		memset(dp,0,sizeof dp);
		rep(i,0,sz(L))rep(j,i+1,sz(L))
			yna[i][j]=any(L[i],L[j]);
		rep(i,0,sz(L))dp[i][i]=1;
		rep(k,1,sz(L)){
			rep(i,0,sz(L)-k){
				dp[i][i+k]=yna[i][i+k];
				rep(j,i+1,i+k)
					dp[i][i+k]-=dp[i][j]*yna[j][i+k]%MOD;
				dp[i][i+k]%=MOD;
				dp[i][i+k]+=MOD;
				dp[i][i+k]%=MOD;
			}
		}
		printf("%d\n",(int)dp[0][sz(L)-1]);
	}
}

int main(){
	fact[0]=1;
	rep(i,1,MOD)fact[i]=fact[i-1]*i%MOD;
	inv[1]=1;
	rep(i,2,MOD)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}