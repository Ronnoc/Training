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

char s[][33]={"Baltimore Bullets","Boston Celtics","Chicago Bulls","Cleveland Cavaliers","Dallas Mavericks","Detroit Pistons","Golden State Warriors","Houston Rockets","L.A. Lakers","Miami Heat","Milwaukee Bucks","Minneapolis Lakers","New York Knicks","Philadelphia 76ers","Philadelphia Warriors","Portland Trail Blazers","Rochester Royals","San Antonio Spurs","Seattle Sonics","St. Louis Hawks","Syracuse Nats","Washington Bullets"};
int t[]={1,17,6,1,1,3,2,2,11,3,1,5,2,2,2,1,1,5,1,1,1,1,0};
const int MXN = 100005;
char ss[MXN];
void solve(){
	gets(ss);
	rep(i,0,1000){
		if(!t[i])break;
		if(strcmp(s[i],ss)==0){
			printf("%d\n",t[i]);
			return;
		}
	}
	printf("%d\n",0);
	return;
}

int main(){
	int _T=1;
	scanf("%d%*c",&_T);
	rep(CA,0,_T){
		printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}