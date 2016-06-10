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
const LL MOD = 1000000007;
#define MAXN 25555
int a[25555][555];
int b[25555];
int gauss_tpivot( int m,int n ) {
	int i, j, k, row, col, index[MAXN];
	int maxp, t;
	for ( i = 0; i < m; i++ )
		index[i] = i;
	for ( k = 0; k < m; k++ ) {
		for ( maxp = 0, i = k; i < m; i++ )
			for ( j = k; j < n; j++ )
				if ( a[i][j]>maxp )
					maxp = a[row = i][col = j];
		if ( maxp == 0 ) {
			for ( i=k; i<m; i++ )if ( b[i]!=0 )return -1;
			return n-k;
		}
		if ( col != k ) {
			for ( i = 0; i < m; i++ )
				t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
			j = index[col], index[col] = index[k], index[k] = j;
		}
		if ( row != k ) {
			for ( j = k; j < n; j++ )
				t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
			t = b[k], b[k] = b[row], b[row] = t;
		}
		for ( j = k + 1; j < n; j++ ) {
			for ( i = k + 1; i < m; i++ )
				a[i][j] ^= a[i][k] * a[k][j];
		}
		for ( i = k + 1; i < m; i++ )
			b[i] ^= b[k] * a[i][k];
	}
	for ( i = n - 1; i >= 0; i-- )
		for ( j = i + 1; j < n; j++ )
			b[i] ^= a[i][j] * b[j];
	for ( k = 0; k < m; k++ )
		a[index[k]][0] = b[k];
	for ( k = 0; k < n; k++ )
		b[k] = a[k][0];
	return 0;
}
int A[22][22];
class PerfectSquare {
public:
	int ways( vector <int> x ) {
		memset( a,0,sizeof a );
		int ret=1;
		int i,j;
		int nn=x.SZ;
		int n=1;
		while ( n*n<nn )n++;
		for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )A[i][j]=x[i*n+j];
		int N=0;
		for ( i=0; i<n; i++ ) {
			for ( j=0; j<n; j++ )a[N][i*n+j]=1;
			b[N]=1;
			N++;
		}
		for ( j=0; j<n; j++ ) {
			for ( i=0; i<n; i++ )a[N][i*n+j]=1;
			b[N]=1;
			N++;
		}
		set<int>S;
		for ( i=0; i<x.SZ; i++ ) {
			int temp=x[i];
			for ( j=2; j*j<=temp; j++ )if ( temp%j==0 ) {
					while ( temp%j==0 )temp/=j;
					S.insert( j );
				}
			if ( temp>1 )S.insert( temp );
		}
		vector<int>P( S.OP,S.ED );
		for ( int p=0; p<P.SZ; p++ ) {
			for ( i=0; i<n; i++ )for ( j=0; j<n; j++ )if ( A[i][j]%P[p]==0 ) {
						int temp=A[i][j],cnt=0;
						while ( temp%P[p]==0 )temp/=P[p],cnt++;
						if ( cnt&1 )a[N][i*n+j]=1;
					}
			b[N]=0;
			N++;
		}
		cout<<N<<" "<<nn<<endl;
		int temp=gauss_tpivot( N,nn );
		if(temp==-1)return 0;
		while(temp--)
			ret=ret*2%MOD;
		return ret;
	}
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
