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
const double PI=acos( -1. );
const LL MOD = 1000000007;

char p[33],q[33];
int vis[55][55];
	int n,m;
void bfs(int x,int y){
	if(x<0||x>=n)return;
	if(y<0||y>=m)return;
	if(vis[x][y])return;
	vis[x][y]=1;
	if(p[x]=='<')bfs(x,y-1);
	else bfs(x,y+1);
	if(q[y]=='^')bfs(x-1,y);
	else bfs(x+1,y);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	while(~scanf("%d%d",&n,&m)){
		scanf("%s%s",p,q);
		int fail=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++){
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j]=0;
			bfs(i,j);
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(vis[i][j]==0)fail=1;
		}
		if(fail)puts("NO");
		else puts("YES");
	}
	return 0;
}
