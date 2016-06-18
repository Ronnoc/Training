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

class BearBall {
public:
	int countThrows( vector <int> x, vector <int> y ) {
		int i,j,k;
		int ret=0;
		int n=x.SZ;
		for(i=0;i<n;i++){
			vector<pair<PII,PII > >L;
			for(j=0;j<n;j++)if(i!=j){
				int dx=x[j]-x[i];
				int dy=y[j]-y[i];
				if(dx<0)dy=-dy,dx=-dx;
				if(dx==0&&dy<0)dy=-dy;
				int g;
				if(dx)g=__gcd(dy,dx);
				else g=__gcd(dx,dy);
				dx/=g,dy/=g;
				L.PB(MP(MP(dx,dy),MP(x[j],y[j])));
			}
			sort(L.OP,L.ED);
			if(L[0].AA==L[L.SZ-1].AA){
				for(j=1;j<n;j++)
					ret+=2*j*(n-j);
				return ret;
			}else {
				int le=0;
				while(le<L.SZ){
					int re=le;
					while(re<L.SZ&&L[re].AA==L[le].AA)
						re++;
					int id=lower_bound(L.OP+le,L.OP+re,MP(L[le].AA,MP(x[i],y[i])))-L.OP;
					if(re-le==1){
						ret++;
					}else {
						ret+=2*(re-le);
						if(id<re)ret--;
						if(id-1>=le)ret--;
					}
					le=re;
				}
			}
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
			int x[]                   = {1,4,2};
			int y[]                   = {1,10,7};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int x[]                   = {0,0,0,1,1};
			int y[]                   = {0,1,2,0,1};
			int expected__            = 22;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int x[]                   = {5,7,9,11};
			int y[]                   = {4,3,2,1};
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int x[]                   = {10,10,50,50,90,90};
			int y[]                   = {5,17,5,17,5,17};
			int expected__            = 34;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int x[]                   = {-100, -90, -80, -70, -85, -90, 0, 20};
			int y[]                   = {-5, -8, -13, -21, -13, -13, -13, -69};
			int expected__            = 68;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int x[]                   = {1,2,3};
			int y[]                   = {0,0,0};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BearBall().countThrows( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) );
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
