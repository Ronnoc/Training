// BEGIN CUT HERE
/*
PROBLEM STATEMENT

People enjoy mazes, but they also get them dirty. 
Arrows, graffiti, and chewing gum are just a few of the souvenirs people leave on the walls.  
You, the maze keeper, are assigned to whiten the maze walls.  
Each face of the wall requires one liter of paint, but you are only required to paint visible faces.  
You are given a map of the maze, and you must determine the amount of paint needed for the job.


The maze is described by a vector <string> maze, where each character can be either '#' (a wall) or '.' (an empty space). 

All '.' characters on the perimeter of the map are considered entrances to the maze.  
Upon entering the maze, one can only move horizontally and vertically through empty spaces, and areas that are not reachable by these movements are not considered visible.  

Each '#' represents a square block with four wall faces (each side of the square is a face).   
A face is visible if it is not directly adjacent to another wall (and is in a reachable area of the maze).  
For example, two adjacent blocks can have at most six visible faces since two of their faces are directly adjacent to each other.  
All exterior faces on the perimeter are considered visible.




	For example, the following picture represents a trivial maze with just one (wide) entrance and only four empty reachable spaces:
	
	
		
	



	To whiten this maze you must paint the faces highlighted in yellow above: 16 for its perimeter, 
	plus 8 interior faces. Note that there are faces that are not visible and thus need not be painted.


DEFINITION
Class:TroytownKeeper
Method:limeLiters
Parameters:vector <string>
Returns:int
Method signature:int limeLiters(vector <string> maze)


CONSTRAINTS
-maze will contain between 1 and 50 elements, inclusive.
-Each element of maze will contain between 1 and 50 characters, inclusive.
-All elements of maze will have the same number of characters.
-All characters in maze will be either '.' or '#'.


EXAMPLES

0)
{"##..#"
,"#.#.#"
,"#.#.#"
,"#####"}

Returns: 24

Example from the problem statement.

1)
{"##",
 "##"}

Returns: 8

Only the perimeter of the maze (which has no interior!) has to be painted.

2)
{"######"
,"#....."
,"#.####"
,"#.#..#"
,"#.##.#"
,"#....#"
,"######"}

Returns: 56

3)
{"######"
,"#....."
,"#..#.."
,"#....."
,"######"}

Returns: 36

4)
{"#.#.#.#"
,".#.#.#."
,"#.#.#.#"
,".#.#.#."}

Returns: 36

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

typedef long long LL;
typedef pair<int, int> PII;


class TroytownKeeper {
public:
  int limeLiters (vector <string> maze) {
		char mp[99][99];
		int dx[]={0,0,1,-1};
		int dy[]={1,-1,0,0};
		int i,j;
		for(i=0;i<maze.size();i++)for(j=0;j<maze[i].size();j++)mp[i+1][j+1]=maze[i][j];
		for(i=0;i<=maze[0].size()+1;i++)mp[0][i]='.';
		for(i=0;i<=maze[0].size()+1;i++)mp[maze.size()+1][i]='.';
		for(i=0;i<=maze.size()+1;i++)mp[i][0]='.';
		for(i=0;i<=maze.size()+1;i++)mp[i][maze[0].size()+1]='.';
		int l=maze.size()+1;
		int r=maze[0].size()+1;
		bool vis[99][99];
		memset(vis,0,sizeof vis);
		queue<PII>Q;
		vis[0][0]=1;
		Q.push(MP(0,0));
		int ans=0;
		while(!Q.empty()){
			PII tp=Q.front();Q.pop();
			int x=tp.AA,y=tp.BB;
			for(int k=0;k<4;k++){
				int xx=x+dx[k],yy=y+dy[k];
				if(xx<=l&&x>=0&&y<=r&&y>=0){
					if(mp[xx][yy]=='.'){
						if(!vis[xx][yy]){
							vis[xx][yy]=1;
							Q.push(MP(xx,yy));
						}
					}
				}
			}
		}
		for(i=0;i<=l;i++)for(j=0;j<=r;j++){
			if(mp[i][j]=='.')continue;
			for(int k=0;k<4;k++){
				int xx=i+dx[k],yy=j+dy[k];
				if(vis[xx][yy])ans++;
			}
		}
    return int(ans);
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
			string maze[]             = {"##..#" ,"#.#.#" ,"#.#.#" ,"#####"};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string maze[]             = {"##",  "##"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string maze[]             = {"######" ,"#....." ,"#.####" ,"#.#..#" ,"#.##.#" ,"#....#" ,"######"};
			int expected__            = 56;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string maze[]             = {"######" ,"#....." ,"#..#.." ,"#....." ,"######"};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string maze[]             = {"#.#.#.#" ,".#.#.#." ,"#.#.#.#" ,".#.#.#."};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string maze[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string maze[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string maze[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TroytownKeeper().limeLiters( vector <string>( maze, maze + ( sizeof maze / sizeof maze[0] ) ) );
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
