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

int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		vector<int>G[111];
		int tot[111];
		memset(tot,0,sizeof tot);
		while(m--){
			scanf("%d%d",&i,&j);
			G[j].PB(i);
			tot[i]++;
		}
		queue<int>Q;
		for(i=1;i<=n;i++)if(!tot[i])Q.push(i);
		int cnt=0;
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(i=0;i<G[u].SZ;i++){
				int v=G[u][i];
				tot[v]--;
				if(tot[v]==0)
					Q.push(v);
			}
			cnt++;
		}
		printf("%s\n",cnt==n?"YES":"NO");
	}
	return 0;
}
