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

int w[505];
int e[505];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(e,-1,sizeof e);
		for(i=1;i<=n;i++)scanf("%d",&w[i]);
		LL ans=0;
		while(m--){
			scanf("%d",&k);
			if(~e[k]){
				for(i=1;i<=n;i++)if(~e[i]&&e[i]<e[k])
					ans+=w[i],e[i]++;
				e[k]=1;
			}else {
				for(i=1;i<=n;i++)if(~e[i])
					ans+=w[i],e[i]++;
				e[k]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
