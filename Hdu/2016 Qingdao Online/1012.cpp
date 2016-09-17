//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
bitset<99>lp[53][51][11];
bitset<99>rp[53][51][11];
int a[51];
void solve(){
	rep(i,0,53)rep(j,0,51)rep(k,0,11)lp[i][j][k].reset();
	rep(i,0,53)rep(j,0,51)rep(k,0,11)rp[i][j][k].reset();
	DRI(N);
	rep(i,1,N+1)RI(a[i]);
	lp[1][0][0].set(0);
	rep(i,1,N+1)rep(j,0,i)rep(k,0,11)if(lp[i][j][k].any()){
		lp[i+1][j][k]|=lp[i][j][k];
		if(!j)lp[i+1][i][k]|=lp[i][j][k];
		if(k<10&&a[i]<=87)
			lp[i+1][j][k+1]|=lp[i][j][k]<<a[i];
	}
	rp[N][0][0].set(87);
	repd(i,N,1)rep(j,0,N+1)rep(k,0,11)if(rp[i][j][k].any()){
		rp[i-1][j][k]|=rp[i][j][k];
		if(!j)rp[i-1][i][k]|=rp[i][j][k];
		if(k<10&&a[i]<=87)
			rp[i-1][j][k+1]|=rp[i][j][k]>>a[i];
	}
	DRI(Q);
	while(Q--){
		int a[3];
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		if(a[0]==a[1])a[0]=0;
		if(a[2]==a[1])a[2]=0;
		int ok=0;
		rep(k,0,11)
			ok|=(lp[a[1]][a[0]][k]&rp[a[1]][a[2]][10-k]).any();
		printf("%s\n",ok?"Yes":"No");
	}
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}