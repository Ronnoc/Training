// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Crow Keith is looking at the goose cage in the zoo.
The bottom of the cage is divided into a grid of square cells.
There are some birds sitting on those cells (with at most one bird per cell).
Some of them are geese and all the others are ducks.

Keith wants to know which birds are geese.
He knows the following facts about them:

There is at least one goose in the cage.
The number of geese is even.
Each bird within Manhattan distance dist of any goose is also a goose.


You are given a vector <string> field and the int dist.
The array field describes the bottom of the cage.
Each character of each element of field describes one of the cells.
The meaning of individual characters follows.

The character 'v' represents a cell that contains a bird.
The character '.' represents an empty cell.


Return the number of possible sets of geese in the cage, modulo 1,000,000,007.
Note that for some of the test cases there can be no possible sets of geese.

DEFINITION
Class:GooseInZooDivOne
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> field, int dist)


NOTES
-The Manhattan distance between cells (a,b) and (c,d) is |a-c| + |b-d|, where || denotes absolute value. In words, the Manhattan distance is the smallest number of steps needed to get from one cell to the other, given that in each step you can move to a cell that shares a side with your current cell.


CONSTRAINTS
-field will contain between 1 and 50 elements, inclusive.
-Each element of field will contain between 1 and 50 characters, inclusive.
-Each element of field will contain the same number of characters.
-Each character of each element of field will be 'v' or '.'.
-dist will be between 0 and 100, inclusive.


EXAMPLES

0)
{"vvv"}
0

Returns: 3

There are three possible sets of positions of geese: "ggd", "gdg", or "dgg" ('g' are geese and 'd' are ducks).

1)
{"."}
100

Returns: 0

The number of geese must be positive, but there are no birds in the cage.

2)
{"vvv"}
1

Returns: 0



3)
{"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}
3

Returns: 898961330



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

LL mod = 1000000007;
LL comb[2505][2505];
int fa[2505];
int rk[2505];
int _abs (int x) {return x>0?x:-x;}
int getfa (int x) {
	return fa[x]==x?x:fa[x]=getfa (fa[x]);
}
class GooseInZooDivOne {
public:
	int count (vector <string> F, int D) {
		LL ret=0LL;
		int i,j;
		memset (comb,0,sizeof comb);
		memset (rk,0,sizeof rk);
		comb[0][0]=1;
		vector<PII>L;
		for (i=0; i<F.SZ; i++) for (j=0; j<F[i].SZ; j++)
				if (F[i][j]=='v') L.PB (MP (i,j));
		for (i=0; i<L.SZ; i++) fa[i]=i;
		for (i=0; i<L.SZ; i++) rk[i]=1;
		for (i=0; i<L.SZ; i++) for (j=i+1; j<L.SZ; j++)
				if (_abs (L[i].AA-L[j].AA) +_abs (L[i].BB-L[j].BB) <=D) {
					int fi=getfa (i);
					int fj=getfa (j);
//					cout<<fi<<"&"<<fj<<endl;
					if (fi!=fj) {
						fa[fj]=fi;
						rk[fi]+=rk[fj];
						rk[fj]=0;
					}
				}
		for (i=1; i<=L.SZ; i++) {
			comb[i][0]=1;
			for (j=1; j<=i; j++)
				comb[i][j]= (comb[i-1][j-1]+comb[i-1][j]) %mod;
		}
		vector<int>odd,even;
		for (i=0; i<L.SZ; i++)
			if (getfa (i) ==i)
				if (rk[i]&1) odd.PB (i);
				else even.PB (i);
		for (i=0; i<=odd.SZ; i+=2) {
			for (j=0; j<=even.SZ; j++)
				ret+=comb[odd.SZ][i]*comb[even.SZ][j]%mod;
			if (i==0) ret-=comb[odd.SZ][i]*comb[even.SZ][0];
		}
//		for (i=0; i<F.SZ; i++) cout<<F[i]<<endl;
//		for (i=0; i<L.SZ; i++) cout<<rk[i]<<" ";
//		cout<<endl;
//		for (i=0; i<L.SZ; i++) cout<<fa[i]<<" ";
//		cout<<endl;
//		cout<<ret%mod<<endl;
//		system("pause");
		return int ( (ret%mod+mod) %mod);
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
				string field[]            = {"vvv"};
				int dist                  = 0;
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = GooseInZooDivOne().count (vector <string> (field, field + (sizeof field / sizeof field[0])), dist);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string field[]            = {"."};
				int dist                  = 100;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = GooseInZooDivOne().count (vector <string> (field, field + (sizeof field / sizeof field[0])), dist);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string field[]            = {"vvv"};
				int dist                  = 1;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = GooseInZooDivOne().count (vector <string> (field, field + (sizeof field / sizeof field[0])), dist);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string field[]            = {"v.v..................v............................" ,".v......v..................v.....................v" ,"..v.....v....v.........v...............v......v..." ,".........vvv...vv.v.........v.v..................v" ,".....v..........v......v..v...v.......v..........." ,"...................vv...............v.v..v.v..v..." ,".v.vv.................v..............v............" ,"..vv.......v...vv.v............vv.....v.....v....." ,"....v..........v....v........v.......v.v.v........" ,".v.......v.............v.v..........vv......v....." ,"....v.v.......v........v.....v.................v.." ,"....v..v..v.v..............v.v.v....v..........v.." ,"..........v...v...................v..............v" ,"..v........v..........................v....v..v..." ,"....................v..v.........vv........v......" ,"..v......v...............................v.v......" ,"..v.v..............v........v...............vv.vv." ,"...vv......v...............v.v..............v....." ,"............................v..v.................v" ,".v.............v.......v.........................." ,"......v...v........................v.............." ,".........v.....v..............vv.................." ,"................v..v..v.........v....v.......v...." ,"........v.....v.............v......v.v............" ,"...........v....................v.v....v.v.v...v.." ,"...........v......................v...v..........." ,"..........vv...........v.v.....................v.." ,".....................v......v............v...v...." ,".....vv..........................vv.v.....v.v....." ,".vv.......v...............v.......v..v.....v......" ,"............v................v..........v....v...." ,"................vv...v............................" ,"................v...........v........v...v....v..." ,"..v...v...v.............v...v........v....v..v...." ,"......v..v.......v........v..v....vv.............." ,"...........v..........v........v.v................" ,"v.v......v................v....................v.." ,".v........v................................v......" ,"............................v...v.......v........." ,"........................vv.v..............v...vv.." ,".......................vv........v.............v.." ,"...v.............v.........................v......" ,"....v......vv...........................v........." ,"....vv....v................v...vv..............v.." ,".................................................." ,"vv........v...v..v.....v..v..................v...." ,".........v..............v.vv.v.............v......" ,".......v.....v......v...............v............." ,"..v..................v................v....v......" ,".....v.....v.....................v.v......v......."};
				int dist                  = 3;
				int expected__            = 898961330;
				
				clock_t start__           = clock();
				int received__            = GooseInZooDivOne().count (vector <string> (field, field + (sizeof field / sizeof field[0])), dist);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
		case 4: {
				string field[]            = {".v...", "v.v.v", ".....", "....."};
				int dist                  = 2;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = GooseInZooDivOne().count (vector <string> (field, field + (sizeof field / sizeof field[0])), dist);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			/*      case 5: {
						string field[]            = ;
						int dist                  = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = GooseInZooDivOne().count( vector <string>( field, field + ( sizeof field / sizeof field[0] ) ), dist );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 6: {
						string field[]            = ;
						int dist                  = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = GooseInZooDivOne().count( vector <string>( field, field + ( sizeof field / sizeof field[0] ) ), dist );
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
