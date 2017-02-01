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
VI G[MXN];
int n,m,q;
int c[MXN];
int I[MXN],J[MXN];
int ans[MXN];
bitset<1024>a[1024];
void dfs(int t,int fa){
	bitset<1024>temp;
	if(c[t]==1){
		temp=a[I[t]];
		a[I[t]].set(J[t]);
		ans[t]+=temp[J[t]]==0;
	}
	if(c[t]==2){
		temp=a[I[t]];
		a[I[t]].reset(J[t]);
		ans[t]-=temp[J[t]]==1;
	}
	if(c[t]==3){
		temp=a[I[t]];
		rep(i,1,m+1){
			a[I[t]].flip(i);
			if(temp[i])ans[t]--;
			else ans[t]++;
		}
	}
	rep(i,0,sz(G[t])){
		ans[G[t][i]]=ans[t];
		dfs(G[t][i],t);
	}
	if(c[t]<=3)
		a[I[t]]=temp;
}
void solve(){
	scanf("%d%d%d",&n,&m,&q);
	int la=0;
	rep(i,1,n+1)a[i].reset();
	rep(i,1,q+1){
		RI(c[i]);
		if(c[i]<=2){RI(I[i]);RI(J[i]);}
		else RI(I[i]);
		if(c[i]==4)la=I[i];
		G[la].PB(i);
		la=i;
	}
	dfs(0,0);
	rep(i,1,q+1)cout<<ans[i]<<"\n";
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