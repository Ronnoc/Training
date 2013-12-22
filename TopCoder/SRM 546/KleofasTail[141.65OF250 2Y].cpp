// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Let X be a nonnegative integer.
The Kleofas tail of X is an infinite sequence of nonnegative integers, defined as follows:


The first element is X.
After an even element Y, the next element of the sequence is Y/2.
After an odd element Z, the next element of the sequence is Z-1.


For example, the Kleofas tail of 60 starts as follows: 60, 30, 15, 14, 7, 6, ...


You are given long longs K, A, and B.
Return the number of integers X between A and B, inclusive, such that the Kleofas tail of X contains at least one occurrence of K.


DEFINITION
Class:KleofasTail
Method:countGoodSequences
Parameters:long long, long long, long long
Returns:long long
Method signature:long long countGoodSequences(long long K, long long A, long long B)


NOTES
-Zero is an even number.


CONSTRAINTS
-K will be between 0 and 10^18, inclusive.
-A will be between 0 and 10^18, inclusive.
-B will be between 0 and 10^18, inclusive.
-A will be less than or equal to B.


EXAMPLES

0)
3
4
8

Returns: 2

The value 3 occurs in the Kleofas tail of 6 and also in the Kleofas tail of 7.

1)
1
23457
123456

Returns: 100000

For each X between 23457 and 123456, inclusive, the Kleofas tail of X contains the value 1.

2)
1234567890123456
10
1000000

Returns: 0

Each Kleofas tail is a nonincreasing sequence.

3)
0
0
2

Returns: 3



4)
2
3
3

Returns: 1

The Kleofas tail of 3 is 3, 2, 1, 0, 0, 0, ...

5)
13
12345
67890123

Returns: 8387584



*/
// END CUT HERE
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
#include <assert.h>

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

LL is(LL K,LL A){
	LL ret=0;
	if(A==K)ret=1;
	else if(A&&A%2==0LL)ret=is(K,A/2);
	else if(A&&A%2==1LL)ret=is(K,A-1);
	return ret;
}
LL F(LL K,LL A,LL B){
	if(B<=K||A==B)return is(K,B);
	if(A<K)A=K;
	if(A>B)return 0;
	if(A%2==1)return is(K,A)+F(K,A+1,B);
	if(B%2==0)return is(K,B)+F(K,A,B-1);
	//A even B odd
	if(K%2==0)if(K>=A&&K<=B)return is(K,A)+F(K,A+1,B);
	return 2*F(K,A/2,B/2);
}
class KleofasTail {
public:
  long long countGoodSequences (long long K, long long A, long long B) {
  	cout<<K<<" "<<A<<" "<<B<<endl;
  	LL k,a,b;
//  	while(cin>>k>>a>>b)cout<<F(k,a,b)<<endl;
//		while(cin>>k>>a)cout<<is(k,a)<<endl;
    long long ret=F(K,A,B);
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
			long long K               = 3LL;
			long long A               = 4LL;
			long long B               = 8LL;
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			long long K               = 1LL;
			long long A               = 23457LL;
			long long B               = 123456LL;
			long long expected__      = 100000LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			long long K               = 1234567890123456LL;
			long long A               = 10LL;
			long long B               = 1000000LL;
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			long long K               = 0LL;
			long long A               = 0LL;
			long long B               = 2LL;
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			long long K               = 2LL;
			long long A               = 3LL;
			long long B               = 3LL;
			long long expected__      = 1LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			long long K               = 13LL;
			long long A               = 12345LL;
			long long B               = 67890123LL;
			long long expected__      = 8387584LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			long long K               = 4LL;
			long long A               = 2LL;
			long long B               = 10LL;
			long long expected__      = 5LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			long long K               = LL;
			long long A               = LL;
			long long B               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			long long K               = LL;
			long long A               = LL;
			long long B               = LL;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences( K, A, B );
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
