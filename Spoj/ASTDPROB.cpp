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

int Ans[1005][1005];
int Z[1005][1005];
PII S[1005];
int last[1005][1005];
int ns;
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,l,_T,n,m,Q;
	while(~scanf("%d%d",&n,&m)) {
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				scanf("%d",&Z[i][j]);
		for(i=1; i<=n; i++)
			for(j=i; j<=n+1; j++)
				Ans[i][j]=0;//[,)
		for(i=1; i<=n; i++) {
			last[i][0]=0;
			for(j=1; j<=m; j++) {
				last[i][j]=last[i][j-1];
				if(Z[i][j])last[i][j]=j;
			}
			for(j=0; j<=m; j++)
				last[i][j]=j-last[i][j];
		}
		for(j=1; j<=m; j++) {
			ns=0;
			S[++ns]=MP(0,0);
			last[n+1][i]=0;
			for(i=1; i<=n+1; i++) {
				l=last[i][j];
				while(S[ns].BB>l) {
					PII tp=S[ns--];
					int f=S[ns].AA+1;
					cmax(Ans[f][i],tp.BB);
				}
				S[++ns]=MP(i,l);
			}
		}
		for(l=n-1; l>=1; l--) {
			for(i=1; i+l<=n; i++)
				cmax(Ans[i][i+l],Ans[i][i+l+1]);
			for(i=2; i+l<=n+1; i++)
				cmax(Ans[i][i+l],Ans[i-1][i+l]);
		}
		for(i=1; i<=n; i++)
			for(l=1; i+l<=n+1; l++)
				Ans[i][i+l]*=l;
		for(l=2; l<=n; l++)
			for(i=1; i+l<=n+1; i++)
				cmax(Ans[i][i+l],Ans[i][i+l-1]),
						 cmax(Ans[i][i+l],Ans[i+1][i+l]);
		scanf("%d",&Q);
		while(Q--) {
			scanf("%d%d",&i,&j);
			printf("%d\n",Ans[i][j+1]);
		}
	}
	return 0;
}
