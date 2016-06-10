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
#define MAXN 200
#define inf 1000000000

int min_cost_max_flow( int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost ) {
	int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
	if ( source==sink ) return inf;
	for ( i=0; i<n; i++ )
		for ( j=0; j<n; flow[i][j++]=0 );
	for ( netcost=0;; ) {
		for ( i=0; i<n; i++ )
			pre[i]=0,min[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for ( pre[source]=source+1,min[source]=0,d[source]=inf,tag=1; tag; )
			for ( tag=t=0; t<n; t++ )
				if ( d[t] )
					for ( i=0; i<n; i++ )
						if ( j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i] )
							tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
						else if ( j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i] )
							tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if ( !pre[sink] )	break;
		for ( netcost+=min[sink]*d[i=sink]; i!=source; )
			if ( pre[i]>0 )
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for ( j=i=0; i<n; j+=flow[source][i++] );
	return j;
}
int mat[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
class SpecialCells {
public:
	int guess( vector <int> x, vector <int> y ) {
		int ret;
		int i,j;
		for(i=0;i<x.SZ;i++)cout<<x[i]<<" ";cout<<endl;
		for(i=0;i<x.SZ;i++)cout<<y[i]<<" ";cout<<endl;
		set<int>X( x.OP,x.ED ),Y( y.OP,y.ED );
		vector<int>L( X.OP,X.ED ),R( Y.OP,Y.ED );
		int S=0,T=1,SS=2,TT=3;
		int sl=4,sr=4+L.SZ;
		memset(mat,0,sizeof mat);
		memset(cost,0,sizeof cost);
		memset(flow,0,sizeof flow);
		mat[SS][S]=x.SZ;
		multiset<int>xx(x.OP,x.ED),yy(y.OP,y.ED);
		for(i=0;i<L.SZ;i++)mat[S][i+sl]=xx.count(L[i]);
		for(i=0;i<L.SZ;i++)for(j=0;j<R.SZ;j++)
			mat[i+sl][j+sr]=1;
		for(j=0;j<R.SZ;j++)mat[j+sr][T]=yy.count(R[j]);
		mat[T][TT]=x.SZ;
		for(i=0;i<x.SZ;i++){
			int l=lower_bound(L.OP,L.ED,x[i])-L.OP;
			int r=lower_bound(R.OP,R.ED,y[i])-R.OP;
			cost[l+sl][r+sr]=1;
		}
		int c;
		ret=min_cost_max_flow(sr+R.SZ,mat,cost,SS,TT,flow,c);
		cout<<x.SZ<<" "<<ret<<" "<<c<<endl;
		return c;
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
				int x[]                   = {1,2};
				int y[]                   = {1,2};
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int x[]                   = {1,1,2};
				int y[]                   = {1,2,1};
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int x[]                   = {1,2,1,2,1,2};
				int y[]                   = {1,2,3,1,2,3};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int x[]                   = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
				int y[]                   = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int x[]                   = {1,100000};
				int y[]                   = {1,100000};
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					int x[]                   = ;
					int y[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int x[]                   = ;
					int y[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int x[]                   = ;
					int y[]                   = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = SpecialCells().guess( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
