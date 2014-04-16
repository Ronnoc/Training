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
const int MXN=500555;
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
int a[500555];
int main(){
	int i,j;
	int n;
	while(~scanf("%d",&n)&&n){
		memset(BIT,0,sizeof BIT);
		LL ans=1LL*n*(n-1)/2;
		vector<int>L;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)L.PB(a[i]);
		SORT(L);
		for(i=1;i<=n;i++){
			j=lower_bound(L.OP,L.ED,a[i])-L.OP;
			ans-=bitsum(BIT,j-1);
			bitadd(BIT,j,1);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
