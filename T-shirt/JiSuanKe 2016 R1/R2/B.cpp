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
int f(int a,int b,int c,int la){
	if(a<0||b<0||c<0)return -1;
	if(a&&b&&c&&la!=2)
		return f(a-1,b-1,c-1,2)+1;
	if(a>=b&&a>=2&&b>=1&&la!=0)
		return f(a-2,b-1,c,0)+1;
	if(b>=a&&a>=1&&b>=2&&la!=1)
		return f(a-1,b-2,c,1)+1;
	if(a>=2&&b>=1&&la!=0)
		return f(a-2,b-1,c,0)+1;
	if(a>=1&&b>=2&&la!=1)
		return f(a-1,b-2,c,1)+1;
	return 0;
}
void solve(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ret=0;
	ret=max(ret,f(a-2,b-1,c,0)+1);
	ret=max(ret,f(a-1,b-2,c,1)+1);
	ret=max(ret,f(a-1,b-1,c-1,2)+1);
	printf("%d\n",ret);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		solve();
	}
	return 0;
}