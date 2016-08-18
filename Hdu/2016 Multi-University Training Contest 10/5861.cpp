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
const int MXN = 200005;
VI L[MXN],R[MXN];
int w[MXN];
int lid[MXN],rid[MXN];
void solve(){
	set<int>S;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		rep(i,0,n+1)L[i].clear(),R[i].clear();
		rep(i,2,n+1)RI(w[i]);
		rep(i,1,m+1){
			DRI(p);DRI(q);
			if(p>q)swap(p,q);
			L[p].PB(i);
			R[q].PB(i);
		}
		S.clear();
		rep(j,0,sz(L[1]))S.insert(L[1][j]);
		LL ans=0;
		rep(i,2,n+1){
			if(!S.empty()){
				lid[i]=*S.OP;
				rid[i]=*(--S.ED);
			}else lid[i]=rid[i]=0;
			rep(j,0,sz(R[i]))S.erase(R[i][j]);
			rep(j,0,sz(L[i]))S.insert(L[i][j]);
		}
		rep(i,0,m+1)L[i].clear(),R[i].clear();
		rep(i,2,n+1){
			L[lid[i]].PB(i);
			R[rid[i]].PB(i);
		}
		int tot=0;
		rep(i,1,m+1){
			rep(j,0,sz(L[i]))tot+=w[L[i][j]];
			printf("%d\n",tot);
			rep(j,0,sz(R[i]))tot-=w[R[i][j]];
		}
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