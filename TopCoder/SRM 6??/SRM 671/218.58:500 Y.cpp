/*
1000个数
找到w[a]*w[c]=w[b]*w[d]的组数，要求a<b<c<d
树状数组sb题，注意统计算法影响的枚举顺序
枚举(a,c)统计不能的(b,d)
分为两种a<=b<=d<=c,b<=d<=a<=c
包含，无交
注意下每个乘积暴力初始化可能会挂
*/
#line 88 "BearDarts.cpp"
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

const int MXN = 1015;
inline int LB(int x){return x&(-x);}
struct BIT{
    LL _[MXN];
    int n;
    void init(int m){
        n=m+5;
        for(int i=0;i<=n;i++)_[i]=0;
    }
    LL query(int w){
        LL ret=0;
        for(w+=3;w>0;w-=LB(w))ret+=_[w];
        return ret;
    }
    void update(int w,LL d){
        for(w+=3;w<n;w+=LB(w))_[w]+=d;
    }
};
class BearDarts {
	public:
	long long count(vector <int> w) {
		LL ret=0;
		map<LL,vector<PII> >S;
		map<LL,vector<PII> >::iterator it;
		int i,j;
		for(j=1;j<w.SZ;j++)
			for(i=j-1;i>=0;i--)
				S[1LL*w[i]*w[j]].PB(MP(i,j));
		BIT Y;
		Y.init(w.SZ);
		for(it=S.OP;it!=S.ED;++it){
			vector<PII>&L=(*it).BB;
			if(L.SZ<=1)continue;
			ret+=1LL*L.SZ*(L.SZ-1)/2;
			for(i=0;i<L.SZ;i++){
				ret-=Y.query(L[i].AA);
				Y.update(L[i].BB,1);
			}
			for(i=0;i<L.SZ;i++)
				Y.update(L[i].BB,-1);
			for(i=0;i<L.SZ;i++){
				ret-=i-Y.query(L[i].AA-1);
				Y.update(L[i].AA,1);
			}
			for(i=0;i<L.SZ;i++)
				Y.update(L[i].AA,-1);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int w[]                   = {6,8,4,3,6};
			long long expected__      = 2LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int w[]                   = {3,4,12,1};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int w[]                   = {42,1000000,1000000,42,1000000,1000000};
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int w[]                   = {1,1,1,1,1};
			long long expected__      = 5LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int w[]                   = {1,2,3,4,5,6,5,4,3,2,1};
			long long expected__      = 22LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int w[]                   = {33554432, 33554432, 67108864, 134217728};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int w[]                   = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = BearDarts().count( vector <int>( w, w + ( sizeof w / sizeof w[0] ) ) );
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
