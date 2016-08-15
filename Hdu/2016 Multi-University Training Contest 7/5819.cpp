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
LL v2=(MOD+1)/2;
LL f[1005][1005];
int z[1005],n;
void solve(){
	RI(n);
	rep(i,1,n+1)RI(z[i]);
	rep(i,1,n+2)rep(j,1,n+2)f[i][j]=0;
	f[1][1]=1;
	rep(i,2,n+1){
		if(!z[i]){
			LL t=1;
			rep(k,1,i){
				t=t*v2%MOD;
				f[i][1]+=f[i-1][k]*t%MOD;
			}
		}
		f[i][1]%=MOD;
		for(int j=i;j>=1;j--){
			if(z[i])f[i][j]+=f[i-1][j-1];
			else f[i][j]+=(f[i][j+1]+f[i-1][j])*v2%MOD;
			f[i][j]%=MOD;
		}
	}
	LL ans=n==1,t=1;
	rep(j,1,n){
		t=t*v2%MOD;
		ans+=f[n-1][j]*t%MOD;
	}
	printf("%d\n",int(ans%MOD));
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