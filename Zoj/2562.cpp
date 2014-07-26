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
bool notp[100007];
int p[20007],pn;
void shai( int n ) {
	pn=0,notp[0]=1;
	for ( int i=2; i<n; i++ ) {
		if ( !notp[i] )p[pn++]=i;
		for ( int j=0; j<pn&&i*p[j]<n; j++ ) {
			notp[i*p[j]]=1;
			if ( i%p[j]==0 )break;
		}
	}
}
LL n;
LL ans,out;
void dfs( int id,LL now,LL w ) {
	LL tp=1;
	int i;
	for ( i=1;; i++ ) {
		tp*=p[id];
		if ( tp*w>n )break;
	}
	i--,tp/=p[id];
	if ( i==0 ) {
		if ( now>ans )ans=now,out=w;
		else if ( now==ans&&out>w )out=w;
		return;
	}
	for ( ; i>=1; i-- ) {
		dfs( id+1,now*( i+1 ),w*tp );
		tp/=p[id];
	}
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	shai( 200 );
	while ( cin>>n ) {
		ans=-1,out=-1;
		dfs( 0,1,1 );
		cout<<out<<endl;
	}
	return 0;
}
