//kybconnor
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

typedef long long LL;
typedef pair<int, int> PII;
const LL mod = 1000000007;
LL inv(LL x){
	LL ret=1;
	LL b=mod-2,a=x;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
LL A[200005];
LL modFact(LL n,LL &e){
	e=0;
	if(!n)return 1;
	LL res=modFact(n/mod,e);
	e+=n/mod;
	if(n/mod%2)return res*(mod-A[n%mod])%mod;
	return res*A[n%mod]%mod;
}
LL comb(LL n,LL k){
	if(n<0||k<0||n<k)return 0;
	LL e1,e2,e3;
	LL a1=modFact(n,e1);
	LL a2=modFact(k,e2);
	LL a3=modFact(n-k,e3);
	if(e1>e2+e3)return 0;
	return a1*inv(a2*a3%mod)%mod;
}
void solve(){
	int n,i,j,k;
	A[0]=1;
	for(i=1;i<=200000;i++)A[i]=A[i-1]*i%mod;
	while(~scanf("%d",&n)){
		if(n==1){printf("%d\n",0);continue;}
		LL res=0;
		for(k=0;k<=n;k++){
			LL delta=2LL*n*comb(2*n-k,k)%mod*A[n-k]%mod*inv(2*n-k)%mod;
			if(k&1)res-=delta;
			else res+=delta;
		}
		res%=mod;res=(res+mod)%mod;
		printf("%lld\n",res);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
