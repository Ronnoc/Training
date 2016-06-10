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
#define cmin(x,y) x=min(x,y)

class WakingUp {
public:
  int maxSleepiness (vector <int> p, vector <int> s, vector <int> v, int D) {
    int ret=0,i,t,lcm=1;
    for(i=0;i<p.SZ;i++)lcm=lcm*p[i]/__gcd(lcm,p[i]);
    int delta=lcm*D;
    for(t=lcm;t<lcm*2;t++)for(i=0;i<p.SZ;i++)if((t-s[i])%p[i]==0)delta-=v[i];
    if(delta<0)return -1;
    int last=0;
    t=0;
    int now=0;
    while(1){
			if(t-last>lcm)break;
			t++;
			now+=D;
			for(i=0;i<p.SZ;i++)if((t-s[i])%p[i]==0)now-=v[i];
			if(ret>now)ret=now,last=t;
    }
    return -ret;
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
			int period[]              = {2, 3};
			int start[]               = {1, 2};
			int volume[]              = {3, 4};
			int D                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int period[]              = {1};
			int start[]               = {1};
			int volume[]              = {17};
			int D                     = 17;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int period[]              = {1};
			int start[]               = {1};
			int volume[]              = {23};
			int D                     = 17;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int period[]              = {9, 2, 5, 5, 7};
			int start[]               = {6, 1, 4, 1, 6};
			int volume[]              = {71, 66, 7, 34, 6};
			int D                     = 50;
			int expected__            = 78;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int period[]              = {5, 6, 5, 3, 8, 3, 4};
			int start[]               = {1, 1, 3, 2, 6, 3, 3};
			int volume[]              = {42, 85, 10, 86, 21, 78, 38};
			int D                     = 88;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int period[]              = ;
			int start[]               = ;
			int volume[]              = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int period[]              = ;
			int start[]               = ;
			int volume[]              = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int period[]              = ;
			int start[]               = ;
			int volume[]              = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WakingUp().maxSleepiness( vector <int>( period, period + ( sizeof period / sizeof period[0] ) ), vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( volume, volume + ( sizeof volume / sizeof volume[0] ) ), D );
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
