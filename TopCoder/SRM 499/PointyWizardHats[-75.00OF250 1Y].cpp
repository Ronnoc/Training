// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The Order of All Things Pointy and Magical has commissioned the creation of some new wizard hats. A wizard hat is created by taking two cones: a decorative top cone, and a warm and fluffy bottom cone. To assemble the hat, both cones are first placed onto a table, so that their bases are horizontal and their apexes point upwards. The top cone is then lifted and placed onto the bottom cone. The base of the top cone has to remain horizontal, and the apex of the top cone must be strictly above the apex of the bottom cone. 

Not every pair of cones can be used to create a wizard hat. A wizard hat is only produced if the following two criteria are both met:

The apex of the top cone must be strictly above the apex of the bottom cone. I.e., when the top cone is placed on top of the bottom cone and released, their apexes must not touch.
Some part of the bottom cone must remain visible to form the brim of the hat. (Otherwise, the hat would look like a simple cone, not like a wizard hat!)


You have several top cones and several bottom cones of various sizes. Each cone can be described by its height (the distance between the apex and the base) and by the radius of its base. The top cones you have are described by topHeight and topRadius: for each valid i, you have one top cone with height topHeight[i] and radius topRadius[i]. The bottom cones you have are described by bottomHeight and bottomRadius in the same way. 

Your task is to determine the maximum number of wizard hats you can make using each of the available top and bottom cones at most once.

DEFINITION
Class:PointyWizardHats
Method:getNumHats
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius)


CONSTRAINTS
-topHeight and topRadius will contain the same number of elements.
-bottomHeight and bottomRadius will contain the same number of elements.
-topHeight will contain between 1 and 50 elements, inclusive.
-topRadius will contain between 1 and 50 elements, inclusive.
-bottomHeight will contain between 1 and 50 elements, inclusive.
-bottomRadius will contain between 1 and 50 elements, inclusive.
-Each element of topHeight, topRadius, bottomHeight, and bottomRadius will be between 1 and 10,000, inclusive.


EXAMPLES

0)
{30}
{3}
{3}
{30}

Returns: 1

The top and bottom cone can be used together to make a wizard hat.

1)
{4,4}
{4,3}
{5,12}
{5,4}

Returns: 1

The only way to produce a wizard hat is to use the top cone 1 (height 4, radius 3) and the bottom cone 0 (height 5, radius 5).

2)
{3}
{3}
{1,1}
{2,4}

Returns: 1



3)
{10,10}
{2,5}
{2,9}
{3,6}

Returns: 2



4)
{3,4,5}
{5,4,3}
{3,4,5}
{3,8,5}

Returns: 2



5)
{1,2,3,4,5}
{2,3,4,5,6}
{2,3,4,5,6}
{1,2,3,4,5}

Returns: 0



6)
{123,214,232,323,342,343}
{123,123,232,123,323,434}
{545,322,123,545,777,999}
{323,443,123,656,767,888}

Returns: 5



7)
{999,999,999,10000,10000,10000}
{10000,10000,10000,1,2,3}
{2324,2323,234,5454,323,232}
{1,2,3222,434,5454,23}

Returns: 3



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

int G[55][55],nx,ny;
int vis[55],lnk[55];
int check(int th,int tr,int bh,int br){
	if(tr>=br)return 0;
	if(th*br<=bh*tr)return 0;
	return 1;
}
bool dfs(int u){
	for(int v=0;v<ny;v++)
		if(G[u][v]&&!vis[v]){
			vis[v]=1;
			if(lnk[v]==-1||dfs(lnk[v])){
				lnk[v]=u;
				return 1;
			}
		}
	return 0;
}
class PointyWizardHats {
public:
  int getNumHats (vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) {
    int ret=0;
    int i,j;
    nx=th.SZ,ny=bh.SZ;
    for(i=0;i<nx;i++)for(j=0;j<ny;j++)
			G[i][j]=check(th[i],tr[i],bh[j],br[j]);
		memset(lnk,-1,sizeof lnk);
		for(i=0;i<nx;i++){
			memset(vis,0,sizeof vis);
			if(dfs(i))ret++;
		}
    return ret;
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
			int topHeight[]           = {30};
			int topRadius[]           = {3};
			int bottomHeight[]        = {3};
			int bottomRadius[]        = {30};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int topHeight[]           = {4,4};
			int topRadius[]           = {4,3};
			int bottomHeight[]        = {5,12};
			int bottomRadius[]        = {5,4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int topHeight[]           = {3};
			int topRadius[]           = {3};
			int bottomHeight[]        = {1,1};
			int bottomRadius[]        = {2,4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int topHeight[]           = {10,10};
			int topRadius[]           = {2,5};
			int bottomHeight[]        = {2,9};
			int bottomRadius[]        = {3,6};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int topHeight[]           = {3,4,5};
			int topRadius[]           = {5,4,3};
			int bottomHeight[]        = {3,4,5};
			int bottomRadius[]        = {3,8,5};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int topHeight[]           = {1,2,3,4,5};
			int topRadius[]           = {2,3,4,5,6};
			int bottomHeight[]        = {2,3,4,5,6};
			int bottomRadius[]        = {1,2,3,4,5};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 6: {
			int topHeight[]           = {123,214,232,323,342,343};
			int topRadius[]           = {123,123,232,123,323,434};
			int bottomHeight[]        = {545,322,123,545,777,999};
			int bottomRadius[]        = {323,443,123,656,767,888};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 7: {
			int topHeight[]           = {999,999,999,10000,10000,10000};
			int topRadius[]           = {10000,10000,10000,1,2,3};
			int bottomHeight[]        = {2324,2323,234,5454,323,232};
			int bottomRadius[]        = {1,2,3222,434,5454,23};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 8: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 9: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 10: {
			int topHeight[]           = ;
			int topRadius[]           = ;
			int bottomHeight[]        = ;
			int bottomRadius[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PointyWizardHats().getNumHats( vector <int>( topHeight, topHeight + ( sizeof topHeight / sizeof topHeight[0] ) ), vector <int>( topRadius, topRadius + ( sizeof topRadius / sizeof topRadius[0] ) ), vector <int>( bottomHeight, bottomHeight + ( sizeof bottomHeight / sizeof bottomHeight[0] ) ), vector <int>( bottomRadius, bottomRadius + ( sizeof bottomRadius / sizeof bottomRadius[0] ) ) );
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
