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

int r[1010];
int play(int x){
	if(x==1)return 0;
	int i;
	for(i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
class ColorfulCards {
public:
  vector <int> theCards (int n, string c) {
    vector <int> ret;
    vector <int> a,b;
    string d;
    int i,j;
    for(i=1;i<=n;i++)d+=play(i)?'R':'B';
    int id=0;
    for(i=0;i<d.SZ;i++){
			if(id<c.SZ&&d[i]==c[id]){
				a.PB(i+1);
				id++;
			}
    }
    id=c.SZ-1;
    for(i=d.SZ-1;i>=0;i--){
			if(id>=0&&d[i]==c[id]){
				b.PB(i+1);
				id--;
			}
    }
    SORT(b);
    if(a.SZ!=c.SZ||b.SZ!=c.SZ)
			for(i=0;i<c.SZ;i++)ret.PB(-1);
    else {
			for(i=0;i<c.SZ;i++)if(a[i]==b[i])ret.PB(a[i]);else ret.PB(-1);
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int N                     = 5;
			string colors             = "RRR";
			int expected__[]          = {2, 3, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int N                     = 7;
			string colors             = "BBB";
			int expected__[]          = {1, 4, 6 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int N                     = 6;
			string colors             = "RBR";
			int expected__[]          = {-1, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int N                     = 58;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 4: {
			int N                     = 495;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 6: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards( N, colors );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
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
