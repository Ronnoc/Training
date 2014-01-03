// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The Casket of Star (sic) is a device in the Touhou universe. Its purpose is to generate energy rapidly.
Initially it contains n stars in a row. The stars are labeled 0 through n-1 from the left to the right.
You are given a vector <int> weight, where weight[i] is the weight of star i.



The following operation can be repeatedly used to generate energy:

Choose a star x other than the very first star and the very last star.
The x-th star disappears.
This generates weight[x-1] * weight[x+1] units of energy.
We decrease n and relabel the stars 0 through n-1 from the left to the right.




Your task is to use the device to generate as many units of energy as possible. Return the largest possible total amount of generated energy.

DEFINITION
Class:CasketOfStar
Method:maxEnergy
Parameters:vector <int>
Returns:int
Method signature:int maxEnergy(vector <int> weight)


CONSTRAINTS
-weight will contain between 3 and 50 elements, inclusive.
-Each element in weight will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: 12

We have only 2 choices:

Make the "2" disappear first, and "3" next. The total energy is 1*3 + 1*4 = 7.
Make the "3" disappear first, and "2" next. The total energy is 2*4 + 1*4 = 12.

So the answer is 12.

1)
{100,2,1,3,100}

Returns: 10400

We proceed as follows:
{100,2,1,3,100} => {100,1,3,100} => {100,3,100} => {100,100}
The total energy is 100*1 + 100*3 + 100*100 = 10400.

2)
{2,2,7,6,90,5,9}

Returns: 1818



3)
{477,744,474,777,447,747,777,474}

Returns: 2937051



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 13



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

int vis[55];
vector <int> w;
int dp[55][55];
int dfs(int l,int r,int L,int R){
	int i;
	if(l==r)return L*R;
	if(l>r)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	for(i=l;i<=r;i++){
		dp[l][r]=max(dp[l][r],dfs(l,i-1,L,w[i])+dfs(i+1,r,w[i],R)+L*R);
	}
	return dp[l][r];
}
class CasketOfStar {
public:
	int maxEnergy (vector <int> we) {
		w=we;
		memset(dp,-1,sizeof dp);
		return dfs(1,w.SZ-2,w[0],w[w.SZ-1]);
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

int verify_case (int casenum, const int &expected, const int &received, clock_t elapsed) {
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
				int weight[]              = {1,2,3,4};
				int expected__            = 12;
				
				clock_t start__           = clock();
				int received__            = CasketOfStar().maxEnergy (vector <int> (weight, weight + (sizeof weight / sizeof weight[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				int weight[]              = {100,2,1,3,100};
				int expected__            = 10400;
				
				clock_t start__           = clock();
				int received__            = CasketOfStar().maxEnergy (vector <int> (weight, weight + (sizeof weight / sizeof weight[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				int weight[]              = {2,2,7,6,90,5,9};
				int expected__            = 1818;
				
				clock_t start__           = clock();
				int received__            = CasketOfStar().maxEnergy (vector <int> (weight, weight + (sizeof weight / sizeof weight[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				int weight[]              = {477,744,474,777,447,747,777,474};
				int expected__            = 2937051;
				
				clock_t start__           = clock();
				int received__            = CasketOfStar().maxEnergy (vector <int> (weight, weight + (sizeof weight / sizeof weight[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				int weight[]              = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int expected__            = 13;
				
				clock_t start__           = clock();
				int received__            = CasketOfStar().maxEnergy (vector <int> (weight, weight + (sizeof weight / sizeof weight[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 5: {
						int weight[]              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = CasketOfStar().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 6: {
						int weight[]              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = CasketOfStar().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 7: {
						int weight[]              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = CasketOfStar().maxEnergy( vector <int>( weight, weight + ( sizeof weight / sizeof weight[0] ) ) );
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
