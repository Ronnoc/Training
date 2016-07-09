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
char s[5][5]={"123","456","789"," 0 "};
bool valid(int x,int y){
	if(x<0||x>=4)return 0;
	if(y<0||y>=3)return 0;
	return isdigit(s[x][y]);
}
void solve(){
	int n;
	cin>>n;
	string ss;
	cin>>ss;
	vector<PII>L;
	for(auto c:ss){
		rep(i,0,4)rep(j,0,3)if(s[i][j]==c)
			L.PB(MP(i,j));
	}
	rep(i,0,4)rep(j,0,3)if(isdigit(s[i][j])){
		int dx=i-L[0].AA,dy=j-L[0].BB;
		if(dx||dy){
			int fail=0;
			rep(i,1,sz(L))
				if(!valid(L[i].AA+dx,L[i].BB+dy))
					fail=1;
			if(!fail){
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}