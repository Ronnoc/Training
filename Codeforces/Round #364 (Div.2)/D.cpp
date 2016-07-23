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

void solve(){
	int n,l,p,q,k;
	scanf("%d%d%d%d%d",&n,&l,&p,&q,&k);
	double le=0,re=1.*l/p;
	rep(i,0,1000){
		double me=(le+re)/2;
		int m=n;
		double d=l;
		double t=0;
		int fail=0;
		while(m){
			if(t>me){
				fail=1;
				break;
			}
			double dt=(d-p*(me-t))/(q-p);
			t+=dt;
			d-=dt*p;
			m=max(0,m-k);
			if(t>me){
				fail=1;
				break;
			}
			if(m){
				dt=dt*(q-p)/(p+q);
				t+=dt;
				d-=dt*p;
			}
		}
		if(fail)le=me;
		else re=me;
	}
	printf("%.16f\n",(le+re)/2);
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}