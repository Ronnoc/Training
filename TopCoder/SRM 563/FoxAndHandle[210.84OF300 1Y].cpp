// BEGIN CUT HERE
/*
PROBLEM STATEMENT
We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".



Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
We can define Shuffle inductively as follows:

for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
for any letters a, b and any strings X, Y:
Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.




Fox Ciel wants to register on TopCoder.
In order to do that, she has to pick a handle.
Ciel has a pet cat called S.
As her handle, Ciel wants to use a string H with the following property:
S can be obtained by shuffling H and some permutation of H together.
For example, if S="ceiiclel", one possible handle would be H="ciel":
she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.



You are given the string S.
The constraints guarantee that there is at least one possible handle H with the above property.
Find and return the lexicographically smallest valid H.

DEFINITION
Class:FoxAndHandle
Method:lexSmallestName
Parameters:string
Returns:string
Method signature:string lexSmallestName(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').
-Each letter ('a'-'z') will occur in S an even number of times.


EXAMPLES

0)
"foxfox"

Returns: "fox"

There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
The lexicographically smallest one is "fox".

1)
"ccieliel"

Returns: "ceil"

Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.

2)
"abaabbab"

Returns: "aabb"



3)
"bbbbaaaa"

Returns: "bbaa"



4)
"fedcbafedcba"

Returns: "afedcb"



5)
"nodevillivedon"

Returns: "deilvon"



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

class FoxAndHandle {
public:
	string lexSmallestName (string S) {
		vector<int>id[55];
		string ret;
		int i,j;
		for (i=0; i<S.SZ; i++) id[S[i]-'a'].PB (i);
		int l=0;
		int now[33];
		memset (now,0,sizeof now);
		while (l<S.SZ) {
			int tot[33];
			int can[55];
			memset (tot,0,sizeof tot);
			memset (can,0,sizeof can);
			for (i=S.SZ-1; i>=l; i--) {
				tot[S[i]-'a']++;
				int wa=0;
				for (j=0; j<26; j++) if (2* (tot[j]+now[j]) <id[j].SZ) wa=1;
				if (!wa) can[i]=1;
			}
			int flag=-1;
			for (i=0; i<26; i++) {
				if (2*now[i]==id[i].SZ) continue;
				for (j=0; j<id[i].SZ; j++)
					if (id[i][j]>=l&&can[id[i][j]]) {flag=id[i][j]; break;}
				if (flag!=-1) break;
			}
			if (flag==-1) break;
//			cout<<flag<<" "<<S[flag]<<endl;
			ret+=S[flag];
			now[S[flag]-'a']++;
			l=flag+1;
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

int verify_case (int casenum, const string &expected, const string &received, clock_t elapsed) {
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
		cerr << "    Expected: \"" << expected << "\"" << endl;
		cerr << "    Received: \"" << received << "\"" << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				string S                  = "foxfox";
				string expected__         = "fox";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string S                  = "ccieliel";
				string expected__         = "ceil";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string S                  = "abaabbab";
				string expected__         = "aabb";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string S                  = "bbbbaaaa";
				string expected__         = "bbaa";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string S                  = "fedcbafedcba";
				string expected__         = "afedcb";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				string S                  = "nodevillivedon";
				string expected__         = "deilvon";
				
				clock_t start__           = clock();
				string received__         = FoxAndHandle().lexSmallestName (S);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 6: {
						string S                  = ;
						string expected__         = ;
			
						clock_t start__           = clock();
						string received__         = FoxAndHandle().lexSmallestName( S );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 7: {
						string S                  = ;
						string expected__         = ;
			
						clock_t start__           = clock();
						string received__         = FoxAndHandle().lexSmallestName( S );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 8: {
						string S                  = ;
						string expected__         = ;
			
						clock_t start__           = clock();
						string received__         = FoxAndHandle().lexSmallestName( S );
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
