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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 1000011;
const LL MOD = 1000000007;
int euler[MXN];
void tableEuler( int n ) {
	for ( int i = 0; i < n; i++ )
		euler[i] = i;
	for ( int i = 2; i < n; i++ )
		if ( euler[i] == i )
			for ( int j = i; j < n; j += i ) euler[j] = euler[j] / i * ( i - 1 );
}
LL pre[MXN];
int main() {
	int i,j;
	tableEuler(MXN);
	pre[0]=euler[0];
	for(i=1;i<MXN;i++)pre[i]=pre[i-1]+euler[i];
	while((cin>>i)&&i)cout<<pre[i]-1<<endl;
	return 0;
}
