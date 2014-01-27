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
typedef long long LL;
typedef pair<int, int> PII;
int dcmp( double x ) {return x < -eps ? -1 : x > eps;}
struct point {
  double x, y;
  point() {}
  point( double _x, double _y ) : x( _x ), y( _y ) {}
  point operator - ( point p ) {return point( x - p.x, y - p.y );}
  point operator + ( point p ) {return point( x + p.x, y + p.y );}
  point operator / ( double d ) {return point( x / d, y / d );}
  point operator * ( double d ) {return point( x * d, y * d );}
  double operator ^ ( point p ) {return x * p.y - y * p.x;} //叉积
  double operator * ( point p ) {return x * p.x + y * p.y;} //点积
  void in() {scanf( "%lf%lf",&x,&y );}
  void out() {printf( "%lf %lf",x,y );}
  double len() {return hypot( x, y );}
  double arc() {return atan2( y, x );}
  bool operator < ( const point &p )const {
    return dcmp( x - p.x ) == 0 ? dcmp( y - p.y ) <= 0 : dcmp( x - p.x ) <= 0;
  }
  point normal() {return ( *this ) / this->len();}	 //规范化
  point rotate() {return point( -y, x );}		 //关于原点对称
  point rotate( double arc ) {				//绕原点旋转arc角度
    return point( x * cos( arc ) - y * sin( arc ), x * sin( arc ) + y * cos( arc ) );
  }
  double dis( point p ) {return ( *this - p ).len();}
  double dis2( point p ) {p = p - ( *this ); return p*p;}
};
void solve() {
  int i,j;
  int T;
  printf( "INTERSECTING LINES OUTPUT\n" );
  scanf( "%d",&T );
  while ( T-- ) {
    point pa,pb,qa,qb;
    pa.in();
    pb.in();
    qa.in();
    qb.in();
    int ka=dcmp( ( pb-pa )^( qa-pa ) );
    int kb=dcmp( ( pb-pa )^( qb-pa ) );
    int kl=dcmp( ( pb-pa )^( qb-qa ) );
    if ( ka==0&&kb==0 ) {printf( "LINE\n" );}
    else if ( kl==0 ) {printf( "NONE\n" );}
    else {
      double px=pb.x-pa.x,qx=qb.x-qa.x;
      double py=pb.y-pa.y,qy=qb.y-qa.y;
      //Yp=py/px*(X-pa.x)+pa.y
      //Yq=qy/qx*(X-qa.x)+qa.y
      //px*qx*pa.y+qx*py*(X-pa.x)=px*qx*qa.y+qy*px*(X-qa.x)
      double X=( px*qx*( qa.y-pa.y )+qx*py*pa.x-qy*px*qa.x )/( qx*py-px*qy ),Y;
      if ( dcmp( px )==0 )Y=qy/qx*( X-qa.x )+qa.y;
      else Y=py/px*( X-pa.x )+pa.y;
      printf( "POINT %.2f %.2f\n",X,Y );
    }
  }
  printf( "END OF OUTPUT\n" );
}
int main() {
//	while(1)
  solve();
  return 0;
}
