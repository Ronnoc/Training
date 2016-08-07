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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
int c[MXN];
int v[MXN];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&c[i]),v[i]=0;;
	rep(i,0,k){
		int t;
		scanf("%d",&t);
		v[t-1]=1;
	}
	LL sum=0;
	rep(i,0,n)sum+=v[i]*c[i];
	LL all=0;
	rep(i,0,n)all+=c[i];
	LL ans=0;
	rep(i,0,n)
		if(v[i])ans+=c[i]*(all-c[i]);
		else ans+=c[i]*sum;
	rep(i,0,n)if(!v[i]&&!v[(i+1)%n])
		ans+=2LL*c[i]*c[(i+1)%n];
	ans/=2;
	cout<<ans<<"\n";
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}