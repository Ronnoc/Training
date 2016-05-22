//kybconnor
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
int n;
int a[111], b[111], k[111];
const double eps = 1e-7;
vector<double>x;
double fabs (double x) {if (x > 0) return x; return -x;}
double equal (double a, double b) {
  if (fabs (a - b) < 1e-7) return 1;
  return 0;
}
bool isIn (double x) {
  if (x + eps < 0) return 0;
  if (x - eps > 100) return 0;
  return 1;
}
double find (double x) {
  double l = -20, r = 20;
  int t;
  for (t = 1; t <= 50; t++) {
    double mid = (l + r) / 2;
    double fmid = sinh (mid);
    if (fmid > x) r = mid;
    else l = mid;
  }
  return l;
}
double g (double x, int i) {
  return k[i] * (x - a[i]) * (x - a[i]) + b[i];
}
double F (double x, double k) {
  double ret = x * sqrt (1 + x * x) + find (x);
  return ret / (4 * k);
}
double ask (double l, double r) {
  double dis = (r - l) / 3;
  double ml = l + dis, mr = r - dis;
  double nowl = 100, nowr = 100;
  int m = 0;
  int i;
  for (i = 1; i <= n; i++)
    if (g (ml, i) < nowl && g (mr, i) < nowr)
      m = i, nowl = g (ml, i), nowr = g (mr, i);
  if (m == 0) return r - l;
  return F (2 * k[m] * (r - a[m]), k[m]) - F (2 * k[m] * (l - a[m]), k[m]);
}
pair<int , pair<double, double> > solve (double A, double B, double C) {
  if (equal (A, 0)) {
    if (equal (B, 0)) {
      if (equal (C, 0)) return MP (-2, MP (-1, -1));
      return MP (-1, MP (-1, -1));
    } else
      return MP (1, MP (-C / B, -C / B));
  } else {
    double delta = B * B - 4 * A * C;
    double mid = -B / (2 * A);
    if (delta + eps < 0) return MP (0, MP (0, 0));
    if (equal (delta, 0)) return MP (1, MP (mid, mid));
    double x1 = (-B + sqrt (delta)) / (2 * A);
    double x2 = (-B - sqrt (delta)) / (2 * A);
    return MP (2, MP (x1, x2));
  }
}
int main() {
  int T;
  scanf ("%d", &T);
  while (T--) {
    x.clear();
    scanf ("%d", &n);
    int i, j;
    for (i = 1; i <= n; i++) scanf ("%d%d%d", &k[i], &a[i], &b[i]);
    x.PB (0), x.PB (100);
    for (i = 1; i <= n; i++) {
      pair<int , pair<double, double> > temp = solve (k[i], -2 * a[i] * k[i], k[i] * a[i] * a[i] + b[i] - 100);
//            cout<<temp.AA<<" "<<temp.BB.AA<<" "<<temp.BB.BB<<endl;
      if (temp.AA == 1) {if (isIn (temp.BB.AA)) x.PB (temp.BB.AA);}
      else if (temp.AA == 2) {
        if (isIn (temp.BB.AA)) x.PB (temp.BB.AA);
        if (isIn (temp.BB.BB)) x.PB (temp.BB.BB);
      }
    }
    for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) {
        pair<int , pair<double, double> >
        temp = solve (k[i] - k[j], -2 * a[i] * k[i] + 2 * a[j] * k[j], k[i] * a[i] * a[i] + b[i] - k[j] * a[j] * a[j] - b[j]);
//            cout<<temp.AA<<" "<<temp.BB.AA<<" "<<temp.BB.BB<<endl;
        if (temp.AA == 1) {if (isIn (temp.BB.AA)) x.PB (temp.BB.AA);}
        else if (temp.AA == 2) {
          if (isIn (temp.BB.AA)) x.PB (temp.BB.AA);
          if (isIn (temp.BB.BB)) x.PB (temp.BB.BB);
        }
      }
    sort (x.begin(), x.end());
//        for(i=0;i<x.size();i++)printf("%3.3lf ",x[i]);printf("\n");
    double res = 0;
    for (i = 1; i < x.size(); i++) res += ask (x[i - 1], x[i]);
    printf ("%.2lf\n", res);
  }
  return 0;
}
