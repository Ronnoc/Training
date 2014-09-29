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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000007;

bool ok(int big,int sml,int per,vector<int>s){
	vector<int>t;
	int i,j;
	for(i=0;i<s.SZ;i++)if(s[i]>big)t.PB(s[i]-big);
	for(i=0;i<sml;i++){
		int cnt=0;
		for(j=t.SZ-1;j>=0;j--)if(t[j]){
			if(cnt+1<per)cnt++,t[j]--;
			else break;
		}
		sort(t.OP,t.ED);
	}
	for(i=0;i<t.SZ;i++)if(t[i])return 0;
	return 1;
}
class ShoppingSurveyDiv1 {
public:
  int minValue (int N, int K, vector <int> s) {
  	sort(s.OP,s.ED);
    int ret=-1;
    int i,j;
    int le=0,re=N;
    while(re>=le){
			if(re-le<=1){
				if(ok(le,N-le,K,s))return le;
				if(ok(re,N-re,K,s))return re;
				break;
			}
			int mid=(le+re)>>1;
			if(ok(mid,N-mid,K,s))re=mid;
			else le=mid;
    }
    return 0;
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
			int N                     = 10;
			int K                     = 2;
			int s[]                   = {1, 2, 3};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int K                     = 2;
			int s[]                   = {1, 2, 3};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 4;
			int K                     = 4;
			int s[]                   = {4, 4, 4, 2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 20;
			int K                     = 3;
			int s[]                   = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 4;
			int K                     = 2;
			int s[]                   = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 2;
			int K                     = 3;
			int s[]                   = {1, 1, 1, 2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int N                     = 3;
			int K                     = 1;
			int s[]                   = {2,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int s[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int K                     = ;
			int s[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShoppingSurveyDiv1().minValue( N, K, vector <int>( s, s + ( sizeof s / sizeof s[0] ) ) );
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
