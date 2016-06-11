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

map<int,int>S;
vector<PII>f(int A){
	vector<PII>L;
	for(int i=0;i*i<=A;i++){
		if(S.find(A-i*i)!=S.ED){
			L.PB(MP(i,S[A-i*i]));
		}
	}
	return L;
}
double St(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double d(LL q,LL w,LL e,LL r){
	LL dx=q-e,dy=w-r;
	return sqrt(dx*dx+dy*dy);
}
double play(LL q,LL w,LL e,LL r,LL t,LL y){
	return St(d(q,w,e,r),d(q,w,t,y),d(e,r,t,y));
}
class MaxTriangle {
public:
	double calculateArea( int A, int B ) {
		int i,j,k;
		S.clear();
		for(i=0;i*i<=2000000000;i++)
			S[i*i]=i;
		vector<PII>LA=f(A),LB=f(B);
		double ret=-1;
		for(auto a:LA)for(auto b:LB){
			LL ax=a.AA,ay=a.BB;
			LL bx=b.AA,by=b.BB;
			for(i=-1;i<=1;i+=2)
				for(j=-1;j<=1;j+=2){
					double f=play(0,0,ax,ay,ax+i*bx,ay+j*by);
					cmax(ret,f);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int A                     = 1;
			int B                     = 1;
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int A                     = 3;
			int B                     = 7;
			double expected__         = -1.0;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int A                     = 41;
			int B                     = 85;
			double expected__         = 29.5;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 3: {
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 4: {
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MaxTriangle().calculateArea( A, B );
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
