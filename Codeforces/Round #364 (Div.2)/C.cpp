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

char s[100005];
stack<int>S[55];
void solve(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n){
		if(islower(s[i]))S[ s[i]-'a' ].push(i);
		if(isupper(s[i]))S[ s[i]-'A'+26 ].push(i);
	}
	vector<int>L;
	rep(i,0,52)if(!S[i].empty())L.PB(i);
	int ans=n;
	for(int i=n-1;i>=0;i--){
		int le=i,re=i;
		int fail=0;
		for(auto id:L){
			if(S[id].empty())
				fail=1;
			else {
				cmin(le,S[id].top());
				if(S[id].top()==re)
					S[id].pop();
			}
		}
		if(fail)break;
		cmin(ans,re-le+1);
	}
	printf("%d\n",ans);
}

int main(){
	int _T=1;
	rep(CA,0,_T){
		solve();
	}
	return 0;
}