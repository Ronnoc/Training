// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Michael loves listening to music from his cell phone while travelling by train. He currently has N songs in his cell phone. During one trip he has the time to listen to P songs. So his cell phone creates a playlist of P (not necessarily different) songs according to the following rules:

Each song has to be played at least once.
At least M songs have to be played between any two occurrences of the same song. (This ensures that the playlist is not playing the same song too often.)

Michael wonders how many different playlists his cell phone can create. You are given the ints N, M, and P. Let X be the number of valid playlists. Since X can be too large, your method must compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:NoRepeatPlaylist
Method:numPlaylists
Parameters:int, int, int
Returns:int
Method signature:int numPlaylists(int N, int M, int P)


NOTES
-Two playlists A and B are different if for some i between 1 and P, inclusive, the i-th song in A is different from the i-th song in B.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 0 and N, inclusive.
-P will be between N and 100, inclusive.


EXAMPLES

0)
1
0
3

Returns: 1

You have only 1 song which can be played as often as you want. 
So the only valid playlist is: {song1, song1, song1}.

1)
1
1
3

Returns: 0

Now is the same scenario as in Example 0, but the song cannot be played 2 times in a row. 
Thus there is no valid playlist.

2)
2
0
3

Returns: 6

Now you have 2 songs and you can play them as often as you want. 
Just remember that playlists {song1, song1, song1} and {song2, song2, song2} are not valid, because each song must be played at least once.

3)
4
0
4

Returns: 24

You have time to play each song exactly once. So there are 4! possible playlists.

4)
2
1
4

Returns: 2

The only two possibilities are {song1, song2, song1, song2} and {song2, song1, song2, song1}.

5)
50
5
100

Returns: 222288991



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
LL comb[111][111];
class NoRepeatPlaylist {
public:
	int numPlaylists (int N, int M, int P) {
		int n=N,m=M,p=P;
		cout<<n<<" "<<m<<" "<<p<<endl;
		const int mod = 1000000007;
		int i,j;
		memset(comb,0,sizeof comb);
		comb[0][0]=1;
		for (i=1; i<=100; i++) {
			comb[i][0]=1;
			for (j=1; j<=i; j++) comb[i][j]= (comb[i-1][j-1]+comb[i-1][j]) %mod;
		}
		LL tp[111];
		for (N=0; N<=100; N++) {
			LL ret=1;
			for (i=1; i<=P; i++) {
				if (i-1<M) {
					if (i-1>=N) ret*=0;
					else ret=ret* (N- (i-1)) %mod;
				} else {
					if (M>=N) ret*=0;
					else ret=ret* (N-M) %mod;
				}
			}
			tp[N]=ret;
		}
		LL ret=0;
		for(i=n;i>=1;i--){
			ret+=((n-i)&1?-1:1)*comb[n][i]*tp[i]%mod;
			cout<<((n-i)&1?-1:1)*comb[n][i]<<" "<<tp[i]<<endl;
		}
		ret%=mod;
		ret+=mod;
		ret%=mod;
		return (int) ret;
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
			int N                     = 1;
			int M                     = 0;
			int P                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 1;
			int M                     = 1;
			int P                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 2;
			int M                     = 0;
			int P                     = 3;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 4;
			int M                     = 0;
			int P                     = 4;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 2;
			int M                     = 1;
			int P                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 50;
			int M                     = 5;
			int P                     = 100;
			int expected__            = 222288991;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NoRepeatPlaylist().numPlaylists( N, M, P );
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
