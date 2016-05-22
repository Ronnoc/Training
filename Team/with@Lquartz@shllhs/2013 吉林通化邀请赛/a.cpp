//shllhs
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;
int main() {
  int t;
  scanf ("%d", &t);
  while (t--) {
    double a, b = 0.0;
    for (int i = 1; i <= 12; i++) {
      scanf ("%lf", &a);
      b += a;
    }
    b /= 12.00;
    int bb = (int) b;
    if (fabs (bb - b) < eps) {
      printf ("$%d\n", bb);
    } else {
      int x = (int) (b * 100.0 + 0.5);
      if ( ( (int) (b * 10.0 + 0.5)) * 10 - (int) (b * 100.0 + 0.5) == 0) {
        printf ("$%.1lf\n", (double) x / 100.0);
      } else {
        printf ("$%.2lf\n", (double) x / 100.0);
      }
    }
  }
  return 0;
}
