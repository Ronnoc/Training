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

const int MXN = 200005;
int a[MXN];
int d[MXN];
vector<int>G[MXN];
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1)G[i].clear();
	rep(i,1,n+1)G[a[i]].push_back(i);
	multiset<int>S;
	d[1]=0;
	S.insert(d[1]+1+a[1]);
	for(auto f:G[1])
		S.erase(S.find(d[f]+1+a[f]));
	rep(i,2,n+1){
		d[i]=d[i-1]+1;
		if(!S.empty()){
			int w=(*S.OP)-i;
			cmin(d[i],w);
		}
		S.insert(d[i]+1+a[i]);
		for(auto f:G[i])
			S.erase(S.find(d[f]+1+a[f]));
	}
	rep(i,1,n+1)printf("%d ",d[i]);
	printf("\n");
}
int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}