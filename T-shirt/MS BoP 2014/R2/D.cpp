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
int x[111];
int y[111];
int z[111];
double xx,yy,zz,xy,xz,yz;
double all( double A,double B,double C ) {
	return SQ( A )*xx+SQ( B )*yy+SQ( C )*zz+2*A*B*xy+2*A*C*xz+2*B*C*yz;
}
void F( double A,double B,double C,double &fa,double &fb,double &fc ) {
	double w=SQ( A )+SQ( B )+SQ( C );
	double ALL=all( A,B,C );
	fa=( ( 2*A*xx+2*B*xy+2*C*xz )*w-2*A*ALL )/SQ( w );
	fb=( ( 2*A*xy+2*B*yy+2*C*yz )*w-2*B*ALL )/SQ( w );
	fc=( ( 2*A*xz+2*B*yz+2*C*zz )*w-2*C*ALL )/SQ( w );
	double d=sqrt( SQ( fa )+SQ( fb )+SQ( fc ) );
	fa/=d,fb/=d,fc/=d;
}
int main() {
	int i,j;
	int T;
	scanf( "%d",&T );
	for ( int CASE=1; CASE<=T; ++CASE ) {
		int n;
		xx=0,yy=0,zz=0,xy=0,xz=0,yz=0;
		scanf( "%d",&n );
		for ( i=0; i<n; i++ )scanf( "%d%d%d",&x[i],&y[i],&z[i] );
		for ( i=0; i<n; i++ )xx+=x[i]*x[i];
		for ( i=0; i<n; i++ )xy+=x[i]*y[i];
		for ( i=0; i<n; i++ )xz+=x[i]*z[i];
		for ( i=0; i<n; i++ )yy+=y[i]*y[i];
		for ( i=0; i<n; i++ )yz+=y[i]*z[i];
		for ( i=0; i<n; i++ )zz+=z[i]*z[i];
		set<pair<pair<double,double>,pair<double,double> > >S;
		S.clear();
		for ( i=1; i<8; i++ ) {
			double dis=1e5;
			double A=i&1,B=i&2,C=i&4,now,next;
			for ( int t=0; t<=40; t++,dis/=2 ) {
				while ( 1 ) {
					double fa,fb,fc;
					F( A,B,C,fa,fb,fc );
					now=all( A,B,C )/( SQ( A )+SQ( B )+SQ( C ) );
					next=all( A-dis*fa,B-dis*fb,C-dis*fc )/( SQ( A-dis*fa )+SQ( B-dis*fb )+SQ( C-dis*fc ) );
					if ( next+eps<now )A-=dis*fa,B-=dis*fb,C-=dis*fc,now=next;
					else break;
				}
			}
			S.insert(MP(MP(all( A,B,C )/( SQ( A )+SQ( B )+SQ( C ) ),A),MP(B,C)));
		}
		printf( "Case %d: %.9lf %.9lf %.9lf\n",CASE,(*S.OP).AA.BB,(*S.OP).BB.AA,(*S.OP).BB.BB );
	}
	return 0;
}
