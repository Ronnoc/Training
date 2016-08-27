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
inline int LB(int x) {return x & (-x);}
LL bit[2005][2005];
vector<pair<PII,int> >L[2005];
int f[2005];
void update(int x,int y,LL w){
	for(int p=x+2;p<2005;p+=LB(p))
		for(int q=y+2;q<2005;q+=LB(q))
			bit[p][q]+=w;
}
LL query(int x,int y){
	LL ret=0;
	for(int p=x+2;p>0;p-=LB(p))
		for(int q=y+2;q>0;q-=LB(q))
			ret+=bit[p][q];
	return ret;
}
int ask[2005][2005];
LL ans[2005];
vector<pair<PII,PII> >Q;
void solve(){
	memset(bit,0,sizeof bit);
	int n,m,k;
	RI(n);RI(m);RI(k);
	rep(i,1,k+1){
		f[i]=1;
		L[i].clear();
		DRI(len);
		while(len--){
			int u,v,w;
			RI(u);RI(v);RI(w);
			L[i].PB(MP(MP(u,v),w));
		}
	}
	int nz=0;
	DRI(q);while(q--){
		char s[10];
		scanf("%s",s);
		if(s[0]=='A'){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			Q.PB(MP(MP(a,b),MP(c,d)));
			rep(i,1,k+1)ask[nz][i]=f[i];
			nz++;
		}
		if(s[0]=='S'){
			DRI(id);
			f[id]^=1;
		}
	}
	memset(ans,0,sizeof ans);
	rep(i,1,k+1){
		rep(j,0,sz(L[i]))
			update(L[i][j].AA.AA,L[i][j].AA.BB,L[i][j].BB);
		rep(j,0,nz)if(ask[j][i]){
			int a=Q[j].AA.AA-1;
			int b=Q[j].AA.BB-1;
			int c=Q[j].BB.AA;
			int d=Q[j].BB.BB;
			ans[j]+=query(c,d)+query(a,b)-query(a,d)-query(c,b);
		}
		rep(j,0,sz(L[i]))
			update(L[i][j].AA.AA,L[i][j].AA.BB,-L[i][j].BB);
	}
	rep(i,0,nz)cout<<ans[i]<<"\n";
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