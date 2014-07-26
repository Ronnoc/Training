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
#include <cassert>
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
const double PI=acos( -1. );
const LL MOD = 1000000007;	//全主元gauss消去解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
#define MAXN 300
#define fabs(x) ((x)>0?(x):-(x))
#define eps 1e-10
int gauss_tpivot( int n, double a[][MAXN], double b[] ) {
	int i, j, k, row, col, index[MAXN];
	double maxp, t;
	for ( i = 0; i < n; i++ )
		index[i] = i;
	for ( k = 0; k < n; k++ ) {
		for ( maxp = 0, i = k; i < n; i++ )
			for ( j = k; j < n; j++ )
				if ( fabs( a[i][j] ) > fabs( maxp ) )
					maxp = a[row = i][col = j];
		if ( fabs( maxp ) < eps )
			return 0;
		if ( col != k ) {
			for ( i = 0; i < n; i++ )
				t = a[i][col], a[i][col] = a[i][k], a[i][k] = t;
			j = index[col], index[col] = index[k], index[k] = j;
		}
		if ( row != k ) {
			for ( j = k; j < n; j++ )
				t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
			t = b[k], b[k] = b[row], b[row] = t;
		}
		for ( j = k + 1; j < n; j++ ) {
			a[k][j] /= maxp;
			for ( i = k + 1; i < n; i++ )
				a[i][j] -= a[i][k] * a[k][j];
		}
		b[k] /= maxp;
		for ( i = k + 1; i < n; i++ )
			b[i] -= b[k] * a[i][k];
	}
	for ( i = n - 1; i >= 0; i-- )
		for ( j = i + 1; j < n; j++ )
			b[i] -= a[i][j] * b[j];
	for ( k = 0; k < n; k++ )
		a[0][index[k]] = b[k];
	for ( k = 0; k < n; k++ )
		b[k] = a[0][k];
	return 1;
}
double A[MAXN][MAXN],B[MAXN];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	double p;
	while ( ~scanf( "%lf",&p ) ) {
		int nid=0;
		map<PII,int>D;
		for ( i=0; i<20; i++ )for ( j=0; j<=i; j++ )
				D[MP( i,j )]=nid++;
		for ( i=0; i<nid; i++ )for ( j=0; j<nid; j++ )A[i][j]=0;
		for ( i=0; i<nid; i++ )B[i]=0;
		for ( i=0; i<20; i++ )for ( j=0; j<=i; j++ ) {
				int ai=i,bi=i,aj=j,bj=j;
				aj++;
				bj-=2;
				if ( ai<aj )swap( ai,aj );
				if ( bj<0 )bj=0;
				//E[i,j]=p*E[ai,aj]+(1-p)*E[bi,bj]+1
				int a=D[MP(ai,aj)],b=D[MP(bi,bj)],u=D[MP(i,j)];
				//-1=-E[u]+p*E[a]+(1-p)*E[b]
				B[u]-=1;
				A[u][u]-=1;
				if(ai<20)A[u][a]+=p;
				A[u][b]+=1-p;
			}
		gauss_tpivot(nid,A,B);
		printf("%.6f\n",B[0]);
	}
	return 0;
}
