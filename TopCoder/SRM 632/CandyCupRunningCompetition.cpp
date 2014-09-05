#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size() 
#define SORT(p) sort(p.OP,p.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000007;

int vis[2005];
LL threes[2005];
int fa[2005];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
class CandyCupRunningCompetition {
public:
  int findMaximum (int N, vector <int> A, vector <int> B) {
    int ret=0;
    int i,j;
    threes[0]=1;
    for(i=1;i<=2000;i++)threes[i]=threes[i-1]*3%MOD;
    for(i=0;i<N;i++)fa[i]=i;
    memset(vis,0,sizeof vis);
    for(i=A.SZ-1;i>=0;i--){
			int u=A[i],v=B[i];
			int fu=getfa(u),fv=getfa(v);
			int flag=0;
			if(fu==getfa(0)&&fv==getfa(N-1))flag=1;
			if(fv==getfa(0)&&fu==getfa(N-1))flag=1;
			if(flag)vis[i]=1;
			else fa[fu]=fv;
    }
    for(i=0;i<A.SZ;i++)if(vis[i])ret=(ret+threes[i])%MOD;
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
