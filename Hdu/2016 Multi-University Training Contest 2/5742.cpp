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

int w[105];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)w[i]=-1;
	rep(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);
		w[x]=y;
	}
	if(~w[1]);else w[1]=100;
	if(~w[2]);else w[2]=w[1];
	if(~w[n]);else w[n]=0;
	for(int i=n-1;i>=1;i--){
		if(~w[i]);else w[i]=w[i+1];
	}
	int p=w[1]+w[2],q=accumulate(w+1,w+n+1,0);
	int g=__gcd(p,q);
	p/=g,q/=g;
	printf("%d/%d\n",p,q);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}