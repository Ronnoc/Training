//kybconnor
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
#define AA first
#define BB second
LL llpow (LL a,LL x,LL mod) {
	LL ret=1;
	while (x) {
		if (x&1) ret=ret*a%mod;
		a=a*a%mod;
		x/=2;
	}
	return ret;
}
map<int,int> moebius (LL n) {
	map<int,int> res;
	vector<int>prime;
	int i,j;
	for (i=2; i*i<=n; i++)
		if (n%i==0) {
			prime.push_back (i);
			while (n%i==0) n/=i;
		}
	if (n!=1) prime.push_back (n);
	
	int m=prime.size();
	for (int i=0; i< (1<<m); i++) {
		int mu=1,d=1;
		for (j=0; j<m; j++) {
			if (i>>j&1) {
				mu*=-1;
				d*=prime[j];
			}
			res[d]=mu;
		}
	}
	return res;
}
LL sum (LL m) {		//1^4+2^4+...+m^4
	LL ret=0;
	LL S0=m;
	LL S1=m* (m+1) /2%mod;
	LL S2=m* (m+1) %mod*llpow (6,mod-2,mod) %mod* (2*m+1) %mod;
	LL S3=S1*S1%mod;
	ret=llpow (m+1,5,mod)-1;
	ret-=10*S3;
	ret-=10*S2;
	ret-=5*S1;
	ret-=S0;
	ret%=mod;
	ret*=llpow (5,mod-2,mod);
	return (ret%mod+mod) %mod;
}
int main() {
	int T;
	scanf ("%d",&T);
	for (int t=1; t<=T; t++) {
		LL i,n;
		scanf ("%lld",&n);
		map<int,int>S=moebius (n);
		LL ans=0;
		map<int,int>::iterator iter;
		for (iter=S.begin(); iter!=S.end(); ++iter) {
			pair<int,int>T=*iter;
//			cout<<T.AA<<" "<<T.BB<<endl;
//			cout<<llpow(T.AA,4,mod)*sum(n/T.AA)<<endl;
			ans+=llpow (T.AA,4,mod) *sum (n/T.AA) *T.BB;
			ans= (ans%mod+mod) %mod;
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
