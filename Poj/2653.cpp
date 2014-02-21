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
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1E-8;
int dcmp( double x ) {return x<-eps?-1:x>eps;}
struct point {
	double x,y;
	point() {}
	point( double _x,double _y ) {x=_x; y=_y;}
	point operator - ( const point p )const {return point( x-p.x,y-p.y );}
	double operator ^ ( const point p )const {return x*p.y-y*p.x;}
};
point u[100011],v[100011];
int n;
bool leave( double a,double b,double c,double d ) {
	double l1=min( a,b ),r1=max( a,b );
	double l2=min( c,d ),r2=max( c,d );
	if ( l1>r2||l2>r1 )return 1;
	return 0;
}
bool connect( point a,point b,point c,point d ) {
	if ( leave( a.x,b.x,c.x,d.x ) )return 0;
	if ( leave( a.y,b.y,c.y,d.y ) )return 0;
	int f1=dcmp( ( c-a )^( b-a ) );
	int f2=dcmp( ( d-a )^( b-a ) );
	int f3=dcmp( ( a-c )^( d-c ) );
	int f4=dcmp( ( b-c )^( d-c ) );
	return f1*f2<=0&&f3*f4<=0;
}
int main(){
	int i,j;
	while(~scanf("%d",&n)&&n){
		for(i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&u[i].x,&u[i].y,&v[i].x,&v[i].y);
		vector<int>A;
		for(i=1;i<=n;i++){
			int flag=0;
			for(j=i+1;!flag&&j<=n;j++)
				if(connect(u[i],v[i],u[j],v[j]))flag=1;
			if(!flag)A.PB(i);
		}
		SORT(A);
		printf("Top sticks: %d",A[0]);
		for(i=1;i<A.SZ;i++)printf(", %d",A[i]);
		printf(".\n");
	}
	return 0;
}
