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


int vis[111];
int n,G[111][111];
bool dfs(int id,int c){
	int i;
	vis[id]=c;
	for(i=0;i<n;i++)if(G[i][id]&&!vis[i])
		dfs(i,3-c);
}
class Family {
public:
	string isFamily( vector <int> p, vector <int> q ) {
		n=p.SZ;
		memset(G,0,sizeof G);
		memset(vis,0,sizeof vis);
		int i,j;
		for(i=0;i<n;i++)if(p[i]!=-1)G[p[i]][q[i]]=G[q[i]][p[i]]=1;
		int no=0;
		for(i=0;i<n;i++)if(!vis[i])dfs(i,1);
		for(i=0;i<n;i++)for(j=0;j<n;j++)if(G[i][j])
			if(vis[i]==vis[j])no=1;
		if(no)return "Impossible";
		else return "Possible";
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

int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) {
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
		cerr << "    Expected: \"" << expected << "\"" << endl;
		cerr << "    Received: \"" << received << "\"" << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				int parent1[]             = {-1,-1,0};
				int parent2[]             = {-1,-1,1};
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int parent1[]             = {-1,-1,-1,-1,-1};
				int parent2[]             = {-1,-1,-1,-1,-1};
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int parent1[]             = {-1,-1,0,0,1};
				int parent2[]             = {-1,-1,1,2,2};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int parent1[]             = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6} ;
				int parent2[]             = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1} ;
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int parent1[]             = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
				int parent2[]             = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 5: {
					int parent1[]             = ;
					int parent2[]             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 6: {
					int parent1[]             = ;
					int parent2[]             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					int parent1[]             = ;
					int parent2[]             = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = Family().isFamily( vector <int>( parent1, parent1 + ( sizeof parent1 / sizeof parent1[0] ) ), vector <int>( parent2, parent2 + ( sizeof parent2 / sizeof parent2[0] ) ) );
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
