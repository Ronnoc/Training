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
	if(~tp){
		tp=min(tp,w);
	}else tp=w;
}
int K[15],L[15];
int A[15][15];
int C[15][15];
int m,n;
LL ans;
int G[15];
void play(int mask,int cost,int has,LL att){
	if(has==8){
		cmax(ans,att);
		return;
	}
	if(__builtin_popcount(mask)+has<8)
		return;
	int id=-1;
	int add=-1;
	int ig=0;
	rep(i,0,n)if(mask>>i&1){
		int now=A[i][L[i]];
		int temp=0;
		rep(j,L[i]+1,K[i]){
			temp+=C[i][j-1];
			if(temp<=cost)
				now=A[i][j];
			else break;
		}
		G[ig++]=(-now);
		if(now>add)add=now,id=i;
	}
	sort(G,G+ig);
	LL best=0;
	rep(i,0,8-has)best-=G[i];
	if(best+att<ans)return;
	play(mask^(1<<id),cost,has+1,att+A[id][L[id]]);
	LL pay=0;
	rep(i,L[id]+1,K[id]){
		pay+=C[id][i-1];
		if(pay<=cost)
			play(mask^(1<<id),cost-pay,has+1,att+A[id][i]);
	}
	play(mask^(1<<id),cost,has,att);
}
void solve(){
	scanf("%d%d",&m,&n);
	rep(i,0,n){
		scanf("%d%d",&K[i],&L[i]);
		L[i]--;
		rep(j,0,K[i])
			scanf("%d",&A[i][j]);
		rep(j,1,K[i])
			scanf("%d",&C[i][j-1]);
	}
	ans=0;
	play((1<<n)-1,m,0,0);
	printf("%lld\n",ans);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d: ",CA+1);
		solve();
	}
	cerr<<"Used "<< (double)clock() / CLOCKS_PER_SEC <<" seconds\n";
	return 0;
}