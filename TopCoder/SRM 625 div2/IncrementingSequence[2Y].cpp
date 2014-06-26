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

class IncrementingSequence {
public:
  string canItBeDone (int k, vector <int> A) {
    string ret;
    int i,j;
    multiset<int>G[111];
    int K=k;
    for(i=0;i<A.SZ;i++)G[A[i]%k].insert(A[i]/k);
    cout<<K<<endl;
    SORT(A);
    for(i=0;i<A.SZ;i++)cout<<A[i]<<" ";
    cout<<endl;
		for(i=0;i<K;i++){
			cout<<i<<"~"<<G[i].SZ<<endl;
			int t=0,now=i;
			if(!i)t++,now+=K;
			while(now<=A.SZ&&!G[i].empty()){
				int x=*G[i].OP;
				if(x>t)return string("IMPOSSIBLE");
				G[i].erase(G[i].OP);
//				cout<<x<<" "<<t<<endl;
				t++;
				now+=K;
			}
			if(now<=A.SZ)return string("IMPOSSIBLE");
		}
    return string("POSSIBLE");
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
			int k                     = 3;
			int A[]                   = {1,2,4,3};
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int k                     = 5;
			int A[]                   = {2,2};
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int k                     = 1;
			int A[]                   = {1,1,1,1,1,1,1,1};
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int k                     = 2;
			int A[]                   = {5,3,3,2,1};
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int k                     = 9;
			int A[]                   = {1,2,3,1,4,5,6,7,9,8};
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int k                     = 2;
			int A[]                   = {1,1,1,1,1,1,2,2,2,2,2,2};
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int k                     = 1;
			int A[]                   = {1};
			string expected__         = "POSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 7: {
			int k                     = 2;
			int A[]                   = {22, 13, 19, 7, 2, 16, 16, 1, 10, 6, 10, 24, 15, 21, 4, 18, 10, 3, 11, 5, 20, 25, 5, 13, 25};
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 8: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IncrementingSequence().canItBeDone( k, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ) );
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
