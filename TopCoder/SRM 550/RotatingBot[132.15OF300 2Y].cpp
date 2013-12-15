// BEGIN CUT HERE
/*
PROBLEM STATEMENT
NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We had a rectangular grid that consisted of W x H square cells.
We placed a robot on one of the cells.
The robot then followed the rules given below.


Initially, the robot is facing east.
The robot moves in steps. In each step it moves to the adjacent cell in the direction it currently faces.
The robot may not leave the grid.
The robot may not visit the same cell twice. (This also means that it may not reenter the starting cell.)
If a step forward does not cause the robot to break the above rules, the robot takes the step.
Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and checks whether a step forward still breaks the above rules.
  If not, the robot takes the step and continues executing this program (still rotated in the new direction).
If the rotation left did not help, the robot terminates the execution of this program.
We can also terminate the execution of the program manually, at any moment.

For example, the following seven images show a series of moves made by the robot in a 12 x 11 board:


We forgot the dimensions of the grid and the original (x,y) coordinates of the cell on which the robot was originally placed, but we do remember its movement. You are given a vector <int> moves. This sequence of positive integers shall be interpreted as follows:
The robot performed moves[0] steps eastwards, turned left, performed moves[1] steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it detected that it should terminate, or we stopped it manually.) We are not sure if the sequence of moves is valid. If the sequence of moves is impossible, return -1. Else, return the minimum area of a grid in which the sequence of moves is possible.
(I.e., the return value is the smallest possible value of the product of W and H.).

DEFINITION
Class:RotatingBot
Method:minArea
Parameters:vector <int>
Returns:int
Method signature:int minArea(vector <int> moves)


CONSTRAINTS
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and 50, inclusive.


EXAMPLES

0)
{15}

Returns: 16

The smallest valid board is a 16x1 board, with the robot starting on the west end of the board.

1)
{3,10}

Returns: 44

The smallest solution is to place the robot into the southwest corner of a 4 x 11 board.

2)
{1,1,1,1}

Returns: -1

This sequence of moves is not possible because the robot would return to its initial location which is forbidden.

3)
{9,5,11,10,11,4,10}

Returns: 132

These moves match the image from the problem statement.

4)
{12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

Returns: 420

5)
{8,6,6,1}

Returns: -1



6)
{8,6,6}

Returns: 63



7)
{5,4,5,3,3}

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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int flag[5];
int mp[2505][2505];
class RotatingBot {
public:
  int minArea (vector <int> mv) {
    int ret;
    int i,j;
    memset(mp,0,sizeof mp);
    memset(flag,-1,sizeof flag);
    if(mv.SZ==0)return 1;
    if(mv.SZ==1)return mv[0]+1;
    if(mv.SZ==2)return (mv[0]+1)*(mv[1]+1);
    if(mv.SZ==3)return (max(mv[0],mv[2])+1)*(mv[1]+1);
    if(mv.SZ==4){
			for(i=0;i<mv.SZ;++i)cout<<mv[i]<<" ";cout<<endl;
			if(mv[2]<mv[0])return -1;
			if(mv[2]==mv[0])if(mv[3]>=mv[1])return -1;
			return (mv[2]+1)*(max(mv[1],mv[3])+1);
    }
    int w=mv[2]+1,h=max(mv[1],mv[3])+1;
    cout<<w<<" "<<h<<" "<<w*h<<endl;
    int x=w-mv[0];
    int y=h-mv[1];
    cout<<x<<" "<<y<<endl;
    if(x<1||y<1||x>w||y>h)return -1;
    for(i=1;i<=w;i++)for(j=1;j<=h;j++)mp[i][j]=0;
    mp[x][y]=1;
    for(i=0;i<mv.SZ;i++){
			int ggg=mv[i];
			while(ggg--){
				x+=dx[i%4];
				y+=dy[i%4];
				if(x>w||x<1){cout<<"~";return -1;}
				if(y>h||y<1){cout<<"!";return -1;}
				if(mp[x][y]){cout<<"@";return -1;}
				mp[x][y]=1;
//				cout<<x<<" "<<y<<endl;
			}
			int xx=x+dx[i%4];
			int yy=y+dy[i%4];
			if(xx<=w&&xx>=1&&yy<=h&&yy>=1&&mp[xx][yy]==0&&i+1!=mv.SZ){cout<<"#";return -1;}
    }
    return w*h;
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
			int moves[]               = {15};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int moves[]               = {3,10};
			int expected__            = 44;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int moves[]               = {1,1,1,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int moves[]               = {9,5,11,10,11,4,10};
			int expected__            = 132;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int moves[]               = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
			int expected__            = 420;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int moves[]               = {8,6,6,1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int moves[]               = {8,6,6};
			int expected__            = 63;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int moves[]               = {5,4,5,3,3};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 8: {
			int moves[]               = {10,10,7,2,3};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 9: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int moves[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RotatingBot().minArea( vector <int>( moves, moves + ( sizeof moves / sizeof moves[0] ) ) );
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
