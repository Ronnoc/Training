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
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)
int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}
int aabs(int x){return x>0?x:-x;}
int G[55][55];
LL comb[55][55];
class OneDimensionalBalls {
public:
  long long countValidGuesses (vector <int> fi, vector <int> se) {
    long long ret=0;
    set<int>v,p,q;
    set<int>::iterator it;
    int a[55],b[55];
    int i,j;
    comb[0][0]=1;
    memset(comb,0,sizeof comb);
    for(i=1;i<=50;i++){
			comb[i][0]=1;
			for(j=1;j<i;j++)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			comb[i][i]=1;
    }
    for(i=0;i<fi.SZ;i++)p.insert(fi[i]);
    for(j=0;j<se.SZ;j++)q.insert(se[j]);
    for(i=0;i<fi.SZ;i++)for(j=0;j<se.SZ;j++)if(fi[i]!=se[j])v.insert(aabs(fi[i]-se[j]));
    for(it=v.OP;it!=v.ED;++it){
			memset(G,0,sizeof G);
			int V=*it;
			for(i=0;i<fi.SZ;i++)for(j=0;j<se.SZ;j++)if(aabs(fi[i]-se[j])==V)G[i][j]=1;
			int pr=hungary(fi.SZ,se.SZ,G,a,b);
			cout<<V<<endl;
			if(pr==fi.SZ){
				set<int>l=p,r=q;
				LL add=1;
				while(!l.empty()){
					int h=*l.OP;
					int up=0,dn=0;
					while(l.find(h)!=l.ED){
						up++,l.erase(l.find(h));
						if(r.find(h-V)!=r.ED)dn++,r.erase(r.find(h-V));
						if(r.find(h+V)!=r.ED)dn++,r.erase(r.find(h+V));
						h+=2*V;
					}
					cout<<dn<<" "<<up<<endl;
					add*=comb[dn][up];
				}
				ret+=add;
			}
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
			int firstPicture[]        = {12,11};
			int secondPicture[]       = {10,11,13};
			long long expected__      = 3LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int firstPicture[]        = {1,2,3};
			int secondPicture[]       = {1,2,3};
			long long expected__      = 0LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int firstPicture[]        = {1,3};
			int secondPicture[]       = {1,3};
			long long expected__      = 1LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int firstPicture[]        = {7234};
			int secondPicture[]       = {6316,689156,689160,689161,800000,1000001};
			long long expected__      = 6LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int firstPicture[]        = {6,2,4};
			int secondPicture[]       = {1,2,3,4,5,7,8};
			long long expected__      = 7LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			int firstPicture[]        = ;
			int secondPicture[]       = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			int firstPicture[]        = ;
			int secondPicture[]       = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int firstPicture[]        = ;
			int secondPicture[]       = ;
			long long expected__      = LL;

			clock_t start__           = clock();
			long long received__      = OneDimensionalBalls().countValidGuesses( vector <int>( firstPicture, firstPicture + ( sizeof firstPicture / sizeof firstPicture[0] ) ), vector <int>( secondPicture, secondPicture + ( sizeof secondPicture / sizeof secondPicture[0] ) ) );
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
