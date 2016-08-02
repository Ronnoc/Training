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

int dig[21],ndig;		//ndig=max{i}:dig[i]!=0
LL f[21][7][12005];
int ok[7][12005][11];
vector<PII>LV;
LL dfs(int id,int mask,int K,int even=1,int first=1){	//dfs(ndig,startMask,aim)
	//cout<<id<<" "<<LV[mask].AA<<" "<<LV[mask].BB<<" "<<K<<" "<<even<<" "<<first<<"\n";
	if(id==-1)return 1-first;
	if(!even&&~f[id][K][mask])return f[id][K][mask];
	LL ret=0;
	if(even)if(~ok[K][mask][dig[id]])ret+=dfs(id-1,ok[K][mask][dig[id]],K,1,0);
	if(first)ret+=dfs(id-1,mask,K,0,1);
	int u=even?dig[id]-1:9;
	for(int i=first?1:0;i<=u;i++)if(~ok[K][mask][i])
		ret+=dfs(id-1,ok[K][mask][i],K,0,0);
	return even?ret:f[id][K][mask]=ret;
}
LL play(LL re,int K){
	ndig=0;
	while(re){dig[ndig++]=re%10;re/=10;}
	return dfs(--ndig,0,K);
}
const int MXN = 100005;
void solve(){
	memset(ok,-1,sizeof ok);
	rep(l,0,5){
		int up=1;
		rep(j,0,l)up*=10;
		rep(j,0,up)LV.PB(MP(l,j));
	}
	sort(all(LV));
	rep(K,2,6)rep(i,0,sz(LV))rep(j,0,10){
		int mask=LV[i].BB;
		int len=LV[i].AA;
		VI Z;
		Z.PB(j);
		while(len--){Z.PB(mask%10);mask/=10;}
		while(sz(Z)>K)Z.pop_back();
		int fail=0;
		rep(u,0,sz(Z))rep(v,u+1,sz(Z))
			fail|=Z[u]==Z[v];
		if(sz(Z)==K)Z.pop_back();
		if(!fail){
			int sum=0;
			reverse(all(Z));
			rep(u,0,sz(Z))sum=sum*10+Z[u];
			int nxt=lower_bound(all(LV),MP(sz(Z),sum))-LV.OP;
			ok[K][i][j]=nxt;
		}
	}
	LL L,R;
	memset(f,-1,sizeof f);
	int K;
	while(cin>>L>>R>>K){
		LL ans=play(R,K)-play(L-1,K);
		cout<<ans<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}