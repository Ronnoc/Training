// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Note that the memory limit for all tasks in this SRM is 256 MB.


Fox Ciel has a matrix A that consists of N rows by M columns.
Both N and M are even.
Each element of the matrix is either 0 or 1.
The rows of the matrix are numbered 0 through N-1 from top to bottom, the columns are numbered 0 through M-1 from left to right.
The element in row i, column j is denoted A(i, j).
You are given a vector <string> A that describes the matrix A.
The character A[i][j] is '1' if A(i, j)=1 and it is '0' otherwise.



A palindrome is a string that reads the same forwards and backwards.
For example, "1001" and "0111001110" are palindromes while "1101" and "000001" are not.



Some rows and some columns in Ciel's matrix may be palindromes.
For example, in the matrix below both row 0 and column 3 are palindromes.
(Row 0 is the palindrome "0000", column 3 is the palindrome "0110".)


0000
0011
0111
1110



You are also given two ints: rowCount and columnCount.
Ciel wants her matrix A to have at least rowCount rows that are palindromes, and at the same time at least columnCount columns that are palindromes.
If this is currently not the case, she can change A by changing some of the elements (from '0' to '1' or vice versa).
Compute and return the smallest possible number of elements she needs to change in order to reach her goal.


DEFINITION
Class:PalindromeMatrix
Method:minChange
Parameters:vector <string>, int, int
Returns:int
Method signature:int minChange(vector <string> A, int rowCount, int columnCount)


CONSTRAINTS
-N and M will be between 2 and 14, inclusive.
-N and M will be even.
-A will contain N elements.
-Each element of A will contain M characters.
-Each character of A will be either '0' or '1'.
-rowCount will be between 0 and N.
-columnCount will be between 0 and M.


EXAMPLES

0)
{"0000"
,"1000"
,"1100"
,"1110"}
2
2

Returns: 1

An optimal solution is to change A(3, 0) to 0. Then we will have palindromes in two rows (0 and 3), and in two columns (0 and 3).

1)
{"0000"
,"1000"
,"1100"
,"1110"}
3
2

Returns: 3

This is similar to the previous example, but in this case we must have three row palindromes.
An optimal solution is to change A(1, 0), A(2, 0) and A(3, 0) to 0.

2)
{"01"
,"10"}
1
1

Returns: 1



3)
{"1110"
,"0001"}
0
0

Returns: 0

Here, we do not have to change A at all.

4)
{"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}
2
3

Returns: 8



5)
{"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}
5
9

Returns: 14



6)
{"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}
6
8

Returns: 31



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


class PalindromeMatrix {
public:
	int minChange (vector <string> A, int rc, int cc) {
		cout<<rc<<" "<<cc<<endl;
		for (int i=0; i<A.SZ; i++) cout<<A[i]<<endl;
		int i,j,k,msk;
		int x[22][22];
		int n=A.SZ,m=A[0].SZ;
		int ret=m*n;
		int l[22],r[22],to[22];
		for (i=0; i<n; i++) for (j=0; j<m; j++) x[i+1][j+1]=A[i][j]-'0';
		for (msk=0; msk< (1<<n); msk++) {
			int tt=0;
			for (i=0; i<n; i++) if (msk>>i&1) tt++;
			if (tt!=rc) continue;
			vector<int>G[5];
			for (k=1; k<=m/2; k++) {
				int c1=n*m,c2=n*m,c0=n*m;
				for (i=0; i<1<<rc; i++) {
					for (j=1; j<=n; j++) l[j]=x[j][k];
					for (j=1; j<=n; j++) r[j]=x[j][m+1-k];
					memset (to,-1,sizeof to);
					int tp=i;
					for (j=0; j<n; j++) if (msk>>j&1) {
							to[j+1]=tp%2;
							tp/=2;
						}
						
					int wa=0;
					for (j=1; j<=n/2; j++) if (to[j]!=-1||to[n+1-j]!=-1) {
							if (to[j]!=-1) {
								if (to[n+1-j]==-1);
								else if (to[n+1-j]!=to[j]) wa=1;
							} else {
								if (to[j]==-1);
								else if (to[n+1-j]!=to[j]) wa=1;
							}
						}
						
						
//					for(j=1;j<=n;j++)cout<<l[j]<<" ";cout<<":l"<<endl;
//					for(j=1;j<=n;j++)cout<<r[j]<<" ";cout<<":r"<<endl;
//					for(j=1;j<=n;j++)cout<<to[j]<<" ";cout<<":to"<<endl;


					int cl=0,cr=0;
					int mst=0;
					for (j=1; j<=n; j++) if (to[j]!=-1) {
							if (l[j]!=to[j]) l[j]=to[j],mst++;
							if (r[j]!=to[j]) r[j]=to[j],mst++;
						}
						
					for (j=1; j<=n/2; j++) {
						if (l[j]!=l[n+1-j]) cl++;
						if (r[j]!=r[n+1-j]) cr++;
					}
//					for(j=1;j<=n;j++)cout<<l[j]<<" ";cout<<":l"<<endl;
//					for(j=1;j<=n;j++)cout<<r[j]<<" ";cout<<":r"<<endl;
//					for(j=1;j<=n;j++)cout<<to[j]<<" ";cout<<":to"<<endl;
//					cout<<"\t";
//					cout<<" msk="<<msk<<" to_clr:"<<i<<" id:"<<k<<" ";
//					cout<<"mst="<<mst<<" cl="<<cl<<" cr="<<cr<<endl;
					if (!wa) c1=min (c1,mst+min (cl,cr));
					if (!wa) c2=min (c2,mst+cl+cr);
					c0=min (c0,mst);
				}
				G[0].PB (c0);
				G[1].PB (c1);
				G[2].PB (c2);
//				cout<<" msk="<<msk<<" "<<c0<<" "<<c1<<" "<<c2<<endl;
//				cout<<"son "<<k<<endl;
//				system("pause");
			}
			int dp[55][55];
			for (i=0; i<=m+2; i++) for (j=0; j<=G[0].SZ; j++) dp[j][i]=n*m;
			dp[0][0]=0;
			for (i=0; i<G[1].SZ; i++) {
				for (j=0; j<=m; j++) {
					dp[i+1][j+0]=min (dp[i+1][j+0],dp[i][j]+G[0][i]);
					dp[i+1][j+1]=min (dp[i+1][j+1],dp[i][j]+G[1][i]);
					dp[i+1][j+2]=min (dp[i+1][j+2],dp[i][j]+G[2][i]);
				}
			}
			int now=n*m;
			for (i=cc; i<=m; i++) now=min (dp[G[0].SZ][i],now);
			ret=min (ret,now);
//			cout<<"finish msk=";
//			printf("%x",msk);
//			cout<<" "<<now<<endl;
//			system("pause");
		}
//		cout<<rc<<" "<<cc<<endl;
//		for(i=0;i<A.SZ;i++)cout<<A[i]<<endl;
//		cout<<"test finish\n";
//		system("pause");
		return ret;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
int run_test_case (int);
void run_test (int casenum = -1, bool quiet = false) {
	if (casenum != -1) {
		if (run_test_case (casenum) == -1 && !quiet)
			cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
		return;
	}
	
	int correct = 0, total = 0;
	for (int i=0;; ++i) {
		int x = run_test_case (i);
		if (x == -1) {
			if (i >= 100) break;
			continue;
		}
		correct += x;
		++total;
	}
	
	if (total == 0) {
		cerr << "No test cases run." << endl;
	} else if (correct < total) {
		cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
	} else {
		cerr << "All " << total << " tests passed!" << endl;
	}
}

int verify_case (int casenum, const int &expected, const int &received, clock_t elapsed) {
	cerr << "Example " << casenum << "... ";
	
	string verdict;
	vector<string> info;
	char buf[100];
	
	if (elapsed > CLOCKS_PER_SEC / 200) {
		sprintf (buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
		info.push_back (buf);
	}
	
	if (expected == received) {
		verdict = "PASSED";
	} else {
		verdict = "FAILED";
	}
	
	cerr << verdict;
	if (!info.empty()) {
		cerr << " (";
		for (int i=0; i< (int) info.size(); ++i) {
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

int run_test_case (int casenum) {
	switch (casenum) {
		case 0: {
				string A[]                = {"0000" ,"1000" ,"1100" ,"1110"};
				int rowCount              = 2;
				int columnCount           = 2;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 1: {
				string A[]                = {"0000" ,"1000" ,"1100" ,"1110"};
				int rowCount              = 2;
				int columnCount           = 2;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 2: {
				string A[]                = {"0000" ,"1000" ,"1100" ,"1110"};
				int rowCount              = 3;
				int columnCount           = 2;
				int expected__            = 3;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 3: {
				string A[]                = {"01" ,"10"};
				int rowCount              = 1;
				int columnCount           = 1;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 4: {
				string A[]                = {"1110" ,"0001"};
				int rowCount              = 0;
				int columnCount           = 0;
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 5: {
				string A[]                = {"01010101" ,"01010101" ,"01010101" ,"01010101" ,"01010101" ,"01010101" ,"01010101" ,"01010101"};
				int rowCount              = 2;
				int columnCount           = 3;
				int expected__            = 8;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 6: {
				string A[]                = {"000000000000" ,"011101110111" ,"010001010101" ,"010001010101" ,"011101010101" ,"010101010101" ,"010101010101" ,"011101110111" ,"000000000000" ,"000000000000"};
				int rowCount              = 5;
				int columnCount           = 9;
				int expected__            = 14;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
		case 7: {
				string A[]                = {"11111101001110" ,"11000111111111" ,"00010101111001" ,"10110000111111" ,"10000011010010" ,"10001101101101" ,"00101010000001" ,"10111010100100" ,"11010011110111" ,"11100010110110" ,"00100101010100" ,"01001011001000" ,"01010001111010" ,"10100000010011"};
				int rowCount              = 6;
				int columnCount           = 8;
				int expected__            = 31;
				
				clock_t start__           = clock();
				int received__            = PalindromeMatrix().minChange (vector <string> (A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
				return verify_case (casenum, expected__, received__, clock()-start__);
			}
			
			// custom cases
			
			/*      case 7: {
						string A[]                = ;
						int rowCount              = ;
						int columnCount           = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = PalindromeMatrix().minChange( vector <string>( A, A + ( sizeof A / sizeof A[0] ) ), rowCount, columnCount );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 8: {
						string A[]                = ;
						int rowCount              = ;
						int columnCount           = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = PalindromeMatrix().minChange( vector <string>( A, A + ( sizeof A / sizeof A[0] ) ), rowCount, columnCount );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
			/*      case 9: {
						string A[]                = ;
						int rowCount              = ;
						int columnCount           = ;
						int expected__            = ;
			
						clock_t start__           = clock();
						int received__            = PalindromeMatrix().minChange( vector <string>( A, A + ( sizeof A / sizeof A[0] ) ), rowCount, columnCount );
						return verify_case( casenum, expected__, received__, clock()-start__ );
					}*/
		default:
			return -1;
	}
}
}


int main (int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test (atoi (argv[i]));
	}
}
// END CUT HERE
