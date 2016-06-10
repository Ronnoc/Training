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
const LL mod = 1000000007;
int x[55][55];
int fa[2555];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int merfa(int u,int v){
	int fu=getfa(u);
	int fv=getfa(v);
	fa[fu]=fv;
}
LL ans[2555];
int tot[2555];
class HexagonPuzzle {
public:
  int theCount (vector <string> B) {
    LL ret=1;
    int cnt=0,i,j;
    for(i=0;i<B.SZ;i++)for(j=0;j<B[i].SZ;j++)if(B[i][j]=='.')x[i][j]=++cnt;
    for(i=1;i<=cnt;i++)fa[i]=i;
    for(i=0;i+1<B.SZ;i++)for(j=0;j<B[i].SZ;j++){
			if(B[i][j]!='.')continue;
			if(B[i+1][j]!='.')continue;
			if(B[i+1][j+1]!='.')continue;
			merfa(x[i][j],x[i+1][j]);
			merfa(x[i][j],x[i+1][j+1]);
    }
    for(i=2;i<B.SZ;i++)for(j=1;j+1<B[i].SZ;j++){
			if(B[i][j]!='.')continue;
			if(B[i-1][j]!='.')continue;
			if(B[i-1][j-1]!='.')continue;
			merfa(x[i][j],x[i-1][j]);
			merfa(x[i][j],x[i-1][j-1]);
    }
    ans[0]=1;
    ans[1]=1;
    ans[2]=1;
    ans[3]=3;
    for(i=4;i<=cnt;i++)ans[i]=ans[i-1]*(1LL*i)%mod;
    memset(tot,0,sizeof tot);
    for(i=1;i<=cnt;i++)tot[getfa(i)]++;
    for(i=1;i<=cnt;i++)ret=ret*ans[tot[i]]%mod;
    return (int)ret;
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
			string board[]            = {".",  ".X",  "X..",  ".X.X"} ;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string board[]            = {"X"} ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string board[]            = {".",  "..",  "...",  ".X.."} ;
			int expected__            = 20160;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string board[]            = {".",  "..",  "XXX",  "..X.",  ".X..X",  "XXXX..",  "..X.X.X",  "..X.XX.."} ;
			int expected__            = 108;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string board[]            = {".",  "..",  "...",  "....",  ".....",  "......",  ".......",  "........"};
			int expected__            = 261547992;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HexagonPuzzle().theCount( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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
