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
#define MAXN 55

int find_components(int n,int mat[][MAXN],int* id){
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN],i,j,k,t;
	for (k=0;k<n;id[k++]=0);
	for (k=0;k<n;k++)
		if (!id[k]){
			for (i=0;i<n;i++)
				a[i]=b[i]=c[i]=d[i]=0;
			a[k]=b[k]=1;
			for (t=1;t;)
				for (t=i=0;i<n;i++){
					if (a[i]&&!c[i])
						for (c[i]=t=1,j=0;j<n;j++)
							if (mat[i][j]&&!a[j])
								a[j]=1;
					if (b[i]&&!d[i])
						for (d[i]=t=1,j=0;j<n;j++)
							if (mat[j][i]&&!b[j])
								b[j]=1;
				}
			for (ret++,i=0;i<n;i++)
				if (a[i]&b[i])
					id[i]=ret;
		}
	return ret;
}
int G[55][55];
int F[55];
class CarrotBoxes {
public:
	double theProbability( vector <string> I ) {
		int i,j,n=I.SZ;
		memset( G,0,sizeof G );
		for ( i=0; i<I.SZ; i++ )for ( j=0; j<I[i].SZ; j++ )
				G[i][j]=I[i][j]=='Y'?1:0;
		int fa[55];
		int na=find_components(I.SZ,G,fa);
		set<int>S;
		set<int>::iterator it;
		for(i=1;i<=na;i++)S.insert(i);
		for(i=1;i<=na;i++)F[i]=1;
		for ( i=0; i<I.SZ; i++ )for ( j=0; j<I[i].SZ; j++ )if(fa[i]!=fa[j]&&G[i][j])
			if(S.find(fa[j])!=S.ED)S.erase(S.find(fa[j]));
		vector<int>L;
		for(it=S.OP;it!=S.ED;++it)L.PB(*it);
		for(i=0;i<L.SZ;i++){
			int vis[55];
			memset(vis,0,sizeof vis);
			for(j=0;j<I.SZ;j++)if(S.find(fa[j])!=S.ED&&fa[j]!=L[i])vis[j]=1;
			queue<int>Q;
			for(j=0;j<I.SZ;j++)if(vis[j])Q.push(j);
			memset(vis,0,sizeof vis);
			while(!Q.empty()){
				int u=Q.front();Q.pop();
				if(vis[u])continue;
				else vis[u]=1;
				for(j=0;j<I.SZ;j++)if(G[u][j])Q.push(j);
			}
			int tot=1;
			for(j=0;j<I.SZ;j++)if(vis[j])tot++;
			if(tot>=I.SZ)return 1.0*( I.SZ-S.SZ+1 )/I.SZ;
		}
		return 1.0*( I.SZ-S.SZ )/I.SZ;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case( int );
void run_test( int casenum = -1, bool quiet = false ) {
	if ( casenum != -1 ) {
		if ( run_test_case( casenum ) == -1 && !quiet )
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for ( int i=0;; ++i ) {
		int x = run_test_case( i );
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

static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); double mmax = max( expected * ( 1.0 - MAX_DOUBLE_ERROR ), expected * ( 1.0 + MAX_DOUBLE_ERROR ) ); return result > mmin && result < mmax; } }
double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }

int verify_case( int casenum, const double &expected, const double &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( topcoder_fequ( expected, received ) ) {
		verdict = "PASSED";
		double rerr = moj_relative_error( expected, received );
		if ( rerr > 0 ) {
			sprintf( buf, "relative error %.3e", rerr );
			info.push_back( buf );
		}
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if ( !info.empty() ) {
		cerr << " (";
		for ( int i=0; i<( int )info.size(); ++i ) {
			if ( i > 0 ) cerr << ", ";
			cerr << info[i];
		}
		cerr << ")";
	}
	cerr << endl;
	
	if ( verdict == "FAILED" ) {
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				string information[]      = {"YYYYY",  "NYNNN",  "NNYNN",  "NNNYN",  "NNNNY"} ;
				double expected__         = 0.8;
				
				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string information[]      = {"YNNNN",  "NYNNN",  "NNYNN",  "NNNYN",  "NNNNY"};
				double expected__         = 0.2;
				
				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string information[]      = {"Y"};
				double expected__         = 1.0;
				
				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string information[]      = {"YNNNN",  "YYNNN",  "YNYNN",  "NNNYY",  "NNNYY"} ;
				double expected__         = 0.6;
				
				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string information[]      = {"YNNNNYNNNNNNN", "NYNNNNYNNNNNN", "NNYNNNNYNNNNN", "NNNYNNNNYNNNN", "NNNNYNNNNYYYY", "NNNNNYNNNYNNN", "NNNNNNYNNNYNN", "NNNNNNNYNNNYN", "NNNNNNNNYNNNY", "NNNNNNNNNYNNN", "NNNNNNNNNNYNN", "NNNNNNNNNNNYN", "NNNNNNNNNNNNY"} ;
				double expected__         = 0.6923076923076923;
				
				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}/*
		case 5: {
				string information[]      = {"YNNNNNNNNYNNNNNNNNNN",  "NYNNNNNNNNNNNNNNNNNN",  "NNYNNNNNNNYNNNNNYNNN",  "NNNYNYNNNNNNNNYNNNNN",  "NNNNYNNNNNNNNNYNNNNY",  "NNNNNYNNNNNNNNNNNNNY",  "NNNNYNYNYNNNNNNNNNNN",  "NNNNNNNYNNNYYNNNNNNN",  "NNNNNNNNYNNNNNNNNNNN",  "YNNNNNNNNYNNNNNYNNNN",  "NNNNNNNNNNYNNNNNNNNN",  "NYNNNNNNNNNYNNNNNNNN",  "NNNNNNNYNNNNYNNNNNNN",  "NNNNNNNNNNNNNYNNNYNN",  "NNNNNNNNNNNYNNYNNNYN",  "NYNNNNNNNNNNNNNYNNNN",  "NNYNNNNNNNNNNNNNYNNN",  "NNNNNNNNNNNNNYNYNYNN",  "NNNNNNNNYNYNNNNNNNYY",  "NNNYNNNNNNNNNNNNNNNY"};
				double expected__         = 0.75;

				clock_t start__           = clock();
				double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}

		// custom cases

		/*      case 6: {
					string information[]      = ;
					double expected__         = ;

					clock_t start__           = clock();
					double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string information[]      = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 8: {
					string information[]      = ;
					double expected__         = ;
		
					clock_t start__           = clock();
					double received__         = CarrotBoxes().theProbability( vector <string>( information, information + ( sizeof information / sizeof information[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		default:
			return -1;
	}
}
}


int main( int argc, char *argv[] ) {
	if ( argc == 1 ) {
		moj_harness::run_test();
	} else {
		for ( int i=1; i<argc; ++i )
			moj_harness::run_test( atoi( argv[i] ) );
	}
}
// END CUT HERE
