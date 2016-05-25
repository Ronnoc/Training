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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos( -1 );
LL extGcd( LL a, LL b, LL &x, LL &y ) {
	LL ret = a;
	if ( b ) {
		ret = extGcd( b, a % b, y, x );
		y -= ( a / b ) * x;
	} else x = 1, y = 0;
	return ret;
}
LL modInv( LL a, LL m ) {
	LL x, y;
	extGcd( a,m,x,y );
	return ( m+x%m )%m;
}
LL t[4002][4002];
class CandyDrawing {
public:
	int findProbability( int N, int K, int _MOD ) {
		LL MOD=_MOD;
		LL n=N;
		int i,j;
		memset(t,0,sizeof t);
//		int FLAG=K<=10;
		for ( j=0; j<=2*K; j++ )t[0][j]=1;
		for ( i=1; i<=K; i++ ) {
			for ( j=i; j<=2*K; j++ ) {
				t[i][j]=t[i][j-1]+t[i-1][j-1]*j;
				if ( t[i][j]>=MOD )t[i][j]%=MOD;
//				if(FLAG)cout<<i<<" "<<j<<" "<<t[i][j]<<"?"<<t[i-1][j-1]<<endl;
			}
		}
		if ( K>N )return 0;
		if ( K==0 )return 1;
		//t[K][0~2K]=f(0~2K)
		LL ret=0;
//		if(FLAG){
//			cout<<K<<"!\n";
//			for(j=0;j<=2*K;j++)cout<<j<<","<<t[K][j]<<endl;
//		}
		for ( j=0; j<=2*K; j++ ) {
			LL fenzi=t[K][j],fenmu=1;
			for ( i=0; i<=2*K; i++ )if ( i!=j ) {
					fenzi=fenzi*( n-i )%MOD;
					fenmu=fenmu*( j-i )%MOD;
				}
			fenzi+=MOD;
			fenzi%=MOD;
			fenmu+=MOD;
			fenmu%=MOD;
//			if(FLAG)cout<<fenzi<<"/"<<fenmu<<endl;
			ret+=fenzi*modInv( fenmu,MOD )%MOD;
		}
		return ret%MOD;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
