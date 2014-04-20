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

class LCMSet {
public:
	string equal( vector <int> A, vector <int> B ) {
		string yes="Equal";
		string no="Not equal";
		int i,j;
		for(i=0;i<A.SZ;i++){
			int lcm=1;
			for(j=0;j<B.SZ;j++)if(A[i]%B[j]==0)
				lcm=lcm/__gcd(lcm,B[j])*B[j];
			if(lcm!=A[i])return no;
		}
		swap(A,B);
		for(i=0;i<A.SZ;i++){
			int lcm=1;
			for(j=0;j<B.SZ;j++)if(A[i]%B[j]==0)
				lcm=lcm/__gcd(lcm,B[j])*B[j];
			if(lcm!=A[i])return no;
		}
		return yes;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
