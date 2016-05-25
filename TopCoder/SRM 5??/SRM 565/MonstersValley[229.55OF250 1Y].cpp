// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i].

Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2.

At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster.



Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins.

You are given the vector<long long> dread and the vector <int> price. Compute the minimum price Manao will pay to safely pass the valley.

DEFINITION
Class:MonstersValley
Method:minimumPrice
Parameters:vector<long long>, vector <int>
Returns:int
Method signature:int minimumPrice(vector<long long> dread, vector <int> price)


CONSTRAINTS
-dread will contain between 1 and 50 elements, inclusive.
-Each element of dread will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-price will contain the same number of elements as dread.
-Each element of price will be either 1 or 2.


EXAMPLES

0)
{8, 5, 10}
{1, 1, 2}

Returns: 2

The example from the problem statement.

1)
{1, 2, 4, 1000000000}
{1, 1, 1, 2}

Returns: 5

Manao has to bribe all monsters in the valley.

2)
{200, 107, 105, 206, 307, 400}
{1, 2, 1, 1, 1, 2}

Returns: 2

Manao can bribe monsters 0 and 3.

3)
{5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}
{2, 2, 1, 1, 1, 1, 2, 1, 2, 1}

Returns: 5

Bribing monsters 0, 1 and 5 is sufficient to pass safely.

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


class MonstersValley {
public:
	int minimumPrice (vector<long long> d, vector <int> p) {
		int ret=0;
		LL dp[55][111];
		int i,j,n=d.SZ;
		for (i=0; i<=n; i++) for (j=0; j<=2*n; j++) dp[i][j]=-1;
		dp[0][p[0]]=d[0];
		for (i=0; i+1<n; i++) for (j=0; j<=2* (i+1); j++) {
				if (dp[i][j]==-1) continue;
				if (dp[i][j]<d[i+1]) {
					dp[i+1][j+p[i+1]]=max (dp[i+1][j+p[i+1]],dp[i][j]+d[i+1]);
				} else {
					dp[i+1][j+p[i+1]]=max (dp[i+1][j+p[i+1]],dp[i][j]+d[i+1]);
					dp[i+1][j]=max (dp[i+1][j],dp[i][j]);
				}
			}
//		for (i=0; i<=n; i++) {
//			for (j=0; j<=2* (i+1); j++) cout<<dp[i][j]<<" ";
//			cout<<endl;
//		}
		for (i=0; i<=2*n; i++) if (dp[n-1][i]!=-1) return i;
		return ret;
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
				long dread[]              = {8, 5, 10};
				int price[]               = {1, 1, 2};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = MonstersValley().minimumPrice (vector<long long> (dread, dread + (sizeof dread / sizeof dread[0])), vector <int> (price, price + (sizeof price / sizeof price[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				long dread[]              = {1, 2, 4, 1000000000};
				int price[]               = {1, 1, 1, 2};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = MonstersValley().minimumPrice (vector<long long> (dread, dread + (sizeof dread / sizeof dread[0])), vector <int> (price, price + (sizeof price / sizeof price[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				long dread[]              = {200, 107, 105, 206, 307, 400};
				int price[]               = {1, 2, 1, 1, 1, 2};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = MonstersValley().minimumPrice (vector<long long> (dread, dread + (sizeof dread / sizeof dread[0])), vector <int> (price, price + (sizeof price / sizeof price[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				long dread[]              = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
				int price[]               = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = MonstersValley().minimumPrice (vector<long long> (dread, dread + (sizeof dread / sizeof dread[0])), vector <int> (price, price + (sizeof price / sizeof price[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 4: {
						long dread[]              = ;
						int price[]               = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = MonstersValley().minimumPrice( vector<long long>( dread, dread + ( sizeof dread / sizeof dread[0] ) ), vector <int>( price, price + ( sizeof price / sizeof price[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 5: {
						long dread[]              = ;
						int price[]               = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = MonstersValley().minimumPrice( vector<long long>( dread, dread + ( sizeof dread / sizeof dread[0] ) ), vector <int>( price, price + ( sizeof price / sizeof price[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 6: {
						long dread[]              = ;
						int price[]               = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = MonstersValley().minimumPrice( vector<long long>( dread, dread + ( sizeof dread / sizeof dread[0] ) ), vector <int>( price, price + ( sizeof price / sizeof price[0] ) ) );
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
