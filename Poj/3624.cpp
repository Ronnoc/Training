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

int v[15000];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<=m;i++)v[i]=0;
		for(i=0;i<n;i++){
			int s,w;
			scanf("%d%d",&s,&w);
			for(j=m-s;j>=0;j--)
				cmax(v[j+s],v[j]+w);
		}
		int ans=0;
		for(i=0;i<=m;i++)cmax(ans,v[i]);
		printf("%d\n",ans);
	}
	return 0;
}

