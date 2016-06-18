#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
#define SZ size()
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}
int sign(LL x){return x<0?-1:x>0;}
struct point {
	LL x, y;
	point( LL _x=0, LL _y=0 ) : x( _x ), y( _y ) {}
	point operator - ( point p ) {return point( x-p.x,y-p.y );}
	point operator + ( point p ) {return point( x+p.x,y+p.y );}
	point operator * ( LL d ) {return point( x*d,y*d );}
	bool operator < ( const point &p ) const {
		return sign( x - p.x ) == 0 ? sign( y - p.y ) <= 0 : sign( x - p.x ) <= 0;
	}
	LL operator *( point p ) {return x*p.x+y*p.y;}//dot
	LL operator ^( point p ) {return x*p.y-y*p.x;}//det
	void out(){
		cout<<x<<" "<<y<<"\n";
	}
} Orz( 0,0 );
vector<point> ConvexHull( vector<point> p ) {
	int n = p.size(), m = 0;
	vector<point> q;
	q.resize( n * 2 );
	sort( p.begin(), p.end() );
	for ( int i = 0; i < n; i ++ ) {
		while ( m > 1 && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	int k = m;
	for ( int i = n - 2; i >= 0; i -- ) {
		while ( m > k && sign( ( q[m - 1] - q[m - 2] ) ^ ( p[i] - q[m - 2] ) )<= 0 )
			m -- ;
		q[m ++ ] = p[i];
	}
	if ( n > 1 ) m -- ;
	q.resize( m );
	return q;
}
LL SSS(point A,point B,point C){
	return abs((B-A)^(C-A));
}
int main(){
	int i,j,k,_T;
	int n;LL S;
	while(cin>>n>>S){
		vector<point>L;
		rep(i,0,n){
			LL x,y;
			cin>>x>>y;
			L.PB(point(x,y));
		}
		L=ConvexHull(L);
		LL mxs=0;
		int p=0,q=0,r=0;
		for(i=0;i<L.SZ;i++){
			k=(i+2+L.SZ)%L.SZ;
			for(j=i+1;j<L.SZ;j++){
				LL now=SSS(L[i],L[j],L[k]);
				while(1){
					LL le=SSS(L[i],L[j],L[(k-1+L.SZ)%L.SZ]);
					LL re=SSS(L[i],L[j],L[(k+1+L.SZ)%L.SZ]);
					if(re>now)now=re,k=(k+1+L.SZ)%L.SZ;
					else if(le>now)now=le,k=(k-1+L.SZ)%L.SZ;
					else break;
				}
				if(now>mxs)
					mxs=now,p=i,q=j,r=k;
			}
		}
		(L[p]+L[q]-L[r]).out();
		(L[q]+L[r]-L[p]).out();
		(L[r]+L[p]-L[q]).out();
	}
	return 0;
}