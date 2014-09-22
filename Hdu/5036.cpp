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

bitset<1024>G[1025];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T,CA,n;
	for(scanf("%d",&T),CA=1;CA<=T;CA++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			G[i].reset();
			G[i].set(i,1);
			int m;
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d",&k);
				G[i].set(k,1);
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				if(G[i][k])G[i]|=G[k];
		double ans=0;
		for(i=1;i<=n;i++){
			int cnt=0;
			for(j=1;j<=n;j++)if(G[j][i])cnt++;
			ans+=1./cnt;
		}
		printf("Case #%d: %.5f\n",CA,ans);
	}
	return 0;
}
