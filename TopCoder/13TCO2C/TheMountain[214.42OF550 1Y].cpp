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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos( -1 );
const LL MOD = 1000000007;
int a[222][222];
int dp[4][222][222];
int fail[4][222][222];
int sum[4][222][222];
int si[4],ti[4],sj[4],tj[4];
int di[4]= {1,1,-1,-1};
int dj[4]= {1,-1,1,-1};
int N,M;
int ff[222][222];
void solve( int k ) {
	int i,j;
	for ( i=si[k]; i!=ti[k]+di[k]; i+=di[k] )
		for ( j=sj[k]; j!=tj[k]+dj[k]; j+=dj[k] ) {
			dp[k][i][j]=a[i][j];
			if ( i-di[k]>=0&&i-di[k]<N )
				cmax( dp[k][i][j],dp[k][i-di[k]][j]+1 ),fail[k][i][j]|=fail[k][i-di[k]][j];
			if ( j-dj[k]>=0&&j-dj[k]<M )
				cmax( dp[k][i][j],dp[k][i][j-dj[k]]+1 ),fail[k][i][j]|=fail[k][i][j-dj[k]];
			if ( ff[i][j]&&dp[k][i][j]>a[i][j] )
				fail[k][i][j]=1;
		}
	for ( i=si[k]; i!=ti[k]+di[k]; i+=di[k] ) {
		sum[k][i][ sj[k] ]=dp[k][i][sj[k]];
		for ( j=sj[k]+dj[k]; j!=tj[k]+dj[k]; j+=dj[k] )
			sum[k][i][j]=sum[k][i][j-dj[k]]+dp[k][i][j];
	}
	for ( i=si[k]+di[k]; i!=ti[k]+di[k]; i+=di[k] )
		for ( j=sj[k]; j!=tj[k]+dj[k]; j+=dj[k] )
			sum[k][i][j]+=sum[k][i-di[k]][j];
}
class TheMountain {
public:
	int minSum( int n, int m, vector <int> p, vector <int> q, vector <int> r ) {
		int ret=MOD;
		int i,j,k;
		N=n,M=m;
		memset( fail,0,sizeof fail );
		memset( ff,0,sizeof ff );
		for ( i=0; i<n; i++ )for ( j=0; j<m; j++ )a[i][j]=1;
		for ( i=0; i<p.SZ; i++ )a[ p[i] ][ q[i] ]=r[i],ff[p[i]][q[i]]=1;
		si[0]=0,si[1]=0,si[2]=n-1,si[3]=n-1;
		ti[0]=n-1,ti[1]=n-1,ti[2]=0,ti[3]=0;
		sj[0]=0,sj[1]=m-1,sj[2]=0,sj[3]=m-1;
		tj[0]=m-1,tj[1]=0,tj[2]=m-1,tj[3]=0;
		for ( i=0; i<4; i++ )solve( i );
//		for(printf("a\n"),i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%3d",a[i][j]);
//		for(printf("ff\n"),i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%3d",ff[i][j]);
//		for(printf("dp[0]\n"),i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%3d",dp[0][i][j]);
//		for(k=0;k<4;k++)for(printf("fail[%d]\n",k),i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%3d",fail[k][i][j]);
//		for(printf("sum[0]\n"),i=0;i<n;i++,printf("\n"))for(j=0;j<m;j++)printf("%3d",sum[0][i][j]);
		for ( i=0; i<N; i++ )
			for ( j=0; j<M; j++ ) {
				int ok=1;
				for ( k=0; k<4; k++ )if ( fail[k][i][j] )ok=0;
				if ( !ok )continue;
				int put=a[i][j];
				for ( k=0; k<4; k++ )cmax( put,dp[k][i][j] );
				int now=0;
				for ( k=0; k<4; k++ )
					if ( i-di[k]>=0&&i-di[k]<N&&j-dj[k]>=0&&j-dj[k]<M )
						now+=sum[k][i-di[k]][j-dj[k]];
				int last=0;
				int u=0,d=0,l=0,r=0;
				for ( k=0; k<i; k++ ) {
					last++;
					cmax( last,a[k][j] );
					if ( j-1>=0 )cmax( last,dp[0][k][j-1]+1 );
					if ( j+1<M )cmax( last,dp[1][k][j+1]+1 );
					if ( ff[k][j]&&last>a[k][j] )ok=0;
					u+=last;
					cmax( put,last+1 );
				}
				last=0;
				for ( k=n-1; k>i; k-- ) {
					last++;
					cmax( last,a[k][j] );
					if ( j-1>=0 )cmax( last,dp[2][k][j-1]+1 );
					if ( j+1<M )cmax( last,dp[3][k][j+1]+1 );
					if ( ff[k][j]&&last>a[k][j] )ok=0;
					d+=last;
					cmax( put,last+1 );
				}
				last=0;
				for ( k=0; k<j; k++ ) {
					last++;
					cmax( last,a[i][k] );
					if ( i-1>=0 )cmax( last,dp[0][i-1][k]+1 );
					if ( i+1<N )cmax( last,dp[2][i+1][k]+1 );
					if ( ff[i][k]&&last>a[i][k] )ok=0;
					l+=last;
					cmax( put,last+1 );
				}
				last=0;
				for ( k=m-1; k>j; k-- ) {
					last++;
					cmax( last,a[i][k] );
					if ( i-1>=0 )cmax( last,dp[1][i-1][k]+1 );
					if ( i+1<N )cmax( last,dp[3][i+1][k]+1 );
					if ( ff[i][k]&&last>a[i][k] )ok=0;
					r+=last;
					cmax( put,last+1 );
				}
				now+=put+u+d+l+r;
				if ( ok )cmin( ret,now );
//				if(ok){
//					cout<<i<<" "<<j<<" "<<now<<endl;
//					cout<<u<<" "<<d<<" "<<l<<" "<<r<<" "<<put<<"  ";
//					for(k=0;k<4;k++)if ( i-di[k]>=0&&i-di[k]<N&&j-dj[k]>=0&&j-dj[k]<M )
//						cout<<k<<"~ "<<sum[k][i-di[k]][j-dj[k]]<<"\t";
//				}
			}
		if ( ret==MOD )return -1;
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
	if ( casenum != -1 ) {
		if ( run_test_case( casenum ) == -1 && !quiet )
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for ( int i=0;; ++i ) {
		int x = run_test_case( i );
		if ( x == -1 ) {
			if ( i >= 100 ) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if ( total == 0 ) {
		cerr << "No test cases run." << endl;
	} else if ( correct < total ) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( expected == received ) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if ( !info.empty() ) {
		cerr << " (";
		for ( int i=0; i<( int )info.size(); ++i ) {
			if ( i > 0 ) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;
	
	if ( verdict == "FAILED" ) {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				int n                     = 2;
				int m                     = 3;
				int rowIndex[]            = {0, 0, 0, 1, 1, 1};
				int columnIndex[]         = {0, 1, 2, 0, 1, 2};
				int element[]             = {4, 6, 9, 1, 3, 6};
				int expected__            = 29;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int n                     = 2;
				int m                     = 3;
				int rowIndex[]            = {1, 0, 1};
				int columnIndex[]         = {2, 2, 0};
				int element[]             = {5, 7, 6};
				int expected__            = 40;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int n                     = 3;
				int m                     = 3;
				int rowIndex[]            = {0, 0, 2, 2};
				int columnIndex[]         = {0, 2, 2, 0};
				int element[]             = {1, 1, 1, 1};
				int expected__            = 15;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int n                     = 2;
				int m                     = 2;
				int rowIndex[]            = {0, 0, 1, 1};
				int columnIndex[]         = {0, 1, 1, 0};
				int element[]             = {5, 8, 5, 8};
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int n                     = 1;
				int m                     = 3;
				int rowIndex[]            = {0};
				int columnIndex[]         = {1};
				int element[]             = {1};
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
				int n                     = 123;
				int m                     = 45;
				int rowIndex[]            = {2, 3, 5, 7, 11};
				int columnIndex[]         = {13, 17, 19, 23, 29};
				int element[]             = {100, 200, 300, 400, 500};
				int expected__            = 367047;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 6: {
				int n                     = 200;
				int m                     = 200;
				int rowIndex[]            = {5};
				int columnIndex[]         = {8};
				int element[]             = {666};
				int expected__            = 5737554;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 7: {
				int n                     = 10;
				int m                     = 10;
				int rowIndex[]            = {0, 8, 7};
				int columnIndex[]         = {3, 1, 9};
				int element[]             = {5, 4, 7};
				int expected__            = 593;
				
				clock_t start__           = clock();
				int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 8: {
					int n                     = ;
					int m                     = ;
					int rowIndex[]            = ;
					int columnIndex[]         = ;
					int element[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 9: {
					int n                     = ;
					int m                     = ;
					int rowIndex[]            = ;
					int columnIndex[]         = ;
					int element[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 10: {
					int n                     = ;
					int m                     = ;
					int rowIndex[]            = ;
					int columnIndex[]         = ;
					int element[]             = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = TheMountain().minSum( n, m, vector <int>( rowIndex, rowIndex + ( sizeof rowIndex / sizeof rowIndex[0] ) ), vector <int>( columnIndex, columnIndex + ( sizeof columnIndex / sizeof columnIndex[0] ) ), vector <int>( element, element + ( sizeof element / sizeof element[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		moj_harness::run_test();
	} else {
		for ( int i=1; i<argc; ++i )
			moj_harness::run_test( atoi( argv[i] ) );
	}
}
// END CUT HERE
