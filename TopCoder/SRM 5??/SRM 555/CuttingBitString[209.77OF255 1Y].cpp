// BEGIN CUT HERE
/*
PROBLEM STATEMENT
We are in a distant future.
After the downfall of mankind, the Earth is now ruled by fairies.
The "Turing game Online" website is hot among fairies right now.
On this website, everyone can play the programming puzzle "Turing game".

Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on.
In the Turing game, the player is given a string of bits (zeros and ones).
The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros.
If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros.
Of course, it may be the case that even this is impossible.
In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed.
You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.

You are given a string S that consists of characters '0' and '1' only.
S represents the string given to a player of the Turing game.
Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5.
If there is no such K, return -1 instead.

DEFINITION
Class:CuttingBitString
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
"101101101"

Returns: 3

We can split the given string into three "101"s.
Note that "101" is 5 in binary.

1)
"1111101"

Returns: 1

"1111101" is 5^3.

2)
"00000"

Returns: -1

0 is not a power of 5.

3)
"110011011"

Returns: 3

Split it into "11001", "101" and "1".

4)
"1000101011"

Returns: -1



5)
"111011100110101100101110111"

Returns: 5



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


class CuttingBitString {
public:
  int getmin (string S) {
		cout<<S<<endl;
    int ret;
    int f[55][55];
    memset(f,0,sizeof f);
    LL five[55];
    int i,j,k;
    five[0]=1;
    for(i=1;;i++)if(five[i-1]<(1LL<<51))five[i]=five[i-1]*5;else break;
    int Uf=i;
    for(i=0;i<S.SZ;i++)for(j=i;j<S.SZ;j++){
			LL now=0;
			if(S[i]=='0')continue;
			for(k=i;k<=j;k++){
				now*=2;
				if(S[k]=='1')now++;
			}
			for(k=0;k<=Uf;k++)if(now==five[k])f[i][j+1]=1;
    }
    int d[55];
    for(i=0;i<=S.SZ;i++)d[i]=100;
    d[0]=0;
    set<int>O;
    O.insert(0);
    while(!O.empty()){
			int u=*O.OP;O.erase(O.OP);
			int dis=d[u]+1;
			for(i=u+1;i<=S.SZ;i++)if(f[u][i]){
				if(d[i]>dis)
					O.insert(i);
				d[i]=min(d[i],dis);
			}
    }
    return d[S.SZ]==100?-1:d[S.SZ];
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
			string S                  = "101101101";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string S                  = "1111101";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string S                  = "00000";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string S                  = "110011011";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string S                  = "1000101011";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string S                  = "111011100110101100101110111";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin( S );
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
