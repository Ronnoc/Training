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
struct BIT {
	LL c[50010];
	int n;
	void init ( int m ) {
		n=m+5;
		for ( int i=0; i<=n; i++ )
			c[i]=0;
	}
	void add ( int t,LL k=1 ) {
		t+=5;
		while ( t<=n ) {
			c[t]+=k;
			t+=t&-t;
		}
	}
	LL sum ( int t ) {
		LL ret=0;
		t+=5;
		while ( t>0 ) {
			ret+=c[t];
			t-=t&-t;
		}
		return ret;
	}
}V;
int w[59999];
int ls[59999];
int lb[59999];
int rs[59999];
int rb[59999];
LL SS[59999];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		int n;
		scanf("%d",&n);
		V.init(n+2);
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(i=1;i<=n;i++){
			ls[i]=V.sum(w[i]);
			V.add(w[i]);
		}
		for(i=1;i<=n;i++){
			lb[i]=i-1-ls[i];
			rb[i]=n-w[i]-lb[i];
			rs[i]=w[i]-1-ls[i];
		}
		SS[n+1]=0;
		for(i=n;i>=1;i--)
			SS[i]=SS[i+1]+rb[i];
		LL ans=0;
		for(i=1;i<=n;i++)
			ans+=ls[i]*SS[i+1];
		cout<<ans<<"\n";
	}
	return 0;
}
