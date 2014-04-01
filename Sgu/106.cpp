#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define LL long long
LL a, b, c;
LL x1, x2, y1, y2;
LL fabs (LL x) {return x > 0 ? x : -x;}
LL exgcd (LL a, LL b, LL &x, LL &y) {
	LL t, ret;
	if (!b) {x = 1, y = 0; return a;}
	ret = exgcd (b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return ret;
}
LL inv (LL a, LL mod) {
	LL d, x, y;
	d = exgcd (a, mod, x, y);
	return d == 1 ? (x + mod) % mod : -1;
}
long long solve() {
	if (!a && !b) {
		if (c != 0) return 0LL;
		return (LL) (y2 - y1 + 1) * (LL) (x2 - x1 + 1);
	}
	if (!b)
		swap (a, b), swap (x1, y1), swap (x2, y2);
	if (!a) {
		if (c % b != 0) return 0LL;
		int k = -c / b;
		if (k >= y1 && k <= y2) return (x2 - x1 + 1);
		else return 0;
	}	//x=(-c-by)/a;		//y=(-c-ax)/b
	LL gcd = __gcd (fabs (a), fabs (b));
	if (c % gcd != 0) return 0LL;
	a /= gcd, b /= gcd, c /= gcd;
	double xp = (-c - b * (double) y1) / a, xq = (-c - b * (double) y2) / a;
	double xl = min (xp, xq), xr = max (xp, xq);
	xl = max (xl, (double) x1);
	xr = min (xr, (double) x2);
	LL l = xl - 1, r = xr + 1;
	while (r > xr) r--;
	while (l < xl) l++;
	if (r < l) return 0;
	LL d = fabs (b);
	LL s = (-fabs (c) % fabs (b) + fabs (b)) % fabs (b);		//sa+c=0 %b s=-c%b*inv()
	s *= inv (fabs (a), fabs (b));
	s %= fabs (b);
	s += fabs (b);
	s %= fabs (b);
	LL ll = (l - s) / d - 1, rr = (r - s) / d + 1;
	while (ll * d + s < l) ll++;
	while (rr * d + s > r) rr--;
	return (rr >= ll) ? (rr - ll + 1) : 0LL;
}
int main() {
	while (cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2)
		cout << solve() << endl;
	return 0;
}
