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
const int MXN = 50;
const LL MOD = 1000000007;
int main() {
	int i,j,k;
	int T;
	cin>>T;
	for ( int CASE=1; CASE<=T; ++CASE ) {
		LL n;
		cin>>n;
		n%=MOD;
		LL ans=0;
		LL all=0,two=0,same=0;
		cout<<"Case "<<CASE<<": ";
		LL inv8=125000001;
		LL inv4=inv8*2;
		LL inv2=inv4*2;
		all=inv8;
		all*=n; all%=MOD; all*=n; all%=MOD; all*=n; all%=MOD;
		all*=n+1; all%=MOD; all*=n+1; all%=MOD; all*=n+1; all%=MOD;
		same=inv4;
		same*=n; same%=MOD;
		same*=n; same%=MOD;
		same*=n+1; same%=MOD;
		same*=n+1; same%=MOD;
		two=same;
		two*=( 2*n+1 ); two%=MOD;
		two-=3*same; two%=MOD;
		cout<<( all-two+MOD )%MOD<<endl;
	}
	return 0;
}
