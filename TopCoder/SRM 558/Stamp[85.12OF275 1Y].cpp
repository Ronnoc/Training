// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Little Fox Jiro has a rectangular board.
On the board there is a row of N unit cells.
The cells are numbered 0 through N-1 from the left to the right.
Initially, the cells are not colored.
Jiro must color each of the cells red, green, or blue.

You are given a string desiredColor with N characters.
For each i, character i of desiredColor represents the color Jiro must use for cell i.
If a character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means that Jiro must use that particular color.
If a character is '*', Jiro may use any of the three colors for the particular cell.

You are also given the ints stampCost and pushCost that describe the cost of the coloring process.
The coloring process consists of two phases.
In the first phase, Jiro must pick a single stamp he will then use to color all the cells.
The length L of the stamp can be any integer between 1 and N, inclusive.
A stamp of length L costs L*stampCost.

In the second phase, Jiro must repeatedly use the stamp to color the cells.
Each use of the stamp works as follows:

Jiro picks one of the three colors and pushes the stamp into ink of the chosen color C.
Jiro picks a segment of L contiguous cells such that each of them is either uncolored or already has the color C.
The segment must be completely inside the board.
That is, the leftmost cell of the segment must be one of the cells 0 through N-L.
Jiro pushes the stamp onto the chosen segment of cells. All the cells now have color C.

Each use of the stamp costs pushCost.

Return the smallest possible total cost of coloring all the cells using the above process.


DEFINITION
Class:Stamp
Method:getMinimumCost
Parameters:string, int, int
Returns:int
Method signature:int getMinimumCost(string desiredColor, int stampCost, int pushCost)


CONSTRAINTS
-desiredColor will contain between 1 and 50 characters, inclusive.
-Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
-stampCost will be between 1 and 100,000, inclusive.
-pushCost will be between 1 and 100,000, inclusive.


EXAMPLES

0)
"RRGGBB"
1
1

Returns: 5

The optimal solution is to choose L=2 and then stamp three times: using red color for cells [0,1], green for [2,3], and blue for [4,5].
The stamp costs 2*1 = 2, each of the three uses costs 1, so the total costs is 2*1 + 3*1 = 5.

1)
"R**GB*"
1
1

Returns: 5

The optimal solution is the same as in the previous example.
Note that you must color all the cells, so choosing L=1 and then using the stamp three times is not a valid solution.

2)
"BRRB"
2
7

Returns: 30

Also, note that once a cell is colored, you are not allowed to stamp over it using a different color.
Therefore, you can only choose L=1 in this case.

3)
"R*RR*GG"
10
58

Returns: 204

It is allowed to stamp the same cell multiple times if all of those stamps use the same color.

4)
"*B**B**B*BB*G*BBB**B**B*"
5
2

Returns: 33



5)
"*R*RG*G*GR*RGG*G*GGR***RR*GG"
7
1

Returns: 30



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


const int inf=1000000007;
class Stamp {
public:
	int getMinimumCost (string s, int sc, int pc) {
		cout<<s<<" "<<sc<<" "<<pc<<endl;
		int ret=sc+pc*s.SZ;
		int i,j,k,l,c,p;
		int x[55];
		for (i=0; i<s.SZ; i++)
			if (s[i]=='R') x[i]=1;
			else if (s[i]=='G') x[i]=2;
			else if (s[i]=='B') x[i]=3;
			else x[i]=0;
		for (l=2; l<=s.SZ; l++) {
			set<int>O;
			set<int>::iterator iter;
			for (i=0; i<l; i++) if (x[i]) O.insert (x[i]);
			if (O.SZ>1) continue;
			if (l==s.SZ) {ret=min (ret,sc*l+pc); continue;}
			if (O.SZ==0) for (j=1; j<=3; j++) O.insert (j);
			for (iter=O.OP; iter!=O.ED; ++iter) {
				int c=*iter;
				int y[55];
				for (i=0; i<s.SZ; i++) y[i]=x[i];
				for (i=0; i<l; i++) y[i]=c;
				int dp[55][5];
				for (i=0; i<s.SZ+4; i++) for (j=0; j<=4; j++) dp[i][j]=inf;
				dp[l][c]=1;
				for (i=l; i<s.SZ; i++) for (j=1; j<=4; j++) {
						if (dp[i][j]==inf) continue;
						if (i+l<=s.SZ) for (k=1; k<=3; k++) {
								int st=i;
								int wa=0;
								for (p=0; p<l; p++)
									if (y[st+p]&&y[st+p]!=k) wa=1;
								if (wa) continue;
								dp[i+l][k]=min (dp[i+l][k],dp[i][j]+1);
							}
						for (k=1; k<l; k++) {
							int st=i-k;
							int wa=0;
							for(p=0;p<l;p++)
								if(y[st+p]&&y[st+p]!=j)wa=1;
							if(wa)continue;
							dp[st+l][j]=min(dp[st+l][j],dp[i][j]+1);
						}
					}
				int mn=inf;
				for(i=1;i<=3;i++)mn=min(mn,dp[s.SZ][i]);
				if(mn<inf)ret=min(sc*l+pc*mn,ret);
			}
		}
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
				string desiredColor       = "RRGGBB";
				int stampCost             = 1;
				int pushCost              = 1;
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string desiredColor       = "R**GB*";
				int stampCost             = 1;
				int pushCost              = 1;
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string desiredColor       = "BRRB";
				int stampCost             = 2;
				int pushCost              = 7;
				int expected__            = 30;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string desiredColor       = "R*RR*GG";
				int stampCost             = 10;
				int pushCost              = 58;
				int expected__            = 204;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string desiredColor       = "*B**B**B*BB*G*BBB**B**B*";
				int stampCost             = 5;
				int pushCost              = 2;
				int expected__            = 33;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				string desiredColor       = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
				int stampCost             = 7;
				int pushCost              = 1;
				int expected__            = 30;
				
				clock_t start__           = clock();
				int received__            = Stamp().getMinimumCost (desiredColor, stampCost, pushCost);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 6: {
						string desiredColor       = ;
						int stampCost             = ;
						int pushCost              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Stamp().getMinimumCost( desiredColor, stampCost, pushCost );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 7: {
						string desiredColor       = ;
						int stampCost             = ;
						int pushCost              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Stamp().getMinimumCost( desiredColor, stampCost, pushCost );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 8: {
						string desiredColor       = ;
						int stampCost             = ;
						int pushCost              = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Stamp().getMinimumCost( desiredColor, stampCost, pushCost );
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
