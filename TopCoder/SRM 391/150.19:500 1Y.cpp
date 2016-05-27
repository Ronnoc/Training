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

LL dp[22][22];
int vis[22][22];
LL D[22],A[22];
LL comb[22][22];
LL dfs(int p,int q){
	if(p<=q)return A[p];
	if(q==0)return 0;
	LL &tp=dp[p][q];
	if(vis[p][q])tp;
	vis[p][q]=1;
	LL a=0,g;
	for(int i=1;i<=p;i++)
		a+=comb[p-1][i-1]*A[i-1]*dfs(p-i,q-1);
	return tp=a;
}
class KeysInBoxes {
public:
  string getAllKeys (int N, int M) {
    string ret;
    int i,j;
    D[1]=0,D[2]=1;
    for(i=3;i<=N;i++)D[i]=(i-1)*(D[i-1]+D[i-2]);
    A[0]=1;
    for(i=1;i<=N;i++)A[i]=A[i-1]*i;
    comb[0][0]=1;
    for(i=1;i<=N;i++){
			comb[i][0]=1;
			for(j=1;j<i;j++)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			comb[i][i]=1;
    }
    char a[99];
    memset(vis,0,sizeof vis);
    LL p=dfs(N,M),q=A[N];
    LL g=__gcd(p,q);
    sprintf(a,"%lld/%lld",p/g,q/g);
    ret=a;
    return ret;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 2;
			int M                     = 1;
			string expected__         = "1/2";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 2;
			int M                     = 2;
			string expected__         = "1/1";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 3;
			int M                     = 1;
			string expected__         = "1/3";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 3;
			int M                     = 2;
			string expected__         = "5/6";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 4;
			int M                     = 2;
			string expected__         = "17/24";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int N                     = 20;
			int M                     = 10;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int N                     = ;
			int M                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = KeysInBoxes().getAllKeys( N, M );
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
