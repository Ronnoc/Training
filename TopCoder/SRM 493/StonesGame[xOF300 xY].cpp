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

int aabs( int x ) {return x>0?x:-x;}
class StonesGame {
public:
	string winner( int N, int M, int K, int L ) {
		string draw="Draw";
		string xian="Romeo";
		string hou="Strangelet";
		if ( K==1 )return draw;
		//case leftmost
		int l1,r1,l2,r2,t1,t2;
		l1=M-( K-1 ),r1=M;
		if ( l1<1 ) {
			r1+=1-l1;
			l1=1;
		}
		t1=r1-( M-l1 );
		l2=M,r2=M+( K-1 );
		if ( r2>N ) {
			l2-=r2-N;
			r2=N;
		}
		t2=r2-( M-l2 );
		if ( t2<t1 )swap( t1,t2 );
//		cout<<t1<<" "<<L<<" "<<t2<<endl;
		if ( L>=t1&&L<=t2&&( t1&1 )==( L&1 ) )return xian;
		int flag=1,can=0;
		for ( int i=t1; i<=t2; i+=max(t2-t1,1) ) {
			l1=i-( K-1 ),r1=i;
			if ( l1<1 ) {r1+=1-l1; l1=1;}
			int tt1=r1-( i-l1 );
			l2=i,r2=i+( K-1 );
			if ( r2>N ) {l2-=r2-N; r2=N;}
			int tt2=r2-( i-l2 );
			if ( tt2<tt1 )swap( tt1,tt2 );
//			cout<<i<<": "<<tt1<<" "<<L<<" "<<tt2<<endl;
			if ( L>=tt1&&L<=tt2&&( tt1&1 )==( L&1 ) )can=1;
			else flag=0;
		}
//		cout<<can<<" "<<flag<<endl;
//		system("pause");
		return can?(flag?hou:draw):draw;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int N                     = 8;
			int M                     = 3;
			int K                     = 8;
			int L                     = 5;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 5;
			int M                     = 1;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 3;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 1000000;
			int M                     = 804588;
			int K                     = 705444;
			int L                     = 292263;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 1000000;
			int M                     = 100000;
			int K                     = 500000;
			int L                     = 600000;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			int N                     = 8;
			int M                     = 3;
			int K                     = 8;
			int L                     = 5;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner( N, M, K, L );
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
