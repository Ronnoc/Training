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
const int MXN = 1000+10;
const LL MOD = 1000000007;
int BIT[MXN+10];
int LB( int w ) {return w&( -w );}
LL query( int w ) {
	LL ret=0;
	for ( w+=5; w>0; w-=LB( w ) )ret+=BIT[w];
	return ret;
}
void update( int w,int d ) {
	for ( w+=5; w<MXN; w+=LB( w ) )BIT[w]+=d;
}
vector<int>Z;
int where( int x ) {
	return lower_bound( Z.OP,Z.ED,x )-Z.OP;
}
int a[MXN+10];
int n;
int main() {
	int i,j;
	freopen( "B-large.in","r",stdin );
	freopen( "B-large.out","w",stdout );
	int T;
	scanf( "%d",&T );
	int l[1010],r[1010];
	for ( int CASE=1; CASE<=T; ++CASE ) {
		scanf( "%d",&n );
		for ( i=1; i<=n; i++ )scanf( "%d",&a[i] );
		Z.clear();
		for ( i=1; i<=n; i++ )Z.PB( a[i] );
		int ans=0;
//		for(i=1;i<=n;i++)Z.PB(MOD-a[i]);
		SORT( Z );
		Z.erase( unique( Z.OP,Z.ED ),Z.ED );
		for(i=0;i<Z.SZ;i++){
			for(j=1;j<=n;j++)if(a[j]==Z[i])break;
			int l=1,r=n;
			while(a[l]<a[j])l++;
			while(a[r]<a[j])r--;
			int dl=j-l;
			int dr=r-j;
			if(dl<dr){
				while(j!=l){
					swap(a[j],a[j-1]);
					ans++;
					j--;
				}
			}else {
				while(j!=r){
					swap(a[j],a[j+1]);
					ans++;
					j++;
				}
			}
		}
		printf( "Case #%d: %d\n",CASE,ans );
	}
	return 0;
}
/*
1
9
9 8 1 2 7 6 4 3 5
*/
