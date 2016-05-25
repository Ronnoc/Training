// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel loves music.
She currently has n songs in her mp3 player.
Their file names are "1.mp3", "2.mp3", and so on, until string(n)+".mp3".



Sadly, Ciel's mp3 player does not sort the files according to the number.
Instead, it simply sorts the file names in lexicographic order, as strings.
So, for instance, if n=10 then the sorted order looks as follows:
"1.mp3", "10.mp3", "2.mp3", ..., "9.mp3".



You are given the int n.
If n is at most 50, return a vector <string> containing the entire sorted list of file names.
If n is more than 50, return a vector <string> containing the first 50 elements of the sorted list of file names.

DEFINITION
Class:FoxAndMp3
Method:playList
Parameters:int
Returns:vector <string>
Method signature:vector <string> playList(int n)


NOTES
-The string A is lexicographically smaller than the string B if either of the following two conditions holds: 1. A is a proper prefix of B; 2. There is an index i such that the first (i-1) characters of A and B are equal, and character i of A has a smaller ASCII value than character i of B.


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
3

Returns: {"1.mp3", "2.mp3", "3.mp3" }

We have 3 files: "1.mp3", "2.mp3", and "3.mp3".
This is also their lexicographic order.

1)
10

Returns: {"1.mp3", "10.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" }

This is the example from the problem statement.

2)
16

Returns: {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" }



3)
32

Returns: {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "17.mp3", "18.mp3", "19.mp3", "2.mp3", "20.mp3", "21.mp3", "22.mp3", "23.mp3", "24.mp3", "25.mp3", "26.mp3", "27.mp3", "28.mp3", "29.mp3", "3.mp3", "30.mp3", "31.mp3", "32.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" }



4)
100000009

Returns: {"1.mp3", "10.mp3", "100.mp3", "1000.mp3", "10000.mp3", "100000.mp3", "1000000.mp3", "10000000.mp3", "100000000.mp3", "100000001.mp3", "100000002.mp3", "100000003.mp3", "100000004.mp3", "100000005.mp3", "100000006.mp3", "100000007.mp3", "100000008.mp3", "100000009.mp3", "10000001.mp3", "10000002.mp3", "10000003.mp3", "10000004.mp3", "10000005.mp3", "10000006.mp3", "10000007.mp3", "10000008.mp3", "10000009.mp3", "1000001.mp3", "10000010.mp3", "10000011.mp3", "10000012.mp3", "10000013.mp3", "10000014.mp3", "10000015.mp3", "10000016.mp3", "10000017.mp3", "10000018.mp3", "10000019.mp3", "1000002.mp3", "10000020.mp3", "10000021.mp3", "10000022.mp3", "10000023.mp3", "10000024.mp3", "10000025.mp3", "10000026.mp3", "10000027.mp3", "10000028.mp3", "10000029.mp3", "1000003.mp3" }



5)
1

Returns: {"1.mp3" }



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

char s[111];
class FoxAndMp3 {
public:
	vector <string> playList (int n) {
		vector <string> ret;
		set<string>tp;
		set<string>::iterator iter;
		sprintf (s,"%d.mp3",n);
		tp.insert (string (s));
		if (n<=100000) {
			int i;
			for (i=1; i<=n; i++) {
				sprintf (s,"%d.mp3",i);
				tp.insert (string (s));
			}
			for (iter=tp.OP; ret.SZ<50&&iter!=tp.ED; ++iter)
				ret.PB (*iter);
		} else {
			int m=1000000000;
			while (m>n)
				m/=10;
			while (m) {
				for (int i=0; i<=100; i++)
					if (i+m<=n) {
						sprintf (s,"%d.mp3",i+m);
						tp.insert (string (s));
					}
				m/=10;
			}
			for (int i=1; i<=100; i++)
				if (i<=n) {
					sprintf (s,"%d.mp3",i);
					tp.insert (string (s));
				}
			for (iter=tp.OP; ret.SZ<50&&iter!=tp.ED; ++iter)
				ret.PB (*iter);
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

template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<< (ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

int verify_case (int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) {
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
				int n                     = 3;
				string expected__[]       = {"1.mp3", "2.mp3", "3.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
		case 1: {
				int n                     = 10;
				string expected__[]       = {"1.mp3", "10.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
		case 2: {
				int n                     = 16;
				string expected__[]       = {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
		case 3: {
				int n                     = 32;
				string expected__[]       = {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "17.mp3", "18.mp3", "19.mp3", "2.mp3", "20.mp3", "21.mp3", "22.mp3", "23.mp3", "24.mp3", "25.mp3", "26.mp3", "27.mp3", "28.mp3", "29.mp3", "3.mp3", "30.mp3", "31.mp3", "32.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
		case 4: {
				int n                     = 100000009;
				string expected__[]       = {"1.mp3", "10.mp3", "100.mp3", "1000.mp3", "10000.mp3", "100000.mp3", "1000000.mp3", "10000000.mp3", "100000000.mp3", "100000001.mp3", "100000002.mp3", "100000003.mp3", "100000004.mp3", "100000005.mp3", "100000006.mp3", "100000007.mp3", "100000008.mp3", "100000009.mp3", "10000001.mp3", "10000002.mp3", "10000003.mp3", "10000004.mp3", "10000005.mp3", "10000006.mp3", "10000007.mp3", "10000008.mp3", "10000009.mp3", "1000001.mp3", "10000010.mp3", "10000011.mp3", "10000012.mp3", "10000013.mp3", "10000014.mp3", "10000015.mp3", "10000016.mp3", "10000017.mp3", "10000018.mp3", "10000019.mp3", "1000002.mp3", "10000020.mp3", "10000021.mp3", "10000022.mp3", "10000023.mp3", "10000024.mp3", "10000025.mp3", "10000026.mp3", "10000027.mp3", "10000028.mp3", "10000029.mp3", "1000003.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
		case 5: {
				int n                     = 1;
				string expected__[]       = {"1.mp3" };
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
			
			// custom cases
			
		case 6: {
				int n                     = 1000000000;
				string expected__[]       = {"1.mp3", "10.mp3", "100.mp3", "1000.mp3", "10000.mp3", "100000.mp3", "1000000.mp3", "10000000.mp3", "100000000.mp3", "1000000000.mp3", "100000001.mp3", "100000002.mp3", "100000003.mp3", "100000004.mp3", "100000005.mp3", "100000006.mp3", "100000007.mp3", "100000008.mp3", "100000009.mp3", "10000001.mp3", "100000010.mp3", "100000011.mp3", "100000012.mp3", "100000013.mp3", "100000014.mp3", "100000015.mp3", "100000016.mp3", "100000017.mp3", "100000018.mp3", "100000019.mp3", "10000002.mp3", "100000020.mp3", "100000021.mp3", "100000022.mp3", "100000023.mp3", "100000024.mp3", "100000025.mp3", "100000026.mp3", "100000027.mp3", "100000028.mp3", "100000029.mp3", "10000003.mp3", "100000030.mp3", "100000031.mp3", "100000032.mp3", "100000033.mp3", "100000034.mp3", "100000035.mp3", "100000036.mp3", "100000037.mp3"};
				
				clock_t start__           = clock();
				vector <string> received__ = FoxAndMp3().playList (n);
				return verify_case (casenum, vector <string> (expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
			}
			/*      case 7: {
						int n                     = ;
						string expected__[]       = ;
			
						clock_t start__           = clock();
						vector <string> received__ = FoxAndMp3().playList( n );
						return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
					}*/
			/*      case 8: {
						int n                     = ;
						string expected__[]       = ;
			
						clock_t start__           = clock();
						vector <string> received__ = FoxAndMp3().playList( n );
						return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
