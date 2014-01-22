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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.begin(),X.end())
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

class AlienAndHamburgers {
public:
	int getNumber ( vector <int> ty, vector <int> ta ) {
		int ret;
		vector<PII>L;
		int i,j;
		for(i=0;i<ty.SZ;i++)L.PB(MP(-ta[i],ty[i]));
		SORT(L);
		for(i=0;i<ty.SZ;i++)L[i].AA*=-1;
		set<int>TY;
		int A=0;
		for(i=0;i<L.SZ;i++)if(L[i].AA>=0)TY.insert(L[i].BB),A+=L[i].AA;else break;
		int id=i;
		vector<PII>Q;
		for(i=id;i<L.SZ;i++)if(TY.find(L[i].BB)!=TY.end())continue;else Q.PB(L[i]);
		map<int,int>YA;
		map<int,int>::iterator it;
		for(i=0;i<Q.SZ;i++)if(YA[Q[i].BB]==0)YA[Q[i].BB]=Q[i].AA;
		else YA[Q[i].BB]=max(YA[Q[i].BB],Q[i].AA);
		vector<int>W;
		for(it=YA.OP;it!=YA.ED;++it){
			W.PB(-(*it).BB);
		}
		SORT(W);
		for(i=0;i<W.SZ;i++)W[i]*=-1;
		int num=TY.SZ;
		for(i=0;i<W.SZ;i++){
			int now=num*A;
			if((num+1)*(A+W[i])>now)num++,A+=W[i];
		}
		return num*A;
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
			int type[]                = {1, 2};
			int taste[]               = {4, 7};
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int type[]                = {1, 1};
			int taste[]               = {-1, -1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int type[]                = {1, 2, 3};
			int taste[]               = {7, 4, -1};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int type[]                = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
			int taste[]               = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
			int expected__            = 54;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int type[]                = {30, 20, 10};
			int taste[]               = {100000, -100000, 100000};
			int expected__            = 400000;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int type[]                = ;
			int taste[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AlienAndHamburgers().getNumber( vector <int>( type, type + ( sizeof type / sizeof type[0] ) ), vector <int>( taste, taste + ( sizeof taste / sizeof taste[0] ) ) );
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
