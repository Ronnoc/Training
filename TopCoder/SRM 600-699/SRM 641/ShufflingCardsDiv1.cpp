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

int f[2005],g[2005];
int dp[2005];
class ShufflingCardsDiv1 {
public:
  int shuffle (vector <int> L) {
    int ret=0;
    int i,j;
    int m=L.SZ,n=L.SZ/2;
    for(i=0;i<m;i++)f[i+1]=L[i];
    for(i=1;i<=m;i++)g[f[i]]=i;
    int ok=1;
    for(i=2;i<=m;i++)if(g[i]<g[i-1])ok=0;
    if(ok)return 0;
    vector<int>Z;
    for(i=1;i<=m;i++)Z.PB(g[i]%2);
    int one=1;
    for(i=0;i<n;i++)if(Z[i]==0)one=0;
    if(one)return 1;
    memset(dp,-1,sizeof dp);
    int c0=0;
    for(i=0;i<n;i++)if(Z[i]==0)c0++;
    dp[c0]=0;
    queue<int>Q;
    Q.push(c0);
    int p=0;
    for(i=1;i<=n;i++)if(i*2-1<=n)p++;
    while(!Q.empty()){
			int a=Q.front();Q.pop();
			int b=n-a;
			int Max=min(a,p)+min(b,n-p);
			int Min=a-min(a,n-p)+b-min(b,p);
			for(i=Min;i<=Max;i++)if(dp[i]==-1){
				dp[i]=dp[a]+1;
				Q.push(i);
			}
    }
    if(~dp[0])return dp[0]+1;
    return -1;
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
			int permutation[]         = {1,2,3,4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int permutation[]         = {1,4,3,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int permutation[]         = {6,3,5,2,4,1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int permutation[]         = {8,5,4,9,1,7,6,10,3,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int permutation[]         = {9,1,7,2,10,3,6,4,8,5};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int permutation[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int permutation[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int permutation[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShufflingCardsDiv1().shuffle( vector <int>( permutation, permutation + ( sizeof permutation / sizeof permutation[0] ) ) );
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
