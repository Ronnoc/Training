#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
  int(X);      \
  scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a, LL b, LL MOD)
{
  LL ret = 1;
  for (; b; b >>= 1)
  {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

int fa[105];
int getfa(int u){
	return fa[u]==u?u:fa[u]=getfa(fa[u]);
}

int n;

int C[105];

VI WW;
VI CC;
VI UU;

bool dfs(int finishCnt,int targetCnt,int targetSum,int curSum,int last){
	// cerr<<finishCnt<<","<<targetCnt<<","<<targetSum<<","<<curSum<<endl;
	if(finishCnt==targetCnt)return true;
	if(curSum==targetSum)return dfs(finishCnt+1,targetCnt,targetSum,0,targetSum);
	rep(i,0,CC.SZ)if(UU[i]<CC[i] && WW[i]<=last){
		UU[i]++;
		if(dfs(finishCnt,targetCnt,targetSum,curSum+WW[i],WW[i])){
			return true;
		}
		else{
			UU[i]--;
			if(curSum==0)
				return false;
		}
	}
	return false;
}

void solve(){
	RI(n);
	DRI(m);
	cerr<<"n="<<n<<" m="<<m<<endl;
	rep(i,1,n+1)fa[i]=i;
	rep(_,0,m){
		DRI(p);DRI(q);
		fa[getfa(p)]=getfa(q);
	}
	map<int,int>Z;
	rep(i,1,n+1)Z[getfa(i)]++;

	rep(i,1,n+1)C[i]=0;
	for(auto pr:Z)C[pr.second]++;

	CC.clear();
	WW.clear();
	for(int i=n;i>=1;i--)
		if(C[i])WW.PB(i),CC.PB(C[i]);

	vector<int>ans;
	rep(i,1,n+1)if(n%i==0){
		// cerr<<"?"<<i<<endl;
		UU.clear();
		UU.resize(CC.SZ);
		rep(_,0,UU.SZ)UU[_]=0;
		if(dfs(0,i,n/i,0,n/i))ans.PB(i);
	}

	for(auto x:ans)printf(" %d",x);
	printf("\n");
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d:", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}