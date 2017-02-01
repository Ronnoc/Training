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
int ok[303][303];
int gd[303][303];
LL sum[303][303];
int key[303];
int val[303];
const int MXN = 100005;
int getok(int le,int re){
	if(re-le<=0)return ok[le][re]=0;
	int &tp=ok[le][re];
	if(~tp)return tp;
	tp=0;
	rep(i,le+1,re+1)if(gd[le][i]>1){
		int now=1;
		if(i-le>1)now&=getok(le+1,i-1);
		if(i<re)now&=getok(i+1,re);
		if(now){
			tp=1;break;
		}
	}
	return tp;
}
LL dp[303][303];
LL getdp(int le,int re){
	if(re-le<=0)return 0;
	if(getok(le,re))return dp[le][re]=sum[le][re];
	LL &tp=dp[le][re];
	if(~tp)return tp;
	tp=getdp(le+1,re);
	rep(i,le+1,re+1)if(getok(le,i)){
		LL temp=sum[le][i]+getdp(i+2,re);
		cmax(tp,temp);
	}
	//cout<<le<<"~"<<re<<" "<<tp<<"\n";
	return tp;
}
void solve(){
	DRI(n);
	rep(i,0,n)RI(key[i]);
	rep(i,0,n)RI(val[i]);
	rep(i,0,n)rep(j,i,n)ok[i][j]=dp[i][j]=-1,gd[i][j]=__gcd(key[i],key[j]);
	rep(i,0,n){
		sum[i][i]=val[i];
		rep(j,i+1,n)sum[i][j]=sum[i][j-1]+val[j];
	}
	cout<<getdp(0,n-1)<<"\n";
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