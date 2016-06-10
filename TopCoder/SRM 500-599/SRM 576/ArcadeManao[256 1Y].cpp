// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You might remember the old computer arcade games. Here is one about Manao.

The game level is an NxM grid of equal cells. The bottom of some cells has a platform at which Manao can stand. All the cells in the bottommost row contain a platform, thus covering the whole ground of the level. The rows of the grid are numbered from 1 to N starting from the top and the columns are numbered from 1 to M starting from the left. Exactly one cell contains a coin and Manao needs to obtain it.

Initially, Manao is standing on the ground, i.e., in the bottommost row. He can move between two horizontally adjacent cells if both contain a platform. Also, Manao has a ladder which he can use to climb. He can use the ladder to climb both up and down. If the ladder is L units long, Manao can climb between two cells (i1, j) and (i2, j) if both contain a platform and |i1-i2| <= L. Note that Manao carries the ladder along, so he can use it multiple times. You need to determine the minimum ladder length L which is sufficient to acquire the coin.

Take a look at the following picture. On this level, Manao will manage to get the coin with a ladder of length 2.



You are given a vector <int> level containing N elements. The j-th character in the i-th row of level is 'X' if cell (i+1, j+1) contains a platform and '.' otherwise. You are also given ints coinRow and coinColumn. The coin which Manao seeks is located in cell (coinRow, coinColumn) and it is guaranteed that this cell contains a platform.

Return the minimum L such that ladder of length L is enough to get the coin. If Manao can perform the task without using the ladder, return 0.

DEFINITION
Class:ArcadeManao
Method:shortestLadder
Parameters:vector <string>, int, int
Returns:int
Method signature:int shortestLadder(vector <string> level, int coinRow, int coinColumn)


NOTES
-Manao is not allowed to fall. The only way in which he may change his vertical coordinate is by using the ladder.


CONSTRAINTS
-level will contain N elements, where N is between 1 and 50, inclusive.
-Each element of level will be M characters long, where M is between 1 and 50, inclusive.
-Each element of level will consist of '.' and 'X' characters only.
-The last element of level will be entirely filled with 'X'.
-coinRow will be between 1 and N, inclusive.
-coinColumn will be between 1 and M, inclusive.
-level[coinRow - 1][coinColumn - 1] will be 'X'.


EXAMPLES

0)
{"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}
2
4

Returns: 2

The example from the problem statement.

1)
{"XXXX",
 "...X",
 "XXXX"}
1
1

Returns: 1

Manao can use the ladder to climb from the ground to cell (2, 4), then to cell (1, 4) and then he can walk right to the coin.

2)
{"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}
1
3

Returns: 4

With a ladder of length 4, Manao can first climb to cell (5, 3) and then right to (1, 3).

3)
{"X"}
1
1

Returns: 0

Manao begins in the same cell as the coin.

4)
{"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}
1
1

Returns: 2



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

vector<pair<PII,int> >L;
int fa[2550];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
class ArcadeManao {
public:
  int shortestLadder (vector <string> M, int X, int Y) {
  	X--;Y--;
    int ret;
    int i,j,k;
    L.clear();
    for(i=0;i<M.SZ;i++){
			cout<<M[i]<<endl;
			for(j=0;j<M[i].SZ;){
				while(j<M[i].SZ&&M[i][j]=='.')j++;
				int l=j;
				while(j<M[i].SZ&&M[i][j]=='X')j++;
				int r=j-1;
				if(l<M[i].SZ)L.PB(MP(MP(l,r),i));
				j=r+1;
//				system("pause");
			}
    }
    int x=M.SZ-1,y=M[0].SZ-1;
    int s,t;
    for(i=0;i<L.SZ;i++){
			if(L[i].AA.AA<=y&&L[i].AA.BB>=y&&L[i].BB==x)s=i;
			if(L[i].AA.AA<=Y&&L[i].AA.BB>=Y&&L[i].BB==X)t=i;
//			cout<<L[i].AA.AA<<" "<<L[i].AA.BB<<" "<<L[i].BB<<endl;
    }
//    cout<<s<<" "<<t<<endl;
    for(ret=0;;ret++){
//			cout<<ret<<endl;
			for(i=0;i<L.SZ;i++)fa[i]=i;
			for(i=0;i<L.SZ;i++)
				for(j=i+1;j<L.SZ;j++){
//					cout<<"!"<<i<<" "<<j<<":";
					if(L[i].AA.AA>L[j].AA.BB)continue;
//					cout<<"1";
					if(L[j].AA.AA>L[i].AA.BB)continue;
//					cout<<"2";
					if(L[i].BB+ret<L[j].BB)continue;
//					cout<<"3";
					if(L[j].BB+ret<L[i].BB)continue;
//					cout<<"4";
					int fi=getfa(i),fj=getfa(j);
//					cout<<fi<<" "<<fj<<endl;
					fa[fi]=fj;
				}
			if(getfa(s)==getfa(t))return ret;
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
			string level[]            = {"XXXX....",  "...X.XXX",  "XXX..X..",  "......X.",  "XXXXXXXX"};
			int coinRow               = 2;
			int coinColumn            = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string level[]            = {"XXXX",  "...X",  "XXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string level[]            = {"..X..",  ".X.X.",  "X...X",  ".X.X.",  "..X..",  "XXXXX"};
			int coinRow               = 1;
			int coinColumn            = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string level[]            = {"X"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string level[]            = {"XXXXXXXXXX",  "...X......",  "XXX.......",  "X.....XXXX",  "..XXXXX..X",  ".........X",  ".........X",  "XXXXXXXXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder( vector <string>( level, level + ( sizeof level / sizeof level[0] ) ), coinRow, coinColumn );
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
