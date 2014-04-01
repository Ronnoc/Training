#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define _LL long long
//扩展Euclid求解gcd(a,b)=ax+by
_LL ext_gcd (_LL a, _LL b, _LL &x, _LL &y) {
	_LL t, ret;
	if (!b) {
		x = 1;
		y = 0;
		return a;
		}
	ret = ext_gcd (b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return ret;
	}
//计算m^a
_LL exponent (_LL m, _LL a) {
     _LL ret = 1;
     while (a) {
          if (a & 1) ret *= m;
          a >>= 1;
          m *= m;
          }
     return ret;
     }
//计算m^a%mod
_LL mod_exponent (_LL m, _LL a, _LL mod) {
	_LL ret = 1;
	m %= mod;
	while (a) {
		if (a & 1) ret *= m;
		a >>= 1;
		m *= m;
		m %= mod;
		ret %= mod;
		}
	return ret;
	}
//求解模线性方程ax=b (% mod)
//返回解的个数,一个解保存在e中
//要求n>0,解的范围0..n-1
_LL mod_linear1 (_LL a, _LL b, _LL mod, _LL &e) {
	_LL d, x, y;
	d = ext_gcd (a, mod, x, y);
	if (b % d)
		return 0;
	e = (x * (b / d) % mod + mod) % mod;
	return d;
	}
_LL Inverse(_LL a,_LL mod){
     _LL d,x,y;
     d=ext_gcd(a,mod,x,y);
     return d==1?(x+mod)%mod:-1;
}

//1+a+...+a^b %mod      //a是prime
_LL sum_geometric (_LL a, _LL b, _LL mod) {
    if(a==1)return (b+1)%mod;
 //   cout<<"sum_geometric: 1+...+"<<a<<"^"<<b<<endl;
	_LL inv = (Inverse (a - 1, mod) + mod) % mod;
	_LL a_pow_b = mod_exponent (a, b + 1, mod);
//	cout<<"a^(b+1): "<<a_pow_b<<endl;
	_LL ans = a_pow_b - 1;
	if (ans < 0) ans += mod;
	ans *= inv;
	ans %= mod;
//	cout<<"ans: "<<ans<<endl;
	return ans;
	}
#define PSIZE 7000
_LL plist[PSIZE], pcount = 0;
int prime (_LL n) {
	int i;
	if ( (n != 2 && ! (n % 2)) || (n != 3 && ! (n % 3)) || (n != 5 && ! (n % 5)) || (n != 7 && ! (n % 7)))
		return 0;
	for (i = 0; plist[i]*plist[i] <= n; ++i)
		if (! (n % plist[i]))
			return 0;
	return n > 1;
	}
void initprime() {
	int i;
	for (plist[pcount++] = 2, i = 3; i < 8000; ++i)
		if (prime (i))
			plist[pcount++] = i;
	}
int prime_factor (_LL n, _LL* f, _LL *nf) {
	int cnt = 0;
	_LL n2 = sqrt ( (double) n);
	for (int i = 0; n > 1 && plist[i] <= n2; ++i)
		if (n % plist[i] == 0) {
			for (nf[cnt] = 0; n % plist[i] == 0; ++nf[cnt], n /= plist[i]);
			f[cnt++] = plist[i];
			}
	if (n > 1) nf[cnt] = 1, f[cnt++] = n;
	return cnt;
	}
_LL solve (_LL a, _LL b, _LL mod) {
	_LL f[30], nf[30];
	int n_prime = prime_factor (a, f, nf);
	_LL ans = 1;
	for (int i = 0; i < n_prime; i++) {
		ans *= sum_geometric (f[i]%mod, b * nf[i], mod);
		ans %= mod;
		}
	return ans;
	}
int main() {
    initprime();
	_LL A, B;
	_LL S=9901;
	while (cin >> A >> B) {
		if (A == 0) cout << 0 << endl;
		else if (B == 0) cout << 1 << endl;
		else cout << solve (A, B, S) << endl;
//		_LL ans=0;
//		_LL aim=exponent(A,B);
//		for(_LL i=1;i<=aim;i++)if(aim%i==0){
//                ans+=i;ans%=S;cout<<i<<" ";}
//		cout<<endl<<ans<<endl;
		}
	return 0;
	}
//59407 1-->2
