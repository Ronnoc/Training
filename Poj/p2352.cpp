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
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const int MXN=32222;
int BIT[MXN+10];
int LB( int w ) {return w&( -w );}
int bitsum( int *BIT,int w ) {
	int ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret+=BIT[w];
	return ret;
}
void bitadd( int *BIT,int w,int d ) {
	for ( w+=5; w<MXN; w+=LB( w ) )BIT[w]+=d;
}
int ans[MXN];
int main() {
	int i,j,p,q;
	int n;
	while(~scanf("%d",&n)){
		vector<PII>L;
		memset(BIT,0,sizeof BIT);
		memset(ans,0,sizeof ans);
		for(i=1;i<=n;i++){
			scanf("%d%d",&p,&q);
			L.PB(MP(p,q));
		}
		SORT(L);
		for(i=0;i<L.SZ;i++){
			ans[bitsum(BIT,L[i].BB)]++;
			bitadd(BIT,L[i].BB,1);
		}
		for(i=0;i<n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
