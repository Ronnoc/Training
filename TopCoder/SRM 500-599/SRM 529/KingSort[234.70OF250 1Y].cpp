// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Every good encyclopedia has an index. The entries in the index are usually sorted in alphabetic order. However, there are some notable exceptions. In this task we will consider one such exception: the names of kings.



In many countries it was common that kings of the same name received ordinal numbers. This ordinal number was written as a Roman numeral and appended to the actual name of the king.
For example, "Louis XIII" (read: Louis the thirteenth) was the thirteenth king of France having the actual name Louis.



In the index of an encyclopedia, kings who share the same name have to be sorted according to their ordinal numbers. For example, Louis the 9th should be listed after Louis the 8th.



You are given a vector <string> kings. Each element of kings is the name of one king. The name of each king consists of his actual name, a single space, and a Roman numeral. Return a vector <string> containing the names
rearranged into their proper order: that is, the kings have to be in ascending lexicographic order according to their actual name, and kings with the same name have to be in the correct numerical order.


DEFINITION
Class:KingSort
Method:getSortedList
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getSortedList(vector <string> kings)


NOTES
-The Roman numerals for 1 through 10 are I, II, III, IV, V, VI, VII, VIII, IX, and X.
-The Roman numerals for 20, 30, 40, and 50 are XX, XXX, XL, and L.
-The Roman numeral for any other two-digit number less than 50 can be constructed by concatenating the numeral for its tens and the numeral for its ones. For example, 47 is 40 + 7 = "XL" + "VII" = "XLVII".
-Standard string comparison routines give the correct ordering for the actual names of kings.
-Formally, given two different strings A and B we say that A is lexicographically smaller than B if either (A is a prefix of B) or (there is at least one index where A and B differ, and for the smallest such index the character in A has a lower ASCII value than the character in B).


CONSTRAINTS
-Each actual name of a king will be a string containing between 1 and 20 characters, inclusive.
-Each actual name will start by an uppercase letter ('A'-'Z').
-Each other character in each actual name will be a lowercase letter ('a'-'z').
-kings will contain between 1 and 50 elements, inclusive.
-Each element of kings will have the form "ACTUALNAME ORDINAL", where ACTUALNAME is an actual name as defined above, and ORDINAL is a valid Roman numeral representing a number between 1 and 50, inclusive.
-The elements of kings will be pairwise distinct.


EXAMPLES

0)
{"Louis IX", "Louis VIII"}

Returns: {"Louis VIII", "Louis IX" }

Louis the 9th should be listed after Louis the 8th.

1)
{"Louis IX", "Philippe II"}

Returns: {"Louis IX", "Philippe II" }

Actual names take precedence over ordinal numbers.

2)
{"Richard III", "Richard I", "Richard II"}

Returns: {"Richard I", "Richard II", "Richard III" }



3)
{"John X", "John I", "John L", "John V"}

Returns: {"John I", "John V", "John X", "John L" }



4)
{"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}

Returns: {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }

These are the French monarchs who ruled between 1328 and 1483.

5)
{"Philippe II", "Philip II"}

Returns: {"Philip II", "Philippe II" }

"Philippe" and "Philip" are distinct names, and "Philip" is lexicographically smaller than "Philippe".

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

int f(string s){
	if(s.empty())return 0;
	string tp="";
	int i;
	if(s.SZ>1&&s[0]=='X'&&s[1]=='L'){
		for(i=2;i<s.SZ;i++)tp+=s[i];
		return 40+f(tp);
	}
	if(s[0]=='L')return 50;
	if(s[0]=='X'){
		for(i=1;i<s.SZ;i++)tp+=s[i];
		return 10+f(tp);
	}
	if(s.SZ>1&&s[0]=='I'&&s[1]=='X'){
		for(i=2;i<s.SZ;i++)tp+=s[i];
		return 9+f(tp);
	}
	if(s.SZ>1&&s[0]=='I'&&s[1]=='V'){
		for(i=2;i<s.SZ;i++)tp+=s[i];
		return 4+f(tp);
	}
	if(s[0]=='V'){
		for(i=1;i<s.SZ;i++)tp+=s[i];
		return 5+f(tp);
	}
	if(s[0]=='I'){
		for(i=1;i<s.SZ;i++)tp+=s[i];
		return 1+f(tp);
	}
}
class KingSort {
public:
  vector <string> getSortedList (vector <string> K) {
    vector <string> ret;
    SORT(K);
    int i,j;
    for(i=0;i<K.SZ;i++)for(j=i+1;j<K.SZ;j++){
			istringstream sl(K[i]);
			istringstream sr(K[j]);
			string l,ln,r,rn;
			sl>>l>>ln;
			sr>>r>>rn;
			if(l!=r)continue;
			int fl=f(ln);
			int fr=f(rn);
			if(fl>fr)swap(K[i],K[j]);
    }
    return K;
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string kings[]            = {"Louis IX", "Louis VIII"};
			string expected__[]       = {"Louis VIII", "Louis IX" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			string kings[]            = {"Louis IX", "Philippe II"};
			string expected__[]       = {"Louis IX", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			string kings[]            = {"Richard III", "Richard I", "Richard II"};
			string expected__[]       = {"Richard I", "Richard II", "Richard III" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			string kings[]            = {"John X", "John I", "John L", "John V"};
			string expected__[]       = {"John I", "John V", "John X", "John L" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			string kings[]            = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
			string expected__[]       = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 5: {
			string kings[]            = {"Philippe II", "Philip II"};
			string expected__[]       = {"Philip II", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 7: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 8: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList( vector <string>( kings, kings + ( sizeof kings / sizeof kings[0] ) ) );
			return verify_case( casenum, vector <string>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
