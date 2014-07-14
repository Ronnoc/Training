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
const double PI = acos(-1);
const LL MOD = 1000000007;
int dp[55];
class DancingFoxes {
public:
  int minimalDays (vector <string> g) {
    int ret;
    int i,j,k;
    int G[55][55];
    memset(G,0,sizeof G);
    for(i=0;i<g.SZ;i++)for(j=0;j<g[i].SZ;j++)
			G[i][j]=g[i][j]=='Y'?1:MOD;
		for(i=0;i<g.SZ;i++)G[i][j]=0;
		int n=g.SZ;
    for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)
			cmin(G[i][j],G[i][k]+G[k][j]);
		dp[0]=0;
		dp[1]=0;
		dp[2]=1;
		dp[3]=2;
		for(i=4;i<=50;i++){
			int k=(i+1)/3;
			dp[i]=dp[i-k]+1;
		}
		cout<<G[0][1]<<endl;
    if(G[0][1]!=MOD)return dp[G[0][1]];
    else return -1;
  }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string friendship[]       = {"NNY",  "NNY",  "YYN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string friendship[]       = {"NNNNN",  "NNYYY",  "NYNYY",  "NYYNY",  "NYYYN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string friendship[]       = {"NNYYNN",  "NNNNYY",  "YNNNYN",  "YNNNNY",  "NYYNNN",  "NYNYNN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string friendship[]       = {"NNYNNNNYN",  "NNNNYNYNN",  "YNNYNYNNN",  "NNYNYNYYN",  "NYNYNNNNY",  "NNYNNNYNN",  "NYNYNYNNN",  "YNNYNNNNY",  "NNNNYNNYN"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string friendship[]       = {"NY",  "YN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string friendship[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DancingFoxes().minimalDays( vector <string>( friendship, friendship + ( sizeof friendship / sizeof friendship[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
