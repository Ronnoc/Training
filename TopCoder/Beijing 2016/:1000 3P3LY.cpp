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

double p[333][333];
vector<double>F[333];
double play(vector<int>&L,int n,int m){
	int i,j;
	double ret=0;
	double pb=1;
	for(i=0;i<L.SZ;i++){
		int id=L[i];
		double ONE=1;
		for(j=0;j<n;j++){
			ret+=pb*ONE;
			ONE*=F[id][j];
		}
		pb*=(1-ONE);
	}
	return ret;
}
class MagicalMatrix {
public:
	double MagicalInspection( int n, int m, vector <int> prob ) {
		int i,j,k;
		for(j=0;j<m;j++)F[j].clear();
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				p[i][j]=1.*prob[i*m+j]/100,F[j].PB(p[i][j]);
		vector<int>L;
		for(j=0;j<m;j++)
			L.PB(j),sort(F[j].OP,F[j].ED);
		double ret=play(L,n,m);
		while(true){
			int flag=0;
			for(i=0;i+1<m;i++)
				for(j=i+1;j<m;j++){
					swap(L[i],L[j]);
					double E=play(L,n,m);
					if(E<ret){
						ret=E;
						flag=1;
					}else swap(L[i],L[j]);
				}
			if(!flag)break;
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
			int n                     = 1;
			int m                     = 1;
			int prob[]                = {50};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int n                     = 1;
			int m                     = 1;
			int prob[]                = {99};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int n                     = 2;
			int m                     = 2;
			int prob[]                = {50,50,50,50};
			double expected__         = 2.625;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int n                     = 2;
			int m                     = 3;
			int prob[]                = {1,1,1,1,1,1};
			double expected__         = 3.0296970101000005;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int n                     = 2;
			int m                     = 2;
			int prob[]                = {60,70,90,80};
			double expected__         = 2.382;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 5: {
			int n                     = 2;
			int m                     = 241;
			int prob[]                = {14, 50, 29, 10, 4, 28, 65, 52, 20, 35, 53, 54, 53, 35, 79, 5, 63, 39, 85, 23, 41, 17, 81, 95, 21, 83, 13, 29, 76, 58, 42, 44, 32, 74, 26, 51, 16, 28, 32, 53, 97, 21, 74, 89, 40, 13, 82, 18, 46, 24, 2, 24, 76, 79, 42, 85, 60, 9, 44, 98, 42, 70, 37, 89, 51, 28, 38, 53, 38, 92, 16, 26, 55, 71, 81, 69, 99, 95, 31, 35, 80, 1, 8, 5, 82, 42, 52, 64, 81, 36, 1, 68, 66, 52, 46, 38, 57, 12, 5, 2, 48, 46, 97, 14, 62, 18, 94, 13, 97, 35, 75, 60, 64, 80, 21, 42, 81, 48, 75, 98, 39, 24, 14, 2, 12, 27, 79, 90, 93, 47, 30, 68, 87, 95, 90, 37, 46, 44, 11, 12, 55, 65, 22, 64, 97, 90, 43, 42, 48, 69, 49, 90, 36, 23, 64, 18, 96, 98, 55, 49, 38, 71, 39, 35, 63, 76, 5, 18, 46, 12, 54, 51, 66, 81, 84, 66, 77, 77, 63, 40, 62, 83, 46, 15, 14, 75, 87, 55, 38, 47, 98, 27, 89, 75, 16, 49, 97, 20, 71, 56, 3, 61, 73, 36, 7, 19, 30, 36, 57, 8, 5, 60, 26, 57, 78, 44, 17, 35, 14, 47, 38, 85, 85, 56, 52, 98, 74, 88, 12, 15, 77, 35, 63, 15, 19, 42, 32, 36, 31, 8, 19, 74, 58, 86, 46, 79, 47, 16, 24, 48, 67, 25, 90, 69, 10, 57, 62, 45, 98, 18, 4, 55, 16, 12, 6, 84, 96, 75, 88, 42, 17, 73, 64, 23, 60, 6, 65, 1, 57, 71, 71, 22, 18, 10, 33, 57, 90, 11, 19, 63, 56, 90, 42, 4, 88, 53, 69, 30, 54, 17, 60, 42, 96, 67, 69, 18, 44, 63, 90, 18, 68, 93, 82, 20, 52, 24, 4, 14, 64, 94, 60, 65, 81, 57, 98, 28, 7, 23, 29, 73, 16, 92, 70, 78, 89, 34, 17, 77, 59, 45, 66, 9, 32, 70, 82, 26, 10, 5, 51, 41, 3, 56, 91, 10, 59, 8, 18, 42, 23, 5, 18, 64, 63, 83, 43, 7, 54, 98, 99, 39, 31, 29, 71, 60, 28, 13, 39, 51, 80, 21, 77, 52, 25, 24, 83, 42, 62, 3, 21, 63, 94, 21, 71, 53, 26, 99, 73, 63, 36, 66, 21, 33, 71, 78, 26, 38, 80, 37, 18, 25, 24, 91, 68, 27, 42, 31, 8, 39, 39, 38, 76, 97, 80, 51, 74, 18, 65, 75, 42, 5, 25, 3, 50, 91, 3, 30, 99, 41, 68, 38, 71, 54, 61, 92, 19, 68, 50, 78, 75, 34, 88, 17, 19, 43, 99, 47, 53, 21, 6, 83, 55, 20, 32, 1, 2, 83, 98, 77, 6, 37, 22, 57, 76, 7, 47, 97, 60, 40, 68, 9, 21, 26};
			double expected__         = 2.0651780842485383;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int prob[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int n                     = ;
			int m                     = ;
			int prob[]                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicalMatrix().MagicalInspection( n, m, vector <int>( prob, prob + ( sizeof prob / sizeof prob[0] ) ) );
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
