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

int L[105];
void solve(){
	int n;
	scanf("%d",&n);
	rep(i,0,n+1)scanf("%d",&L[i]);
	long double le=.5,re=1e9;
	rep(i,0,1000000){
		long double me=(le+re)/2;
		long double S=0;
		long double mul=me;
		rep(i,1,n+1){
			S+=L[i]*mul;
			mul*=me;
		}
		if(S>L[0])re=me;
		else le=me;
	}
	double ge=(le+re)/2;
	double ans=1/ge-1;
	printf("%.16f\n",ans);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}