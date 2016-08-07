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
int a[MXN];
LL g[77][77];
int c[77];
int MASK;
LL temp;
void dfs(int id,LL now,int mask){
	if(id<0){
		if(now<temp){
			temp=now;
			MASK=mask;
		}
		return;
	}
	rep(i,0,2){
		c[id]=i;
		LL add=0;
		rep(j,id+1,20){
			if(c[j]^c[id])add-=g[j][id];
			else add+=g[j][id];
		}
		dfs(id-1,now+add,mask|(c[id]<<id));
	}
}
void solve(){
	int Z=20;
	DRI(n);
	rep(i,0,n)RI(a[i]);
	rep(i,0,Z)c[i]=0;
	rep(i,0,Z)rep(j,0,Z)g[i][j]=0;
	rep(i,1,n){
		repd(k,Z-1,0)if((a[i-1]^a[i])>>k&1){
			repd(j,k-1,0)if((a[i]^a[i-1])>>j&1){
				if((a[i]>>k&1)==(a[i]>>j&1))g[k][j]+=2<<j;
				else g[k][j]-=2<<j;
			}
			break;
		}
	}
	temp=MASK=0;
	dfs(Z-1,0,0);
	LL ans=0;
	rep(i,0,n)a[i]^=MASK;
	rep(i,1,n)ans+=fabs(a[i]-a[i-1]);
	cout<<MASK<<" "<<ans<<"\n";
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}