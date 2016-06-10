/*
观察到当步数足够多的时候具有mod2周期性
暴力撸sg
*/
#line 125 "BoardEscape.cpp"
#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int,int> PII;
int sg[55][55][2505];
vector<string>S;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int getSG(int i,int j,int k){
	if(~sg[i][j][k])return sg[i][j][k];
	if(S[i][j]=='E')sg[i][j][k]=0;
	else if(k==0)sg[i][j][k]=0;
	else {
		vector<int>L;
		for(int v=0;v<4;v++){
			int x=i+dx[v],y=j+dy[v];
			if(x>=0&&x<S.SZ)
				if(y>=0&&y<S[x].SZ)
					if(S[x][y]!='#')
						L.PB(getSG(x,y,k-1));
		}
		sort(L.OP,L.ED);
		L.erase(unique(L.OP,L.ED),L.ED);
		L.PB(-1);
		for(int l=0;l<L.SZ;l++)
			if(L[l]!=l){
				sg[i][j][k]=l;
				break;
			}
	}
	//cout<<i<<" "<<j<<" "<<k<<" "<<sg[i][j][k]<<"\n";
	return sg[i][j][k];
}
class BoardEscape {
	public:
	string findWinner(vector <string> s, int k) {
		S=s;
		memset(sg,-1,sizeof sg);
		int ret=0,i,j;
		int n=s.SZ,m=s[0].SZ;
		for(i=0;i<s.SZ;i++)
			for(j=0;j<s[i].SZ;j++)
				if(s[i][j]=='T'){
					int temp=getSG(i,j,k>n*m?(k-(n*m))%2+(n*m):k);
					ret^=temp;
				}
		if(ret)return string("Alice");
		else return string("Bob");
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
			string s[]                = {"TE"};
			int k                     = 2;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string s[]                = {"E#E",  "#T#",  "E#E"};
			int k                     = 1000000;
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string s[]                = {"T.T.T.",  ".E.E.E"};
			int k                     = 1;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string s[]                = {"TTE"};
			int k                     = 6;
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string s[]                = {"..........................",  "......TTT..TTT..T...T.....",  ".....T.....T..T.TT.TT.....",  "......TTT..TTT..T.T.T.....",  ".........T.T.T..T...T.....",  "......TTT..T..T.T...T.....",  "..........................",  "...E#E#E#E#E#E#E#E#E#E#...",  "..........................",  "......TTT..TTT...TTT......",  ".....T........T.T.........",  "......TTT.....T..TTT......",  ".....T...T...T..T...T.....",  "......TTT....T...TTT......",  "..........................",  "...#E#E#E#E#E#E#E#E#E#E...",  "..........................",  "....TT...T...T..T.TTT.T...",  "...T.....T...T..T.T...T...",  "...T.TT..T...TTTT.TT..T...",  "...T..T..T...T..T.T.......",  "....TT...TTT.T..T.T...T...",  ".........................."};
			int k                     = 987654321;
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string s[]                = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string s[]                = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string s[]                = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BoardEscape().findWinner( vector <string>( s, s + ( sizeof s / sizeof s[0] ) ), k );
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
