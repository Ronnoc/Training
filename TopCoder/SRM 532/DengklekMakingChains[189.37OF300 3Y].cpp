// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony. 



Mr. Dengklek works as a chain maker. Today, he would like to make a beautiful chain as a decoration for one of his lovely ducks. He will produce the chain from leftovers he found in his workshop. Each of the leftovers is a chain piece consisting of exactly 3 links. Each link is either clean or rusty. Different clean links may have different degrees of beauty.



You are given a vector <string> chains describing the leftovers. Each element of chains is a 3-character string describing one of the chain pieces. A rusty link is represented by a period ('.'), whereas a clean link is represented by a digit ('0'-'9'). The value of the digit in the clean link is the beauty of the link. For example, chains = {".15", "7..", "532", "..3"} means that Mr. Dengklek has 4 chain pieces, and only one of these ("532") has no rusty links.



All links have the same shape, which allows Mr. Dengklek to concatenate any two chain pieces. However, the link shape is not symmetric, therefore he may not reverse the chain pieces. E.g., in the above example he is able to produce the chain "532.15" or the chain ".15..37..", but he cannot produce "5323..".



To produce the chain, Mr. Dengklek will follow these steps:

Concatenate all chain pieces in any order.
Pick a contiguous sequence of links that contains no rusty links. Remove and discard all the remaining links.

The beauty of the new chain is the total beauty of all the links picked in the second step. Of course, Mr. Dengklek would like to create the most beautiful chain possible.



Return the largest possible beauty a chain can have according to the above rules.

DEFINITION
Class:DengklekMakingChains
Method:maxBeauty
Parameters:vector <string>
Returns:int
Method signature:int maxBeauty(vector <string> chains)


NOTES
-Mr. Dengklek is not allowed to remove and discard individual links before concatenating the chain pieces.
-If all links in the input are rusty, Mr. Dengklek is forced to select an empty sequence of links. The beauty of an empty sequence is 0.


CONSTRAINTS
-chains will contain between 1 and 50 elements, inclusive.
-Each element of chains will contain exactly 3 characters.
-Each character in each element of chains will be either a '.' or one of '0'-'9'.


EXAMPLES

0)
{".15", "7..", "402", "..3"}

Returns: 19

One possible solution:


In the first step, concatenate the chain pieces in the order "..3", ".15", "402", "7.." to obtain the chain "..3.154027..".
In the second step, pick the subsequence "154027".

The beauty of the chain in this solution is 1+5+4+0+2+7 = 19.

1)
{"..1", "7..", "567", "24.", "8..", "234"}

Returns: 36

One possible solution is to concatenate the chain pieces in this order:

"..1", "234", "567", "8..", "24.", "7.." -> "..12345678..24.7..",

and then to pick the subsequence "12345678". Its beauty is 1+2+3+4+5+6+7+8 = 36.

2)
{"...", "..."}

Returns: 0

Mr. Dengklek cannot pick any links.

3)
{"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}

Returns: 28



4)
{"..1", "3..", "2..", ".7."}

Returns: 7



5)
{"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}

Returns: 58



*/
// END CUT HERE
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


class DengklekMakingChains {
public:
  int maxBeauty (vector <string> s) {
    int ret=0;
    int cl[55],cr[55],co[55];
    memset(cl,-1,sizeof cl);
    memset(cr,-1,sizeof cr);
    memset(co,-1,sizeof co);
    int i,j;
    s.PB(string("."));
    s.PB(string("."));
    int n=s.SZ,mid=0;
    for(i=0;i<n;i++){
			string tp=s[i]+'.';
			int ths=0;
			for(j=0;j<tp.SZ;j++){
				if(tp[j]!='.')ths+=tp[j]-'0';
				else {
					ret=max(ret,ths);
					ths=0;
				}
			}
    }
    for(i=0;i<n;i++){
			int has=0;
			for(j=0;j<s[i].SZ;j++)if(s[i][j]=='.')has=1;
			if(has){
				co[i]=0;
				j=0;
				cr[i]=0;
				while(s[i][j]!='.')cr[i]+=s[i][j++]-'0';
				j=s[i].SZ-1;
				cl[i]=0;
				while(s[i][j]!='.')cl[i]+=s[i][j--]-'0';
			}else {
				co[i]=1;
				for(j=0;j<s[i].SZ;j++)mid+=s[i][j]-'0';
			}
    }
    ret=max(ret,mid);
    for(i=0;i<n;i++)for(j=0;j<n;j++){
			if(i==j)continue;
			if(co[i]||co[j])continue;
			ret=max(ret,cl[i]+cr[j]+mid);
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
			string chains[]           = {"9.9","123"};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}/*
		case 1: {
			string chains[]           = {"..1", "7..", "567", "24.", "8..", "234"};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string chains[]           = {"...", "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string chains[]           = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string chains[]           = {"..1", "3..", "2..", ".7."};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string chains[]           = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) );
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
