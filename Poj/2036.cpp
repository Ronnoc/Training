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
#define AA first
#define BB second
#define MP make_pair
#define PB push_back
#define SZ size()
#define OP begin()
#define ED end()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
int n;
PLL A[20010],B[20010];
vector<pair<pair<PLL,LL>,pair<PLL,PLL> > >L;
LL mabs( LL x ) {return x>0?x:-x;}
int main() {
	int i,j;
	while ( ~scanf( "%d",&n )&&n ) {
		L.clear();
		for ( i=0; i<n; i++ ) {
			double q,w,e,r;
			scanf( "%lf%lf%lf%lf",&q,&w,&e,&r );
			q*=100,w*=100,e*=100,r*=100;
			q+=0.1,w+=0.1,e+=0.1,r+=0.1;
			LL Q=q,W=w,E=e,R=r;
			A[i]=min( MP( Q,W ),MP( E,R ) );
			B[i]=max( MP( Q,W ),MP( E,R ) );
			LL dx=B[i].AA-A[i].AA;
			LL dy=B[i].BB-A[i].BB;
			LL gcd=__gcd( mabs( dx ),mabs( dy ) );
			dx/=gcd,dy/=gcd;
			LL ty=dx*A[i].BB-dy*A[i].AA;
			LL tx=dy*A[i].AA-dx*A[i].BB;
			LL t;
			if ( dx )t=ty/dx;
			else t=tx/dy;
			L.PB( MP( MP( MP( dx,dy ),t ),MP( A[i],B[i] ) ) );
		}
		sort( L.OP,L.ED );
		int ans=0;
		for ( i=0; i<L.SZ; ) {
			int l=i;
			while ( i<L.SZ&&L[i].AA==L[l].AA )i++;
			PLL le=L[l].BB.AA;
			PLL re=L[l].BB.BB;
			for ( j=l+1; j<i; j++ ) {
				if ( L[j].BB.AA<=re )re=max( re,L[j].BB.BB );
				else {
					ans++;
					le=L[j].BB.AA;
					re=L[j].BB.BB;
				}
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
