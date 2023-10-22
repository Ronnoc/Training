#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <unordered_set>
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

int fa[3005*3005];
int sz[3005*3005];
int qi[3005*3005];
int getfa(int u){
	if(fa[u]==u)return u;
	return fa[u]=getfa(fa[u]);
}

int tid[3005][3005];
char S[3005][3005];

void solve(){
	DRI(R);
	DRI(C);

	rep(i,0,R)scanf("%s",S[i]);
	int tot = 0;
	rep(i,0,R)rep(j,0,C) tid[i][j] = tot++;
	rep(i,0,tot)fa[i]=i, qi[i]=0, sz[i]=0;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	rep(i,0,R)rep(j,0,C)if(S[i][j] == 'W'){
		int u = tid[i][j];
		rep(_,0,4){
			int nx = i + dx[_];
			int ny = j + dy[_];
			if(0<=nx&&nx<R)
				if(0<=ny&&ny<C){
					if(S[nx][ny] == 'W'){
						int v = tid[nx][ny];
						int fu = getfa(u);
						int fv = getfa(v);
						fa[fu]=fv;
					}
				}
		}
	}
	rep(i,0,R)rep(j,0,C)if(S[i][j] == 'W'){
		int u = tid[i][j];
		int fu = getfa(u);
		sz[fu]++;
	}
	rep(i,0,R)rep(j,0,C)if(S[i][j] == '.'){
		set<int>neib;
		rep(_,0,4){
			int nx = i + dx[_];
			int ny = j + dy[_];
			if(0<=nx&&nx<R)
				if(0<=ny&&ny<C){
					if(S[nx][ny] == 'W'){
						int v = tid[nx][ny];
						int fv = getfa(v);
						neib.insert(fv);
					}
				}
		}
		for(auto fv:neib)
			qi[fv]++;
	}

	int mx_kill = 0;
	rep(i,0,R)rep(j,0,C)if(S[i][j] == '.'){
		set<int>neib;
		rep(_,0,4){
			int nx = i + dx[_];
			int ny = j + dy[_];
			if(0<=nx&&nx<R)
				if(0<=ny&&ny<C){
					if(S[nx][ny] == 'W'){
						int v = tid[nx][ny];
						int fv = getfa(v);
						neib.insert(fv);
					}
				}
		}
		int kill_cnt = 0;
		for(auto fv:neib)if(qi[fv] == 1)
			kill_cnt += sz[fv];
		cmax(mx_kill, kill_cnt);
	}
	printf(" %d\n",mx_kill);
	// if(mx_kill > 0){
	// 	printf("YES\n");
	// }else {
	// 	printf("NO\n");
	// }

	// rep(i,0,R){
	// 	rep(j,0,C)cout<<tid[i][j]<<" ";
	// 	cout<<endl;
	// }
	// rep(i,0,R){
	// 	rep(j,0,C)cout<<getfa(tid[i][j])<<" ";
	// 	cout<<endl;
	// }
	// rep(i,0,R){
	// 	rep(j,0,C)cout<<sz[getfa(tid[i][j])]<<" ";
	// 	cout<<endl;
	// }
	// rep(i,0,R){
	// 	rep(j,0,C)cout<<qi[getfa(tid[i][j])]<<" ";
	// 	cout<<endl;
	// }

}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
  }
  fflush(stdout);
  return 0;
}