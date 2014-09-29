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
int G[1000005];
int F[1000005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=m;i++)G[i]=-1;
		for(i=1;i<=n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u<1)u=1;
			if(v>m)v=m;
			cmax(G[u],v);
		}
		F[1]=G[1];
		for(i=2;i<=m;i++)F[i]=max(F[i-1],G[i]);
		int ans=0;
		int where=0;
		int fail=0;
		while(where<m){
			int next=F[where+1];
			if(next<where+1){fail=1;break;}
			where=next;
			ans++;
		}
		if(!fail)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
