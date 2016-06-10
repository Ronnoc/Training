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
#include <fstream>
#include <cstdlib>
#include <cstring>
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
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;

vector<LL>x,y;
LL a;
int t,n;
LL dis( int id,LL lx,LL rx,LL ly,LL ry ) {
	LL ret=0;
	if ( x[id]<lx )ret+=lx-x[id];
	else if ( x[id]>rx )ret+=x[id]-rx;
	if ( y[id]<ly )ret+=ly-y[id];
	else if ( y[id]>ry )ret+=y[id]-ry;
	return ret;
}
class CrouchingAmoebas {
public:
	int count( vector <int> X, vector <int> Y, int A, int T ) {
		int ret=1,i,j,dx,dy,ii,jj;
		x.clear(),y.clear();
		a=A,t=T,n=X.SZ;
		LL lx,ly;
		for ( i=0; i<n; i++ )x.PB( X[i] );
		for ( i=0; i<n; i++ )y.PB( Y[i] );
		for ( ii=0; ii<n; ii++ )for ( jj=0; jj<n; jj++ ) {
				lx=x[ii]-5,ly=y[jj]-5;
				for ( dx=0; dx<=10; dx++ )for ( dy=0; dy<=10; dy++ ) {
						LL blx=lx+dx,brx=lx+dx+a;
						LL bly=ly+dy,bry=ly+dy+a;
						vector<LL>L;
						for ( j=0; j<n; j++ )
							L.PB( dis( j,blx,brx,bly,bry ) );
						SORT( L );
						int id=0;
						LL tot=0;
						while ( id<L.SZ&&tot+L[id]<=t )tot+=L[id++];
						ret=max( ret,id );
					}
			}
		return ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
