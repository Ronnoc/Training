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
const int MXN = 1000005;
char q[5];
set<int>S;
int mu[MXN], p[MXN], pn,pre[MXN];
bool flag[MXN];	//true为合数
//for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
void sieve(int n) {
	pn = 0;
	mu[1] = 0;
	pre[1]=1;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
			mu[i] = 1;						//phi[i]=i-1;
			pre[i]=i;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			pre[i*p[j]]=p[j];
			mu[i * p[j]] = mu[i]+1;
			if (i % p[j] == 0) break;
		}
	}
}
VI play(int w){
	map<int,int>F;
	while(w>1){
		F[pre[w]]++;
		w/=pre[w];
	}
	VPII R(F.OP,F.ED);
	VI ret[2];
	ret[0].PB(1);
	int x=0,y=1;
	rep(i,0,sz(R)){
		ret[y].clear();
		rep(t,0,sz(ret[x])){
			int mul=1;
			rep(k,0,R[i].BB+1){
				ret[y].PB(ret[x][t]*mul);
				mul*=R[i].AA;
			}
		}
		swap(x,y);
	}
	return ret[x];
}
int X[MXN][20],mask[MXN];
void solve(){
	int *g=mu;
	int CA=0,Q;
	while(~scanf("%d",&Q)){
		if(!Q)break;
		printf("Case #%d:\n",++CA);
		while(Q--){
			scanf("%s",q);DRI(w);
			if(q[0]=='I'){
				if(!S.count(w)){
					S.insert(w);
					VI L=play(w);
					rep(i,0,sz(L)){
						int t=L[i];
						X[t][g[w]-g[t]]++;
						mask[t]|=1<<(g[w/t]);
					}
				}
			}
			if(q[0]=='D'){
				if(S.count(w)){
					S.erase(w);
					VI L=play(w);
					rep(i,0,sz(L)){
						int t=L[i];
						X[t][g[w]-g[t]]--;
						if(!X[t][g[w]-g[t]])mask[t]^=1<<(g[w/t]);
					}
				}
			}
			if(q[0]=='Q'){
				int ans=-1;
				if(!S.empty()){
					ans=1000;
					VI L=play(w);
					rep(i,0,sz(L)){
						int t=L[i];
						int add=__builtin_ctz(mask[t]);
						if(mask[t])cmin(ans,g[w/t]+add);
					}
				}
				printf("%d\n",ans);
			}
		}
		for(set<int>::iterator it=S.OP;it!=S.ED;++it){
			int w=*it;
			VI L=play(w);
			rep(i,0,sz(L)){
				int t=L[i];
				while(mask[t]){
					int la=__builtin_ctz(mask[t]);
					X[t][la]=0;
					mask[t]^=1<<la;
				}
			}
		}
		S.clear();
	}
}

int main(){
	sieve(1000000);
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}