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
	int a,p,q;
	while(~scanf("%d%d%d",&a,&p,&q)){
		if(a==0)printf("%.10f\n",0.0);
        else if(p>q){
            double ans=1.*a*p/(p+q)/(p-q);
            printf("%.10f\n",ans);
        }else printf("Infinity\n");
		/*double dt=1e-6,t=0;
		double x=0,y=a;
		while(t<1e2){
			double dl=sqrt(x*x+y*y);
			if(dl<=(p+q)*dt)break;
			double dx=(-x*p/dl+q)*dt;
			double dy=(-y*p/dl)*dt;
			x+=dx;y+=dy;t+=dt;
		}
		printf("%.10f\n",t);*/
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