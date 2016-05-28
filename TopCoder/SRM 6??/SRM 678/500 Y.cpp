/*
单调栈处理数据
二分答案，暴力扫一遍完事
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

LL MOD = 1000000007;
class TheEmpireStrikesBack {
	int check(LL g,vector<pair<LL,LL> >L){
		int ret=0;
		int id=0,i;
		for(i=0;id<L.SZ&&i<L.SZ;i++){
			if(i+1<L.SZ&&L[i+1].BB+g>=L[id].BB)continue;
			ret++;
			while(id<L.SZ&&L[id].AA<=L[i].AA+g)id++;
		}
		return ret;
	}
public:
	int find( int AX, int BX, int CX, int AY, int BY, int CY, int N, int M ) {
		int i,j,k;
		int ret;
		vector<pair<LL,LL> >P;
		LL tx=AX,ty=AY;
		for(i=0;i<N;i++){
			P.PB(MP(tx,ty));
			tx=((tx*BX)%MOD+CX)%MOD;
			ty=((ty*BY)%MOD+CY)%MOD;
		}
		sort(P.OP,P.ED);
		stack<pair<LL,LL> >S;
		for(i=0;i<P.SZ;i++){
			while(!S.empty()){
				pair<LL,LL>tp=S.top();
				if(tp.BB<=P[i].BB)S.pop();
				else break;
			}
			S.push(P[i]);
		}
		vector<pair<LL,LL> >L;
		while(!S.empty()){
			L.PB(S.top());
			S.pop();
		}
		reverse(L.OP,L.ED);
		LL mx=-1,my=-1;
		for(i=0;i<L.SZ;i++)cmax(mx,L[i].AA),cmax(my,L[i].BB);
		LL le=0,re=max(mx,my),ge;
		while(re>=le){
			if(re-le<=1){
				if(check(le,L)<=M)ge=le;
				else ge=re;
				break;
			}
			LL mid=(le+re)>>1;
			if(check(mid,L)<=M)re=mid;
			else le=mid;
		}
		return ret=ge;
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
			int AX                    = 2;
			int BX                    = 2;
			int CX                    = 2;
			int AY                    = 2;
			int BY                    = 2;
			int CY                    = 2;
			int N                     = 2;
			int M                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int AX                    = 2;
			int BX                    = 2;
			int CX                    = 2;
			int AY                    = 2;
			int BY                    = 4;
			int CY                    = 1000000000;
			int N                     = 2;
			int M                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int AX                    = 1;
			int BX                    = 3;
			int CX                    = 8;
			int AY                    = 10000;
			int BY                    = 10;
			int CY                    = 999910000;
			int N                     = 3;
			int M                     = 1;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int AX                    = 0;
			int BX                    = 0;
			int CX                    = 0;
			int AY                    = 0;
			int BY                    = 0;
			int CY                    = 0;
			int N                     = 100000;
			int M                     = 1000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int AX                    = 10;
			int BX                    = 20;
			int CX                    = 30;
			int AY                    = 40;
			int BY                    = 50;
			int CY                    = 60;
			int N                     = 100000;
			int M                     = 10;
			int expected__            = 15720;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int AX                    = ;
			int BX                    = ;
			int CX                    = ;
			int AY                    = ;
			int BY                    = ;
			int CY                    = ;
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int AX                    = ;
			int BX                    = ;
			int CX                    = ;
			int AY                    = ;
			int BY                    = ;
			int CY                    = ;
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int AX                    = ;
			int BX                    = ;
			int CX                    = ;
			int AY                    = ;
			int BY                    = ;
			int CY                    = ;
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheEmpireStrikesBack().find( AX, BX, CX, AY, BY, CY, N, M );
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
