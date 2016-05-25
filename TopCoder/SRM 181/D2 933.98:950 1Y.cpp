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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.begin(),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
bool isp[3000010];
class EngineersPrimes {
public:
	long long smallestNonPrime ( int N ) {
		long long ret;
		LL i,j;
		memset(isp,0,sizeof isp);
		for(isp[2]=1,i=3;i<3000010;i+=2)isp[i]=1;
		for(i=3;i<3000010;i+=2)if(isp[i])
			for(j=i*i;j<3000010;j+=i*2)isp[j]=0;
		int now=0;
		for(i=1;;i++)if(isp[i]){
			now++;
			if(now>N)return i*i;
		}
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int N                     = 3;
			long long expected__      = 49LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 1;
			long long expected__      = 9LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 265;
			long long expected__      = 2886601LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 1835;
			long long expected__      = 247716121LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 10000;
			long long expected__      = 10971096049LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = EngineersPrimes().smallestNonPrime( N );
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
