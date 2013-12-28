// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You used to have only 30 rocks, but now you have plenty of them. In fact, we will assume that you have a potentially infinite supply of rocks. You would like to show that you own over 9000 rocks.
You have a set of boxes. You will choose a subset of those boxes and fill them with rocks so that the total number of rocks will be over 9000. Each box has a lower and an upper bound on the number of rocks it may contain.

You are given the vector <int>s lowerBound and upperBound. For each i, the values lowerBound[i] and upperBound[i] have the following meaning: If you decide to use box i, the number of rocks you may put inside the box must be between lowerBound[i] and upperBound[i], inclusive.

X is a positive integer that has two properties:

X is over 9000.
It is possible to select some of the boxes and fill them with appropriate numbers of rocks in such a way that the total number of rocks used is exactly X.

Compute and return the number of possible values of X.

DEFINITION
Class:Over9000Rocks
Method:countPossibilities
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countPossibilities(vector <int> lowerBound, vector <int> upperBound)


CONSTRAINTS
-lowerBound will contain between 1 and 15, elements, inclusive.
-upperBound will contain the same number of elements as lowerBound.
-Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
-Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{9000}
{9001}

Returns: 1

You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is over 9000.

1)
{9000, 1, 10}
{9000, 2, 20}

Returns: 15

You have to choose box 0 and at least one other box, otherwise you have no chance of placing over 9000 rocks.
If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, inclusive.

2)
{1001, 2001, 3001, 3001}
{1003, 2003, 3003, 3003}

Returns: 9



3)
{9000,90000,1,10}
{9000,90000,3,15}

Returns: 38



4)
{1,1,1,1,1,1}
{3,4,5,6,7,8}

Returns: 0



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


class Over9000Rocks {
public:
	int countPossibilities (vector <int> l, vector <int> r) {
		vector<PII>T;//l,-r
		int i,j;
		T.PB(MP(0,0));
		for(i=0;i<l.SZ;i++){
//			cout<<l[i]<<" & "<<r[i]<<endl;
			vector<PII>TT=T;
			for(j=0;j<T.SZ;j++)TT.PB(MP(T[j].AA+l[i],T[j].BB-r[i]));
			SORT(TT);
			TT.erase(unique(TT.OP,TT.ED),TT.ED);
//			for(int i=0;i<TT.SZ;i++)cout<<TT[i].AA<<" -> "<<-TT[i].BB<<" ";
//			cout<<endl;
			T.clear();
			for(j=1;j<TT.SZ;j++){
				PII &le=TT[j-1];
				PII &ri=TT[j];
				if(ri.AA>-le.BB)T.PB(le);
				else {
					ri.AA=min(le.AA,ri.AA);
					ri.BB=min(ri.BB,le.BB);
				}
			}
			T.PB(TT.back());
//			for(int i=0;i<T.SZ;i++)cout<<T[i].AA<<" -> "<<-T[i].BB<<" ";
//			cout<<endl;
		}
//		for(i=0;i<T.SZ;i++)cout<<T[i].AA<<" -> "<<-T[i].BB<<endl;
		int ret=0;
		for(i=0;i<T.SZ;i++){
			int l=T[i].AA;
			int r=-T[i].BB;
			if(l<9001)l=9001;
			if(r>=l)ret+=r-l+1;
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
				int lowerBound[]          = {9000};
				int upperBound[]          = {9001};
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				int lowerBound[]          = {9000, 1, 10};
				int upperBound[]          = {9000, 2, 20};
				int expected__            = 15;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				int lowerBound[]          = {1001, 2001, 3001, 3001};
				int upperBound[]          = {1003, 2003, 3003, 3003};
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				int lowerBound[]          = {9000,90000,1,10};
				int upperBound[]          = {9000,90000,3,15};
				int expected__            = 38;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				int lowerBound[]          = {1,1,1,1,1,1};
				int upperBound[]          = {3,4,5,6,7,8};
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
		case 5: {
				int lowerBound[]          = {16859, 287723} ;
				int upperBound[]          = {287608, 630151};
				int expected__            = 900787;
				
				clock_t start__           = clock();
				int received__            = Over9000Rocks().countPossibilities (vector <int> (lowerBound, lowerBound + (sizeof lowerBound / sizeof lowerBound[0])), vector <int> (upperBound, upperBound + (sizeof upperBound / sizeof upperBound[0])));
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			/*      case 6: {
						int lowerBound[]          = ;
						int upperBound[]          = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof lowerBound[0] ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof upperBound[0] ) ) );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 7: {
						int lowerBound[]          = ;
						int upperBound[]          = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = Over9000Rocks().countPossibilities( vector <int>( lowerBound, lowerBound + ( sizeof lowerBound / sizeof lowerBound[0] ) ), vector <int>( upperBound, upperBound + ( sizeof upperBound / sizeof upperBound[0] ) ) );
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
