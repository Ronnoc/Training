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
int dcmp (double x) {return x < -eps ? -1 : x > eps;}
struct point {
  double x, y;
  point() {}
  point (double _x, double _y) : x (_x), y (_y) {}
  point operator - (point p) {return point (x - p.x, y - p.y);}
  point operator + (point p) {return point (x + p.x, y + p.y);}
  point operator / (double d) {return point (x / d, y / d);}
  point operator * (double d) {return point (x * d, y * d);}
  bool operator < (const point &p) const {
    return dcmp (x - p.x) == 0 ? dcmp (y - p.y) <= 0 : dcmp (x - p.x) <= 0;
  }
  double operator * (point p) {return x * p.y - y * p.x;} //叉积
  double operator | (point p) {return x * p.x + y * p.y;} //点积
  double len() {return hypot (x, y);}
  double arc() {return atan2 (y, x);}
  point normal() {return (*this) / this->len();}	 //规范化
  point rotate() {return point (-y, x);}		 //关于原点对称
  point rotate (double arc) {				//绕原点旋转arc角度
    return point (x * cos (arc) - y * sin (arc), x * sin (arc) + y * cos (arc));
  }
  double dis (point p) {return (*this - p).len();}
  double dis2 (point p) {p = p - (*this); return p|p;}
  void out() {printf ("%lf %lf\n",x,y);}
};
point p[22],q[22];
int fa[22];
int getfa (int x) {return x==fa[x]?x:fa[x]=getfa (fa[x]);}
bool cross (point a,point b,point c,point d) {
  if (dcmp ( (b-c) * (a-c)) ==0) {if (dcmp ( (b-c) | (a-c)) <=0) return 1;}
  if (dcmp ( (b-d) * (a-d)) ==0) {if (dcmp ( (b-d) | (a-d)) <=0) return 1;}
  swap(a,c);swap(b,d);
  if (dcmp ( (b-c) * (a-c)) ==0) {if (dcmp ( (b-c) | (a-c)) <=0) return 1;}
  if (dcmp ( (b-d) * (a-d)) ==0) {if (dcmp ( (b-d) | (a-d)) <=0) return 1;}
  if (dcmp ( (b-c) * (a-c)) ==0) return 0;
  if (dcmp ( (b-d) * (a-d)) ==0) return 0;
  swap(a,c);swap(b,d);
  if (dcmp ( (b-c) * (a-c)) ==0) return 0;
  if (dcmp ( (b-d) * (a-d)) ==0) return 0;
  if (dcmp ( (b-c) * (a-c))*dcmp ( (b-d) * (a-d))>0)return 0;
  swap(a,c);swap(b,d);
  if (dcmp ( (b-c) * (a-c))*dcmp ( (b-d) * (a-d))>0)return 0;
  return 1;
}
void solve() {
  int i,j;
  int n;
  while (scanf ("%d",&n) !=EOF&&n) {
    for (i=1; i<=n; i++) scanf ("%lf%lf%lf%lf",&p[i].x,&p[i].y,&q[i].x,&q[i].y);
    for (i=1; i<=n; i++) fa[i]=i;
    for (i=1; i<=n; i++) for (j=i+1; j<=n; j++)
        if (cross (p[i],q[i],p[j],q[j])) fa[getfa (i)]=getfa (j);
    int u,v;
    while (~scanf ("%d%d",&u,&v) !=EOF) {
      if (!u&&!v) break;
      if (getfa (u) ==getfa (v)) printf ("CONNECTED\n");
      else printf ("NOT CONNECTED\n");
    }
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
