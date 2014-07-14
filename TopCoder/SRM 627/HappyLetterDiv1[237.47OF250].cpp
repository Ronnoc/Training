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

class HappyLetterDiv1 {
public:
	string getHappyLetters( string s ) {
		string ret;
		int i,j;
		SORT( s );
		string g=s;
		g.erase( unique( g.OP,g.ED ),g.ED );
		for ( i=0; i<g.SZ; i++ ) {
			map<char,int>S;
			int cnt=0;
			for ( j=0; j<s.SZ; j++ )
				if ( s[j]==g[i] )cnt++;
				else S[s[j]]++;
			multiset<int>G;
			multiset<int>::iterator it,jt;
			for(map<char,int>::iterator it=S.OP;it!=S.ED;++it)
				G.insert((*it).BB);
			while(G.SZ>1){
				it=G.OP;
				jt=--G.ED;
				int p=*it;
				int q=*jt;
				G.erase(it);
				G.erase(jt);
				p--;
				q--;
				if(p>0)G.insert(p);
				if(q>0)G.insert(q);
			}
			if(G.SZ==0)ret+=g[i];
			else {
				int r=*G.OP;
				if(r<cnt)ret+=g[i];
			}
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
				string letters            = "aabbacccc";
				string expected__         = "abc";
				
				clock_t start__           = clock();
				string received__         = HappyLetterDiv1().getHappyLetters( letters );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 1: {
				string letters            = "aaaaaaaccdd";
				string expected__         = "a";
				
				clock_t start__           = clock();
				string received__         = HappyLetterDiv1().getHappyLetters( letters );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 2: {
				string letters            = "ddabccadb";
				string expected__         = "abcd";
				
				clock_t start__           = clock();
				string received__         = HappyLetterDiv1().getHappyLetters( letters );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 3: {
				string letters            = "aaabbb";
				string expected__         = "";
				
				clock_t start__           = clock();
				string received__         = HappyLetterDiv1().getHappyLetters( letters );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
		case 4: {
				string letters            = "rdokcogscosn";
				string expected__         = "cos";
				
				clock_t start__           = clock();
				string received__         = HappyLetterDiv1().getHappyLetters( letters );
				return verify_case( casenum, expected__, received__, clock()-start__ );
			}
			
		// custom cases
		
		      case 5: {
					string letters            = "aabbbbbbbbbbbccqwertyuio";
					string expected__         = "a";
		
					clock_t start__           = clock();
					string received__         = HappyLetterDiv1().getHappyLetters( letters );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}
		/*      case 6: {
					string letters            = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = HappyLetterDiv1().getHappyLetters( letters );
					return verify_case( casenum, expected__, received__, clock()-start__ );
				}*/
		/*      case 7: {
					string letters            = ;
					string expected__         = ;
		
					clock_t start__           = clock();
					string received__         = HappyLetterDiv1().getHappyLetters( letters );
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
