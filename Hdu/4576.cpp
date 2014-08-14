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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const LL MOD = 1000000007;
double dp[2][222];
int main() {
	int i,j;
	int n,m,l,r;
	while(~scanf("%d%d%d%d",&n,&m,&l,&r)){
		if(!n&&!m&&!l&&!r)break;
		l--;r--;
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		int x=0,y=1;
		while(m--){
			int w;
			scanf("%d",&w);
			for(i=0;i<n;i++)dp[y][i]=0;
			for(i=0;i<n;i++)if(dp[x][i]>1e-16){
				dp[y][(i+w)%n]+=dp[x][i]/2;
				dp[y][(i-w+n)%n]+=dp[x][i]/2;
			}
			swap(x,y);
		}
		double ans=0;
		for(i=l;i<=r;i++)ans+=dp[x][i];
		printf("%.4f\n",ans);
	}
	return 0;
}
