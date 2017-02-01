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
int check(int x,int d){
	if(d==1)return x>=1900;
	else return x<1900;
}
void solve(){
	int n;
	while(cin>>n){
		VPII L;
		rep(i,0,n){
			int c,d;
			cin>>c>>d;
			L.PB(MP(c,d));
		}
		int x = 1000000000;
		int isinf = 1;
		rep(i,0,n){
			int c = L[i].AA,d=L[i].BB;
			isinf&=check(x,d);
			x+=c;
		}
		if(isinf){
			cout<<"Infinity\n";
			continue;
		}
		int le = -1000000000;
		int re = 1000000000;
		int dif = 0;
		rep(i,0,n){
			int c = L[i].AA,d=L[i].BB;
			if(d==1)cmax(le,1900-dif);
			if(d==2)cmin(re,1900-dif);
			dif+=c;
		}
		if(le<re){
			cout<<re-1+dif<<"\n";
		}else cout<<"Impossible\n";
	}
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