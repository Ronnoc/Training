// Paste me into the FileEdit configuration dialog

#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max((x),(y))
#define cmin(x,y) x=min((x),(y))

typedef long long LL;
typedef pair<int,int> PII;

class GroupSRMDiv2 {
public:
	int FindGroups( vector <int> t ) {
		int i,j,k;
		int ret=0;
		map<int,int>S;
		int ans=0;
		for(int i=0;i<t.SZ;i++){
			S[t[i]]++;
		}
		for(auto p:S){
			int u=p.AA,v=p.BB;
			if(v%u==0)ret+=v/u;
			else return -1;
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
			int t[]                   = {1,1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int t[]                   = {1,2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int t[]                   = {2,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int t[]                   = {2,2,3,3,3};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int t[]                   = {3,3,2,2,2};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int t[]                   = {2,3,2,3,2,3,2,1,1,2,2};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GroupSRMDiv2().FindGroups( vector <int>( t, t + ( sizeof t / sizeof t[0] ) ) );
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
