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

int vis[200005];
int x[100005],y[100005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d%d",&x[i],&y[i]);
	if(1LL*n*(n-1)/2>=2*m)printf("YES\n");
	else {
		rep(i,0,2*m+1)vis[i]=0;
		rep(i,0,n)rep(j,i+1,n){
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			vis[abs(dx)+abs(dy)]++;
		}
		int flag=0;
		rep(i,0,2*m+1)flag|=vis[i]>1;
		printf("%s\n",flag?"YES":"NO");
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}