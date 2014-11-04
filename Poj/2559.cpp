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

int Z[100005];
PII S[100005];
int ns;
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,l,_T,n,m,Q;
	while(~scanf("%d",&n)&&n) {
		m=1;
		for(i=1; i<=n; i++)
			scanf("%d",&Z[i]);
		LL Ans=0;
		ns=0;
		S[++ns]=MP(0,0);
		Z[n+1]=0;
		for(i=1; i<=n+1; i++) {
			l=Z[i];
			while(S[ns].BB>l) {
				PII tp=S[ns--];
				int f=S[ns].AA+1;
				cmax(Ans,1LL*(i-f)*tp.BB);
			}
			S[++ns]=MP(i,l);
		}
		printf("%I64d\n",Ans);
	}
	return 0;
}
