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

LL dp[1<<16];
int f[55][1<<16];
int g[55][1<<16];
class FoxAndGemstone {
public:
	string isPossible( vector <string> bags ) {
		int i,j,k;
		int m=16;
		for(int i=0;i<bags.SZ;i++)
			sort(bags[i].OP,bags[i].ED);
		sort(bags.OP,bags.ED);
		bags.erase(unique(bags.OP,bags.ED),bags.ED);
		memset(f,0,sizeof f);
		for(j=0;j<bags.SZ;j++)for(i=0;i<1<<m;i++){
			f[j][i]=0;
			int cnt=__builtin_popcount(i);
			if(cnt<=1){
				for(k=0;k<bags[j].SZ;k++){
					int t=bags[j][k]-'A';
					if(i>>t&1)f[j][i]++;
				}
			}
			else {
				int id=i&-i;
				f[j][i]=f[j][i^id]+f[j][id];
			}
		}
		for(i=0;i<bags.SZ;i++){
			for(j=0;j<1<<m;j++){
				g[i][j]=0;
				for(k=0;k<bags.SZ;k++)
					if(k!=i&&f[k][j]>f[i][j]){
						g[i][j]=1;
						break;
					}
			}
		}
		string ret;
		LL tot=0;
		for(k=0;k<bags.SZ;k++){
			for(i=0;i<1<<m;i++)dp[i]=0;
			dp[0]=1;
			for(i=0;i<1<<m;i++)if(dp[i])
				for(j=0;j<m;j++){
					if(i>>j&1);else {
						int next=i^(1<<j);
						if(!g[k][next])dp[next]+=dp[i];
					}
				}
			tot+=dp[(1<<m)-1];
			//cout<<bags[k]<<" "<<dp[(1<<m)-1]<<"\n";
		}
		LL aim=1;
		for(i=1;i<=m;i++)aim*=i;
		return tot==aim?"Possible":"Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string bags[]             = {"AB", "AC"};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string bags[]             = {"A", "BC"};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string bags[]             = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string bags[]             = {"AB","AC","AD","BC","BD","CD"};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string bags[]             = {"AB", "CD"};
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			string bags[]             = {"A", "A", "A"};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

      case 6: {
			string bags[]             = {"A","BC","AB"};
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
/*      case 7: {
			string bags[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			string bags[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndGemstone().isPossible( vector <string>( bags, bags + ( sizeof bags / sizeof bags[0] ) ) );
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
