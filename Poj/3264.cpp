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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int mx[50005][17];
int mn[50005][17];
int w[50005];
int n;
int main() {
	int i,j;
	int Q;
	scanf( "%d%d",&n,&Q );
	for ( i=0; i<n; i++ )scanf( "%d",&w[i] );
	for ( i=0; i<n; i++ )mx[i][0]=w[i];
	for ( i=0; i<n; i++ )mn[i][0]=w[i];
	for ( j=1; n>>j; j++ ) {
		for ( i=0; i+( 1<<j )<=n; i++ )mx[i][j]=max( mx[i][j-1],mx[i+( 1<<( j-1 ) )][j-1] );
		for ( i=0; i+( 1<<j )<=n; i++ )mn[i][j]=min( mn[i][j-1],mn[i+( 1<<( j-1 ) )][j-1] );
	}
	while ( Q-- ) {
		int l,r;
		scanf( "%d%d",&l,&r );
		l--;r--;
		int p=w[r],q=w[r];
		for(j=1;n>>j;j++);j++;
		while(j--)if(l+(1<<j)-1<=r){
			cmax(p,mx[l][j]);
			cmin(q,mn[l][j]);
			l+=1<<j;
		}
		printf("%d\n",p-q);
	}
	return 0;
}
