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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

int fa[30005];
int pre[30005];
int sz[30005];
int getfa(int u) {
	if(u==fa[u])return u;
	int v=getfa(fa[u]);
	if(fa[u]!=v)
		pre[u]+=pre[fa[u]];
	return fa[u]=v;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	int n=30000,m;
	while(~scanf("%d",&m)) {
		for(i=1; i<=n; i++)fa[i]=i,pre[i]=0,sz[i]=1;
		while(m--) {
			char s[5];
			int X,Y;
			scanf("%s%d",s,&X);
			if(s[0]=='M') {
				scanf("%d",&Y);
				int fx=getfa(X);
				int fy=getfa(Y);
				pre[fx]+=sz[fy];
				sz[fy]+=sz[fx];
				fa[fx]=fy;
			} else {
				getfa(X);
				printf("%d\n",pre[X]);
			}
		}
	}
	return 0;
}
/*
9
M 1 2
M 2 3
M 1 4
M 2 5
C 1
C 2
C 3
C 4
C 5
*/
