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
const double PI = acos( -1 );
const LL MOD = 1000000007;
bool inner( int p,int q,vector<PII>&D ) {
	int i;
	int ret=0;
	for(int i=0;i<D.SZ;i++)if(q>=D[i].AA&&p<=D[i].BB)ret+=min(D[i].BB,q)-max(D[i].AA,p)+1;
	return ret==(q-p+1);
}
int play( int l,int r,vector<PII>&D ) {
	int ret=0,i;
	for ( i=0; i<D.SZ; i++ )if ( l<=D[i].BB&&r>=D[i].AA ) {
			int p=max( D[i].AA,l );
			int q=min( D[i].BB,r );
			ret+=q-p+1;
		}
	return r-l+1-ret;
}
vector<PII> input( int l,int r,vector<PII>D ) {
	vector<PII>ret;
	cout<<l<<" "<<r<<" ";
	for(int i=0;i<D.SZ;i++)cout<<D[i].AA<<"~"<<D[i].BB<<"\t";
	cout<<endl;
	for ( int i=0; i<D.SZ; i++ ) {
		if ( D[i].AA>r||D[i].BB<l )ret.PB( D[i] );
		else {
			cmax( r,D[i].BB );
			cmin( l,D[i].AA );
		}
	}
	if ( r>=l )ret.PB( MP( l,r ) );
	for(int i=0;i<ret.SZ;i++)cout<<ret[i].AA<<"~"<<ret[i].BB<<"\t";
	cout<<endl;
	SORT(ret);
	return ret;
}
class InverseRMQ {
public:
	string possible( int n, vector <int> A, vector <int> B, vector <int> C ) {
		string yes="Possible",no="Impossible";
		map<int,vector<PII> >Q;
		map<int,vector<PII> >::iterator it;
		int i,j;
		for ( i=0; i<C.SZ; i++ )Q[C[i]].PB( MP( A[i],B[i] ) );
		int last=0;
		int remain=0;
		vector<PII>D;
//		cout<<n<<endl;
//		for(i=0;i<A.SZ;i++)cout<<A[i]<<" ";cout<<endl;
//		for(i=0;i<A.SZ;i++)cout<<B[i]<<" ";cout<<endl;
//		for(i=0;i<A.SZ;i++)cout<<C[i]<<" ";cout<<endl;
		for ( it=Q.OP; it!=Q.ED; ++it ) {
			cout<<( *it ).AA<<endl;
			vector<PII>L=( *it ).BB;
			int l=L[0].AA,r=L[0].BB;
			int p=L[0].AA,q=L[0].BB;
			for ( i=1; i<L.SZ; i++ ) {
				cmax( p,L[i].AA );
				cmin( q,L[i].BB );
				cmin( l,L[i].AA );
				cmax( r,L[i].BB );
			}
			if ( p>q )return no;
			cout<<p<<"~"<<q<<endl;
			int add=( *it ).AA-last;
			last=( *it ).AA;
			remain+=add;
			if ( inner( p,q,D ) )return no;
			int todo=play( l,r,D );
			cout<<todo<<endl;
//			cout<<todo<<endl;
			if ( todo>remain )return no;
			remain-=todo;
			for(int k=0;k<D.SZ;k++)cout<<D[k].AA<<"~"<<D[k].BB<<"\t";
			cout<<endl;
			D=input( l,r,D );
			for(int k=0;k<D.SZ;k++)cout<<D[k].AA<<"~"<<D[k].BB<<"\t";
			cout<<endl;
		}
		return yes;
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

int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if ( elapsed > CLOCKS_PER_SEC / 200 ) {
		sprintf( buf, "time %.2fs", elapsed * ( 1.0/CLOCKS_PER_SEC ) );
		info.push_back( buf );
	}
	
	if ( expected == received ) {
		verdict = "PASSED";
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
		cerr << "    Expected: \"" << expected << "\"" << endl;
		cerr << "    Received: \"" << received << "\"" << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				int n                     = 5;
				int A[]                   = {1,2,4};
				int B[]                   = {2,4,5};
				int ans[]                 = {3,4,5};
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				int n                     = 3;
				int A[]                   = {1,2,3};
				int B[]                   = {1,2,3};
				int ans[]                 = {3,3,3};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				int n                     = 600;
				int A[]                   = {1,101,201,301,401,501};
				int B[]                   = {100,200,300,400,500,600};
				int ans[]                 = {100,200,300,400,500,600};
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				int n                     = 1000000000;
				int A[]                   = {1234,1234};
				int B[]                   = {5678,5678};
				int ans[]                 = {10000,20000};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				int n                     = 8;
				int A[]                   = {1,2,3,4,5,6,7,8};
				int B[]                   = {1,2,3,4,5,6,7,8};
				int ans[]                 = {4,8,2,5,6,3,7,1};
				string expected__         = "Possible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 5: {
				int n                     = 1000000000;
				int A[]                   = {1};
				int B[]                   = {1000000000};
				int ans[]                 = {19911120};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		case 6: {
				int n                     = 10;
				int A[]                   = {4, 5, 6};
				int B[]                   = {5, 6, 7};
				int ans[]                 = {6, 7, 5};
				string expected__         = "Impossible";
				
				clock_t start__           = clock();
				string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		/*      case 7: {//10, {4, 5, 6}, {5, 6, 7}, {6, 7, 5}
					int n                     = 10;
					int A[]                   = {4, 5, 6};
					int B[]                   = {5, 6, 7};
					int ans[]                 = {6, 7, 5};
					string expected__         = "Impossible";
		
					clock_t start__           = clock();
					string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 8: {
					int n                     = ;
					int A[]                   = ;
					int B[]                   = ;
					int ans[]                 = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = InverseRMQ().possible( n, vector <int>( A, A + ( sizeof A / sizeof A[0] ) ), vector <int>( B, B + ( sizeof B / sizeof B[0] ) ), vector <int>( ans, ans + ( sizeof ans / sizeof ans[0] ) ) );
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

