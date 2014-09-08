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
const LL MOD = 123456789;
struct BIT {
	LL _c[10010];
	int _n;
	void init ( int m ) {
		_n=m+5;
		for ( int i=0; i<=_n; i++ )
			_c[i]=0;
	}
	void add ( int t,LL k=1 ) {
		t+=5;
		while ( t<=_n ) {
			_c[t]=(_c[t]+k)%MOD;
			t+=t&-t;
		}
	}
	LL sum ( int t ) {
		LL ret=0;
		t+=5;
		while ( t>0 ) {
			ret+=_c[t];
			t-=t&-t;
		}
		return ret%MOD;
	}
}T[105];
int a[10005];
int b[10005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			b[i]=a[i+1];
		sort(b,b+n);
		int nb=unique(b,b+n)-b;
		for(i=0;i<=m;i++)T[i].init(nb);
		vector<int>L,ID;
		T[0].add(-1,1);
		for(i=1;i<=n;i++){
			int id=lower_bound(b,b+nb,a[i])-b;
			for(j=1;j<=m;j++)
				T[j].add(id,T[j-1].sum(id-1));
		}
		cout<<T[m].sum(nb)<<endl;
	}
	return 0;
}
/*
8 3
1 1 2 2 3 3 4 4
3 2
1 1 2
7 3
1 7 3 5 9 4 8
*/
