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


class ColoredStrokes {
public:
  int getLeast (vector <string> p) {
    int ret=0;
    vector <string> r,b;
    int i,j;
    for(i=0;i<p.SZ;i++){
			r.PB(p[i]);
			cout<<p[i]<<" "<<r[i]<<endl;
			for(j=0;j<r[i].SZ;j++)if(r[i][j]=='G')r[i][j]='R';
			for(j=0;j<r[i].SZ;j++)if(r[i][j]=='B')r[i][j]='.';
    }
    for(i=0;i<p.SZ;i++){
			b.PB(p[i]);
			for(j=0;j<b[i].SZ;j++)if(b[i][j]=='G')b[i][j]='B';
			for(j=0;j<b[i].SZ;j++)if(b[i][j]=='R')b[i][j]='.';
    }
    for(j=0;j<b[0].SZ;j++){
			string s=".";
			for(i=0;i<b.SZ;i++)s+=b[i][j];
			for(i=1;i<s.SZ;i++)if(s[i-1]=='.'&&s[i]=='B')ret++;
			cout<<s<<endl;
    }
    cout<<endl;
    for(j=0;j<r.SZ;j++){
			string s="."+r[j];
			for(i=1;i<s.SZ;i++)if(s[i-1]=='.'&&s[i]=='R')ret++;
			cout<<s<<endl;
    }
    cout<<endl;
    for(i=0;i<r.SZ;i++)cout<<p[i]<<endl;
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
			string picture[]          = {"...",  "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string picture[]          = {"..B.",  "..B."};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string picture[]          = {".BB."};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string picture[]          = {"...B..",  ".BRGRR",  ".B.B.."};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string picture[]          = {"...B..",  ".BRBRR",  ".B.B.."};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string picture[]          = {"GR",  "BG"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string picture[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColoredStrokes().getLeast( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ) );
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
