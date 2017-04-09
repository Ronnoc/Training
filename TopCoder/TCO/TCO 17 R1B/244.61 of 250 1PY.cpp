#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef vector<int> VI;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

class CoinConstruction {
public:
	vector <int> construct( int k ) {
		int i,j;
		vector <int> ret;
		VI S;
		int m = k;
		while(m){
			S.PB(m%2);
			m/=2;
		}
		reverse(all(S));
		int sum=0;
		rep(i,0,sz(S)){
			if(S[i]){
				ret.PB(sum+1);
				sum+=sum+1;
			}else {
				ret.PB(sum);
				sum+=sum;
			}
		}
		return ret;
	}
};

// BEGIN CUT HERE
// 
		/*
		set<int>St;
		for(int mask = 1 ;mask < 1<< sz(ret);mask++){
			int temp = 0;
			rep(i,0,sz(ret)){
				if(mask>>i&1)temp+=ret[i];
			}
			St.insert(temp);
		}
		assert(sz(St)==k);
		assert(sz(ret)<=20);*/
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
			int k                     = 6;
			int expected__[]          = {3, 4, 7 };

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 1: {
			int k                     = 26;
			int expected__[]          = {1, 1, 10, 10, 100, 100 };

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 2: {
			int k                     = 7;
			int expected__[]          = {1, 1, 1, 1, 1, 1, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
		case 3: {
			int k                     = 1;
			int expected__[]          = {999999999 };

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}

		// custom cases

      case 4: {
			int k                     = 1;
			int expected__[]          = {};

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
      case 5: {
			int k                     = 2;
			int expected__[]          = {};

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
      case 6: {
			int k                     = 1000000;
			int expected__[]          = {};

			clock_t start__           = clock();
			vector <int> received__   = CoinConstruction().construct( k );
			return verify_case( casenum, vector <int>( expected__, expected__ + ( sizeof expected__ / sizeof expected__[0] ) ), received__, clock()-start__ );
		}
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
