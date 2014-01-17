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

typedef long long LL;
typedef pair<int, int> PII;
typedef long long lint;		//easy to change
lint extGcd (lint a, lint b, lint &x, lint &y) {
  lint ret = a;
  if (b) {
    ret = extGcd (b, a % b, y, x);
    y -= (a / b) * x;
  } else
    x = 1, y = 0;
  return ret;
}
lint modInv (lint a, lint m) {
  lint x, y;
  extGcd (a,m,x,y);
  return (m+x%m) %m;
}
LL fact[111111];	//预处理n! mod p 的表 O(p)
LL two[111111];
// n!=a*p^e return a%p
LL modFact (LL n, LL p, LL &e) {
  e = 0;
  if (!n) return 1;
  LL res = modFact (n / p, p, e);
  e += n / p;
  if (n / p % 2)
    return res * (p - fact[n % p]) % p;
  return res * fact[n % p] % p;
}
//C _(n) ^(k) %p
LL modComb (LL n, LL k, LL p) {
//	cout<<"C"<<n<<","<<k<<endl;
  if (n < 0 || k < 0 || n < k) return 0;
  LL e1, e2, e3;
  LL a1 = modFact (n, p, e1);
  LL a2 = modFact (k, p, e2);
  LL a3 = modFact (n - k, p, e3);
  if (e1 > e2 + e3) return 0;
  return a1 * modInv (a2 * a3 % p, p) % p;
}
int x[111111],n;
const int mod = 1000000007 ;
vector<PII>T;
LL play (int l,int r) {
  LL add=1;
  for (int i=0; i<T.SZ; i++) {
    int x=T[i].BB;
    int has=r-l+1;
    int in=T[i].AA-1-has;
//				cout<<x<<" "<<has<<" "<<in<<" "<<l<<" "<<r<<endl;
    if (x<l) {
      if (l-in>x+1) add*=0;
      else add=add*modComb (in,l-x-1,mod) %mod;
//					cout<<" "<<modComb(in,l-x-1,mod)<<" ";
      l=x;
      r=l+has+in;
      //r-l=has+in
    } else {
      if (r+in<x-1) add*=0;
      else add=add*modComb (in,x-r-1,mod) %mod;
//					cout<<" "<<modComb(in,x-r-1,mod)<<" ";
      r=x;
      l=r-has-in;
    }
//				cout<<l<<" "<<r<<" "<<add<<endl;
		if(add==0)return 0;//剪枝从178ms到71ms
  }
  add=add*modComb (n- (r-l+1),l-1,mod);
  return add;
}
void solve() {
  fact[0]=1;
  two[0]=1;
  int i;
  for (i=1; i<=100000; i++) fact[i]=fact[i-1]*i%mod;
  for (i=1; i<=100000; i++) two[i]=two[i-1]*2%mod;
  while (cin>>n) {
    T.clear();
    int i;
    for (i=1; i<=n; i++) {
      scanf ("%d",&x[i]);
      if (x[i]) T.PB (MP (x[i],i));
    }
    sort (T.begin(),T.end());
    int l=n;
    int r=1;
    int wa=0;
    for (i=0; !wa&&i<T.SZ; i++) {
      if (T[i].BB>l&&T[i].BB<r) wa=1;
      else l=min (T[i].BB,l),r=max (T[i].BB,r);
    }
    if (wa) {
      printf ("0\n");
      continue;
    }
    if (T.empty()) {
      LL ret=0;
      for (i=1; i<=n; i++) {
        ret= (ret+modComb (n-1,i-1,mod)) %mod;
      }
      cout<<ret<<endl;
      continue;
    }
    if (T[0].AA==1) {
      int l=T[0].BB,r=T[0].BB;
      LL add=1;
      for (i=1; i<T.SZ; i++) {
        int x=T[i].BB;
        int has=r-l+1;
        int in=T[i].AA-1-has;
//				cout<<x<<" "<<has<<" "<<in<<" "<<l<<" "<<r<<endl;
        if (x<l) {
          if (l-in>x+1) add*=0;
          else add=add*modComb (in,l-x-1,mod) %mod;
//					cout<<" "<<modComb(in,l-x-1,mod)<<" ";
          l=x;
          r=l+has+in;
          //r-l=has+in
        } else {
          if (r+in<x-1) add*=0;
          else add=add*modComb (in,x-r-1,mod) %mod;
//					cout<<" "<<modComb(in,x-r-1,mod)<<" ";
          r=x;
          l=r-has-in;
        }
//				cout<<l<<" "<<r<<" "<<add<<endl;
      }
      add=add*modComb (n- (r-l+1),l-1,mod);
      cout<<add<<endl;
      continue;
    }
    int s=T[0].BB;
    int l1=1,r1=s-1;
    int l2=s+1,r2=n;
    for (i=1; i<T.SZ; i++) {
      if (T[i].BB<s) l1=max (l1,T[i].BB+1);
      if (T[i].BB>s) r2=min (r2,T[i].BB-1);
    }
    LL ans=0;
//    cout<<"here"<<endl;
    if (l1<=r1&&l1>=1&&r1<=n) {
      for(i=l1;i<=r1;i++)ans=(ans+play(i,i))%mod;
    }
    if (l2<=r2&&l2>=1&&r2<=n)
      for(i=l2;i<=r2;i++)ans=(ans+play(i,i))%mod;
    ans%=mod;
    cout<<ans<<endl;
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
