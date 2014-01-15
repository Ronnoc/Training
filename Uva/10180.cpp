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

const long double eps = 1e-11;
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
int dcmp (long double x) {return x<-eps?-1:x>eps;}
void solve() {
  int i,j;
  int T;
  cin>>T;
  while (T--) {
    long double xa,ya,xb,yb,R;
    cin>>xa>>ya>>xb>>yb>>R;
    long double dx=xb-xa;
    long double dy=yb-ya;
    long double p=0,q=1;
    for (int t=0; t<100&&dcmp (p-q) !=0; t++) {
      long double l=p+ (q-p) /3;
      long double r=q- (q-p) /3;
      long double xl=xa+l*dx;
      long double yl=ya+l*dy;
      long double xr=xa+r*dx;
      long double yr=ya+r*dy;
      long double dl=sqrt (SQ (xl) +SQ (yl));
      long double dr=sqrt (SQ (xr) +SQ (yr));
      if (dcmp (dl-dr) >0) p=l;
      else q=r;
    }
    long double xx=xa+p*dx;
    long double yy=ya+p*dy;
    long double d=sqrt (SQ (xx) +SQ (yy));
    if (dcmp (d-R) >=0) printf ("%.3lf\n", double (sqrt (SQ (xa-xb) +SQ (ya-yb))));
    else {
      long double theta=acos (R/sqrt (SQ (xa) +SQ (ya))) +acos (R/sqrt (SQ (xb) +SQ (yb)));
      long double phi = acos ( (xa*xb+ya*yb) / (sqrt (SQ (xa) +SQ (ya)) *sqrt (SQ (xb) +SQ (yb))));
      if (dcmp (ya*xb-xa*yb) ==0) phi=acos (-1);
      long double hu= (phi-theta) *R;
      long double sega=sqrt (SQ (xa) +SQ (ya)-R*R);
      long double segb=sqrt (SQ (xb) +SQ (yb)-R*R);
//      cout<<phi<<" "<<theta<<" "<<sega<<" "<<segb<<endl;
      printf ("%.3lf\n",double (hu+sega+segb));
    }
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
