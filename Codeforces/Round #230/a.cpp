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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
typedef long long LL;
typedef pair<int, int> PII;
void solve() {
	int i,j;
	int n;
	while ( ~scanf( "%d",&n ) ) {
		if(n==0){cout<<1<<endl;continue;}
		LL p=0,tot=1;
		LL last=0;
//		cout<<tot<<"~";
		for ( i=-n+1; i<0; i++ ) {
			j=sqrt( 1LL*n*n-1LL*i*i )+1e-15;
			while ( 1LL*( j+1 )*( j+1 )+1LL*i*i<=1LL*n*n )
				j++;
			while ( 1LL*j*j+1LL*i*i>1LL*n*n )
				j--;
			if(j==last)tot++;
			else tot+=j-last;
			last=j;
		}
//		cout<<endl;
		cout<<tot*4<<endl;
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
