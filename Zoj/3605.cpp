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
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
double dp[55][55][55];
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--) {
		memset(dp,0,sizeof dp);
		int s,n,o,m;
		scanf("%d%d%d%d",&n,&m,&o,&s);
		dp[0][0][s]=1;
		for(i=0; i<m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			for(j=max(o+i-m,0); j<=i&&j<=o; j++) {
				double mis,see;
				if(j+m==o+i)mis=0,see=1;
				else if(j==o)mis=1,see=0;
				else mis=1.*(m-i-o+j)/(m-i),see=1.*(o-j)/(m-i);
				for(k=1; k<=n; k++)dp[i+1][j][k]+=dp[i][j][k]*mis;
				for(k=1; k<=n; k++)dp[i+1][j+1][k]+=dp[i][j][k]*see;
				if(u!=v) {
					dp[i+1][j+1][u]-=dp[i][j][u]*see;
					dp[i+1][j+1][v]-=dp[i][j][v]*see;
					dp[i+1][j+1][u]+=dp[i][j][v]*see;
					dp[i+1][j+1][v]+=dp[i][j][u]*see;
				}
			}
		}
		double pp=-100;
		int id=-1;
		for(i=1; i<=n; i++)if(dp[m][o][i]>pp+1e-8)
				pp=dp[m][o][i],id=i;
		printf("%d\n",id);
	}
	return 0;
}
/*
1
3 5 1 1
1 1
1 1
1 2
1 3
1 3
*/
