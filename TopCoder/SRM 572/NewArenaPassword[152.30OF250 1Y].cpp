// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You are a huge fan of an online programming contest called SRM (Special Round Match). To participate in an SRM contest, you must first download an applet called Arena, log in to the Arena by entering your username and password, and start competing.

Recently, to avoid hackers' attacks on the Arena, SRM imposes a new rule for the users' passwords. From now on, the first K characters of each user's password must match its last K characters. In this way, if someone enters a password with different first and last K characters repeatedly, it can be considered an attack from hackers.

However, you love your old password and do not want to change many characters from it. You are given a string oldPassword representing your old password, and an int K. Return the minimum number of characters of oldPassword that must be changed so that the string containing the first K characters of oldPassword is equal to the string containing the last K characters of oldPassword.

DEFINITION
Class:NewArenaPassword
Method:minChange
Parameters:string, int
Returns:int
Method signature:int minChange(string oldPassword, int K)


CONSTRAINTS
-oldPassword will contain between 1 and 50 characters, inclusive.
-Each character of oldPassword will be a lowercase letter 'a' - 'z'.
-K will be between 1 and the number of characters of oldPassword, inclusive.


EXAMPLES

0)
"topcoderopen"
5

Returns: 3

A possible solution is changing your password into "topcndetopcn". To do this, you must change the 4th, 7th, and 10th characters (0-based) of "topcoderopen".

1)
"puyopuyo"
4

Returns: 0

Your old password already satisfies the new rule.

2)
"loool"
3

Returns: 1

The first and the last K characters can overlap. In this case, the only optimal solution is to change your password into "lolol".

3)
"arena"
5

Returns: 0



4)
"amavckdkz"
"??amavckd"
7

Returns: 5
4)
"abcabcabca"
"???abcabca"
7

Returns: 5



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

int fa[55];
int getfa (int x) {
	return x==fa[x]?x:fa[x]=getfa (fa[x]);
}
map<char,int>F[55];
map<char,int>::iterator iter;
class NewArenaPassword {
public:
	int minChange (string o, int K) {
		if (K==o.SZ) return 0;
		cout<<o<<" "<<K<<endl;
		int ret=0;
		int len=o.SZ,i,j;
		for (i=0; i<o.SZ; i++) fa[i]=i;
		for (i=0; i<o.SZ; i++) F[i].clear();
		for (i=0; i<K; i++) {
			int l=i,r=len-K+i;
			int fl=getfa (l);
			int fr=getfa (r);
			fa[fl]=fr;
		}
		for (i=0; i<o.SZ; i++) F[getfa (i)][o[i]]++;
		for (i=0; i<o.SZ; i++) {
			if (F[i].empty()) continue;
			int mx=-1,tot=0;
			for (iter=F[i].OP; iter!=F[i].ED; ++iter)
				tot+= (*iter).BB;
			for (iter=F[i].OP; iter!=F[i].ED; ++iter)
				if ( (*iter).BB>mx) mx= (*iter).BB;
//			for (iter=F[i].OP; iter!=F[i].ED; ++iter)
//				cout<<(*iter).AA<<" with"<<(*iter).BB<<"  ";
//			cout<<endl;
			ret+=tot-mx;
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
				string oldPassword        = "topcoderopen";
				int K                     = 5;
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = NewArenaPassword().minChange (oldPassword, K);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string oldPassword        = "puyopuyo";
				int K                     = 4;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = NewArenaPassword().minChange (oldPassword, K);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string oldPassword        = "loool";
				int K                     = 3;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = NewArenaPassword().minChange (oldPassword, K);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string oldPassword        = "arena";
				int K                     = 5;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = NewArenaPassword().minChange (oldPassword, K);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string oldPassword        = "amavckdkz";
				int K                     = 7;
				int expected__            = 5;
				
				clock_t start__           = clock();
				int received__            = NewArenaPassword().minChange (oldPassword, K);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 5: {
						string oldPassword        = ;
						int K                     = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = NewArenaPassword().minChange( oldPassword, K );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 6: {
						string oldPassword        = ;
						int K                     = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = NewArenaPassword().minChange( oldPassword, K );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 7: {
						string oldPassword        = ;
						int K                     = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = NewArenaPassword().minChange( oldPassword, K );
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
