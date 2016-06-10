// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In a normal election, one expects the percentages received by each of the candidates to sum to exactly 100 percent.  There are two ways this might not be the case: if the election is fraudulent, or if the reported percentages are rounded.
For example, in an election with 3 voters and 3 candidates, if each voter chooses a different candidate the final percentages would be reported as 33, 33, 33, which only sum to 99.  Conversely, in an election with 7 voters and 3 candidates, if the candidates receive 2, 2, and 3 votes, respectively, the final percentages would be reported as 29, 29, and 43, which sum to 101.
The ministry of voting wants you to help them determine if an election was run fairly or not.  You'll be given a vector <int> percentages, giving the percentage of the vote that went to each candidate, rounded to the nearest whole number (in the case a number lies halfway between 2 consecutive integers, it will be rounded up).  If the election could be legitimate, return the minimum number of voters that could have participated in this election.  If the election is definitely fraudulent, return -1.

DEFINITION
Class:ElectionFraudDiv1
Method:MinimumVoters
Parameters:vector <int>
Returns:int
Method signature:int MinimumVoters(vector <int> percentages)


NOTES
-You may assume that whenever the election may be legitimate, the smallest possible number of voters will fit into a int.


CONSTRAINTS
-percentages will contain between 1 and 50 elements, inclusive.
-Each element of percentages will be between 0 and 100, inclusive.


EXAMPLES

0)
{33, 33, 33}

Returns: 3

The first example from the problem statement.

1)
{29, 29, 43}

Returns: 7

The second example from the problem statement.

2)
{12, 12, 12, 12, 12, 12, 12, 12}

Returns: -1

These results are impossible.

3)
{13, 13, 13, 13, 13, 13, 13, 13}

Returns: 8



4)
{0, 1, 100}

Returns: 200

The only possibility is that the candidates received 0, 1, and 199 votes, respectively.

5)
{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}

Returns: 97



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

bool can(int n,vector<int>p){
	int m=p.SZ;
	int i,j;
	vector<PII>q;
	for(i=0;i<m;i++){
		for(j=(n*p[i]-1.5*n)/100;j<=n;j++){
			if(j<0)j=0;
			int f=100.0*j/n+0.5;
			if(f==p[i])break;
		}
		int l=j,r=j;
		while(1){
			j=r+1;
			int f=100.0*j/n+0.5;
			if(f==p[i])r++;
			else break;
		}
		q.PB(MP(l,r));
	}
	int mn=0,mx=0;
	for(i=0;i<q.SZ;i++)mn+=q[i].AA;
	for(i=0;i<q.SZ;i++)mx+=q[i].BB;
	return n>=mn&&n<=mx;
}
class ElectionFraudDiv1 {
public:
  int MinimumVoters (vector <int> p) {
  	SORT(p);
    int ret=-1;
    for(int i=1;i<=10000;i++){
			if(can(i,p)){ret=i;break;}
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
			int percentages[]         = {33, 33, 33};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int percentages[]         = {29, 29, 43};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int percentages[]         = {12, 12, 12, 12, 12, 12, 12, 12};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int percentages[]         = {13, 13, 13, 13, 13, 13, 13, 13};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int percentages[]         = {0, 1, 100};
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int percentages[]         = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int expected__            = 97;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters( vector <int>( percentages, percentages + ( sizeof percentages / sizeof percentages[0] ) ) );
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
