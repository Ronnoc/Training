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


int G[11][11];
void pl( int a,int b ) {
	G[a][b]=1;
	G[b][a]=1;
}
void play( string s,set<string>*a ) {
	int i,id;
	for ( i=0; i<10; i++ )a[i].clear();
	for ( i=0; i<s.SZ; i++ )if ( s[i]=='*' )id=i;
	queue<pair<int,string> >Q;
	Q.push( MP(id,s) );
	while ( !Q.empty() ) {
		int pa=Q.front().AA;
		string pb=Q.front().BB;
//		cout<<pb<<endl;
		Q.pop();
		if ( a[pa].find( pb )!=a[pa].ED )continue;
		a[pa].insert( pb );
		for(i=0;i<10;i++)if(G[pa][i]){
			string tp=pb;
			tp[pa]=tp[i];
			tp[i]='*';
			Q.push(MP(i,tp));
		}
	}
	cout<<"~";
}
class NinePuzzle {
public:
	int getMinimumCost( string init, string goal ) {
		int ret=9,i,j;
		memset( G,0,sizeof G );
		pl( 0,1 ),pl( 0,2 );
		pl( 1,2 ),pl( 1,2 ),pl( 1,4 );
		pl( 2,4 ),pl( 2,5 );
		pl( 3,4 ),pl( 3,6 ),pl( 3,7 );
		pl( 4,5 ),pl( 4,7 ),pl( 4,8 );
		pl( 5,8 ),pl( 5,9 );
		pl( 6,7 ),pl( 7,8 ),pl( 8,9 );
		set<string>a[10],b[10];
		set<string>::iterator it,jt;
		play( init,a );
		int id;
		for(i=0;i<goal.SZ;i++)if(goal[i]=='*')id=i;
		for ( it=a[id].OP; it!=a[id].ED; ++it ){
				string aa=*it,bb=goal;
				int now=0;
				for ( i=0; i<aa.SZ; i++ )if ( aa[i]!=bb[i] )now++;
				ret=min( ret,now );
			}
		return ret;
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

int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) {
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
		cerr << "    Expected: " << expected << endl;
		cerr << "    Received: " << received << endl;
	}
	
	return verdict == "PASSED";
}

int run_test_case( int casenum ) {
	switch ( casenum ) {
		case 0: {
				string init               = "BG*YRGRRYR" ;
				string goal               = "BGGY*YRRRR" ;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = NinePuzzle().getMinimumCost( init, goal );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string init               = "GBBB*BGBBG" ;
				string goal               = "RYYY*YRYYR";
				int expected__            = 9;
				
				clock_t start__           = clock();
				int received__            = NinePuzzle().getMinimumCost( init, goal );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string init               = "RRBR*BRBBB" ;
				string goal               = "BBRB*RBRRR" ;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = NinePuzzle().getMinimumCost( init, goal );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		/*      case 3: {
					string init               = ;
					string goal               = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = NinePuzzle().getMinimumCost( init, goal );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 4: {
					string init               = ;
					string goal               = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = NinePuzzle().getMinimumCost( init, goal );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 5: {
					string init               = ;
					string goal               = ;
					int expected__            = ;
		
					clock_t start__           = clock();
					int received__            = NinePuzzle().getMinimumCost( init, goal );
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
