// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Three kids are playing the following game: A word is written on a sheet of paper, and one after another, the players take turns adding letters to the word.  During each turn, a player must add a single letter to either the beginning or the end of the word. If a player cannot add a letter during his turn, the game ends and that player is declared the loser.



During the game, a player might cheat by making an illegal move. Any move where the player does not add exactly one letter to either the beginning or the end of the word is considered illegal. The only exception is the last move of the game, when the loser adds no letters to the word. Given the log of the game, you must determine whether any of the players cheated.



You are also given the vector <string>s first, second, and third, containing the chronological lists of words seen by each of the players at the beginning of their turns. Element 0 of first is therefore the original word, element 0 of second is the word after the first player makes his first move, element 0 of third is the word after the second player makes his first move, etc.  Return 1, 2, or 3 if the first, second, or third player, respectively, cheated.  If multiple players cheated, return the player who cheated first.  If nobody cheated, return -1.



DEFINITION
Class:KidsWordGame
Method:getCheater
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getCheater(vector <string> first, vector <string> second, vector <string> third)


CONSTRAINTS
-first will contain between 1 and 50 elements, inclusive.
-second and third each will contain between 0 and 50 elements, inclusive.
-Each element of first, second and third will contain between 0 and 50 characters, inclusive.
-Each element of first, second and third will contain only lowercase letters ('a'-'z').
-Define a = the number of elements in first, b = the number of elements in second, c = the number of elements in third. One of the following conditions will hold: a = b = c, a = b+1 = c+1, a = b = c+1.


EXAMPLES

0)
{"e","ello"}
{"el","hello"}
{"ell","ello"}

Returns: 2

The second player saw "hello" before making his second move, and then, the third player saw "ello" immediately after the second player made his second move.  Therefore, the second player cheated on his second move because "hello" -> "ello" is not a legal move.


1)
{"de","coder","topcoder"}
{"der","pcoder","tipcoder"}
{"oder","opcoder","cheatcoder"}

Returns: 1

The first player cheated on his third turn. "topcoder" -> "tipcoder" is an illegal move.


2)
{"world","sworld"}
{"word"}
{"sword"}

Returns: 1

3)
{"","abcd"}
{"a"}
{"ab"}

Returns: 3

In this case, the third player added more than one letter to the word.  Note that the initial word may be empty.


4)
{""}
{}
{}

Returns: -1

5)
{""}
{""}
{""}

Returns: 1

The first player did not add a letter, so he is a cheater.


6)
{"e","wyve","vffwyve","puvffwyvef","bpuvffwyveftl",
"tbpuvffwyveftlwz","ttbpuvffwyveftlwzcl",
"ttbpuvffwyveftlwzcletq","uuttbpuvffwyveftlwzcletqh",
"sjuuttbpuvffwyveftlwzcletqhd","vuysjuuttbpuvffwyveftlwzcletqhd",
"vjvuysjuuttbpuvffwyveftlwzcletqhdn",
"qsvjvuysjuuttbpuvffwyveftlwzcletqhdnn",
"hmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj",
"ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm",
"ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudk",
"jqophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"}
{"ve","fwyve","uvffwyve","puvffwyveft","bpuvffwyveftlw","ttbpuvffwyveftlwz",
"ttbpuvffwyveftlwzcle","ttbpuvffwyveftlwzcletqh","uuttbpuvffwyveftlwzcletqhd",
"ysjuuttbpuvffwyveftlwzcletqhd","jvuysjuuttbpuvffwyveftlwzcletqhd",
"vjvuysjuuttbpuvffwyveftlwzcletqhdnn","qsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj",
"hmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm",
"ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmu",
"ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"}
{"yve","ffwyve","uvffwyvef","puvffwyveftl","tbpuvffwyveftlw","ttbpuvffwyveftlwzc",
"ttbpuvffwyveftlwzclet","uttbpuvffwyveftlwzcletqh","juuttbpuvffwyveftlwzcletqhd",
"uysjuuttbpuvffwyveftlwzcletqhd","vjvuysjuuttbpuvffwyveftlwzcletqhd",
"svjvuysjuuttbpuvffwyveftlwzcletqhdnn","mqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj",
"phmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm",
"ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmud",
"qophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"}

Returns: -1

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
#define OP begin()
#define ED end()
#define SZ size() 
typedef long long LL;
typedef pair<int, int> PII;

bool cheat(string a,string b){
	if(b.SZ!=a.SZ+1)return 1;
	int i;
	string tp;
	tp="";
	for(i=1;i<b.SZ;i++)tp.PB(b[i]);
	if(tp==a)return 0;
	tp="";
	for(i=0;i+1<b.SZ;i++)tp.PB(b[i]);
	if(tp==a)return 0;
	return 1;
}
class KidsWordGame {
public:
  int getCheater (vector <string> first, vector <string> second, vector <string> third) {
		vector<string>L[3],G;
		L[0]=first,L[1]=second,L[2]=third;
		int i,j;
		for(j=0;j<L[0].size();j++)for(i=0;i<3;i++)if(L[i].SZ>j)G.PB(L[i][j]);
		if(G.size()<=1)return -1;
		for(i=1;i<G.size();i++)if(cheat(G[i-1],G[i])){
			cout<<G[i-1]<<" "<<G[i]<<endl;
			if(i%3)return i%3;
			else return 3;
		}
		return -1;
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
			string first[]            = {"e","ello"};
			string second[]           = {"el","hello"};
			string third[]            = {"ell","ello"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string first[]            = {"de","coder","topcoder"};
			string second[]           = {"der","pcoder","tipcoder"};
			string third[]            = {"oder","opcoder","cheatcoder"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string first[]            = {"world","sworld"};
			string second[]           = {"word"};
			string third[]            = {"sword"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string first[]            = {"","abcd"};
			string second[]           = {"a"};
			string third[]            = {"ab"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string first[]            = {""};
			string second[]           = {};
			string third[]            = {};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string first[]            = {""};
			string second[]           = {""};
			string third[]            = {""};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			string first[]            = {"e","wyve","vffwyve","puvffwyvef","bpuvffwyveftl", "tbpuvffwyveftlwz","ttbpuvffwyveftlwzcl", "ttbpuvffwyveftlwzcletq","uuttbpuvffwyveftlwzcletqh", "sjuuttbpuvffwyveftlwzcletqhd","vuysjuuttbpuvffwyveftlwzcletqhd", "vjvuysjuuttbpuvffwyveftlwzcletqhdn", "qsvjvuysjuuttbpuvffwyveftlwzcletqhdnn", "hmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj", "ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm", "ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudk", "jqophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"};
			string second[]           = {"ve","fwyve","uvffwyve","puvffwyveft","bpuvffwyveftlw","ttbpuvffwyveftlwz", "ttbpuvffwyveftlwzcle","ttbpuvffwyveftlwzcletqh","uuttbpuvffwyveftlwzcletqhd", "ysjuuttbpuvffwyveftlwzcletqhd","jvuysjuuttbpuvffwyveftlwzcletqhd", "vjvuysjuuttbpuvffwyveftlwzcletqhdnn","qsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj", "hmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm", "ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmu", "ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"};
			string third[]            = {"yve","ffwyve","uvffwyvef","puvffwyveftl","tbpuvffwyveftlw","ttbpuvffwyveftlwzc", "ttbpuvffwyveftlwzclet","uttbpuvffwyveftlwzcletqh","juuttbpuvffwyveftlwzcletqhd", "uysjuuttbpuvffwyveftlwzcletqhd","vjvuysjuuttbpuvffwyveftlwzcletqhd", "svjvuysjuuttbpuvffwyveftlwzcletqhdnn","mqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnj", "phmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjm", "ophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmud", "qophmqsvjvuysjuuttbpuvffwyveftlwzcletqhdnnjmudku"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			string first[]            = ;
			string second[]           = ;
			string third[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string first[]            = ;
			string second[]           = ;
			string third[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			string first[]            = ;
			string second[]           = ;
			string third[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KidsWordGame().getCheater( vector <string>( first, first + ( sizeof first / sizeof first[0] ) ), vector <string>( second, second + ( sizeof second / sizeof second[0] ) ), vector <string>( third, third + ( sizeof third / sizeof third[0] ) ) );
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
