#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define _LL long long
int mod;

_LL exponent( _LL x,int m ) {
	long long res=1;
	while ( m ) {
		if ( m&1 )
			res*=x;
		x*=x;
		res%=mod;
		x%=mod;
		m/=2;
	}
	return res;
}

int isp[33333];
vector<int>prime;
const int MP = 32000;
int prime_shai(){
	prime.clear();
	int i,j;
	for(i=2;i<=MP;i++)isp[i]=1;
	for(i=2;i<=MP;i++){
		if(!isp[i])continue;
		prime.push_back(i);
		for(j=2*i;j<=MP;j+=i)isp[j]=0;
	}
}

_LL phi(_LL n){
    _LL i,tp=n;
    _LL res=n;
    for(i=0;i<prime.size()&&prime[i]*prime[i]<=tp;i++)while(n%prime[i]==0){
        res*=(prime[i]-1);
        res/=prime[i];
        while(n%prime[i]==0)n/=prime[i];
    }
    if(n>1){res/=n;res*=n-1;}
    return res;
}

int main() {
	int n,m,i,j,T;
	prime_shai();
	for ( scanf( "%d",&T ); T; T-- ) {
		scanf( "%d%d",&n,&mod );
		long long res=0;
		int i;
		for ( i=1; i*i<=n; i++ ) {
			if ( n%i )continue;
			res+=phi(n/i)*exponent( n,i-1 );
			if(i*i!=n)res+=phi(i)*exponent( n,n/i-1 );
			res%=mod;
		}
		printf( "%I64d\n",res );
	}
	return 0;
}
