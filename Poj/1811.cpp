#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long LL;
LL mr[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
const int MXN = 150000;
int isp[MXN+10], p[MXN+10], mp = 0;
LL llpro (LL a, LL b, LL mod) {
	LL ret = 0;
	if (b > a) swap (a, b);
	while (b) {
		if (b & 1) {ret += a; ret %= mod;}
		a += a;
		a %= mod;
		b /= 2;
	}
	return ret;
}
LL power (LL a, LL m, LL mod) {
	LL ret = 1LL;
	while (m) {
		if (m & 1) ret = llpro (a, ret, mod);
		a = llpro (a, a, mod);
		m /= 2;
	}
	return ret;
}
LL llrand(){
	LL x=0LL;
	x<<=15;x+=rand();
	x<<=15;x+=rand();
	x<<=15;x+=rand();
	x<<=15;x+=rand();
	return x;
}
bool RabinMiller (LL n) {
	int i;
	if (n < MXN && isp[i]) return 1;
	for(i=1;i<=mp;i++)if(n%p[i]==0)return 0;
	for (i = 0; i < 7; ++i)
		if (mr[i] < n && power (mr[i], n - 1, n) != 1LL)
			return 0;
	return 1;
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL f (LL x, LL mod) {
	return (llpro (x, x, mod) + 1) % mod;
}
LL pollardrho (LL n) {
	for (int i = 1; i <= mp; i++)
		if (n % p[i] == 0) return p[i];
	LL i, x, y, ret;
	i = 1;
	while (1) {
		x = i++;
		y = f (x, n);
		ret = gcd ( (y > x ? y - x : x - y) % n, n);
		while (ret == 1) {
			x = f (x, n);
			y = f (f (y, n), n);
			ret = gcd ( (y > x ? y - x : x - y) % n, n) % n;
		}
		if (0 < ret && ret < n) {
			LL l = RabinMiller (ret) ? ret : pollardrho (ret);
			LL ans = n / ret;
			LL r = RabinMiller (ans) ? ans : pollardrho (ans);
			return min (l, r);
		}
	}
}
int main() {
	long long i, j, sn = sqrt ((double)MXN);
	for (i = 3, isp[2] = 1; i < MXN; i++) isp[i] = i % 2;
	for (i = 3; i <= sn + 1; i++) if (isp[i])
			for (j = i * i; j <= MXN; j +=2* i) isp[j] = 0;
	for (i = 2; i < MXN; i++) if (isp[i]) p[++mp] = i;
	LL n,t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (RabinMiller (n)) cout << "Prime" << endl;
		else cout << pollardrho (n) << endl;
	}
	return 0;
}
