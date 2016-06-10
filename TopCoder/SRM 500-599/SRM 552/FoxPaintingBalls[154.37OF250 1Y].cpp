// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A Ball Triangle is a set of identical balls placed in a triangular shape. A Ball Triangle has N rows, numbered 1 to N from top to bottom. For all i, 1 <= i <= N, the i-th row contains i balls. For example, the following image shows a Ball Triangle with N=3.




Fox Jiro has infinitely many Ball Triangles. He can paint a Ball Triangle according to the following conditions:

Each of the balls has to be painted either red, green, or blue.
No two adjacent balls may share the same color.

The following image shows one valid coloring of a Ball Triangle for N=3.




Jiro wants to paint as many Ball Triangles as he can.
As long as he follows the rules above, he may color the Ball Triangles in any way he likes.
Some of the colored Ball Triangles may look exactly the same, but they don't have to.
The only other constraint is the total amount of paint available to Jiro:
In all the triangles together, he can paint at most R balls red, G balls green, and B balls blue.

You are given the long longs R, G, and B.
You are also given the int N.
Return the maximum possible number of Ball Triangles Jiro can paint.

DEFINITION
Class:FoxPaintingBalls
Method:theMax
Parameters:long long, long long, long long, int
Returns:long long
Method signature:long long theMax(long long R, long long G, long long B, int N)


CONSTRAINTS
-R, G and B will each be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
-N will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
2
2
3

Returns: 1

Jiro can paint one Ball Triangle in the same way as in the image in the statement.

1)
1
2
3
3

Returns: 0

This time Jiro can paint no Ball Triangles.

2)
8
6
6
4

Returns: 2



3)
7
6
7
4

Returns: 2



4)
100
100
100
4

Returns: 30



5)
19330428391852493
48815737582834113
11451481019198930
3456

Returns: 5750952686



6)
1
1
1
1

Returns: 3



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

LL play (LL R,LL G,LL B,LL n) {
	
}
class FoxPaintingBalls {
public:
	long long theMax (long long R, long long G, long long B, int N) {
		LL n=N;
		long long ret=0;
		if (N==1LL)
			return R+G+B;
		n= (n+1) *n/2;
		LL per=n/3;
		LL mx=max (R,max (G,B));
		LL mn=min (R,min (G,B));
		cout<<R<<" "<<G<<" "<<B<<" "<<n<<" "<<per<<endl;
		if (n%3) {
			LL l=0,r=(R+G+B)/n,ans;
			while(r>=l){
				if(r-l<=1){
					LL mid=r;
					LL x1=R-mid*per;
					LL x2=G-mid*per;
					LL x3=B-mid*per;
					if(x1<0||x2<0||x3<0)ans=l;
					else if(x1+x2+x3<mid)ans=l;
					else ans=r;
					break;
				}
				LL mid=(l+r)>>1;
				LL x1=R-mid*per;
				LL x2=G-mid*per;
				LL x3=B-mid*per;
				if(x1<0||x2<0||x3<0)r=mid;
				else if(x1+x2+x3<mid)r=mid;
				else l=mid;
			}
			return ans;
		}
		return mn/per;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case (int);
void run_test (int casenum = -1, bool quiet = false) {
	if (casenum != -1) {
		if (run_test_case (casenum) == -1 && !quiet)
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for (int i=0;; ++i) {
		int x = run_test_case (i);
		if (x == -1) {
			if (i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if (total == 0) {
		cerr << "No test cases run." << endl;
	} else if (correct < total) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case (int casenum, const long long &expected, const long long &received, clock_t elapsed) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if (elapsed > CLOCKS_PER_SEC / 200) {
		sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
		info.push_back (buf);
	}
	
	if (expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if (!info.empty()) {
		cerr << " (";
		for (int i=0; i< (int) info.size(); ++i) {
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

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				long long R               = 2LL;
				long long G               = 2LL;
				long long B               = 2LL;
				int N                     = 3;
				long long expected__      = 1LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				long long R               = 1LL;
				long long G               = 2LL;
				long long B               = 3LL;
				int N                     = 3;
				long long expected__      = 0LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				long long R               = 8LL;
				long long G               = 6LL;
				long long B               = 6LL;
				int N                     = 4;
				long long expected__      = 2LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				long long R               = 7LL;
				long long G               = 6LL;
				long long B               = 7LL;
				int N                     = 4;
				long long expected__      = 2LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				long long R               = 100LL;
				long long G               = 100LL;
				long long B               = 100LL;
				int N                     = 4;
				long long expected__      = 30LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				long long R               = 19330428391852493LL;
				long long G               = 48815737582834113LL;
				long long B               = 11451481019198930LL;
				int N                     = 3456;
				long long expected__      = 5750952686LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 6: {
				long long R               = 1LL;
				long long G               = 1LL;
				long long B               = 1LL;
				int N                     = 1;
				long long expected__      = 3LL;
				
				clock_t start__           = clock();
				long long received__      = FoxPaintingBalls().theMax (R, G, B, N);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 7: {
						long long R               = LL;
						long long G               = LL;
						long long B               = LL;
						int N                     = ;
						long long expected__      = LL;
			
						clock_t start__           = clock();
						long long received__      = FoxPaintingBalls().theMax( R, G, B, N );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 8: {
						long long R               = LL;
						long long G               = LL;
						long long B               = LL;
						int N                     = ;
						long long expected__      = LL;
			
						clock_t start__           = clock();
						long long received__      = FoxPaintingBalls().theMax( R, G, B, N );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 9: {
						long long R               = LL;
						long long G               = LL;
						long long B               = LL;
						int N                     = ;
						long long expected__      = LL;
			
						clock_t start__           = clock();
						long long received__      = FoxPaintingBalls().theMax( R, G, B, N );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
		default:
			return -1;
	}
}
}


int main (int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test (atoi (argv[i]));
	}
}
// END CUT HERE
