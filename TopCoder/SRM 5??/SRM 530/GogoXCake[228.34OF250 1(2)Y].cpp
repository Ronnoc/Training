// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Like all other software engineers, Gogo likes to cut and eat cake. He used a rectangular baking dish to make a cake. The dish is divided into a grid of unit square cells. Initially, all the cells contained the cake.

Gogo's friend John wanted to eat the cake. Gogo gave John a rectangular cake cutter with the following properties:

The cake cutter is divided into a grid of cells. The cells are of the same size as the cells of the dish.
The cake cutter contains cells of two types: used cells and ignored cells.
Each of the first row, the last row, the first column, and the last column of the cutter contains at least one used cell.

When used, the cake cutter must be placed on the dish according to the following rules:

Each cell of the cutter must contain a single cell of the dish.
It is not allowed to flip or rotate the cutter. Rows and columns of the cutter must correspond to some consecutive rows and some consecutive columns of the dish in the given orientation. (See the last two examples.)
Each used cell of the cutter must be placed onto a cell that still contains cake. The ignored cells may be placed onto any cells.


When the cake cutter is used in the way described above, it removes the cake from all the used cells. John may have used the cake cutter multiple times, one after another.

After John went home, Gogo examined the cake that remained in the dish. He now wants to check whether John really cut the cake according to the above rules. You are given vector <string>s cake and cutter. The remaining cake is described by cake. More precisely, cake[i][j] is 'X' if the cell in the i-th row and j-th column of the dish still contains cake; otherwise cake[i][j] is '.' (a period). The cake cutter is described by cutter. More precisely, cutter[i][j] is '.' (a period) if the cell in the i-th row and j-th column of the cutter is used, and 'X' if the cell is ignored.

Return "YES" (quotes for clarity) if it is possible that John only ate the cake by using the cutter in the way described above. Return "NO" otherwise.

DEFINITION
Class:GogoXCake
Method:solve
Parameters:vector <string>, vector <string>
Returns:string
Method signature:string solve(vector <string> cake, vector <string> cutter)


NOTES
-The used cells in the cutter do not have to be contiguous.


CONSTRAINTS
-cake will contain between 1 and 50 elements, inclusive.
-Each element of cake will contain between 1 and 50 characters, inclusive.
-All elements of cake will contain the same number of characters.
-Each character in each element of cake will be either '.' or 'X'.
-There will be at least one '.' in cake
-cutter will contain between 1 and R elements, inclusive, where R is the number of elements in cake.
-Each element of cutter will contain between 1 and C characters, inclusive, where C is the number of characters in each element of cake.
-All elements of cutter will contain the same number of characters.
-Each character in each element of cutter will be either '.' or 'X'.
-Each of the first row, the first column, the last row, and the last column of the cutter will contain at least one '.'.


EXAMPLES

0)
{"X.X"
,"..."
,"..."
,"X.X"}
{".X"
,".."
,"X."}

Returns: "YES"



1)
{"..XX"
,"...X"
,"X..."
,"XX.."}
{".."
,".."}

Returns: "NO"



2)
{"...X..."}
{"..."}

Returns: "YES"



3)
{".X."
,"X.X"
,".X."}
{"."}

Returns: "YES"



4)
{"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}
{".X."
,"XXX"
,".X."}

Returns: "NO"



5)
{".."
,"X."
,".X"}
{".."
,".X"
,"X."}

Returns: "NO"

You may not flip the cutter.

6)
{"X.."
,".XX"
,".XX"}
{".XX"
,".XX"
,"X.."}

Returns: "NO"

You may not rotate the cutter.

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


class GogoXCake {
public:
  string solve (vector <string> s, vector <string> c) {
    int i,j,p,q;
    while(1){
			int has=0;
			for(i=0;i<s.SZ;i++)for(j=0;j<s[i].SZ;j++)if(s[i][j]=='.')has=1;
			if(!has)return string("YES");
			int add=0;
			for(i=0;!add&&i<s.SZ;i++)for(j=0;!add&&j<s[i].SZ;j++){
				int allfit=1;
				for(p=0;p<c.SZ;p++)for(q=0;q<c[p].SZ;q++){
					int x=i+p;
					int y=j+q;
					if(x>=s.SZ){allfit=0;continue;}
					if(y>=s[i].SZ){allfit=0;continue;}
					if(c[p][q]=='.'&&s[x][y]=='X')allfit=0;
				}
				if(!allfit)continue;
				for(p=0;p<c.SZ;p++)for(q=0;q<c[p].SZ;q++){
					int x=i+p;
					int y=j+q;
					if(c[p][q]=='.')s[x][y]='X';
				}
				add=1;
			}
			if(!add)return string("NO");
    }
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string cake[]             = {"X.X" ,"..." ,"..." ,"X.X"};
			string cutter[]           = {".X" ,".." ,"X."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string cake[]             = {"..XX" ,"...X" ,"X..." ,"XX.."};
			string cutter[]           = {".." ,".."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string cake[]             = {"...X..."};
			string cutter[]           = {"..."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string cake[]             = {".X." ,"X.X" ,".X."};
			string cutter[]           = {"."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string cake[]             = {"XXXXXXX" ,"X.....X" ,"X.....X" ,"X.....X" ,"XXXXXXX"};
			string cutter[]           = {".X." ,"XXX" ,".X."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string cake[]             = {".." ,"X." ,".X"};
			string cutter[]           = {".." ,".X" ,"X."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			string cake[]             = {"X.." ,".XX" ,".XX"};
			string cutter[]           = {".XX" ,".XX" ,"X.."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 7: {
			string cake[]             = ;
			string cutter[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string cake[]             = ;
			string cutter[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			string cake[]             = ;
			string cutter[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = GogoXCake().solve( vector <string>( cake, cake + ( sizeof cake / sizeof cake[0] ) ), vector <string>( cutter, cutter + ( sizeof cutter / sizeof cutter[0] ) ) );
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
