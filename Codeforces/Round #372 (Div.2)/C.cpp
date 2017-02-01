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
int f[MXN];
void solve(){
	for(LL i=1;i<=100000;i++){
		for(LL j=1LL*i*i;j<=100000;j+=i*i)
			f[j]=1LL*i*i;
	}
	int n;
	while(~scanf("%d",&n)){
		LL num=2;
		LL level=1;
		//real level*num
		while(level<=n){
			LL next = level+1;
			LL fn=next*next;
			LL w=level/f[level];
			LL less=num/fn/w;
			LL ms=sqrt(1.*less)-1;
			if(ms<0)ms=0;
			while(ms*ms<less)ms++;
			LL kmin=ms*ms*w-num/fn;
			while(num%fn!=0&&kmin==0){
				ms++;
				kmin=ms*ms*w-num/fn;
			}
			LL x=(kmin+num/fn)*fn-num;
			cout<<(long long)x<<"\n";
			num=(num+x)/fn*level;
			LL g=sqrt(num)-1;
			if(g<0)g=0;
			while(g*g<num)g++;
			assert(g*g==num);
			num=g;
			level++;
		}
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