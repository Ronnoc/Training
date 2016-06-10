/*
从1到0撸一遍，从0到1撸一遍
处理可以从S到T在[0,2N]中的所有时间点
撸周期的gcd
看是不是1
*/
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

vector<int>v;
vector<int>g[2005];
int d[2005][4005];
class WalkingToSchool {
public:
	bool play(int N,int S,int T,vector<int>p,vector<int>q){
		int i,j,k;
		for(i=0;i<N;i++)
			g[i].clear();
		for(i=0;i<p.SZ;i++)
			g[p[i]].PB(q[i]);
		v.clear();
		memset(d,0,sizeof d);
		queue<PII>Q;
		Q.push(MP(S,0));
		d[S][0]=1;
		int fp=0,fq=0;
		while(!Q.empty()){
			PII tp=Q.front();
			Q.pop();
			int u=tp.AA;
			int t=tp.BB;
			if(u==T){
				if(t&1)fp=1;
				else fq=1;
			}
			if(t>2*N){
				break;
			}
			for(i=0;i<g[u].SZ;i++){
				int v=g[u][i];
				if(!d[v][t+1]){
					Q.push(MP(v,t+1));
					d[v][t+1]=1;
				}
			}
		}
		vector<int>L;
		for(i=0;i<=2*N;i++)if(d[T][i])L.PB(i);
		if(L.empty()||L.SZ==1)return 0;
		int fi=L[0],g=0;
		for(i=1;i<L.SZ;i++){
			g=__gcd(g,L[i]-fi);
		}
		return g==1;
	}
	string canWalkExactly( int N, vector <int> p, vector <int> q ) {
		int i,j,k;
		string yes="Freedom";
		string no="Chores";
		int flag=play(N,0,1,p,q)&&play(N,1,0,p,q);
		return flag?yes:no;
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
			int N                     = 2;
			int from[]                = {0, 1};
			int to[]                  = {1, 0};
			string expected__         = "Chores";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int N                     = 3;
			int from[]                = {0, 1, 1, 2};
			int to[]                  = {1, 0, 2, 0};
			string expected__         = "Freedom";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int N                     = 4;
			int from[]                = {0, 2, 2, 3, 0};
			int to[]                  = {2, 0, 3, 0, 1};
			string expected__         = "Chores";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int N                     = 10;
			int from[]                = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9};
			int to[]                  = {4, 5, 6, 7, 9, 4, 6, 0, 1, 3, 8, 4, 6, 1, 4, 8, 1, 7, 8, 1, 4, 2, 5, 6, 8};
			string expected__         = "Chores";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int N                     = 8;
			int from[]                = {0, 1, 4, 6, 7, 5, 2, 3, 0};
			int to[]                  = {1, 4, 6, 7, 5, 2, 3, 0, 7};
			string expected__         = "Freedom";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int N                     = 2000;
			int from[]                = {};
			int to[]                  = {};
			string expected__         = "Chores";

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int from[]                = ;
			int to[]                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int N                     = ;
			int from[]                = ;
			int to[]                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int N                     = ;
			int from[]                = ;
			int to[]                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = WalkingToSchool().canWalkExactly( N, vector <int>( from, from + ( sizeof from / sizeof from[0] ) ), vector <int>( to, to + ( sizeof to / sizeof to[0] ) ) );
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
